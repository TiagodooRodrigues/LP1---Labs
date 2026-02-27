#include <stdio.h>
#include <string.h>
int main () {
 int codigo, quantidade;
 float preco = 0;
 char reposta[10];
 do {
 printf("Cachorro quente	100	1,20 \nCrepe simples	101	1,30\n Crepe com chocolate	102	1,50\nHambúrguer	103	1,20\nCheeseburguer	104	1,30\nRefrigerante	105	1,00\n");
 puts("Digite o codigo e sua quantidade");
  scanf ("%d %d",&codigo,&quantidade);
  switch (codigo)
  {
  case 100:
      preco += 1.20 * quantidade;
      break;
  case 101:
      preco += 1.30 * quantidade;
      break;
  case 102:
       preco += 1.50 * quantidade;
       break;
  case 103:
       preco += 1.20 * quantidade;
       break;
  case 104:
       preco += 1.30 * quantidade;
       break;
  case 105:
       preco += 1.00 * quantidade;
       break;
  default:
       puts("Digite o codigo correto que deseja");
       break;
       return 0;
  }
  printf("Deseja mais snacks?\n");
  scanf("%s",reposta);
 } while (strcmp(reposta,"Sim") == 0);
 printf("Tem de pagar %0.2f euros\n",preco);
 return 0;
}