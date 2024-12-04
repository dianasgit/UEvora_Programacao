/*Implemente um programa em C que calcule a média de N números reais. O programa deve seguir as seguintes diretrizes:

    Função para o cálculo da média:
    Crie uma função chamada calcular_media que:
        Receba como argumento o número de elementos (N).
        Solicite ao utilizador os N números reais.
        Aloque dinamicamente memória para armazenar os números utilizando a função malloc.
        Calcule e devolva a média dos números inseridos.
        A função calcular_media deve libertar a memória alocada dinamicamente após o cálculo, utilizando a função free.
*/


#include <stdio.h>
#include <stdlib.h>

float calcular_media(int n) {

float sum =0;
float *nums = (float *) malloc(n*sizeof(float));    

for(int i = 0 ; i < n; i++){
        scanf("%f", &nums[i]);
        sum = sum+nums[i];
    }
return (sum/n);
}