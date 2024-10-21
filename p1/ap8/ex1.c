/*1) Escreva um programa que lê um número inteiro positivo nnn e calcula a soma de todos os números pares de 1 até nnn. Utilize um ciclo para somar apenas os números pares e uma condicional para verificar se o número é par.
Regras:
● O programa deve usar um ciclo para iterar de 1 até nnn.
● Apenas números pares devem ser somados*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){

    int num, soma, cont;

    scanf("%d", &num);

    cont = 1;
    soma = 0;
    while(cont <= num){
        if (cont%2 == 0){
            soma = soma + cont;
        }
        cont = cont +1;
    }

    printf("soma: %d", soma);
    return 0;
}