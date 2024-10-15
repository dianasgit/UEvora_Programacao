/*Escreva um programa para ler o salário de um trabalhador e o valor da prestação de um empréstimo bancário. Se a prestação for maior que 20% do salário, exiba a mensagem: “Empréstimo não concedido”. Caso contrário, imprima a mensagem: “Empréstimo concedido”.*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    
    float salario, parcela;

    printf("\nDigite o valor do salário do trabalhador:\n");
    scanf ("%f",&salario);

    printf("\nDigite o valor da prestação do empréstimo:\n");
    scanf ("%f",&parcela);


    if ((salario*0.2) > parcela){
        printf ("\nEmpréstimo concedido");
    }else {
        printf ("\nEmprestimo negado\n.");
    }
    return 0;
}