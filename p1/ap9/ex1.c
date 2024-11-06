#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv []) {
    int numero_secreto, palpite;
    int tentativas = 0;

    scanf("%d", &numero_secreto);

    if (numero_secreto<0 || numero_secreto>100){
    printf("numero invalido\n");
    }else{
    do {
    scanf("%d", &palpite);
    tentativas = tentativas +1;
       if (palpite > numero_secreto){
            printf("alto\n");
        }else if (palpite < numero_secreto){
            printf("baixo\n");
        }

    } while (palpite != numero_secreto);
    printf("adivinhou em %d tentativas.\n", tentativas);

    }
    return 0;
}