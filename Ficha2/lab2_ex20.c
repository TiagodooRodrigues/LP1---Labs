#include <stdio.h>
int main () {
  printf("Qual é o numero de quilometros que pecorreu?\n");
  int percorridos,litros,conversao;
  scanf("%d",&percorridos);
  printf("Qual o numero de litros que consumiu?\n");
  scanf("%d",&litros);
  conversao = (100 * litros) / percorridos;
  printf("Consumo aos 100km = %d\n",conversao);
}