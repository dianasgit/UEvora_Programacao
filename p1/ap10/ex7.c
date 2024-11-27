/*Implemente uma função com o nome factorial(), com um argumento inteiro.
A função deve devolver o seguinte:
● se o argumento é menor que zero, devolve None
● se o argumento é maior ou igual a zero, devolve o respetivo factorial
Depois de definir a função imprima o valor devolvido pela função quando invocada
com o argumento 6.*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    int fac = 1;

    if(n == 0){
        return printf("%d\n", fac);
    }else if(n > 0){
        for (int x=1 ; n >= x ; x = x+1){
                fac = fac*x;
            }
        return printf("%d\n", fac);    
    }else {
        return printf("None\n");
    }
}
int main (void){
    int f;
    scanf("%d", &f);

    printf("%d", factorial(f));
}