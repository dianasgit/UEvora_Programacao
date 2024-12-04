/*Adicione a funcionalidade de adicionar um novo aluno ao sistema. Para
isso o utilizador deve introduzir:
● Nome do aluno
● Número do aluno
● Média do aluno
O programa deve adicionar estas informações no ficheiro
base_dados_aluno.txt
Input esperado:
Nome: João Silva
Número: 12345
Média: 14.5
Output esperado:
Aluno adicionado com sucesso.*/

#include <stdio.h>
#include <stdlib.h>

void adicionarAluno(const char *nome_ficheiro){
    FILE *ficheiro = fopen(nome_ficheiro, "a");
    
    if (ficheiro == NULL){
        perror ("Erro ao abrir ficheiro");
    }
    char nome[50];
    int numero;
    float media;

    printf ("Nome: ");
    scanf ("%s" , nome);
    printf ("Numero: ");
    scanf ("%d" , numero);
    printf ("Média: ");
    scanf ("%f" , nome);


}




int main() {
    const char *nome_ficheiro = "base_dados_alunos.txt";

    FILE *ficheiro = fopen(nome_ficheiro, "r");

    if (ficheiro == NULL) {
        ficheiro = fopen(nome_ficheiro, "r");
        printf("Ficheiro '%s' criado com sucesso.\n", nome_ficheiro);
    } else {
        printf("O ficheiro '%s' já existe.\n", nome_ficheiro);
        fclose(ficheiro);

    }
    return 0;
}