/*Escreva um programa com três funções:
● quadrado(v)
● cubo(v)
● quadrado_mais_cubo(v), que devolve a soma do quadrado de v com o cubo de v
Depois, no main, deve:
● ler um valor inteiro, x
● executar a terceira função passando x como argumento, e guardando o
resultado numa variável y
● imprimir y*/

#include <stdio.h>
#include <stdlib.h>

int quadrado(int v){
    int q = v*v;
    return q;
}

int cubo(int v){
    int q = v*v*v;
    return q;
}
int quadrado_mais_cubo(int v){
    int q = quadrado(v)+ cubo(v);
    return q;
}

int main (int argc, char* argv[]){

    int x, y;
    scanf("%d", &x);

    y = quadrado_mais_cubo(x);

    printf("%d", y);

    return 0;
}