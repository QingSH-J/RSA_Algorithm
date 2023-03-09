//
//  RAS_encryption.cpp
//  Homework
//
//  Created by 金心羽 on 2023/3/8.
//

#include "RSA_encryption.hpp"

RSA_Algorithm::RSA_Algorithm()
{
}

long long RSA_Algorithm::Mod(long long number, long long N)
{
    long long remainder = number % N;
    return remainder;
}


long long RSA_Algorithm::CreateModuloNumber()
{
    long long* nums = new long long(100);
    long long returnnums = 0; //创建密钥模N
    long long count = 0;
    long long i = 0;
    for(i = 100; i < 155; i ++)
    {
        if(IsPrime(i))
        {
            nums[count] = i;
            count ++;
        }
    }
    srand((unsigned)time(NULL));
    long long position1 = rand() % count;
    long long position2 = rand() % count;
    moduloN = nums[position1] * nums[position2];
    p = nums[position1];
    q = nums[position2];
    returnnums = moduloN;
    return moduloN;
}

long long RSA_Algorithm::CreatePublicKey()
{
    long long* nums = new long long(1000);
    long long count = 0;
    theta = (p - 1) * (q - 1);
    for(PublicKey = 2; PublicKey < theta; PublicKey ++)
    {
        if(gcd(theta, PublicKey) == 1)
        {
            nums[count] = PublicKey;
            count ++;
        }
    }
    srand((unsigned)time(NULL));
    long long position = rand() % count;
    PublicKey = nums[position];
    return PublicKey;
}

long long RSA_Algorithm::CreatePrivateKey()
{
    long long* nums = new long long(100);
    long long count = 0;
    for(PrivateKey = 2; PrivateKey < theta; PrivateKey ++)
    {
        if(Mod(PrivateKey * PublicKey, theta) == 1)
        {
            nums[count] = PrivateKey;
            count ++;
        }
    }
    srand((unsigned)time(NULL));
    long long position = rand() % count;
    PrivateKey = nums[position];
    return PrivateKey;
}


long long RSA_Algorithm::gcd(long long number1, long long number2)
{
    while(number2 != 0)
    {
        long long r = number2;
        number2 = number1 % number2;
        number1 = r;
    }
    return number1;
}

RSA_Algorithm::RSA_Algorithm(long long E, long long N, long long D)
{
    PublicKey = E;
    moduloN = N;
    PrivateKey = D;
}

bool RSA_Algorithm::IsPrime(long long number)
{
    for(int i = 2; i <= number / 2; i ++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}

long long RSA_Algorithm::Mutiple(long long number1, long long number2)
{
    return number1 * number2;
}

long long RSA_Algorithm::Modulo(long long N, long long text, long long Key)
{
    if(Key == 0)
    {
        return 1;
    }
    else if(Key % 2 == 1)
    {
        return Modulo(N, text, Key - 1) * text % N;
    }
    else
    {
        long long temp = Modulo(N, text, Key / 2) % N;
        return temp * temp % N;
    }
}

long long RSA_Algorithm::CreateCipherText(long long Plaintext)
{
    scanf("%lld", &Plaintext);
    long long CipherText = 0;
    if(Plaintext > moduloN - 1)
    {
        return -1;
    }
    else
    {
        //long long operatornumber = pow(Plaintext, PublicKey);
        CipherText = Modulo(moduloN, Plaintext, PublicKey);
    }
    return CipherText;
}

long long RSA_Algorithm::DecryptionText(long long Ciphertext)
{
    long long Plaintext = 0;
    //long long operatornumber = pow(Ciphertext, PrivateKey);
    Plaintext = Modulo(moduloN, Ciphertext, PrivateKey);
    return Plaintext;
}

