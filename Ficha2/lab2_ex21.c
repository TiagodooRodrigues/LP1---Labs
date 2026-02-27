#include <stdio.h>
int teste() {
  int hora,minuto,segundo,tempo;
  printf("Digite a hora: \n");
  scanf("%d",&hora);
  printf("Digite o minuto: \n");
  scanf("%d",&minuto);
  printf("Digite o segundo: \n");
  scanf("%d",&segundo);
  tempo = hora * 3600 + minuto * 60 + segundo;
  printf("%d\n",tempo);
  return 0;
}
int main (void) {
  teste();
}