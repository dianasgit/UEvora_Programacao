/*Média de vários valores: Elabore um programa para ir lendo uma sequência de valores (sem perguntar quantos são, usando a prompt 'valor: ') até que o valor inserido seja 0. Nessa altura, não pede mais valores, e
mostra a soma de todos os anteriores. Sugestão: use um ciclo e uma variável auxiliar (total) para acumular a soma dos diversos valores
que vão sendo inseridos. O ciclo repete a leitura e soma,até que o valor lido é zero, ou por outras palavras, enquanto o valor não é zero
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv []){

    float valor, total;

    printf("valor: ");
    scanf("%f", &valor);

    while (valor != 0){
        total = total + valor;
        printf("valor: ");
        scanf("%f", &valor);
    }

    printf("soma: %.2f", total);   
    return 0;
}