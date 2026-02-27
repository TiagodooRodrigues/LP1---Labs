# include <stdio.h>
 int main () {
  int idade , preco;
  char reposta;
  do {
  puts("Qual é a sua idade?");
  scanf("%d",&idade);
  if (idade < 16) {
    preco += 10;
  }
  if (idade >= 16 && idade < 65) {
    preco += 17;
  }
  if (idade >= 65) {
    preco += 10;
  }
  puts("Quer comprar mais um bilhete?");
  scanf(" %c",&reposta);
  } while (reposta == 's');
  printf("Total em bilhetes: %d\n",preco);
  return 0;
}