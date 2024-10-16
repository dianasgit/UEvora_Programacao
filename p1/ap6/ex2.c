/*Uma empresa de frescos precisa de um sistema que, com base na temperatura
fornecida, classifique-a como “fria” (abaixo de 10°C), “amena” (entre 10°C e 25°C) ou
“quente” (acima de 25°C).
a. Entrada: Um número inteiro representando a temperatura.
b. Saída: "A temperatura é fria", "A temperatura é amena" ou "A temperatura é
quente".*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc , char *argv[]){

    int temp;

    printf("Digite a temperatura\n");
    scanf ("%d", &temp);

    if (temp < 10) {
        printf("A temperatura é fria");
    } else if (temp>=10 && temp<=25){
        printf("A temperatura é amena");
    } else if (temp>25){
        printf("A temperatura é quente");
    }

    return 0;
}