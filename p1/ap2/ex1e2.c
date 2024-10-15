#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    char name[] = "Diana Romão";
    char course[] = "Eng.Informática";
    char university[] = "UÉvora";
    float num1, num2;

    printf ("Meu nome é %s. Sou aluna do curso de licenciatura em %s na %s.\n", name, course, university);

    printf ("Por favor digite dois numeros não inteiros com decimal separado por ponto:\n");

    scanf ("%f  %f", &num1 , &num2);
     
    int summation = ((int)num1 + (int)num2 );
    
    printf ("Quando convertidos para inteiros a soma de ambos os números é: %d \n", summation);

    return 0;
} 
