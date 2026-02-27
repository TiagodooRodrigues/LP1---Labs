
# include <stdio.h>
int main() 
{
    int valor = 90000; 
    int tamanho;

    tamanho = sizeof(valor);
    
    printf("Um short int : %d\n",valor); 
    printf("espaco de memoria ocupado: %d bytes", tamanho);
    return 0;
}
