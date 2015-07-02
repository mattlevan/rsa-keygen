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
#include <stdbool.h>
#include <gmp.h> // GNU Multiple Precision Arithmetic Library
#include "miller-rabin.h" // Miller-Rabin primality test library

#define PREC 10
#define TOP 4000

int main() {
    mpz_t num; // declare very large int

    mpz_init(num); // initialize with a very large random number
    mpz_set_ui(num, 1); // what does this do?

    while (mpz_cmp_ui(num, TOP) < 0) {
        if (miller_rabin_test(num, PREC)) {
            gmp_printf("%Zd might be prime.\n", num);
        }

        mpz_add_ui(num, num, 1);
    }

    mpz_clear(num);

    return EXIT_SUCCESS;
}