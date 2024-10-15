#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[]){

    float n1 , n2 , n3 , media;

    printf ("\nDigite 3 numeros, caso numero não inteiro separe o decimal com ponto:");

    scanf ("%f %f %f", &n1, &n2, &n3);

    media = ((n1 + n2 + n3) / 3);

    printf ("\nA média dos 3 valores digitados é: %.2f \n", media);

    return 0;
}
