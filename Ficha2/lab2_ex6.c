#include <stdio.h>
int main () {
    float media,a1,a2,a3,a4;
    printf("Digite a sua nota: \n");
    scanf("%f\n",&a1);
    scanf("%f\n",&a2);
    scanf("%f\n",&a3);
    scanf("%f",&a4);
    media = (a1 + a2 + a3 + a4) / 4;
    printf("A media do aluno:%0.2f\n",media);
    return 0;
}