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
#include <math.h>
#include <primesieve.h>

int main()
{
    uint64_t nth, random, p, q, d, e, n; 
    uint64_t d_x_e, phi_n;

    // Generate three random, large primes p and q
    for (int i = 0; i < 3; i++) {
        // Fetch a random number using arc4random
        nth = arc4random_uniform(UINT16_MAX);

        if (i == 0) {
            // Find the nth prime from 0
            p = primesieve_nth_prime(nth, 0);
            printf("p      = %llu\n", p);
        }
        else if (i == 1) {
            // Find the nth prime from 0
            q = primesieve_nth_prime(nth, 0);
            printf("q      = %llu\n", q);
        }
        else if (i == 2) {
            // Find the nth prime from 0
            e = primesieve_nth_prime(nth, 0);
            printf("e      = %llu\n", e);
        }
    }

    // Calculate and print the value of n
    n = p*q;
    printf("n      = %llu\n", n);

    // Calculate and print the value of phi(n)
    phi_n = (p-1)*(q-1);
    printf("phi(n) = %llu\n", phi_n);

    // Calculate and print the value of d

    printf("d      = %llu\n\n", d);
    
    return EXIT_SUCCESS;
}
