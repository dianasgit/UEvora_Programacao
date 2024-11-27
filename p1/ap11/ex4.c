/*Escreva um programa para ler 2 vetores, x e y. Com 10 números inteiros
cada. Crie um novo vetor z para calcular a subtração dos valores dos
vetores x e y (z = x – y).*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){

    int vetx[10] , vety[10] , vetz[10];

    for (int i=0 ; i<10 ; i=i+1){
        scanf("%d", &vetx[i]);
    }

    for (int i=0 ; i<10 ; i=i+1){
        scanf("%d", &vety[i]);
    }

    for (int i=0 ; i<10 ; i=i+1){
        vetz[i]= (vetx[i]-vety[i]);
        printf("sub %d\n", vetz[i]);
    }

    return 0;
}