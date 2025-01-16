#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int menuNovoJogo();
void loadOldgame();
void vitoria();
void saveGame();
void configCoins();
void printCoins();
int chooseStartingPlayer();
int checkEnd(int numColunas, int *coins);
int* jogadaHumanoValida(int *jogada, int numColunas, int *coins);
void jogadaMaquinaValida(int *jogada, int numColunas, int *coins);

struct Game {
	int game_mode;
	int current_player;
	int numColunas;
	int *coins;
	int is_saved;
} g;

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
		    printf("Digite um número inteiro positivo.\n");   	    }
    }
} 


void menuInicial(){

		do {
        printf("\nBem vindo ao Jogo da Moeda.\nPor favor digite a opção que pretende:\n");
		printf("      1 - Iniciar Novo Jogo\n");
		printf("      2 - Continuar Jogo Guardado\n");
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
			break;         
		} else {
			printf("Número não encontrado no menu!\n");
		}
	} while(1);
}

int menuNovoJogo(){
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
            printf("Modo de jogo Humano X Maquina.\n");
            return g.game_mode = 2;
            break;
        }else if (g.game_mode == 1){
            printf("Modo de jogo Humano X Humano.\n");
            break;
        }else {
			printf("Número não encontrado no menu!\n");
		}
	} while (1);
}

void configCoins(){
    g.coins = NULL; 
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
    printf("Jogo Iniciou! \nPara guardar o jogo, no estado atual, inserir 0 0.\n");
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
			break;
		}

	} while(1);
}

void startGameHvM(){
	printf("Jogo Iniciou! \nPara guardar o jogo, no estado atual, inserir 0 0.");
	int play[2];
	g.current_player = chooseStartingPlayer();
	
	do{
		memset(play, 0, sizeof(play));
		
		if (g.current_player == 2){
			printCoins(g.numColunas, g.coins);
			jogadaMaquinaValida(play, g.numColunas, g.coins);
			printf("\nA máquina escolheu a fila %d e retirou %d moedas.\n", play[0], play[1]);

			g.current_player = 1;
			if (checkEnd(g.numColunas, g.coins) == 1) {
				vitoria();
				}
			}
		}	

		if (g.current_player == 1){
			printCoins(g.numColunas, g.coins);
			printf("\nJogador %d - Escolha a fila de moedas e o número de moedas para retirar.\n", g.current_player);
			memset(play, 0, sizeof(play));						
			jogadaHumanoValida(play, g.numColunas, g.coins);
			
			g.coins[ play[0]-1 ] = g.coins[ play[0]-1 ] - play[1];
			g.current_player = 2;
			
			if (checkEnd(g.numColunas, g.coins) == 1) {
				vitoria();
				break;
			}
		}
	}while (1);
}

int* jogadaHumanoValida(int *jogada, int numColunas, int *coins) {
	char input[50];
	int num1;
	int num2;

    do{
		char input[50] = "";
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
					printf("Digite valores possíveis para este jogo!\n");
				}
			} else {
				printf("Digite valores possíveis para este jogo!\n");
			}
		} else {
			printf("Faça uma jogada válida\n");
		}
    }while(1);
}


void jogadaMaquinaValida(int* jogada, int numColunas, int *coins) {

	int check = 0;
	int value;
	int coluna;
	int lines_with_value = 0;
	srand(time(NULL));   

	while(!check) {
        
		coluna = rand() % numColunas;
		if (coins[coluna] > 0) {
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

int chooseStartingPlayer() {
	srand(time(NULL));   
	return rand() %2 + 1;
}

int checkEnd(int numColunas, int *coins) {
	for (int i = 0; i < numColunas; i++) {
		if (coins[i] > 0) {
			return 0;
		}
	}
	return 1;  // 1 = JOGO TERMINOU
}

void vitoria(){
	if (g.current_player == 1) {
		printf("Jogador %d venceu!\n", g.current_player);
	} else if { (g.game_mode == 2 && g.current_player == 2) {
  		printf("Maquina venceu!\n"); 
	} else {
	printf("Jogador %d venceu!\n", g.current_player); 
	}  			
	if (g.is_saved == 1) {
		remove("Cgame.txt");  
	}
	menuInicial();
}

void saveGame(){
    FILE *ponteiro = fopen("Cgame.txt", "w");

	if (ponteiro == NULL) {
		printf("Erro :Não foi possível escrever o arquivo que salva o jogo.\n");
		menuInicial();  
	}

	fprintf(ponteiro, "%d\n", g.game_mode);
	fprintf(ponteiro, "%d\n", g.current_player);
	fprintf(ponteiro, "%d\n", g.numColunas);
	for (int i = 0; i < g.numColunas; i++) {
		fprintf(ponteiro, "%d", g.coins[i]);
		if (i != g.numColunas - 1) {
			fprintf(ponteiro, " ");
		}
	}
	fprintf(ponteiro, "\n");
	fclose(ponteiro);
	printf("O jogo foi guardado.\n");
	menuInicial();
}

void loadOldgame(){
	FILE *ponteiro = fopen("Cgame.txt", "r");

	if (ponteiro == NULL) {
        printf("Erro: Não há jogo salvo ou o arquivo não pôde ser aberto.\n");
        menuInicial();
    }

	fseek(ponteiro, 0, SEEK_END);
	long filesize = ftell(ponteiro);  //ftell retorna posição atual 
	if (filesize == 0) { 
		printf("Erro: Não há jogo salvo.\n");
		menuInicial();
	}
	
	fseek(ponteiro, 0, SEEK_SET); 

	fscanf(ponteiro, "%d\n", &g.game_mode);
	fscanf(ponteiro, "%d\n", &g.current_player);
	fscanf(ponteiro, "%d\n", &g.numColunas);

	g.coins = malloc(g.numColunas * sizeof(int));  

	for (int i = 0; i < g.numColunas; i++) {
		fscanf(ponteiro, "%d", &g.coins[i]);
	}

	g.is_saved = 1;
	fclose(ponteiro);

	if (g.game_mode == 1) {
		startGameHvH();
	} else {
		startGameHvM();
	}
}


int main() {
	//const char *savefile = "Cgame.txt";

	do {
    	menuInicial();

		if (g.game_mode == 2){
    	    configCoins();
        	startGameHvM();
		}else if (g.game_mode == 1){
        	configCoins();
        	startGameHvH();
    	}
	} while(1);

	return 0;
}
