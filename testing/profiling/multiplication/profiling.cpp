
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

    EncryptionParameters parms(scheme_type::bfv);
    size_t poly_modulus_degree = 4096;
    
    parms.set_poly_modulus_degree(poly_modulus_degree);

    auto recommended = CoeffModulus::BFVDefault(poly_modulus_degree);

    parms.set_coeff_modulus(recommended);

    parms.set_plain_modulus(1024);

    SEALContext context(parms);

    KeyGenerator keygen(context);
    SecretKey secret_key = keygen.secret_key();
    PublicKey public_key;

    keygen.create_public_key(public_key);
    
    Encryptor encryptor(context, public_key);
    Evaluator evaluator(context);
    Decryptor decryptor(context, secret_key);

    Ciphertext cipher_arg1;
    Ciphertext cipher_arg2;
    Plaintext plain_result;
    Ciphertext cipher_result;
    Ciphertext cipher_aux;
    RelinKeys relin_keys;

    //ExecutionTimer<std::chrono::microseconds> timer;

    keygen.create_relin_keys(relin_keys);
    
    //Plaintext plain_arg(uint64_to_hex_string(i));
    //encryptor.encrypt(plain_arg, enc_arg);
    //cout << "Multiplying enc(200) * enc(35)" << endl;
    //evaluator.relinearize_inplace(enc_result, relin_keys);
    //timer.start();
    
    Plaintext plain_arg1(to_string(22));
    Plaintext plain_arg2(to_string(33));
    encryptor.encrypt(plain_arg1, cipher_arg1);
    encryptor.encrypt(plain_arg2, cipher_arg2);
    
    //Plaintext plain_arg(uint64_to_hex_string(i));
    //encryptor.encrypt(plain_arg, enc_arg);
    //evaluator.relinearize_inplace(enc_result, relin_keys);
    evaluator.multiply(cipher_arg1, cipher_arg2, cipher_result);
    //cout << "Result: " << decrypted_result.to_string() << endl;
    
    for(int i=1; i<20; i++)
    {
        evaluator.relinearize(cipher_result, relin_keys, cipher_aux);
    }
    
    //timer.stop();
    //cout << "Result: " << plain_result.to_string() << endl;
}