#include <stdint.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdint>
#include <functional>
#include <type_traits>

using namespace std;

//no carry
inline unsigned char add_uint64(uint64_t operand1, uint64_t operand2, uint64_t *result)
{
	*result = operand1 + operand2;
    return static_cast<unsigned char>(*result < operand1);
}

//no carry, riscv version
inline unsigned char add_uint64_riscv(uint64_t operand1, uint64_t operand2, uint64_t *result)
{
    // Since the word of the CPU is 64 bits the ADD will perfom a 64 bit adition,
    //on the other hand the ADDW would perform a 32 bit adition.
    asm volatile(
        "ADD %0, %1, %2"
    : "=r" (*result) //%0
    : "r" (operand1), "r" (operand2) //%1 and %2
    );

	return static_cast<unsigned char>(*result < operand1); //The original function has this return value, rewrite as riscv functions??
}

//with carry
inline unsigned char add_uint64(uint64_t operand1, uint64_t operand2, unsigned char carry, uint64_t *result)
{
	operand1 += operand2;
    *result = operand1 + carry;
 
    return (operand1 < operand2) || (~operand1 < carry);
}

//with carry, riscv version
inline unsigned char add_uint64_riscv(uint64_t operand1, uint64_t operand2, unsigned char carry, uint64_t *result)
{
	/*
	operand1 += operand2;
    *result = operand1 + carry;
    return (operand1 < operand2) || (~operand1 < carry);
	*/

	asm volatile(
        "ADD %0, %1, %2;"
		"ADD %0, %0, %3;"
    : "=r" (*result) //%0
    : "r" (operand1), "r" (operand2), "r" (carry) //%1 and %2
    );

    return (operand1 < operand2) || (~operand1 < carry);
}

inline void multiply_uint64_riscv(uint64_t operand1, uint64_t operand2, uint64_t *result128)
{
   	uint64_t resh;
	uint64_t resl;

   	asm volatile(	"MULHU %0, %2, %3;"
					"MUL %1, %2, %3;"
				
				: "+r"(resh), "+r"(resl)
				: "r"(operand1), "r"(operand2)
				: "memory");

	result128[1] = (uint64_t)resh;
	result128[0] = (uint64_t)resl;

	//cout << "Result asm: " << to_string(resh) << to_string(resl) << endl;
}

unsigned char add_uint128(uint64_t *operand1, uint64_t *operand2, uint64_t *result)
{
    unsigned char carry = add_uint64_riscv(operand1[0], operand2[0], result);
    return add_uint64_riscv(operand1[1], operand2[1], carry, result + 1);
}

inline void multiply_uint64_generic(uint64_t operand1, uint64_t operand2, uint64_t *result128)
{    
	auto operand1_coeff_right = operand1 & 0x00000000FFFFFFFF;
    auto operand2_coeff_right = operand2 & 0x00000000FFFFFFFF;
    operand1 >>= 32;
    operand2 >>= 32;

    auto middle1 = operand1 * operand2_coeff_right;
    uint64_t middle;
    auto left = operand1 * operand2 + (static_cast<uint64_t>(add_uint64(middle1, operand2 * operand1_coeff_right, &middle)) << 32);
	auto right = operand1_coeff_right * operand2_coeff_right;
    auto temp_sum = (right >> 32) + (middle & 0x00000000FFFFFFFF);

    result128[1] = static_cast<uint64_t>(left + (middle >> 32) + (temp_sum >> 32));
    result128[0] = static_cast<uint64_t>((temp_sum << 32) | (right & 0x00000000FFFFFFFF));
}

template <std::size_t Count = 0>
void multiply_accumulate_uint64(const uint64_t* operand1, const uint64_t* operand2, uint64_t* accumulator)
{
	uint64_t qword[2];
	multiply_uint64_riscv(*operand1, *operand2, qword);
	//cout << to_string(Count) << "Multiplying: " <<  *operand1 << " by " << *operand2 << " res_low: " << qword[0] << " res_high: " << qword[1] << endl;

    multiply_accumulate_uint64<Count - 1>(operand1 + 1, operand2 + 1, accumulator);
    add_uint128(qword, accumulator, accumulator);
	//cout << to_string(Count) << "Res: " << accumulator[0] << ", " << accumulator[1] << endl;
}

template <>
void multiply_accumulate_uint64<0>(const uint64_t *operand1, const uint64_t *operand2, uint64_t *accumulator)
{
	// Base case; nothing to do
}

int main(int argc, char** argv)
{

    uint64_t a[2] = {232953229826203942, 825826491950185275};
    uint64_t b[2] = {102037917626262625, 916381620130101029};

	uint64_t result[2] = {0,0};//Index 0 -> low part

	multiply_accumulate_uint64<2>(a, b, result);

	cout << "Result original low: " << to_string(result[0]) << ", high: " << to_string(result[1]) << endl;
}