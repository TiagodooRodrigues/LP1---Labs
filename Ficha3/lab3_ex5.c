#include <stdio.h>
int main () {
 int dia;
 puts("Digite o numero do mes");
 scanf("%d", &dia);
 switch (dia)
 {
 case 1:
 puts("Janeiro");
 break;
 case 2:
 puts("Fevereiro");
 break;
 case 3:
 puts("Marco");
 break;
 case 4:
 puts("Abril");
 case 5:
 puts("Maio");
 break;
 case 6: 
 puts("Junho");
 break;
 case 7:
 puts("Julho");
 break;
 case 8:
 puts("Agosto");
 break;
 case 9:
 puts("Setembro");
 case 10:
 puts("Outubro");
 case 11:
 puts("Novembro");
 break;
 case 12:
 puts("Dezembro");
 break;
 default:
 puts("Digite o mes correto");
  break;
 }
 return 0;
}