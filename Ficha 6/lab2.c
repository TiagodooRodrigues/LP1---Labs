#include <stdio.h>
  int main() {
    int x = 5;
    float y = 5.0;
    int *ptrx = &x; // o conteudo de prtx vai ser o endereco de x
    float *ptry = &y; // o conteudo de prty vai ser o endereco de y
    printf("O valor de ptrx: %ld\n",ptrx);
    printf("O valor de ptrx: %ld\n",ptry);
 }
