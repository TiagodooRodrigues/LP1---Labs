#include <stdio.h>
#include <math.h>
int main () {
    float kg, altura ,IMC;
    printf("Digite o seu peso em kg: \n");
    scanf("%f",&kg);
    printf("Digite a sua altura em metros: \n");
    scanf("%f",&altura);
    IMC = kg / pow(altura,2);
    printf("IMC : %0.2f\n",IMC);
}