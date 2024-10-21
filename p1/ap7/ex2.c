/*2. Altere o programa acima para verificar se os números inteiros informados pelo utilizador são diferentes. Se os números forem diferentes, imprimir no ecrã todos os números entre eles. Se forem iguais, imprimir no ecrã a mensagem: “Os números informados são iguais”
*/

#include <stdio.h>
#include <stdlib.h>

int main (int arg, char *argv[]){

    int num1, num2, x;

    printf("Escreva dois numeros");
    scanf("%d %d", &num1, &num2);

    if(num1 == num2){
        printf("Os múmeros informados são iguais");
    }else if (num1 > num2){
        x = num2;
        num2 = num1;
        num1 = x;
    }
        num1= num1+1;
        while(num2>num1){
            printf("%d\n", num1);
            num1 = num1+1;
        }
    return 0;
}