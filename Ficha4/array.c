#include <stdio.h>
#define MAXSIZE 4
int main() {
  
  int vetor[MAXSIZE];
  int i;
  int encontrou = 0;
  int valorintroduzido;
  int posicaoencontrada;
  for(i=0; i < MAXSIZE; i++)
  {
    printf("Insira um numero inteiro: ");
    scanf("%d", &vetor[i]); 
  }
  printf("Digite um numero inteiro que pretende procurar: ");
  scanf("%d", &valorintroduzido);

  for (i = 0; i < MAXSIZE; i++)
  {
    if (valorintroduzido == vetor[i]){
      encontrou = 1;
      posicaoencontrada = i;
    }
  }
  if(encontrou) {
    printf("O numero %d existe na posição %d",valorintroduzido,posicaoencontrada);
  } else {
    printf("O numero %d nao existe na lista",valorintroduzido);
  }
  return 0;
}