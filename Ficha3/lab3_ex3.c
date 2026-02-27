#include <stdio.h>
int main() {
 int salario,bonus;
 char plano;
 puts("Digite o seu plano da empresa: ");
 scanf(" %c", &plano);
 puts("Digite o seu salario atual: ");
 scanf("%d", &salario);
 switch (plano)
 {
 case 'A' : bonus = salario + (salario * 0.10);
          break;
 case 'B': bonus = salario + (salario * 0.15);
          break;
 case 'C': bonus = salario + (salario * 0.20);
         break;
 default: puts("Digite um plano da empresa correto");
         break;
 }
 printf("O salario final sera de : %d\n",bonus);
 return 0;
}