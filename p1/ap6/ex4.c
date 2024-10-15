/* Escreva um programa que leia um número e, caso ele seja diferente de 0 calcule e mostre:
- O quadrado do número informado;
- A raiz quadrada do número informado*/

// ***** PARA FAZER A COMPILAÇÃO JUNTO COM O MATH.H  USE $ gcc -o ex4 ex4.c -lm   ** atenção ao -lm no final

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc , char *argv[]){

    float num;
    printf ("Digite um número:");
    scanf ("%f", &num);

    if (num == 0){
        printf ("O número digitado é %f.\n", num);
    }else{
        printf ("O número digitado é %.2f\n. O quadrado deste número é %.1f e a raiz é %.2f.\n\n", num , num*num, sqrt(num) );
    }
    return 0;
}