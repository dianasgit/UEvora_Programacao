/*Implemente um jogo simples de adivinhas. O programa deve gerar um número aleatório
entre 1 e 100, e o utilizador deve tentar adivinhar o número. A cada tentativa, o programa deve
dizer se o número inserido é maior ou menor do que o número correto. O ciclo termina
quando o utilizador acerta o número.
Regras:
● Utilize um ciclo while que continua até que o utilizador adivinhe o número
corretamente.
● O programa deve dar dicas ao utilizador para dizer se o número é maior ou menor.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* argv[]){

    int num;

    srand(time(0));
    int sorteio = rand()%100 + 1;

    scanf("%d", &num);

    while(num != sorteio){
        if (num > sorteio){
            printf("O número sorteado é menor, tente de novo: \n");
        }else if (num < sorteio){
            printf("O número sorteado é maior, tente de novo: \n");
        }
        scanf("%d", &num);
    }
    printf("Você acertou! ");
    return 0;
}