# rsa-keygen
## Generates numbers required for RSA encryption and decryption keys.  

Requires primesieve library. Compile with -lprimesieve option.  

**FOR EDUCATIONAL PURPOSES ONLY**
RSA requires these numbers: 

p, q, and e such that...  
p is a large, random prime number  
q is a different, large, random prime number  
e is a different, large (but small in this program)  
random prime number that is relatively prime with phi(n)
n such that...
n is simply (p*q).

d such that...
d * e = 1 mod ((p-1)(q-1)), in other words d* e = 1 mod (phi(n))
where phi() is Euler's totient function.
The public key pair is defined as <e,n>.
The private key pair is defined as <d,n>.
