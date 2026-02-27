#include <stdio.h>
#include <string.h>
#define MAX 25
void zerar(int a , int b , char matriz[MAX][MAX]) { /* funcao que transforma matriz em default com '_' */
  for (a = 0; a < MAX; a++) {
    for (b = 0; b < MAX ; b++) {
      matriz[a][b] = '_';
    }
  }
}
void escreverMatriz(int a, int b, char matriz[MAX][MAX]) { /* funcao que escreve a matriz */
  for (a = 0; a < MAX; a++){
      for (b = 0; b < MAX; b++){
      printf("%c", matriz[a][b]);
      }
      printf("\n");
    }
}
void exportarFile(int a, int b, char matriz[MAX][MAX], FILE *copia){ /* exportar o ficheiro pretendido */
  int tamanhox = 25 , tamanhoy = 25 ;
  fprintf(copia,"%d %d\n",tamanhox,tamanhoy); /* escreve primeira linha com informacao tamanho do mapa */
  for (a = 0; a < 25; a++)
        {
          for (b = 0; b < 25; b++)
          { 
            if (matriz[a][b] != '_') {
              fprintf(copia,"%c %d %d\n", matriz[a][b],a,b); /* escreve tipo bomba e a sua coordenada */
            }
          }
      }
}
void menu(){ /* escreve menu inicial */ 
printf("+-----------------------------------------------------\n");
printf("read <filename>     - read input file\n");
printf("show                - show the mine map\n");
printf("trigger <x> <y>     - trigger mine at <x> <y>\n");
printf("plant <x> <y>       - place armed mine at <x> <y>\n");
printf("export <filename>   - save file with current map\n");
printf("quit                - exit program\n");
printf("sos                 - show menu\n");
printf("+-----------------------------------------------------\n");
}
int main() {
int a = 0,b=0;  /* variaveis coordenandas para as funcoes */
int x,y; /* variaveis que recebe as coordenandas na matriz */
int first = 0;
char linhas[300]; /* ficheiro fgets */
char escolha[30];
char matriz[MAX][MAX];
char NomeFicheiro[30];
char simbolo; /* * ou . */
FILE *original , *copia;
menu();
zerar(a,b,matriz);
printf(">");
do{
  scanf("%s",escolha);
  if (strcmp(escolha, "show") == 0) {
    escreverMatriz(a,b,matriz);
    printf(">");
  } else if (strcmp(escolha, "sos") == 0) {
    menu();
    printf(">");
  } else if (strcmp(escolha, "read") == 0) {
    scanf("%s",NomeFicheiro);
    original = fopen(NomeFicheiro,"r"); /* abre o ficheiro original */
    if (original == NULL) {
      puts("Error opening file"); /* nao detetou o ficheiro */
    } else {
      zerar(a,b,matriz);
      while (!feof(original)){ /* enquanto nao termina a leitura do ficheiro */
        x= -1;
        y= -1; /* meti coordenadas fora da matriz quando deteta se apenas . ou * dava erro por ter coordenandas fora da matriz */
        fgets(linhas,300,original);
        sscanf(linhas,"%c %d %d", &simbolo, &x, &y);
        if (simbolo =='#'|| simbolo =='\r' || simbolo == '\n') {
            continue; /* caso seja comentario ou linha vazia ignora */
        }
        if (first == 0) {
          if (sscanf(linhas, "%d %d",&x, &y) != 2) { /* se o tamanho nao corresponder a estrutura 25 25 */
            puts("File is corrupted");
            zerar(a,b,matriz);
            break;
          } else {
            first = 1; /* ja nao entra mais neste if , ou seja , ja obteve o tamanho do mapa */
            continue;
          }
        }
        if (sscanf(linhas, "%c %d %d",&simbolo,&x, &y) == 3) {
        if ((simbolo == '.' || simbolo == '*') && (x >= 0 && x < 25) && (y >=0 && y< 25))
        {
            matriz[x][y] = simbolo; /* aceita as coordenas e tipo (. ou *) */
        } else {
          puts("File is corrupted"); 
          zerar(a,b,matriz);
          break;
        }
        } else {
          puts("File is corrupted"); 
          zerar(a,b,matriz);
          break;
        }
      }
      fclose(original);
    }
    printf(">");
  } else if (strcmp(escolha, "trigger") == 0) {
      scanf("%d %d",&x,&y);
      if ((x > 24 || y > 24) || (x < 0 || y < 0)) { /* coordenadas invalidas */
        puts("Invalid coordinate");
        printf(">");
        continue;
      } else {
      if( matriz[x][y] != '.' && matriz[x][y] != '*') { /* nao existe mina */
       puts("No mine at specified coordinate");
       printf(">");
       continue;
      }
      if (matriz[x][y] == '.') {
        matriz[x][y] = '*';
      }
      }
      printf(">");
  } else if (strcmp(escolha, "plant") == 0){
    scanf("%d %d",&x,&y);
      if ((x > 24 || y > 24) || (x < 0 || y < 0)) { /* coordenadas invalidas */
        puts("Invalid coordinate");
        printf(">");
        continue;
      } else {
        if (matriz[x][y] == '*'|| matriz[x][y] == '_') { /* muda para armed */
          matriz[x][y] = '.';
        }
      }
      printf(">");
  } else if (strcmp(escolha, "export") == 0){
      scanf("%s",NomeFicheiro);
      copia = fopen(NomeFicheiro, "w");
      if (copia == NULL) {
        puts("Error opening file");
      } else {
        exportarFile(a,b,matriz,copia);
      }
      fclose(copia);
      printf(">");
    } else if (strcmp(escolha, "quit") == 0 ) {
      return 0;
    } else {
      puts("Invalid command");
      printf(">");
      scanf(" %s",escolha);
      continue;
    }
} while (strcmp(escolha,"quit") != 0);
return 0;
}