/*4) Escreva um programa que lê um número inteiro nnn e calcula o seu fatorial n!. O fatorial de um número é a multiplicação de todos os números inteiros positivos de 1 até n.
Regras:
● Utilize um ciclo para calcular o fatorial de n.
● O programa deve validar se o número inserido é positivo.*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char*argv[]){

    int num, fact;
    scanf("%d", &num);

    if (num >= 0){
        fact = 1;
        while(num>=1){
            fact = fact * num;
            num = num -1;
        }
        printf("%d \n", fact);
    }else{
        printf("Erro. Número negativo não calcula fatorial.");
}
    return 0;
}