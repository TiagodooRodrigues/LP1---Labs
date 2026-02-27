#include <stdio.h>
int main () {
    int a,b,c,d;
    printf("Digite 4 numeros: \n");
    scanf("%d\n",&a);
    scanf("%d\n",&b);
    scanf("%d\n",&c);
    scanf("%d",&d);
    int calculo = (a + b + c) * d;
    printf("%d\n",calculo);
    return 0;
}