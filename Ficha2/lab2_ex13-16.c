#include <stdio.h>
int main () {
    long double x;
    int y,a,b,c,soma;
    scanf("%Lf\n",&x);
    scanf("%d\n",&y);
    scanf("%d\n",&a);
    scanf("%d\n",&b);
    scanf("%d",&c);
    soma = a + b +c;
    printf("%Lf\n",x);
    printf("%d\n",y);
    printf("A soma = %d\n",soma);
}