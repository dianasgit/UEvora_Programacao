/*Imagine que trabalha numa fábrica que avalia a qualidade dos produtos através de três medições diferentes: resistência, durabilidade e estética, cada uma avaliada numa escala de 0 a 10. Para um produto ser considerado de boa qualidade, todas as medições têm que ser pelo menos 7. Crie um programa que leia três números (representando as medições) e indique se o produto é de boa qualidade ou não.
---a. Entrada: Três números inteiros. ---b. Saída: "Produto de boa qualidade" ou "Produto de má qualidade"*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

    int resistencia, durabilidade, estetica;

    printf("Digite o valor da resistência entre 0 e 10 ");
    scanf("%d", &resistencia);

    printf("Digite o valor da durabilidade entre 0 e 10");
    scanf("%d", &durabilidade);

    printf("Digite o valor da estetica entre 0 e 10 ");
    scanf("%d", &estetica);

    if (resistencia >10|| durabilidade >10|| estetica >10){
        printf ("\nErro. Escala de avaliação entre 0 e 10.");
   
    } else if (resistencia <0|| durabilidade <0|| estetica <0){
        printf ("\nErro. Escala de avaliação entre 0 e 10.");
   
    } else if ( resistencia >=7 && durabilidade >=7 && estetica >=7){
        printf ("\nProduto de boa qualidade\n");
   
    } else {
        printf ("\nProduto de má qualidade\n");
    }

    return 0;
}