#include <stdio.h>
int vetores[8];
int i,j,contador,soma30,soma;
int main() {
  for(i =0 ; i < 8;i++){
    scanf("%d",&j);
    vetores[i] = j;
    if (j > 30) {
      contador++;
      soma30 += j;
    }
    soma+=j;
  }
  for (i = 0; i < 8;i++) {
    printf("%d",vetores[i]);
  }
  printf("\n");
  printf("A soma maiores de 30 : %d, e a soma de todos:%d",soma30,soma);
  return 0;
}