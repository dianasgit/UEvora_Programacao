#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para armazenar o estado do jogo
struct Game {
    int game_mode;
    int current_player;
    int colunasCoin;
    int *coins;
    int is_saved;
};

// Variável global para o jogo
struct Game g;

// Função para obter um número natural
int get_natural_number() {
    int number;
    char input[100];

    while (1) {
        printf("Digite um número natural: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (sscanf(input, "%d", &number) == 1 && number >= 0) {
            return number;
        }
        printf("Entrada inválida. Tente novamente.\n");
    }
}

// Configuração inicial das moedas
void configCoins() {
    printf("Quantas filas deseja no seu jogo?: ");
    g.colunasCoin = get_natural_number();

    // Aloca memória para as moedas
    g.coins = malloc(g.colunasCoin * sizeof(int));
    if (!g.coins) {
        printf("Erro ao alocar memória para as moedas.\n");
        exit(1);
    }

    for (int i = 0; i < g.colunasCoin; i++) {
        printf("Quantas moedas tem a fila %d: ", i + 1);
        g.coins[i] = get_natural_number();
    }
}

// Imprime o estado atual do jogo
void printCoins() {
    printf("\nEstado atual do jogo:\n");
    for (int i = 0; i < g.colunasCoin; i++) {
        printf("Fila %d: %d moedas\n", i + 1, g.coins[i]);
    }
}

// Verifica se o jogo terminou
int checkEnd() {
    for (int i = 0; i < g.colunasCoin; i++) {
        if (g.coins[i] > 0) {
            return 0; // O jogo continua
        }
    }
    return 1; // O jogo terminou
}

// Escolhe o jogador inicial de forma aleatória
int chooseStartingPlayer() {
    srand(time(NULL));
    return rand() % 2 + 1;
}

// Jogada válida do humano
void jogadaHumano() {
    int fila, moedas;

    while (1) {
        printf("\nJogador %d, escolha a fila e o número de moedas para retirar (ex.: 2 3): ", g.current_player);
        char jogada[50];
        fgets(jogada, sizeof(jogada), stdin);
        jogada[strcspn(jogada, "\n")] = '\0';

        if (sscanf(jogada, "%d %d", &fila, &moedas) == 2 && fila > 0 && fila <= g.colunasCoin) {
            if (moedas > 0 && moedas <= g.coins[fila - 1]) {
                g.coins[fila - 1] -= moedas;
                break;
            } else {
                printf("Número de moedas inválido.\n");
            }
        } else {
            printf("Jogada inválida. Tente novamente.\n");
        }
    }
}

// Jogada da máquina (simples)
void jogadaMaquina() {
    printf("\nJogada da máquina...\n");
    srand(time(NULL));

    while (1) {
        int fila = rand() % g.colunasCoin;
        if (g.coins[fila] > 0) {
            int moedas = rand() % g.coins[fila] + 1;
            g.coins[fila] -= moedas;
            printf("A máquina retirou %d moedas da fila %d.\n", moedas, fila + 1);
            break;
        }
    }
}

// Inicia o jogo
void startGame() {
    g.current_player = chooseStartingPlayer();
    printf("\nJogador inicial: Jogador %d\n", g.current_player);

    while (!checkEnd()) {
        printCoins();

        if (g.game_mode == 1 || (g.game_mode == 2 && g.current_player == 1)) {
            jogadaHumano();
        } else if (g.game_mode == 2 && g.current_player == 2) {
            jogadaMaquina();
        }

        if (checkEnd()) {
            printf("\nFim do jogo! Jogador %d venceu!\n", g.current_player);
            break;
        }

        g.current_player = (g.current_player == 1) ? 2 : 1;
    }
}

// Menu para iniciar novo jogo
void menuNovoJogo() {
    printf("\nEscolha o modo de jogo:\n");
    printf("1 - Humano x Humano\n");
    printf("2 - Humano x Máquina\n");
    printf("3 - Voltar ao menu inicial\n");
    printf("Escolha uma opção: ");

    g.game_mode = get_natural_number();

    if (g.game_mode == 3) {
        return;
    } else if (g.game_mode == 1 || g.game_mode == 2) {
        configCoins();
        startGame();
    } else {
        printf("Opção inválida.\n");
    }
}

// Menu principal
void menuInicial() {
    while (1) {
        printf("\nBem vindo ao Jogo da Moeda.\n");
        printf("1 - Iniciar Novo Jogo\n");
        printf("2 - Sair\n");
        printf("Escolha uma opção: ");

        int opcao = get_natural_number();

        if (opcao == 1) {
            menuNovoJogo();
        } else if (opcao == 2) {
            printf("Saindo do jogo. Até a próxima!\n");
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
}

// Função principal
int main() {
    g.coins = NULL; // Inicializa o ponteiro de moedas
    menuInicial();

    // Libera a memória alocada para as moedas, se necessário
    if (g.coins) {
        free(g.coins);
    }
    return 0;
}
