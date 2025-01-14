#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Game {
	int game_mode;
	int current_player;
	int numColunas;
	int *coins;
	int is_saved;
};

struct Game g;

int checkEnd(int numColunas, int *coins) {
	for (int i = 0; i < numColunas; i++) {
		if (coins[i] > 0) {
			return 0;
		}
	}
	return 1;  // 1 = JOGO TERMINOU
}

void jogadaHumanoValida(int *jogada, int numColunas, int *coins) {
	char input[50];
	int num1;
	int num2;

    do{
        fgets(input, sizeof(input), stdin);
                
        input[strcspn(input, "\n")] = '\0';

        if (sscanf(input, "%d %d", &num1, &num2) == 2 && num1 >= 0 && num2 >= 0) {
            if (num1 == 0 && num2 == 0) {
                saveGame();
                break;
			} else if (num1 <= g.numColunas && num2 != 0) {
				if (num2 <= coins[num1-1] && coins[num1-1] != 0) {
					jogada[0] = num1;
					jogada[1] = num2;
					return jogada;
				} else {
					printf("Faça uma jogada válida\n");
				}
			} else {
				printf("Faça uma jogada válida\n");
			}
		} else {
			printf("Faça uma jogada válida\n");
		}
    }while(1);
}

int get_natural_number() {
	int number;
	char input[100];

    while(1){
        fgets(input, sizeof(input), stdin);
	    input[strcspn(input, "\n")] = '\0';

		if (sscanf(input, "%d", &number) == 1 && number > 0 && strchr(input, '.') == NULL && strchr(input, ',') == NULL && strchr(input, ' ') == NULL) {
	        return number;
            break;
	    } else { 
		    printf("Digite um número inteiro positivo.");   	    }
    }
} 

int chooseStartingPlayer() {
	srand(time(NULL));   
	return rand() %2 + 1;
}

void configCoins(){
    printf("Quantas filas deseja no seu jogo?:\n");	
	g.numColunas = get_natural_number();
    g.coins = malloc(g.numColunas * sizeof(int));  

	for (int i = 0; i < g.numColunas; i++) {
		printf("Quantas moedas tem a fila %d?\n", i + 1);
		g.coins[i] = get_natural_number();
	}
}

void printCoins() {
	printf("\nEstado do Jogo:\n");
	for (int i = 0; i < g.numColunas; i++) {
		printf("Fila %d: %d moedas\n", i + 1, g.coins[i]);
	}
}

void startGameHvH(){
    printf("Jogo Iniciou! \nPara guardar o jogo, no estado atual, inserir 0 0.");
	int play[2];
	g.current_player = chooseStartingPlayer();

    do{
		printCoins(g.numColunas, g.coins);  
		printf("Jogador %d - Escolha a fila de moedas e o número de moedas para retirar.\n", g.current_player);
		
	    memset(play, 0, sizeof(play));
		jogadaHumanoValida(play, g.numColunas, g.coins);						

		g.coins[ play[0]-1 ] = g.coins[ play[0]-1 ] - play[1];

		if (g.current_player == 1) {
			g.current_player = 2;
		} else {
			g.current_player = 1;
		}

		if (checkEnd(g.numColunas, g.coins) == 1) {
			vitoria();
		}
	} while(1);
}

void startGameHvM(){
	printf("Jogo Iniciou! \nPara guardar o jogo, no estado atual, inserir 0 0.");
	int play[2];
	g.current_player = chooseStartingPlayer();
	
	do{
		memset(play, 0, sizeof(play));
		printCoins(g.numColunas, g.coins);
		
		if (g.current_player == 2){
			jogadaMaquinaValida(play, g.numColunas, g.coins);
			printf("A máquina escolheu a fila %d e retirou %d moedas.\n", play[0], play[1]);
				if (checkEnd(g.numColunas, g.coins) == 1) {
					vitoria();
					break;
				}
			g.current_player = 1;

		} else if (g.current_player == 1){
			printf("Jogador %d - Escolha a fila de moedas e o número de moedas para retirar.\n", g.current_player);
			jogadaHumanoValida(play, g.numColunas, g.coins);						
			g.coins[ play[0]-1 ] = g.coins[ play[0]-1 ] - play[1];
				if (checkEnd(g.numColunas, g.coins) == 1) {
					vitoria();
					break;
				}
			g.current_player = 2;
		}
	}while (1);
}

void jogadaMaquinaValida(int* jogada, int numColunas, int *coins) {

	int check = 0;
	int value;
	int coluna;
	int lines_with_value = 0;
	srand(time(NULL));   

	while(!check) {
        
		coluna = rand() % numColunas;
		if (coluna > 0) {
			value = rand() % (coins[coluna] + 1);
			if (value > 0) {
				lines_with_value = 0;
				for (int i = 0; i < numColunas; i++) {
					if (coins[i] != 0) {
						lines_with_value = lines_with_value + 1;
					}
				}

				if (lines_with_value == 1 && coins[coluna] > 1) {  // Ganhando
					jogada[0] = coluna + 1;
					jogada[1] = coins[coluna] - 1;
					coins[coluna] = 1;
					check = 1;
				} else if (lines_with_value == 1 && coins[coluna] == 1) {  // Perdendo
					jogada[0] = coluna + 1;
					jogada[1] = 1;
					coins[coluna] = 0;
					check = 1;
				}else if (lines_with_value > 1) {  // Jogada qualquer
					jogada[0] = coluna + 1;
					jogada[1] = value;
					coins[coluna] = coins[coluna] - value;
					check = 1;
				}
			}
		}
	}
}

void vitoria(){
	printf("Jogador %d venceu!\n", g.current_player);
	if (g.is_saved == 1) {
		remove("Cgame.txt");
	}
	menuInicial();
}

void endgame(){
	printf("Fim do jogo.\n");
	exit;
}

void menuInicial(){
		do {
        printf("\nBem vindo ao Jogo da Moeda.\nPor favor digite a opção que pretende:\n");  /////////// print aparece diferente no terminal
		printf("      1 - Iniciar Novo Jogo\n");
		printf("      2 - Carregar Jogo\n");
		printf("      3 - Sair\n");   

		int num_menu = get_natural_number(); 

		if (num_menu == 1) {
			menuNovoJogo();
            break;
		} else if (num_menu == 2) {
			loadOldgame();
            break;
		} else if (num_menu == 3) {
			exit(0);           
		} else {
			printf("Número não encontrado no menu!\n");
		}
	} while(1);
}

void saveGame(){
    FILE *ofile = fopen("Cgame.txt", "w");

	if (ofile == NULL) {
		printf("Erro :Não foi possível escrever o arquivo que salva o jogo.\n");
		menuInicial();  //////////// 
	}

	fprintf(ofile, "%d\n", g.game_mode);
	fprintf(ofile, "%d\n", g.current_player);
	fprintf(ofile, "%d\n", g.numColunas);
	for (int i = 0; i < g.numColunas; i++) {
		fprintf(ofile, "%d", g.coins[i]);
		if (i != g.numColunas - 1) {
			fprintf(ofile, " ");
		}
	}
	fprintf(ofile, "\n");

	fclose(ofile);

	printf("O jogo foi guardado.\n");

	menuInicial();
}

void loadOldgame(){
	FILE *ifile = fopen("Cgame.txt", "r");

	if (ifile == NULL) {
        printf("Erro: Não há jogo salvo ou o arquivo não pôde ser aberto.\n");
        menuInicial();
    }

	// Procura o tamanho do arquivo, se for zero, significa que está vazio
	fseek(ifile, 0, SEEK_END);
	long filesize = ftell(ifile);

	if (filesize == 0) { // arquivo vazio
		printf("Erro: Não há jogo salvo.\n");
		menuInicial();
	}
	
	fseek(ifile, 0, SEEK_SET);  // volta ao inicio do arquivo

	fscanf(ifile, "%d\n", &g.game_mode);
	fscanf(ifile, "%d\n", &g.current_player);
	fscanf(ifile, "%d\n", &g.numColunas);

	g.coins = malloc(g.numColunas * sizeof(int));  // Aloca o espaço de n linhas no array moedas

	for (int i = 0; i < g.numColunas; i++) {
		fscanf(ifile, "%d", &g.coins[i]);

		if (i != g.numColunas - 1) {
			fscanf(ifile, " ");  // pula os espaços
		}
	}

	g.is_saved = 1;

	fclose(ifile);

	if (g.game_mode == 1) {
		startGameHvH();
	} else {
		startGameHvM();
	}
}

void menuNovoJogo(){
	do { 
		printf("Insira o modo de Jogo \n");
		printf("         1 - Humano x Humano\n"); 
		printf("         2 - Humano x Máquina\n");
		printf("         3 - Voltar ao Menu anterior\n");
        
		g.game_mode = get_natural_number();

		if (g.game_mode == 3) {
			menuInicial();
            break;
		}else if (g.game_mode == 2){
            printf("Modo de jogo Humano X Maquina.");
            configCoins();
            startGameHvM();
            break;

        }else if (g.game_mode == 1){
            printf("Modo de jogo Humano X Humano.");
            configCoins();
            startGameHvH();
            break;

        }else {
			printf("Número não encontrado no menu!");
		}
	} while (1);
}

int main() {
	char input_user[50];
    int size_string;
	int num_menu;
	int is_natural;
	int is_valid;
	int is_the_end;
	const char *savefile = "save.txt";

    g.coins = NULL; 

    menuInicial();
}
