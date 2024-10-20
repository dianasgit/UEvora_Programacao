//Escreva um programa para ler 2 números inteiros a e b, informados pelo utilizador e imprimir no ecrã todos os números inteiros entre eles. Considere que o primeiro número informado a será menor que b.

#include <stdio.h>
#include <stdlib.h>

int main (int arg, char *argv[]){

    int num1, num2, x;

    printf("Escreva dois numeros");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2){
        x = num2;
        num2 = num1;
        num1 = x;
    }
        while(num2>num1){
            printf("%d\n", num1);
            num1 = num1+1;
        }
    return 0;
}