/*1. Imagine que você está a criar um sistema de verificação para um supermercado. Algumas promoções só são aplicáveis a produtos cujo código é múltiplo de 5 e de 11, simultaneamente. Implemente um programa que, dado o código de um produto, verifique se ele é elegível para essa promoção. ---a. Entrada: Um número inteiro representando o código do produto. ---b. Saída: "O produto está em promoção" ou "O produto não está em promoção" */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

    int codigo, promo;
    printf("\nDigite o código do produto.\n");
    scanf ("%d", &codigo);

    if (codigo%5==0 && codigo%11==0){
        printf ("\nO produto está em promoção");
    }else{
        printf ("\nO produto não está em promoção. \n");
    }

    return 0;
}