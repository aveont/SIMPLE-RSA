// This is a simple and naive RSA implementation in C, comprised of both code and pseudocode. 

#include <stdio.h>
#include <math.h>

int isPrime(int number);
int isCoPrime(int a, int b);
int lcm(int a, int b);
int modularMultiInverse(int d, int temp);

int main(void) {
  int p;
  int q;
  int n;
  printf("Please select two prime numbers. \n");

  printf("Prime number 1: ");
  scanf("%d", &p);
  if (isPrime(p) == 1) {
    printf("%d is not a prime number!\n", p);
    return 0;
  } 
  // checking if p is a prime number, or else algorithm does not work

  printf("Prime number 1: ");
  scanf("%d", &q);
  if (isPrime(q) == 1) {
    printf("%d is not a prime number!\n", q);
    return 0;
  }
  // checks if q is a prime number, or else algorithm does not work
  // OPTIONALLY/RECCOMENDED: add a minimum size checker, so that you pick a large enough prime number
  // to enhance cryptographic strength of implementation

  if (p == q) {
    printf("p and q cannot be the same numbers.\n");
    return 0;
  }
  n = p * q;
  int temp = (p-1) * (q-1);
  int totient = lcm((p-1), (q-1));

  printf("Select a prime number d, which is co-prime to %d, and such that 2 < d < %d", temp, n);
  int d;
  scanf("%d", &d);
  if (isCoPrime(d, n) == 1) {
    printf("%d is not a co-prime to %d!\n", d, n);
    return 0;
  }
  if ((d < 2) || (d > n)) {
    printf("d must be greater than 2 or less than n!\n");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if ((n % i) == 0) {
      if (d == i) {
        printf("d should not be a divisor of n!\n");
        return 0;
      }
    }
  }

  int modInverse = modularMultiInverse(d, temp);
  if (modInverse = 0) {
    printf("Modular Multiplicative Inverse failed to calculate, please try with different parameters!\n");
    return 0;
  }

  printf("Your public key is : \n");
  printf("n  : %d\n d: %d", n, d);
  printf("Your private key is : \n");
  printf("n  : %d\n d: %d", n, modInverse);
  // DISCLAIMER: DO NOT DISCLOSE YOUR PRIVATE KEY
}

int isPrime(int number) {
  if (number == 1 || number == 0) {
    return 1;
  }
  // 1 and 0 are not prime numbers

  for (int i = 2; i < number; i++) {
    if ((number % i) == 0) {
      return 1;
    }
  }
  // checking if any number can perfectly divide our "prime" number. If it can, it is not a prime.

  return 0;
}

int isCoPrime(int a, int b) {
  if ((isPrime(a) == 0) && (isPrime(b) == 0)) {
    return 0;
  }
  int HCF = (a * b) / (lcm(a,b));
  if (HCF != 1) {
    return 1;
  } else {
    return 0;
  }
}

int lcm(int a, int b) {
  int flag = 0;
  while (flag == 0) {
    if (a == b) {
      flag = 1;
    }
    if (a > b) {
      b = b + b;
    }
    if (a < b) {
      a = a + a;
    }
  }
  return a;
}

int modularMultiInverse(int d, int temp) {
  int maxSize = 50000;
  // The maximum modular multiplicative inverse value will be 50000
  // as prime numbers p and q get larger, this can also increase. 
  // This cap is placed out of simplicy and convenience to ensure the program is not stuck
  // if something does go wrong.
  int e = 0;
  for (int i = 1; i < maxSize; i++) {
    if ((d * e) % temp == 1) {
      return e;
    }
  }
  return 0;
}