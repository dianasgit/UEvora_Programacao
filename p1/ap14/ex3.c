/*ogo da Forca em C

Descrição:

Crie um jogo da forca em C, onde introduz uma palavra e um outro jogador tenta adivinhá-la letra por letra. A cada tentativa errada, uma parte do corpo do boneco da forca é desenhada. Se o jogador acertar todas as letras antes de completar o desenho, vence.

Funcionalidades:

    Introduza a palavra a adivinhar: A palavra a adivinhar deve ser lida do input
    Estado do jogo: Mantenha um vetor para representar as letras da palavra, inicialmente com underscores (_). A cada tentativa correta, substitua o underscore pela letra correspondente.
    Desenho do boneco da forca: Utilize caracteres para desenhar as partes do corpo do boneco a cada erro. Já implementado, apens necessitam de chamar a função 
    void draw_hangman(int errors).
    Tentativas: Limite o número de tentativas do jogador.
*/

#include <stdio.h>
#include <string.h>

#define MAX_ERRORS 6  // Número máximo de erros antes de perder

// Função para desenhar o boneco da forca
int draw_hangman(int errors) {
    const char *stages[] = {
        "  +---+\n      |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n  |   |\n      |\n     ===",
        "  +---+\n  O   |\n /|   |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="
    };
    printf("%s\n", stages[errors]);
    return 0;
}


int main() {
    char chosen_word[100];
    //char hidden_word[100];
   
    scanf("%s", chosen_word);
   
    int size = strlen(chosen_word);
    char letras[size];
    char try;
    int errors = 0;

    
    for (int i = 0 ; i < size ; i++){
        letras[i] = '_';
    }
    
    // Limpa a ecra (para jogar no terminal)
    
    while (errors < MAX_ERRORS){

    draw_hangman(errors);
    printf ("%c \nDigite uma letra:", letras);
    

    /*// Implementa o código do jogo
    
    // Derrota
    draw_hangman(errors);
    printf("Perdeu. A palavra era: %s\n", chosen_word);

    }

    return 0;
}*/
    
    int flag = 0;


for (int i = 0 ; i < size ; i++){
        scanf("%c", &try);
        flag = 0;

    if (chosen_word[i] == try) {
        letras[i] = try;
        flag = 1;
        }
    }
    
    if (!flag) {
            errors++;
            printf("Letra errada! A letra '%c' não está na palavra. Tem %d tentativas.\n", try, MAX_ERRORS - errors);
    } else {
        printf("Boa! A letra '%c' está na palavra.\n", try);
    }

        // Verifica se a palavra foi completamente adivinhada
        if (strcmp(letras, chosen_word) == 0) {
            draw_hangman(errors);
            printf("%s\n", letras);
            printf("Ganhou! A palavra era: %s\n", chosen_word);
            return 0;
        }
    }

    // Derrota
    draw_hangman(errors);
    printf("Você perdeu! A palavra era: %s\n", chosen_word);

    return 0;
}