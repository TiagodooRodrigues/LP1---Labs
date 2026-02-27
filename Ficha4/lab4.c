#include <stdio.h>
int vetores[10];
int pares[10];
int impares[10];
int i,j,k;
int main() {
  for (i = 0, k = 0; i < 30;i++,k++){
    scanf("%d",&vetores[i]);
    if (vetores[i] % 2 == 0) {
      pares[k] = vetores[i];
    } else {
      impares[k] = vetores[i];
    }
    if (i == 4|| i==9 || i == 14 || i ==19|| i== 24 || i == 29){
      printf("Pares: ");
      for (j=0; j < 5 ; j++) {
        if (pares[j] != 0) {
          printf("%d ",pares[j]);
        }
      }
      printf("\n");
      printf("Impares: ");
      for (j=0; j < 5; j++) {
        if (impares[j] != 0) {
           printf("%d ",impares[j]);
        }
      }
      printf("\n");
      for (j = 0 ; j < 5 ; j++) {
        pares[j] = 0;
        impares[j] = 0;
      }
      }
      if ( k == 4 ) {
        k = -1;
    }
  }
  return 0;
}