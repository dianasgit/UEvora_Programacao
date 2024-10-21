/*Escreva um programa que lê dois números inteiros a e b, onde a <= b , e conta quantos
números no intervalo fechado de a até b são divisíveis por 3 e 5 ao mesmo tempo. O programa
deve usar um ciclo para verificar todos os números entre a e b.*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char*argv[]){

    int numA, numB, x,cont;

    scanf ("%d %d", &numA, &numB);

    if (numB < numA){
        x = numA;
        numA = numB;
        numB = x;
    }

    x = numA;
    cont = 0;
    
    while(x < numB){
        if (x%5 ==0 && x%3 == 0){
            cont = cont +1;
        }
        x = x+1;
    }

    printf("- %d números no intervalo fechado de %d até %d são divisíveis por 3 e 5 ao mesmo tempo.\n", cont, numA, numB);

    return 0;

}