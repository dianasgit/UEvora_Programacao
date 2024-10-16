/*Uma loja de roupas tem um sistema de inventário que necessita ser automatizado. Eles
precisam de um programa que receba o stock atual de 4 tipos de produto (camisas,
calças, casacos e sapatos) e verifique se algum dos produtos está em falta (stock zero).
Caso algum esteja em falta, o programa deve alertar para a reposição do stock desse
produto. ----a. Entrada: Quatro números inteiros representando o stock de cada tipo de
produto. ----b. Saída: Uma mensagem indicando quais produtos precisam de reposição ou
uma mensagem de que todos os produtos estão em stock*/

#include <stdio.h>
#include <stdlib.h>

int main (int charc, char *argv[]){

    int camisas, calcas, casacos, sapatos;

    printf ("Digite os valores de stock de camisas, calças, casacos e sapatos");
    scanf ( "%d %d %d %d", &camisas, &calcas, &casacos, &sapatos);

    if ((camisas && calcas && casacos && sapatos) >0){
        printf("todos os produtos estão em stock");

    }
    if ( camisas <= 0){
        printf("\nCamisas precisam de reposição");
    }
    if ( calcas <= 0){
        printf("\nCalças precisam de reposição");
    }
    if ( casacos <= 0){
        printf("\nCasacos precisam de reposição");
    }
    if ( sapatos <= 0){
        printf("\nSapatos precisam de reposição");
    }

    return 0;
}