/* Escreva um programa que pede ao utilizador para definir uma senha e depois verificar se a
senha está correta. O utilizador tem 3 tentativas para introduzir a senha correta. Se a senha
correta for inserida dentro das 3 tentativas, o programa deve mostrar "Acesso concedido", caso
contrário, o programa deve mostrar "Acesso negado".
Regras: ● O programa deve utilizar um ciclo while ou for com uma condicional para verificar
as tentativas. ● Se a senha correta for inserida, o ciclo deve terminar.*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){

    int senha, try, n;

    printf("Digite uma senha: ");
    scanf("%d", &senha);

    n = 1;
    while (n <4 && senha != try){
        printf("\ndigite novamente a senha\n");
        scanf("%d", &try);
        n = n+1;

        if(try == senha){
            printf("Acesso concedido");
            return 0;
        }else{
            printf("Acesso negado\n");
        }
    }
    return 0;
}