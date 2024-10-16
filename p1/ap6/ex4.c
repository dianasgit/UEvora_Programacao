/*Uma empresa tem um sistema de bónus para os seus funcionários com base no
número de anos que eles trabalharam. A regra é a seguinte: 
Até 5 anos: sem bónus;
De 6 a 10 anos: bónus de 5% do salário;
Mais de 10 anos: bónus de 10% do salário.
Implemente um programa que leia o número de anos de serviço de um funcionário e o seu salário, e calcule o valor do bónus. ----a. Entrada: Dois números inteiros: o número de anos de serviço e o salário do funcionário. ----- b. Saída: O valor do bónus a ser pago.*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

    int anos, salario;
    float bonus;

    printf("Digite o número de anos de serviço");
    scanf("%d", &anos);

    printf("Digite o salário atual");
    scanf("%d", &salario);

    if (anos <6){
        bonus = salario * 0;
        printf("O valor do bónus é: %.2f", bonus);

    }else if (anos>=6 && anos<=10){
        bonus = salario * 0.05;
        printf ("O valor do bónus é: %.2f", bonus);

    }else if (anos>10){
        bonus = salario * 0.1;
        printf ("O valor do bónus é: %.2f", bonus);
    }

    return 0;
}