#include <stdio.h>
#include <ctype.h>

int main() {
  char letra;
  int contador, deslocamento, caracteres;
  int tamanho, tamanho_novo;
  int i, j, k, m;
  int x, y;
  char texto[166];
  char lista[36] ={'a','b','c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
      'n', 'o', 'p', 'q', 'r', 's', 't','u', 'v', 'w', 'x', 'y', 'z','0','1','2','3','4','5','6','7','8','9'};
  char textomedio[166] = ""; /* Texto Secundario */
  int caracteresconta; /* variavel que guarda numero negativo para positivo */
  do {
    scanf("%c", & letra);
    if (letra != 'h' && letra != 'q') {
      /* se nao for h e q recebe informacao */
      scanf("%d %[^\n]s", & caracteres, texto);
    }
    if (letra == 'h') {
      puts(texto);
      continue; /* retorna inicio do dowhile */
    }
    if (letra == 'q') {
      puts("Exiting->");
      return 0; /* termina o programa */
    }
    if (letra != 'r' && letra != 's') {
      puts("Error: Unknown option"); /* ja nao vai entrar nos proximos if */
    }
    for (tamanho = 0; texto[tamanho] != '\0'; tamanho++); /* tamanho do array */
    if (letra == 'r') {
      for (i = 0; i < tamanho; i++) {
        /* stringcopy */
        textomedio[i] = texto[i];
      }
      if (caracteres == 0) {
        /* nao faz nada por ser 0 */
        puts(texto);
      }
      if (caracteres < 0) {
        caracteresconta = caracteres * -1;
        while (caracteresconta >= tamanho) {
          /* caso escolho o shift maior que o tamanho */
          caracteresconta = caracteresconta - tamanho;
        }
        for (contador = 0; contador < caracteresconta; contador++) {
          for (deslocamento = 0; deslocamento < tamanho; deslocamento++) {
            texto[deslocamento] = texto[deslocamento + 1];
          }
        }
        for (tamanho_novo = 0; texto[tamanho_novo] != '\0'; tamanho_novo++); /* tamanho novo do array */
        for (contador = tamanho_novo, deslocamento = 0; contador < tamanho; contador++, deslocamento++) {
          texto[contador] = textomedio[deslocamento];
        }
        puts(texto);
      }
      if (caracteres > 0) {
        while (caracteres >= tamanho) {
          /* caso escolho o shift maior que o tamanho */
          caracteres = caracteres - tamanho;
        }
        for (contador = 0; contador < caracteres; contador++) {
          for (deslocamento = tamanho - 1; deslocamento > 0; deslocamento--)
            texto[deslocamento] = texto[deslocamento - 1];
        }
        for (contador = caracteres - 1, deslocamento = tamanho - 1; contador >= 0; contador--, deslocamento--) {
          texto[contador] = textomedio[deslocamento];
        }
        puts(texto);
      }
    }
    if (letra == 's') {
      if (caracteres > 35 || caracteres < -35) {
        puts("Error: out of bound"); /* limite de intervalos */
        continue;
      } else {
        if (caracteres > 0) {
          for (i = 0; i < tamanho; i++) {
            y = 0; /* comeca com zero e mantem caso nao pertenca ao array */
            for (x = 0; x < 36; x++) {
              if (tolower(texto[i]) == lista[x]) {
                /* caso o array tenha esse caracter */
                y = 1;
              }
            }
            if (y == 1) {
              /* comeca fazer a cifragem */
              for (k = 0; lista[k] != tolower(texto[i]); k++); /* descobre a posicao do caracter no array */
              for (j = k, m = 0; m != caracteres; j++, m++) {
                /* faz o shift */
                if (j == 35) {
                  j = -1;
                }
              }
              texto[i] = toupper(lista[j]); /* troca a letra do texto para caracter cifrado */
            }
          }
        }
        if (caracteres < 0) {
          caracteresconta = caracteres * -1;
          for (i = 0; i < tamanho; i++) {
            y = 0 /* comeca com zero e mantem caso nao pertenca ao array */ ;
            for (x = 0; x < 36; x++) {
              if (tolower(texto[i]) == lista[x]) {
                /* caso o array tenha esse caracter */
                y = 1;
              }
            }
            if (y == 1) {
              for (k = 0; lista[k] != tolower(texto[i]); k++); /* descobre a posicao do caracter no array */
              for (j = k, m = 0; m != caracteresconta; j--, m++) {
                /* faz o shift */
                if (j == 0) {
                  j = 36;
                }
              }
              texto[i] = toupper(lista[j]); /* troca a letra do texto para caracter cifrado */
            }
          }
        }
        if (caracteres == 0) {
          for (i = 0; i < tamanho; i++) {
            texto[i] = toupper(texto[i]); /* apenas altera tudo para maiscula */
          }
        }
      }
      puts(texto);
      for (i = 0; i < tamanho; i++) {
        /* stringcopy */
        textomedio[i] = texto[i];
      }
    }
  } while (letra != 'q');
  return 0;
}