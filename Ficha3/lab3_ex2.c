# include <stdio.h>
#include <stdbool.h>
 int main () {
   bool ciclo = false;
   char resposta;
   do {
   puts("Por favor insira uma das seguintes opções: ");
   puts("p) piano		v)violino ");
   puts("t) trompete  	c) contrabaixo");
   puts("s) sair");
   scanf(" %c", &resposta);
    switch(resposta) {
      case 'p': puts("Pianista toca piano");
              break;
      case 'v': puts("Violinista toca violino");
              break;
      case 't': puts("Trompete toca mal");
              break;
      case 'c': puts("Contrabaixista toca contrabaixo");
              break;
      case 's': puts ("Saiu do Menu");
              ciclo = true;
              break;
      default: puts ("Escolha uma opcao valida");
                    }
   } while (ciclo == false);
   return 0;
}