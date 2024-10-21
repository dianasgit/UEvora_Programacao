/*Escreva um programa para ler um número inteiro positivo e imprimir seus divisores. Exemplo: Os divisores de 66 são: 1, 2, 3, 6, 11, 22, 33, 66.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int num, div;

    scanf("%d", &num);
   
    div = 1;
    while(num >= div){
        if (num%div == 0){
            printf("%d\n", div);
        }
        div = div +1;
    }
    return 0;
}