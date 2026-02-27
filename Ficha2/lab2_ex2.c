#include <stdio.h>
int main () {
    printf("Digite a temperatura: ");
    float fahnereit , celsius;
    scanf("%f",&fahnereit);
    printf("A temperatura atual em Fahnereit é de %0.2f\n",fahnereit);
    celsius = 5.0 * (fahnereit - 32.0)/9.0;
    printf("A temperatura em graus sera: %0.2f\n",celsius);
    return 0;
}