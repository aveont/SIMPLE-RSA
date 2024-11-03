// A simple program which encrypts a message, given a public key and a message

#include <stdio.h>
#include <math.h>

int main(void) {
  int message = 0;
  printf("Insert message to encrypt: \n");
  scanf("%d", message);

  int d;
  int n;
  printf("Please insert your public key.\n");
  printf("n: ");
  scanf("%d", &n);
  printf("\nd: ");
  scanf("%d", &d);

  int decrypted = (pow(message, d) % n);
  printf("\nThe encrypted message is: %d\n", decrypted);
  return 0;
}