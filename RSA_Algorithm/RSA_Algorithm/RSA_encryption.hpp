//
//  RAS_encryption.hpp
//  Homework
//
//  Created by 金心羽 on 2023/3/8.
//

#ifndef RAS_encryption_hpp
#define RAS_encryption_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <algorithm>
#include <math.h>
using namespace std;
class RSA_Algorithm
{
public:
    long long PublicKey;    //公钥
    long long moduloN;
    long long PrivateKey;    //私钥
    long long q;             //组成钥匙的素数
    long long p;             //组成钥匙的素数
    long long theta;         //theta = (p - 1) * (q - 1)
public:
    RSA_Algorithm();
    RSA_Algorithm(long long E, long long N, long long D);
    long long CreateCipherText(long long Plaintext);
    long long DecryptionText(long long Ciphertext);
    bool IsPrime(long long number);
    long long Mutiple(long long number1, long long number2);
    long long Modulo(long long N, long long plaintext, long long publicKey);
    long long CreatePublicKey();
    long long CreatePrivateKey();
    long long CreateModuloNumber();
    long long gcd(long long number1, long long number2);
    long long pow(long long base, long long exponent);
    long long Mod(long long number, long long N);
};
#endif /* RAS_encryption_hpp */

