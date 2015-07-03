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
#include <stdint.h>
#include <stdbool.h>
#include <primesieve.h>


#define MAX 18446744026464911360

int main()
{
    uint64_t random, nth, p, q, n;

    for (int i = 0; i < 2; i++) {
        nth = arc4random_uniform(10);
        if (i == 0) {
            p = primesieve_nth_prime(nth, MAX);
        }
        else {
            q = primesieve_nth_prime(nth, MAX);
        }
    }

    n = p*q;

    printf("First prime p = %llu\n", p);
    printf("Second prime q = %llu\n", q);
    printf("n = p*q = %llu\n", n);

    return EXIT_SUCCESS;
}