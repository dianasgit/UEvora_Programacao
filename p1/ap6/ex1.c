#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

//Escreva um programa para ler um número inteiro e verifique se esse número é par ou ímpar. Após verificar, o programa deve escrever no ecrã o resultado da verificação

int num;

printf ("\nDigite um número inteiro.\n");
scanf ("%d", &num);

if (num%2 == 0){
    printf ("\nO número %d é PAR.", num);
} else {
    printf ("\nO número %d é ÍMPAR.", num);
}

return 0;
}