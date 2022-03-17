#include <stdint.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdint>
#include <functional>
#include <type_traits>
#include "seal/util/uintarith.h"

void set_mod_value(uint64_t value)
{
    // All normal, compute const_ratio and set everything
    uint64_t value_ = value;
    bit_count_ = get_significant_bit_count(value_);
    // Compute Barrett ratios for 64-bit words (barrett_reduce_128)
    uint64_t numerator[3]{ 0, 0, 1 };
    uint64_t quotient[3]{ 0, 0, 0 };
    // Use a special method to avoid using memory pool
    divide_uint192_inplace(numerator, value_, quotient);
    const_ratio_[0] = quotient[0];
    const_ratio_[1] = quotient[1];
    // We store also the remainder
    const_ratio_[2] = numerator[0];
    uint64_count_ = 1;
    // Set the primality flag
    is_prime_ = util::is_prime(*this);
}

/*
Returns input mod modulus. This is not standard Barrett reduction.
Correctness: modulus must be at most 63-bit.
@param[in] input Should be at most 128-bit.
*/

uint64_t barrett_reduce_128(uint64_t *input, uint64_t &modulus)
{
    // Reduces input using base 2^64 Barrett reduction
    // input allocation size must be 128 bits

    unsigned long long tmp1, tmp2[2], tmp3, carry;
    const std::uint64_t *const_ratio = modulus.const_ratio().data();

    // Multiply input and const_ratio
    // Round 1
    multiply_uint64_hw64(input[0], const_ratio[0], &carry);

    multiply_uint64(input[0], const_ratio[1], tmp2);
    tmp3 = tmp2[1] + add_uint64(tmp2[0], carry, &tmp1);

    // Round 2
    multiply_uint64(input[1], const_ratio[0], tmp2);
    carry = tmp2[1] + add_uint64(tmp1, tmp2[0], &tmp1);

    // This is all we care about
    tmp1 = input[1] * const_ratio[1] + tmp3 + carry;

    // Barrett subtraction
    tmp3 = input[0] - tmp1 * modulus.value();

    // One more subtraction is enough
	return SEAL_COND_SELECT(tmp3 >= modulus.value(), tmp3 - modulus.value(), tmp3);
}


int main(int argc, char** argv)
{
    //uint64_t a = 12334560987659876422;
    //uint64_t b = 10202756454589098765;
    uint64_t a[2] = {232953229826203942, 825826491950185275};
    uint64_t b[2] = {102037917626262625, 916381620130101029};

    //__uint128_t result; //12334560987659876422 x 10202756454589098765 = 125846521731369693166050541028252818830
	//uint64_t result[2];
	uint64_t result1[2] = {0,0};//Index 0 -> low part
	//uint64_t result2[2] = {0,0};

    //add_uint64(a, b, &result);
	//multiply_uint64_riscv(a, b, result2);
    //multiply_uint64_generic(a, b, result1);

	multiply_accumulate_uint64<2>(a, b, result1);

	cout << "Result original low: " << to_string(result1[0]) << ", high: " << to_string(result1[1]) << endl;
	//cout << "Result riscv low   : " << to_string(result2[0]) << ", high: " << to_string(result2[1]) << endl;

}