#include <stdio.h>
int main () {
    float largura , comprimento , area , perimetro;
    printf("Digite a largura: \n");
    scanf("%f\n",&largura);
    printf("Digite o comprimento: \n");
    scanf("%f",&comprimento);
    area = largura * comprimento;
    perimetro = largura + comprimento;
    printf("O perimetro : %0.2f e a Area: %0.2f\n",perimetro,area);
}