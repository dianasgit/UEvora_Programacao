/*Exercício: Jogo da Batalha Naval Simples


Descrição do exercício:

Implemente uma versão simples do jogo "Batalha Naval". Neste jogo, o tabuleiro é uma matriz de 5x5, e o jogador tenta descobrir a posição de um navio escondido, fornecendo coordenadas para "atacar". O jogo termina quando o jogador encontra o navio ou quando as tentativas (máximo de 5) se esgotarem.
Regras do Jogo:

    O tabuleiro é uma matriz 5x5 inicializada com 0 (representando água).
    Um único navio estará escondido em uma posição da matriz, representado pelo número 1.
    O jogador terá 5 tentativas para encontrar o navio.
    Se o jogador acertar, o jogo termina e uma mensagem de vitória é exibida.
    Se o jogador errar, actualiza o tabuleiro com X na posição atacada, e o jogo continua.
    Caso todas as tentativas sejam usadas, o jogo termina e a posição do navio é revelada.

Passos para Implementação

1. Inicialização do Jogo:

    Crie um tabuleiro de 5x5 representado por uma matriz de caracteres.
    Coloque um navio numa posição aleatória da matriz.  (no code runner será numa posição fixa, para TPC implementar numa posição aleatória)

2. Ciclo Principal:

    Solicite ao jogador as coordenadas (linha e coluna) para "atacar".
    Verifique se a jogada é válida (dentro do intervalo 0-4).
    Atualize o tabuleiro conforme o resultado do ataque:
        * para quando acerta.
        X para erro.

3. Fim do Jogo:

    Exiba uma mensagem de vitória se o navio for encontrado.
    Se as tentativas terminarem, mostre a posição do navio.
*/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void tabuleiro(char mar[5][5]){
    printf("Tabuleiro Atual:\n");
    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 5 ; j++){
            printf ("%c ", mar[i][j]);
        }
        printf("\n");
    }
}

void ataque (char mar[5][5], int jogadas, int x, int y){
        while (jogadas < 5){
            int i, j;
            scanf("%d %d", &i , &j);

            if (i==x && j==y){
                printf ("\nParabéns! Encontrou o navio!\n");
                mar[x][y] = '*';
                tabuleiro (mar);
                break;
                
            } else {
                mar[i][j] = 'X';
                jogadas = jogadas +1;
                printf("Água! Tente novamente.\n");
                if(jogadas < 5){
                    tabuleiro (mar);
                }
        } 
}
            if (jogadas >=5){
                printf("\nVocê perdeu! O navio estava em (%d, %d).\n", x , y);
                mar[x][y] = '*';
                tabuleiro (mar);
        }

        }
        


int main (void){

    char mar[5][5];
    int x = 2;
    int y = 3;
    int jogadas = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mar[i][j] = '0';
        }
    }

    ataque(mar, jogadas, x, y);

    return 0;
}

/*RESPOSTA DO PROFESSOR:
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5
#define MAX_TENTATIVAS 5

void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = '0'; 
        }
    }
}

void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro Atual:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAMANHO][TAMANHO];
    int linhaNavio, colunaNavio;
    int linhaJogador, colunaJogador;
    int tentativas = 0;


    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posicionar o navio aleatoriamente
    linhaNavio = 2;
    colunaNavio = 3;

    // Ciclo principal do jogo
    while (tentativas < MAX_TENTATIVAS) {
        if(tentativas>0){
            mostrarTabuleiro(tabuleiro);
        }
        scanf("%d %d", &linhaJogador, &colunaJogador);

        // Validar coordenadas
        if (linhaJogador < 0 || linhaJogador >= TAMANHO || colunaJogador < 0 || colunaJogador >= TAMANHO) {
            printf("Coordenadas inválidas! Por favor, insira valores entre 0 e 4.\n");
            continue;
        }

        tentativas++;

        // Verificar se o jogador acertou
        if (linhaJogador == linhaNavio && colunaJogador == colunaNavio) {
            tabuleiro[linhaJogador][colunaJogador] = '*'; // Acerto
            printf("\nParabéns! Encontrou o navio!\n");
            mostrarTabuleiro(tabuleiro);
            return 0;
        } else {
            tabuleiro[linhaJogador][colunaJogador] = 'X'; // Erro
            printf("Água! Tente novamente.\n");
        }
    }

    // Se esgotou as tentativas
    printf("\nVocê perdeu! O navio estava em (%d, %d).\n", linhaNavio, colunaNavio);
    tabuleiro[linhaNavio][colunaNavio] = '*';
    mostrarTabuleiro(tabuleiro);

    return 0;
}
*/