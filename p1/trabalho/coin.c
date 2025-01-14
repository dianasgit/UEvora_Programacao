#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

struct Game {
	int game_mode;
	int current_player;
	int numColunas;
	int *coins;
	int is_saved;
};

	struct Game g;

int get_natural_number() {
	char input[100];
	int number;

    fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';

    while(1){
	    if (sscanf(input, "%d", &number) == 1 && number > 0) {
		    return number;
            break;
	    } else {
		    printf("Digite um número inteiro positivo.");
	        fgets(input, sizeof(input), stdin);
	        input[strcspn(input, "\n")] = '\0';
	    }
    }
} 

void menuInicial(){

	printf("\nBem vindo ao Jogo da Moeda.\n");
	
	while(1) {
		printf("Por favor digite a opção que pretende:\n");
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
			printf("Número não encontrado no menu!");
		}
	} 
}

void menuNovoJogo(){
	do { 
		printf("Insira o modo de Jogo \n");
		printf("         (1) Humano x Humano\n"); 
		printf("         (2) Humano x Máquina\n");
		printf("         (3) Voltar ao Menu Inicial\n");
        
		g.game_mode = get_natural_number();

		if (g.game_mode == 3) {
			menuInicial();
            break;
		}else if (g.game_mode == 2){
            printf("Modo de jogo Humano X Maquina.");
            configCoins();
            startGame();
            break;

        }else if (g.game_mode == 1){
            printf("Modo de jogo Humano X Humano.");
            configCoins();
            startGame();
            break;

        }else {
			printf("Número não encontrado no menu!");
		}
	} while (1);
}

void configCoins(){
    printf("Quantas filas deseja no seu jogo?:\n");
		
	g.numColunas = get_natural_number();
    g.coins = malloc(g.numColunas * sizeof(int));  

	for (int i = 0; i < g.numColunas; i++) {
		printf("Quantas moedas tem a fila %d:\n", i + 1);
		g.coins[i] = get_natural_number();
	}
}


void printCoins(int numColunas, int *coins) {
	printf("Estado do Jogo:\n");
	for (int i = 0; i < numColunas; i++) {
		printf("Fila %d: %d moedas\n", i + 1, coins[i]);
	}
}

void startGame(){
    printf("Jogo Iniciou! \nPara guardar o jogo, no estado atual, inserir 0 0.");
	int play[2];

    do{
	printCoins(g.numColunas, g.coins);  //////////////////
	
        //HUMANO
		if (g.game_mode == 1 || (g.game_mode == 2 && g.current_player == 1)) {

            g.current_player = chooseStartingPlayer();

            do{
			printf("Jogador %d - Escolha a fila de moedas e o número de moedas para retirar.\n", g.current_player);
		
                memset(play, 0, sizeof(play));
				jogadaHumanoValida(play, g.numColunas, g.coins);						

				g.coins[ play[0]-1 ] = g.coins[ play[0]-1 ] - play[1];
					
                if (checkEnd(g.numColunas, g.coins) == 0) {
					vitory(); //////////////
				}

                if (g.current_player == 1) {
					g.current_player = 2;
				} else {
						g.current_player = 1;
				}
				}while (1);           
        }


        //MAQUINA
		if (g.current_player == 2 && g.game_mode == 2) {
			memset(play, 0, sizeof(play));
			jogadaMaquinaValida(play, g.numColunas, g.coins);
			
            printf("A máquina escolheu a fila %d e retirou %d moedas.\n", play[0], play[1]);

			if (checkEnd(g.numColunas, g.coins)== 0);
			g.current_player = 1;

		} 

	} while(1);
}


void jogadaHumanoValida(int *jogada, int numColunas, int *coins) {
	char jogada[50];
	int num1;
	int num2;

    do {
        // Lê o jogada como string
        fgets(jogada, sizeof(jogada), stdin);
                
        // Remove o fim da linha se houver
        jogada[strcspn(jogada, "\n")] = '\0';

        // Tenta ler dois números separados por espaço
        if (sscanf(jogada, "%d %d", &num1, &num2) == 2 && num1 >= 0 && num2 >= 0) {
            if (num1 == 0 && num2 == 0) {
                saveGame();//////////////
                break;
            }

        if (num1 < g.numColunas && num2 != 0) {
            if (num2 <= coins[num1-1] && coins[num1-1] != 0) {
                coins[0] = num1;
                coins[1] = num2;
                return coins;
                        
            } else {
            printf("Faça uma jogada válida\n");
            }

        } else {
            printf("Faça uma jogada válida\n");
        }
        }
    }while(1);
}



void jogadaMaquinaValida(int*play, int numColunas, int *coins) {

	int check = 0;
	int lines_with_value = 0;
    int jogada[2];
	srand(time(NULL));   


	while(!check) {
        int coluna = rand() %g.numColunas;
        int value = rand() %(coins[coluna-1]);

		for (int i = 0; i < g.numColunas; i++) {
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
			endgame(); ///////////// ;
			check = 1;
		}else if (lines_with_value > 1) {  // Jogada qualquer
			jogada[0] = coluna - 1;
			jogada[1] = value;
			coins[coluna] = coins[coluna] - value;
			check = 1;
		} 
	}
}

int checkEnd(int numColunas, int *coins) {
	int check = 0;
	for (int i = 0; i < numColunas; i++) {
		if (coins[i] > 0) {
			check = 1;
		}
	}
	return check;
}

int chooseStartingPlayer() {

	srand(time(NULL));   
	int player = rand() % 2 + 1;

	if (player == 1) {
		return 1;
	} else {
		return 2;
	}
}

saveGame(){
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

	startGame();
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

    void menuInicial();

    void victory();{

	    printf("Jogador %d venceu!\n", g.current_player);
	        if (g.is_saved == 1) {
		    remove(savefile);
	    }
	    menuInicial();
    }

	endgame();{
		printf("Fim do jogo.\n");
        exit;
    }

}



