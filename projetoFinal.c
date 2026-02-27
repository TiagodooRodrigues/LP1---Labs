#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "messages.h"

struct node /*classe da bomba*/
{
  int linha; /* x */
  int coluna; /* y */
  int time; /* tempo de explosao */
  struct node *nextBomb; /* proxima bomba */
};

struct node *head = NULL; /* primeiro elemento */
struct node *current = NULL; /* variavel auxiliar para pecorrer a lista */

void printList() { /* funcao que faz print da lista ligada */
   struct node *ptr = head;
   while(ptr != NULL) { /* percorrer a lista */
     printf("%d [%d, %d]\n",ptr->time,ptr->linha,ptr -> coluna); /* escrever a explosao */
     ptr = ptr->nextBomb; /* passa para o proximo da lista */
   }
}
void insert (int xCor, int yCor, int time ) { /* inserir na linkedlist */
  struct node *bomba = (struct node*)malloc(sizeof(struct node)); 
  /*inserir os dados da bomba */
  bomba -> linha = xCor;
  bomba -> coluna = yCor;
  bomba -> time = time;
  bomba -> nextBomb = NULL;
  /* --------------------- */
  /* inserir no fim da lista */
  if (head == NULL) {
    head = bomba;
  } else {
    struct node *Last = head;
    while (Last->nextBomb != NULL) {
      Last = Last -> nextBomb;
    }
    Last -> nextBomb = bomba;
  }
  /* -------------------------- */
}

void logList(int x , int y ,char ** ptr_matriz , int xTamanho , int yTamanho , int time) {
  /* x - 1 */
  if (x -1 >= 0 && ptr_matriz[x-1][y] == '.') { /* 10 */
  insert(x-1,y,time + 10);
  ptr_matriz[x-1][y] = '+';
  }
  /* x - 1 e y -1 */
  if (x - 1 >= 0 && y -1 >= 0 && ptr_matriz[x-1][y-1] == '.') { /* 11 */
  insert(x-1,y-1,time + 11);
  ptr_matriz[x-1][y-1] = '+';
  }
  /* y - 1 */
  if (y - 1 >= 0 && ptr_matriz[x][y-1] == '.') { /* 12 */
  insert(x,y-1,time + 12);
  ptr_matriz[x][y-1] = '+';
  }
  /* x + 1 e y -1 */
  if (x + 1 < xTamanho && y -1 >= 0 && ptr_matriz[x+1][y-1] == '.') { /* 13 */
  insert(x+1,y-1,time + 13);
  ptr_matriz[x+1][y-1] = '+';
  }
  /* x + 1 */
  if (x + 1 < xTamanho && ptr_matriz[x+1][y] == '.') { /* 14 */
  insert(x+1,y,time + 14);
  ptr_matriz[x+1][y] = '+';
  }
  /* x + 1 e y +1 */
  if (x +1 < xTamanho && y + 1 < yTamanho && ptr_matriz[x+1][y+1] == '.') { /* 15 */
  insert(x+1,y+1,time + 15);
  ptr_matriz[x+1][y+1] = '+';
  }
  /* y + 1 */
  if (y + 1 < yTamanho && ptr_matriz[x][y+1] == '.') { /* 16 */
  insert(x,y+1,time + 16);
  ptr_matriz[x][y+1] = '+';
  }
  /* x - 1 e y + 1 */
  if (x -1 >= 0 && y + 1 < yTamanho && ptr_matriz[x-1][y+1] == '.') { /* 17 */
  insert(x-1,y+1,time + 17);
  ptr_matriz[x-1][y+1] = '+';
  }
}
int length() { /* funcao que determina o tamanho da lista ligada */
   int length = 0;
   struct node *current;
   for(current = head; current != NULL; current = current->nextBomb) {
      length++;
   }
   return length;
}

void sort() { /* funcao para ordernar pelo tempo de explosao a lista ligada */
   int i, j, k, tempLinha, tempData, tempColum;
   struct node *current;
   struct node *next;
   int size = length();
   k = size ;
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->nextBomb;
      for ( j = 1 ; j < k ; j++ ) {   
         if ( current->time > next->time ) {
            tempData = current->time;
            current->time = next->time;
            next->time = tempData;

            tempLinha = current->linha;
            current->linha = next->linha;
            next->linha = tempLinha;

            tempColum = current->coluna;
            current->coluna = next->coluna;
            next->coluna = tempColum;
         }
         current = current->nextBomb;
         next = next->nextBomb;
      }
   }   
}
void zerar(int a, int b, char ** ptr_matriz, int xTamanho, int yTamanho) { /* funcao que limpa a matriz */
  /* funcao que transforma matriz em default com '_' */
  for (a = 0; a < xTamanho; a++) {
    for (b = 0; b < yTamanho; b++) {
      ptr_matriz[a][b] = '_';
    }
  }
}

void escreverMatriz(int a, int b, char ** ptr_matriz, int xTamanho, int yTamanho) { /* funcao que escreve a matriz */
  /* funcao que escreve a matriz */
  for (a = 0; a < xTamanho; a++) {
    for (b = 0; b < yTamanho; b++) {
      printf("%c", ptr_matriz[a][b]);
    }
    printf("\n");
  }
}

void exportarFile(int a, int b, char ** ptr_matriz, FILE * copia, int xTamanho, int yTamanho) { /* funcao que exporta o mapa */
  /* exportar o ficheiro pretendido */
  fprintf(copia, "%d %d\n", xTamanho, yTamanho); /* escreve primeira linha com informacao tamanho do mapa */
  for (a = 0; a < xTamanho; a++) {
    for (b = 0; b < yTamanho; b++) {
      if (ptr_matriz[a][b] != '_') {
        fprintf(copia, "%c %d %d\n", ptr_matriz[a][b], a, b); /* escreve tipo bomba e a sua coordenada */
      }
    }
  }
}
void printPropagate(int a,int b ,char ** ptr_matriz, int xTamanho, int yTamanho) { /* escreve as matrizes do propagate */
  struct node *ptr = head;
   while(ptr != NULL) {
     escreverMatriz(a,b,ptr_matriz,xTamanho,yTamanho);
     ptr = ptr->nextBomb;
   }
}
void menu() { /* menu inicial do projeto */
  /* escreve menu inicial */
  puts(MSG_ENDTITLE);
  printf("show                - show the mine map\n");
  printf("propagate <x> <y>   - explode bomb at <x> <y>\n");
  printf("log <x> <y>			    - explode bomb at <x> <y>\n");
  printf("plant <x> <y>       - place bomb at <x> <y>\n");
  printf("export <filename>   - save file with current map\n");
  printf("quit                - exit program\n");
  printf("sos                 - show menu\n");
  puts(MSG_ENDTITLE);
}

int main(int argc, char ** agrv) {
  char ** ptr_matriz; /* ponteiro para malloc da matriz */
  int contadorMatriz; /* contador para definicao da matriz */
  int a = 0, b = 0; /* variaveis coordenandas para as funcoes */
  int x, y; /* variaveis que recebe as coordenandas nas linhas de txt */
  int xTamanho, yTamanho; /* variaveis que sao lidas no inicio do txt */
  int first = 0; /* verificar se leu a primeira linha */
  char linhas[300]; /* ficheiro fgets */
  char escolha[30];
  char NomeFicheiro[30];
  char simbolo; /* * ou . */
  FILE * original, * copia;
  if (argc < 2) { /* nao encontrou o ficheiro para leitura */
    puts(MSG_FNAME);
    exit(0);
  }
  original = fopen(agrv[1], "r"); /* abre o ficheiro original */
  if (original == NULL) {
    puts(MSG_FILE_OPN); /* nao detetou o ficheiro */
  } else {
    while (!feof(original)) {
      /* enquanto nao termina a leitura do ficheiro */
      x = -1;
      y = -1; /* meti coordenadas fora da matriz quando deteta se apenas . ou * dava erro por ter coordenandas fora da matriz */
      fgets(linhas, 300, original);
      sscanf(linhas, "%c %d %d", & simbolo, & x, & y);
      if (simbolo == '#' || simbolo == '\r' || simbolo == '\n') {
        continue; /* caso seja comentario ou linha vazia ignora */
      }
      if (first == 0) {
        if (sscanf(linhas, "%d %d", & x, & y) != 2) {
          /* se o tamanho nao corresponder a estrutura 25 25 */
          puts(MSG_FILE_CRP);
          exit(0);
        } else {
          first = 1; /* ja nao entra mais neste if , ou seja , ja obteve o tamanho do mapa */
          xTamanho = x; /* linhas do mapa */
          yTamanho = y; /* colunas do mapa */
          ptr_matriz = (char ** ) malloc(xTamanho * sizeof(char * )); /* allocar memoria dinamica para a matriz */
          for (contadorMatriz = 0; contadorMatriz < xTamanho; contadorMatriz++) { /* numero de linhas */
            ptr_matriz[contadorMatriz] = (char * ) malloc(yTamanho * sizeof(char)); /* numero de colunas */
          }
          zerar(a, b, ptr_matriz, xTamanho, yTamanho); /* limpar a matriz */
          continue;
        }
      }
      if (sscanf(linhas, "%c %d %d", & simbolo, & x, & y) == 3) {
        if ((simbolo == '.' || simbolo == '*') && (x >= 0 && x < xTamanho) && (y >= 0 && y < yTamanho)) {
          ptr_matriz[x][y] = simbolo; /* aceita as coordenas e tipo (. ou *) */
        } else {
          puts(MSG_FILE_CRP);
          exit(0);
        }
      } else {
        puts(MSG_FILE_CRP);
        exit(0);
      }
    }
    fclose(original);
  }
  menu();
  printf(MSG_PROMPT);
  do {
    scanf("%s", escolha);
    if (strcmp(escolha, "show") == 0) {
      escreverMatriz(a, b, ptr_matriz, xTamanho, yTamanho);
      printf(MSG_PROMPT);
    } else if (strcmp(escolha, "sos") == 0) {
      menu();
      printf(MSG_PROMPT);
    } else if (strcmp(escolha, "plant") == 0) {
      scanf("%d %d", & x, & y);
      if ((x > xTamanho || y > yTamanho) || (x < 0 || y < 0)) {
        /* coordenadas invalidas */
        puts(MSG_INVAL_CRD);
        printf(MSG_PROMPT);
        continue;
      } else {
        if (ptr_matriz[x][y] == '*' || ptr_matriz[x][y] == '_') {
          /* muda para armed */
          ptr_matriz[x][y] = '.';
        }
      }
      printf(MSG_PROMPT);
    } else if (strcmp(escolha,"log") == 0){
      scanf("%d %d",&x,&y);
      if ((x > xTamanho || y > yTamanho) || (x < 0 || y < 0)) { /* coordenadas invalidas */
        puts(MSG_INVAL_CRD);
        printf(MSG_PROMPT);
        continue;
      }
      if( ptr_matriz[x][y] != '.' && ptr_matriz[x][y] != '*') { /* nao existe mina */
       puts(MSG_NOBOMB);
       printf(MSG_PROMPT);
       continue;
      }
      insert(x,y,0); /* o primeiro log */
      ptr_matriz[x][y] = '+'; /* nao repetir o log */
      logList(x,y,ptr_matriz,xTamanho,yTamanho,0);
      current = head;
      while(current != NULL) { /* inserir os dados na lista ligada sobre as explosoes */
      logList(current ->linha,current -> coluna,ptr_matriz,xTamanho,yTamanho,current -> time);
      current = current -> nextBomb;
      }
      current = head;
      while(current != NULL) { /* trocar para as minas , as coordenandas que tem '+' */
      ptr_matriz[current -> linha][current -> coluna] = '*';
      current = current -> nextBomb;
      }
      current = head;
      sort(); /* colocar em ordem a lista ligada */
      printList(); 
      while (head != NULL) { /* libertar memoria dinamica */
        current = head;
        head = head->nextBomb;
        free(current);
      }
      printf(MSG_PROMPT);
    } else if (strcmp(escolha,"propagate") == 0) {
      scanf("%d %d",&x,&y);
      if ((x > xTamanho || y > yTamanho) || (x < 0 || y < 0)) { /* coordenadas invalidas */
        puts(MSG_INVAL_CRD);
        printf(MSG_PROMPT);
        continue;
      }
      if( ptr_matriz[x][y] != '.' && ptr_matriz[x][y] != '*') { /* nao existe mina */
       puts(MSG_NOBOMB);
       printf(MSG_PROMPT);
       continue;
      }
      insert(x,y,0);
      ptr_matriz[x][y] = '+';
      logList(x,y,ptr_matriz,xTamanho,yTamanho,0);
      current = head;
      while(current != NULL) {
      logList(current ->linha,current -> coluna,ptr_matriz,xTamanho,yTamanho,current -> time);
      current = current -> nextBomb;
      }
      current = head;
      while(current != NULL) {
      ptr_matriz[current -> linha][current -> coluna] = '*';
      current = current -> nextBomb;
      }
      current = head;
      sort();
      printPropagate(a,b,ptr_matriz,xTamanho,yTamanho); /* em vez de print da lista , dou print dos mapas */
      while (head != NULL) { /* libertar memoria dinamica */
        current = head;
        head = head->nextBomb;
        free(current);
      }
      printf(MSG_PROMPT);
    }
     else if (strcmp(escolha, "export") == 0) {
      scanf("%s", NomeFicheiro);
      copia = fopen(NomeFicheiro, "w");
      if (copia == NULL) {
        puts(MSG_FILE_OPN);
      } else {
        exportarFile(a, b, ptr_matriz, copia, xTamanho, yTamanho);
      }
      fclose(copia);
      printf(MSG_PROMPT);
    } else if (strcmp(escolha, "quit") == 0) {
      exit(0);
    } else {
      puts(MSG_INVAL_CMD);
      printf(MSG_PROMPT);
      scanf("%s", escolha);
      continue;
    }
  } while (strcmp(escolha, "quit") != 0);
  exit(0);
}