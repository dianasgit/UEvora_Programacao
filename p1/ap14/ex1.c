/*Escreva uma função para trocar os valores de duas variáveis inteiras utilizando apenas apontadores.

Função a implementar:
void swap(int *a, int *b)*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
int temp = *a; 
*a = *b;       
*b = temp; 
}

int main(){

    return 0;
}