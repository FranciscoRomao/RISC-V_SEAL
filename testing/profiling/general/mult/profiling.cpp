
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
#include "../../timing.h"
#include "../../utils.h"

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

    Ciphertext x_encrypted;
    Ciphertext enc_arg;
    Ciphertext enc_result;
    Plaintext decrypted_result;
    RelinKeys relin_keys;
    
    Plaintext plain_common("2");
    encryptor.encrypt(plain_common, x_encrypted);
    ExecutionTimer<std::chrono::microseconds> timer;
    Plaintext plain_mult("3");

    encryptor.encrypt(plain_common, enc_result);
    keygen.create_relin_keys(relin_keys);
    
    for(int i=1; i<50; i++)
    {
        //Plaintext plain_arg(uint64_to_hex_string(i));
        //encryptor.encrypt(plain_arg, enc_arg);
        cout << "Multiplying by 3";
        timer.start();
        //evaluator.relinearize_inplace(enc_result, relin_keys);
        evaluator.multiply_plain(enc_result, plain_mult, enc_result);
        timer.stop();
        decryptor.decrypt(enc_result, decrypted_result);
        //cout << "Result: " << decrypted_result.to_string() << endl;
    }
}