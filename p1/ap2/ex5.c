#include <stdio.h>
#include <stdlib.h>

int main (int argc , char *argv[]){

    float x = 2.7;
    int y = 3;

    float produto = (x*(y*y));

    printf ("\nO produto entre o quadrado %.1f e o número  %d = %.1f \n\n", y, x, produto);
    
    return 0;
}