// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license.

#include "seal/seal.h"
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
#include "../timing.h"
#include "../utils.h"

using namespace std;
using namespace seal;
using namespace std::chrono;


int main()
{
    cout << "Running profiling program" << endl;
    cout << "[Note]-All timing values are in microseconds" << endl;
    print_sep();

    cout << "Initializing parms object: " << endl;
    ExecutionTimer<std::chrono::microseconds> timer;
    EncryptionParameters parms(scheme_type::bfv);
    timer.stop();
    print_sep();
    size_t poly_modulus_degree = 4096;
    
    cout << "Setting poly_modulus_degree: " << endl;
    timer.start();
    parms.set_poly_modulus_degree(poly_modulus_degree);
    timer.stop();
    print_sep();

    cout << "Recommending coeff_modulus: " << endl;
    timer.start();
    auto recommended = CoeffModulus::BFVDefault(poly_modulus_degree);
    timer.stop();
    print_sep();

    cout << "Setting recommended coeff_modulus: " << endl;
    timer.start();
    parms.set_coeff_modulus(recommended);
    timer.stop();
    print_sep();

    cout << "Setting plain_modulus: " << endl;
    timer.start();
    parms.set_plain_modulus(1024);
    timer.stop();
    print_sep();

    cout << "Initializing context class and verifiyng parameters: " << endl;
    timer.start();
    SEALContext context(parms);
    //cout << "Parameter validation: " << context.parameter_error_message() << endl;
    timer.stop();
    print_sep();

    cout << "Initializing keygen class: " << endl;
    timer.start();
    KeyGenerator keygen(context);
    timer.stop();
    print_sep();

    cout << "Generating secret key: " << endl;
    timer.start();
    SecretKey secret_key = keygen.secret_key();
    timer.stop();
    print_sep();
    
    cout << "Generating public key: " << endl;
    timer.start();
    PublicKey public_key;
    keygen.create_public_key(public_key);
    timer.stop();
    print_sep();

    cout << "Generating encryptor instance: " << endl;
    timer.start();
    Encryptor encryptor(context, public_key);
    timer.stop();
    print_sep();

    cout << "Generating evaluator instance: " << endl;
    timer.start();
    Evaluator evaluator(context);
    timer.stop();
    print_sep();

    cout << "Generating decryptor instance: " << endl;
    timer.start();
    Decryptor decryptor(context, secret_key);
    timer.stop();
    print_sep();

    //4x^4 + 8x^3 + 8x^2 + 8x + 4 = 4(x + 1)^2 * (x^2 + 1)

    uint64_t x = 6;

    Ciphertext x_encrypted;
    RelinKeys relin_keys;
    Ciphertext x_sq_plus_one;
    Ciphertext x_plus_one_sq;
    Ciphertext encrypted_result;
    Plaintext decrypted_result;

    cout << "Generating plaintext 6: " << endl;
    timer.start();
    Plaintext x_plain(uint64_to_hex_string(x));
    timer.stop();
    print_sep();

    cout << "Encrypting plain 6: " << endl;
    timer.start();
    encryptor.encrypt(x_plain, x_encrypted);
    timer.stop();
    print_sep();

    cout << "Generating plaintext 1: " << endl;
    timer.start();
    Plaintext plain_one("1");
    timer.stop();
    print_sep();

    cout << "Generating plaintext 4: " << endl;
    timer.start();
    Plaintext plain_four("4");
    timer.stop();
    print_sep();

    cout << "Generating relinearization keys: " << endl;
    timer.start();
    keygen.create_relin_keys(relin_keys);
    timer.stop();
    print_sep();

    // (x^2)
    Ciphertext x_squared;
    cout << "Compute (x^2): " << endl;
    timer.start();
    evaluator.square(x_encrypted, x_squared);
    timer.stop();
    print_sep();

    cout << "Relinearization: " << endl;
    timer.start();
    evaluator.relinearize_inplace(x_squared, relin_keys);
    timer.stop();
    print_sep();

    cout << "Adding 1 [(x^2+1)]: " << endl;
    timer.start();
    evaluator.add_plain(x_squared, plain_one, x_sq_plus_one);
    timer.stop();
    print_sep();

    // (x + 1)^2
    Ciphertext x_plus_one;
    cout << "Adding 1 [x+1]: " << endl;
    timer.start();
    evaluator.add_plain(x_encrypted, plain_one, x_plus_one);
    timer.stop();
    print_sep();

    cout << "Squaring (x+1) [(x+1)^2]: " << endl;
    timer.start();
    evaluator.square(x_plus_one, x_plus_one_sq);
    timer.stop();
    print_sep();

    cout << "Relinarization: " << endl;
    timer.start();
    evaluator.relinearize_inplace(x_plus_one_sq, relin_keys);
    timer.stop();
    print_sep();

    // (x^2 + 1) * (x + 1)^2 * 4
    cout << "Multiplying by 4 * [4*(x^2+1)]: " << endl;
    timer.start();
    evaluator.multiply_plain_inplace(x_sq_plus_one, plain_four);
    timer.stop();
    print_sep();

    cout << "Multiplying (x^2 + 1)  by ((x + 1)^2 * 4): " << endl;
    timer.start();
    evaluator.multiply(x_sq_plus_one, x_plus_one_sq, encrypted_result);
    timer.stop();
    print_sep();

    cout << "Relinearization: " << endl;
    timer.start();
    evaluator.relinearize_inplace(encrypted_result, relin_keys);
    timer.stop();
    print_sep();

    cout << "Decryption: " << endl;
    timer.start();
    decryptor.decrypt(encrypted_result, decrypted_result);
    timer.stop();
    cout << "0x" << decrypted_result.to_string() << endl;
    print_sep();

    /*
    For x=6, 4(x^2+1)(x+1)^2 = 7252. Since the plaintext modulus is set to 1024,
    this result is computed in integers modulo 1024. Therefore the expected output
    should be 7252 % 1024 == 84, or 0x54 in hexadecimal.
    */

    return 0;
}
