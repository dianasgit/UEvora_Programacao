/*Você foi encarregado de criar um programa que ajude a planear o orçamento de uma
festa. A festa terá três tipos de despesas: comida, bebida e entretenimento. O programa deve ler o valor estimado para cada tipo de despesa e, se o total ultrapassar 1000 euros, deve alertar que o orçamento está acima do esperado. ----a. Entrada: Três números representando os custos de comida, bebida e entretenimento. ---- b. Saída: "Orçamento dentro do limite" ou "Orçamento acima do limite".*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

    float comida, bebida, entret;

    printf ("Digite os custos com comida\n");
    scanf ("%f", &comida);

    printf ("Digite os custos com bebida\n");
    scanf ("%f", &bebida);    
    
    printf ("Digite os custos com entretenimento\n");
    scanf ("%f", &entret);

    if((comida+bebida+entret)>1000){
        printf("Orçamento acima do limite");
    }else if ((comida+bebida+entret)<=1000){
        printf("Orçamento dentro do limite");
    }

    return 0;
}