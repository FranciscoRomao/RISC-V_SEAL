
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
    Plaintext decrypted_result;
    
    Plaintext plain_one("3");
    Plaintext plain_arg("1");
    encryptor.encrypt(plain_one, x_encrypted);
    ExecutionTimer<std::chrono::microseconds> timer;

    for(int i=0; i<20; i=i+1)
    {
        //Plaintext plain_arg(uint64_to_hex_string(i));
        //encryptor.encrypt(plain_arg, enc_arg);
        cout << "Decrypting " << to_string(i*3) << ";";
        evaluator.add_plain(x_encrypted, plain_one, x_encrypted);
        timer.start();
        decryptor.decrypt(x_encrypted, decrypted_result);
        timer.stop();
        //cout << "Result: " << decrypted_result.to_string() << endl;
    }
}