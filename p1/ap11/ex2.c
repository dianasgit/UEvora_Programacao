/*Com o uso de vetores, escreva um programa para ler do teclado 10 valores
inteiros e em seguida, imprimi-los na ordem inversa.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

int valores[10];

int i = 0;
while( i < 10){
    scanf("%d", &valores[i]);
    i = i+1;
    }

i = 9;
while( i >= 0){
    printf("%d \n", valores[i]);
    i = i-1;
}
return 0;
}