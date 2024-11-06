/*Escreva um programa para ler um vetor de 10 posições. Verifique se
existem valores iguais e imprima-os*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int vet[10];
    
    for (int i = 0 ; i<10 ; i=i+1){
        scanf("%d", &vet[i]);
    }

    for (int n = 0 ; n<10 ; n=n+1){
        for (int i = n+1 ; i<10 ; i=i+1){
            if (vet[i] == vet [n])
            printf("\n repetição %d", vet[n]);
        }
    }
    return 0;
}