/* Contagem crescente e decrescente:
Implemente um programa para ler um valor inteiro (com a prompt "limite da contagem: "). Usando dois ciclos, uma para contagem crescente até aquele valor, outro para contagem decrescente até zero, programe o equivalente a:
limite da contagem: 10
valor: 1
valor: 2
valor: 3
valor: 4
valor: 5
valor: 6
valor: 7
valor: 8
valor: 9
valor: 10
valor: 9
valor: 8
valor: 7
valor: 6
valor: 5
valor: 4
valor: 3
valor: 2
valor: 1
valor: 0
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){

    int num, cont;

    scanf("%d", &num);
    printf("limite da contagem: %d\n", num);

    cont = 1;
    while( cont < num){
        printf("valor: %d \n", cont);
        cont = cont +1;
    }

    while( cont > -1 ){
        printf("valor: %d \n", cont);
        cont = cont - 1;
    }

    return 0;
}
