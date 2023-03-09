# RSA_Algorithm
RSA_Algorithm encrypt password
RSA(Rivest-Shamir-Adleman) is a public-key cryptosystem that is widely used for security transmission.
RSA key generation
Algorithm1 (pseudo code)
input: Security parameter l
1.Randomly select two primes p and q of the same bitlength l/2.
2.Compute n = p * q, and θ = (p - 1) * (q - 1).
3.Select an arbitrary integer e with 1 < e < θ and gcd(e, θ) = 1
4.Compute the integer d satisfying 1 < d < θ and ed ≡ 1 (modθ).
5.return (n, e, d)

RSA encryption and signature schemes use the fact that
m^(ed) ≡ m (mod n)   //Please learn the modulo theory

The encryption and decryption procedures for the (basic) RSA public-key encryption scheme are presented as Algorithms2 and 3.
Decryption works because c^d ≡ (m^e)^d ≡ m (mod n)
The security relies on the difficulty of computing the plaintext m from the ciphertext c = m^e mod n and the public parameters n and e. This is the problem of finding eth roots modulo n and is assumed(but has not been proven) to be as difficult as the integer factorization problem.

Algorithm2 (pseudo code) RSA encryption
input: plaintext m in [0, n - 1].
1.Ciphertext c
2.Compute c = m^e mod n
3.return c

Algorithm3(pseudo code)RSA decryption
input: RSA public key(n, e) RSA private key d, ciphertext c
1.Plaintext m
2.Compute m = c^d mod n
3.return m


[1] Darrel Hankerson Alfred Menezes Scott Vanstone Guide to EllipticCurve Cryptography
