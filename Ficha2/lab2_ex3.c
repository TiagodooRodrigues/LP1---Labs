#include <stdio.h>
#include <math.h>
int main () {
    printf("Digite o raio do circulo: \n");
    double raio;
    scanf("%lf",&raio);
    double pi = 3.141592;
    double area = pi * pow(raio,2);
    printf("A area do circulo tem valor: %0.2f\n",area);
    return 0;
}