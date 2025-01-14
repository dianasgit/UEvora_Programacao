/*Implemente um programa que verifique se o ficheiro
base_dados_alunos.txt, existe. Caso não existam, o programa deve criá-lo vazio. Este passo assegura que o sistema pode operar mesmo sem ficheiro pré-existir.
Output esperado:
Ficheiro 'base_dados_alunos.txt' criado com sucesso.*/


#include <stdio.h> 
#include <stdlib.h>

int main() {
    const char *nome_ficheiro = "base_dados_alunos.txt";

    FILE *ficheiro = fopen(nome_ficheiro, "r");

    if (ficheiro == NULL) {
        ficheiro = fopen(nome_ficheiro, "w");
        printf("Ficheiro '%s' criado com sucesso.\n", nome_ficheiro);
    } else {
        printf("O ficheiro '%s' já existe.\n", nome_ficheiro);
        fclose(ficheiro);

    }
    return 0;
}
