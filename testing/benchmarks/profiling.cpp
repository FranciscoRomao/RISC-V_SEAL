// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license.

//#include "examples.h"

//#include "seal/seal.h"
#include "iostream"

using namespace std;
using namespace seal;

unsigned long read_cycles(void)
{
    unsigned long cycles;
	printf("Working!!!"\n);
	asm volatile ("rdcycle %0" : "=r" (cycles));
	return cycles;
}

std::string uint64_to_hex_string(std::uint64_t value)
{
    return seal::util::uint_to_hex_string(&value, std::size_t(1));
}

void main()
{
    cout << "Running profiling program" << endl;

    EncryptionParameters parms(scheme_type::bfv);

    size_t poly_modulus_degree = 4096;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    cout << "Setting polymodulus: " << endl;

    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    cout << "Setting coeff_modulus: " << endl;

    parms.set_plain_modulus(1024);
    cout << "Setting coef_modulus: " << endl;

    SEALContext context(parms);
    cout << "Generating context class and verifyng parameters: " << endl;
    //cout << "Parameter validation: " << context.parameter_error_message() << endl;

    KeyGenerator keygen(context);
    cout << "Creating keygen class: " << endl;

    SecretKey secret_key = keygen.secret_key();
    cout << "Generating secret key: " << endl;
    
    PublicKey public_key;
    cout << "Creating public class: " << endl;

    keygen.create_public_key(public_key);
    cout << "Generating public key: " << endl;

    Encryptor encryptor(context, public_key);
    cout << "Generating encryptor instance: " << endl;

    Evaluator evaluator(context);
    cout << "Generating evaluator instance: " << endl;

    Decryptor decryptor(context, secret_key);
    cout << "Generating decryptor instance: " << endl;

    //4x^4 + 8x^3 + 8x^2 + 8x + 4 = 4(x + 1)^2 * (x^2 + 1)

    Ciphertext x_encrypted;
    Plaintext x_decrypted;
    RelinKeys relin_keys;
    Ciphertext x_sq_plus_one;
    Ciphertext x_plus_one_sq;
    Ciphertext encrypted_result;
    Plaintext decrypted_result;

    Plaintext plain_one("1");
    Plaintext plain_four("4");
    cout << "Generating plaintexts 1 and 4: " << endl;

    keygen.create_relin_keys(relin_keys);
    cout << "Generate relinearization keys: " << endl;

    // (x^2)    
    Ciphertext x_squared;
    evaluator.square(x_encrypted, x_squared);
    cout << "Compute (x^2): " << endl;

    evaluator.relinearize_inplace(x_squared, relin_keys);
    cout << "Relinearization: "

    evaluator.add_plain(x_squared, plain_one, x_sq_plus_one);
    cout << "Adding 1 [(x^2+1)]: " << endl;

    // (x + 1)^2
    Ciphertext x_plus_one;
    evaluator.add_plain(x_encrypted, plain_one, x_plus_one);
    cout << "Compute x_plus_one (x+1): " << endl;
    
    evaluator.square(x_plus_one, x_plus_one_sq);
    cout << "Squaring (x+1) [(x+1)^2]: " << endl;

    evaluator.relinearize_inplace(x_plus_one_sq, relin_keys);
    cout << "Relinarization: " << endl;


    // (x^2 + 1) * (x + 1)^2 * 4
    evaluator.multiply_plain_inplace(x_sq_plus_one, plain_four);
    cout << "Compute [4] * [(x^2+1)]: " << endl;

    evaluator.multiply(x_sq_plus_one, x_plus_one_sq, encrypted_result);
    cout << "Compute [(x^2 + 1)] * [(x + 1)^2 * 4]: " << endl;
    
    evaluator.relinearize_inplace(encrypted_result, relin_keys);
    cout << "Relinearization: " << endl;

    decryptor.decrypt(encrypted_result, decrypted_result);
    cout << "Decryption: " << endl;
    cout << "0x" << decrypted_result.to_string() << endl;

    /*
    For x=6, 4(x^2+1)(x+1)^2 = 7252. Since the plaintext modulus is set to 1024,
    this result is computed in integers modulo 1024. Therefore the expected output
    should be 7252 % 1024 == 84, or 0x54 in hexadecimal.
    */

    return 0;
}
