/*Implemente uma função velocidade(v0,a,t)
com três argumentos, para calcular e devolver a velocidade de um carro, sabendo que a aceleração (a) é constante e decorreram t segundos desde que foi registada a velocidade inicial v0. v= v0 + at
No programa principal deverá ler valores numéricos para usar como argumentos na
invocação desta função.*/

#include <stdio.h>
#include <stdlib.h>

float velocidade(float v0, float a, float t){
float v = v0 + a*t;
return v;
}

int main(void){
    float v0, a, t;
    scanf("%f %f %f", &v0 , &a, &t);
    printf("%f", velocidade(v0, a, t));

    return 0;
}