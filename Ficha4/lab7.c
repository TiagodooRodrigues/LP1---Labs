#include <stdio.h>
#include <string.h>
char nomes[6][10];
float PR1[6];
float PR2[6];
int media[6];
char final[6][10];
int i;
int main() {
  for (i = 0; i < 4; i++) {
    scanf("%s %2f %2f",nomes[i],&PR1[i],&PR2[i]);
    media[i] = (PR1[i] + PR2[i]) / 2;
    if (media[i] > 5.0) {
    strcpy(final[i],"aprovado");
    }
    if (media[i] <= 5.0) {
    strcpy(final[i],"reprovado");
    }
  }
  for (i=0; i<6 ;i++) {
   printf("%s ",final[i]);
  }
  return 0;
}