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


#define RAND_MAX 18446744026464911360

int main()
{
    for (int i = 0; i < 2; i++) {
        // Ensure random is less than RAND_MAX
        uint64_t random = arc4random() % ((unsigned)RAND_MAX +1);
        // Random to specify nth prime in primesieve_nth_prime() call
        uint64_t nth = arc4random();

        if (i == 0) {
            // Declare and assign p (first random, large prime)
            uint64_t p = primesieve_nth_prime(nth, random);
        }
        else {
            // Declare and assign q (second random, large prime)
            uint64_t q = primesieve_nth_prime(nth, random);
        }
    }

  uint64_t n = 1000;
  if (argv[1])
    n = atol(argv[1]);
  uint64_t prime = primesieve_nth_prime(n, 0);
  printf("%lluth prime = %llu\n", n, prime);

  return EXIT_SUCCESS;
}