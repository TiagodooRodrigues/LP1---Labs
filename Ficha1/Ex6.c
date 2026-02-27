#include <stdio.h>
int main() 
{
    float valor= 900.25;
    int tamanho;

    tamanho = sizeof(valor);
    printf("Um float : %E",valor); 
    printf("espaco de memoria ocupado: %d bytes", tamanho);
    return 0;
}