#include <iostream>
#include "RSA_encryption.hpp"
using namespace std;

int main()
{
    RSA_Algorithm ras;
    long long newnums = ras.CreateModuloNumber();
    long long publickey = ras.CreatePublicKey();
    long long privatekey = ras.CreatePrivateKey();
    cout << newnums << " " << ras.p << " " << ras.q << " " << ras.theta << " " << ras.PublicKey << " " << ras.PrivateKey << endl;
    long long plaintext = 0;
    long long CipherText = ras.CreateCipherText(plaintext);
    cout << CipherText << endl;
    long long PlainTextGet = ras.DecryptionText(CipherText);
    cout << PlainTextGet << endl;
}
