#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
int main() {
char letra;
int contador,deslocamento,caracteres;
bool ciclo = false;
char texto[166];
char textomedio[166];
unsigned int caracteresconta;
do {
 scanf(" %c %d %[^\n]s",&letra,&caracteres,texto);
 if(letra != 'r' && letra != 'h' && letra != 'q' && letra != 's'){
  puts("Error: Unknown option");
 }
 if (caracteres > 35 || caracteres < -35){
  puts("Error: out of bound");
 }
 if (letra == 'r') {
   strcpy(textomedio,texto);
   if (caracteres < 0) {
     caracteresconta = caracteres * -1;
     for (contador = 0 ; contador < caracteresconta ; contador++) {
       for (deslocamento = 0; deslocamento < strlen(texto); deslocamento++) {
         texto[deslocamento] = texto[deslocamento+1];
         }
       }
       for (contador = strlen(texto),deslocamento = 0; contador < strlen(textomedio);contador++,deslocamento++) {
         texto[contador] = textomedio[deslocamento];
       }
       puts(texto);
       strcpy(textomedio,texto);
   }
   if (caracteres > 0) {
     for (contador = 0 ; contador < caracteres; contador++) {
       for (deslocamento = strlen(texto)- 1; deslocamento > 0 ;deslocamento--)
       texto[deslocamento] = texto[deslocamento -1];
     }
     for(contador = caracteres-1,deslocamento=strlen(textomedio)-1; contador >= 0;contador--,deslocamento--){
       texto[contador] = textomedio[deslocamento];
     }
     puts(texto);
     strcpy(textomedio,texto);
  }
  if (caracteres == 0 ) {
   puts(texto);
 }
 }
 if (letra == 's') {
   for (int i =0 ; i < strlen(texto); i++) {
     if (texto[i] != ' ' && texto[i] != '.') {
      texto[i] = toupper(texto[i]) + caracteres;
      if (texto[i] > 'Z') {
        switch (texto[i])
        {
        case 91: texto[i] = '0';
        break;
        case 92: texto[i] = '1';
        break;
        case 93: texto[i] = '2';
        break;
        case 94: texto[i] = '3';
        break;
        case 95: texto[i] = '4';
        break;
        case 96: texto[i] = '5';
        break;
        case 97: texto[i] = '6';
        break;
        case 98: texto[i] = '7';
        break;
        case 99: texto[i] = '8';
        break;
        case 100: texto[i] = '9';
        break;
        }
      }
     }
  }
   puts(texto);
   strcpy(textomedio,texto);
 }
 if (letra == 'h') {
   puts(textomedio);
  }
 if (letra == 'q') {
  puts("Exiting->");
  ciclo = true;
 }
} while (ciclo == false);
return 0;
}