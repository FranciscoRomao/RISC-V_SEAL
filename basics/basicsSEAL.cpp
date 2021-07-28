
#include "seal/seal.h"
#include <iostream>

using namespace std;
using namespace seal;

int main()
{
    EncryptionParameters parms(scheme_type::bfv);

    size_t poly_modulus_degree = 4096;
    parms.set_poly_modulus_degree(poly_modulus_degree);

    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));

    parms.set_plain_modulus(1024);

    SEALContext context(parms);

    KeyGenerator keygen(context);
    SecretKey secret_key = keygen.secret_key();
    PublicKey public_key;
    
    keygen.create_public_key(public_key);

    Encryptor encryptor(context, public_key);

    Evaluator evaluator(context);

    Decryptor decryptor(context, secret_key);

    int x = 6;
    Plaintext x_plain(to_string(x));

    Ciphertext x_encrypted;
    encryptor.encrypt(x_plain, x_encrypted);    

    Plaintext x_decrypted;
    decryptor.decrypt(x_encrypted, x_decrypted);

    Ciphertext x_sq_plus_one;
    evaluator.square(x_encrypted, x_sq_plus_one);
    Plaintext plain_one("1");
    evaluator.add_plain_inplace(x_sq_plus_one, plain_one);

    Plaintext decrypted_result;
    decryptor.decrypt(x_sq_plus_one, decrypted_result);
    cout << "Final result: 0x" << decrypted_result.to_string() << endl;
    return 0;
}
