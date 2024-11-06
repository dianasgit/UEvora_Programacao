#include <stdio.h>
#include <stdlib.h>

float media4(float n1, float n2, float n3, float n4) {   
    float med = (n1 + n2 + n3 + n4)/4;
    return med;
}

int main(int argc, char*argv[]){

    float n1 = 2.5;
    float n2 = 5;
    float n3 = 7.5;
    float n4 = 10;
    
    printf("Média de %.2f\n", media4(n1 , n2 , n3, n4));
    
    
    return 0;
}