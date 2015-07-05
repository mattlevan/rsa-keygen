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

int int_pow(int base, int exp);
uint64_t gcd(uint64_t a, uint64_t b);

int main()
{
    uint64_t nth, random, p, q, d, e, n, k; 
    uint64_t d_x_e, phi_n;

    // Generate two random, large primes p and q
    for (int i = 0; i < 2; i++) {
        // Fetch a random number using arc4random
        nth = arc4random_uniform(10);

        if (i == 0) {
            // Find the nth prime from 0
            p = primesieve_nth_prime(nth, 0);
            printf("p       = %llu\n", p);
        }
        else {
            // Find the nth prime from 0
            q = primesieve_nth_prime(nth, 0);
            printf("q       = %llu\n", q);
        }
    }

    // Calculate and print the value of n
    n = p*q;
    printf("n       = %llu\n", n);

    // Calculate and print the value of phi(n)
    phi_n = (p-1)*(q-1);
    printf("phi(n)  = %llu\n", phi_n);

    // Calculate and print the value of k
    k = arc4random_uniform(9) + 2;
    printf("k       = %llu\n", k);

    // Generate small number e that is relatively prime with phi(n)
    for (e = (uint64_t)arc4random_uniform(19); e > 1; e++) {
        if (gcd(e, phi_n) == 1) {
            printf("e       = %llu\n", e);
            break;
        }
    }

    // Calculate and print the value of d
    for (d = 0; d < n; d++) {
        if (((d*e) % n) == 1) {
            printf("d       = %llu\n", d);
            break;
        }
    }

    // Calculate and print (d*e) % n
    printf("(d*e)%cn = %llu\n\n", '%', (d*e)%n);

    // Print public and private key pairs
    printf("Pub key pair <e,n>: <%llu,%llu>\n", e, n);
    printf("Prv key pair <d,n>: <%llu,%llu>\n\n", d, n);

    // Get message
    uint64_t m = 5;

    // Encrypt message
    uint64_t c = uint64_t_pow(m,e);
    c %= n;
    printf("Encrypted message: %llu\n", c);

    // Decrypt message
    uint64_t message = uint64_t_pow(c,d);
    message %= n;
    printf("Decrypted message: %llu\n", message);

    return EXIT_SUCCESS;
}

uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

uint64_t uint64_t_pow(uint64_t base, uint64_t exp) {
    if (exp == 0) {
        return 1;
    }
    else if (exp % 2) {
        return base * uint64_t_pow(base, exp - 1);
    }
    else {
        uint64_t temp = uint64_t_pow(base, exp / 2);
        return temp * temp;
    }
}