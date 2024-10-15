#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    char letra;

    printf ("\nDigite uma letra e carregue enter: \n");

    scanf ("%c", &letra);

    int numAscii = (int)letra;

    printf ("A letra que você digitou é '%c' e dentro da tabela ASCII o número que representa esta letra é %d. \n\n " , letra , numAscii);

return 0;
}