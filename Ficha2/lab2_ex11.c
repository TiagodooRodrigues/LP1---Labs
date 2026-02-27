#include <stdio.h>
int main (void) {
  int segundos_entrada;
    printf("Digite o numero de segundos: \n");
    scanf("%d",&segundos_entrada);
    int segundosgravados = segundos_entrada;
     int dia = segundos_entrada / (24 * 3600); 
     segundos_entrada = segundos_entrada % (24 * 3600); 
    int horas = segundos_entrada / 3600; 
    segundos_entrada %= 3600; 
    int minutos = segundos_entrada / 60 ; 
    segundos_entrada %= 60; 
    int segundos = segundos_entrada;
    printf("%0.1d segundos corresponde a %0.1d dias , %0.1d horas , %0.1d minutos ,%0.1d segundos",segundosgravados,dia,horas,minutos,segundos);
}