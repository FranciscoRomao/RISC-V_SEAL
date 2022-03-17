#include <algorithm>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <mutex>
#include <numeric>
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

unsigned long read_cycles(void)
{
    unsigned long cycles;
	asm volatile ("rdcycle %0" : "=r" (cycles));
	return cycles;
}

std::string uint64_to_hex_string(std::uint64_t value)
{
    return seal::util::uint_to_hex_string(&value, std::size_t(1));
}

void print_sep()
{
    cout << "------------------------------" << endl;
}