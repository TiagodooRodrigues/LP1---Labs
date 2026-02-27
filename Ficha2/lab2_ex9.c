#include <stdio.h>
int main () {
    float euros , dollars;
    printf("Digite o dinheiro em Euros: \n");
    scanf("%f",&euros);
    dollars = euros * 1.23;
    printf("O valor em dollars sera: %0.2f$\n",dollars);
}