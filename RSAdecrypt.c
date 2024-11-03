// A simple program which decrypts a RSA message, given a message and a private key.

#include <stdio.h>
#include <math.h>

int main(void) {
  int message = 0;
  printf("Insert message to decrypt: \n");
  scanf("%d", message);

  int e;
  int n;
  printf("Please insert your private key.\n");
  printf("n: ");
  scanf("%d", &n);
  printf("\ne: ");
  scanf("%d", &e);

  int decrypted = (pow(message, e) % n);
  printf("\nThe decrypted message is: %d\n", decrypted);
  return 0;
}