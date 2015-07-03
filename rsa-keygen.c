/* Matt Levan
 * CSC 500 -- Research Methods
 * Dr. Mohsen Beheshti
 * Summer Session I & II 2015
 * California State University, Dominguez Hills
 *
 * ***FOR EDUCATIONAL PURPOSES ONLY***
 *
 * rsa-keygen.c, a program to illustrate key generation for use in 
 * RSA encryption protocol. 
 *
 *
 * RSA requires these numbers: 
 * 
 * p, q, and e such that...
 * p is a large, random prime number
 * q is a different, large, random prime number
 * e is a different, large, random prime number
 *
 * n such that...
 * n is simply (p*q).
 * 
 * d such that...
 * d * e = 1 mod ((p-1)(q-1)), in other words d* e = 1 mod (phi(n))
 * where phi() is Euler's totient function.
 *
 * The public key pair is defined as <e,n>.
 * The private key pair is defined as <d,n>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include <gmp.h>
#include <primesieve.h>

void mpz_set_ull(mpz_t rop, unsigned long long op);

int main()
{
    uint64_t max, random, nth, p, q; 
    mpz_t mpz_n, mpz_p, mpz_q; // GMP variables

    max = primesieve_get_max_stop();

    for (int i = 0; i < 2; i++) {
        nth = arc4random_uniform(max);
        printf("Random: %llu\n", nth);
        if (i == 0) {
            p = primesieve_nth_prime(nth, max);
            printf("1st prime p = %llu\n", p);
        }
        else {
            q = primesieve_nth_prime(nth, max);
            printf("2nd prime q = %llu\n", q);
        }
    }

    // mpz_set_ui(mpz_p, p);
    // mpz_set_ui(mpz_q, q);

    // mpz_mul(mpz_n, mpz_p, mpz_q);


    // gmp_printf("n = p*q = %Z\n", mpz_n);

    return EXIT_SUCCESS;
}

void mpz_set_ull(mpz_t rop, unsigned long long op)
{
    mpz_import(rop, 1, 1, sizeof(op), 0, 0, &op);
}

