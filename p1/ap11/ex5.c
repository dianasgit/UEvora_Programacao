#include <stdio.h>

int main() {
    int list[10];  // Vetor para armazenar os 10 números
    int i, j, numero, ja_existe;

    // Leitura dos 10 números
    for (i = 0; i < 10; i++) {
        ja_existe = 0;  // Inicializa como "não existe", o número ainda não foi verificado

        // Pede ao usuário para digitar um número
        while (1) {
            printf("Digite o %dº número: ", i + 1);
            scanf("%d", &numero);

            // Verifica se o número já foi digitado
            ja_existe = 0; // Reset da flag de duplicidade
            for (j = 0; j < i; j++) {
                if (list[j] == numero) {
                    ja_existe = 1;  // Marca como "existe" se encontrar o número
                    printf("Número já digitado! Digite outro número.\n");
                    break;  // Sai do loop de verificação
                }
            }

            // Se o número não for duplicado, armazena no vetor e sai do loop
            if (!ja_existe) {
                list[i] = numero;
                break;  // Sai do loop while após inserir um número válido
            }
        }
    }

    // Imprime o vetor final
    printf("\nNúmeros digitados:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}