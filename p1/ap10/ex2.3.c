/*Implemente uma função media4(a,b,c,d)
com quatro argumentos float, para calcular e devolver a média dos quatro argumentos.
Na função principal deverá ler valores numéricos para usar como argumentos na
invocação desta função*/

#include <stdio.h>
#include <stdlib.h>

float media(float a, float b, float c, float d){
float media = (a+b+c+d)/4;
return media;
}

float sucessor(float x){
float y = x+1;
return y;
}

int main (void){

float a,b,c,d, med, suc;
scanf("%f %f %f %f", &a , &b , &c , &d);

med = media(a,b,c,d);
printf("%.2f", media(a,b,c,d));

suc = sucessor(med);
printf("\n%.2f", suc);

    return 0;
}