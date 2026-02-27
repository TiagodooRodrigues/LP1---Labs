#include <stdio.h>
int main () {
    int x = 78000000;
    int v1 = 0.46 * x;
    int v2 = 0.32 * x;
    float percentagem = 1.00 - (0.46 + 0.32);
    int v3 = percentagem * x;
    printf("O primeiro vencedor ganha %d$ , o segundo vencedor ganha %d$, e o terceiro ganha %d$\n",v1,v2,v3);
}