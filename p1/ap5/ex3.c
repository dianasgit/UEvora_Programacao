/* Emreunião, definiu-se que o percentual de reajuste deve considerar as seguintes regras:
a. Trabalhadores com salário mensal até 1.000 euros recebem um reajuste de 5%;
b. Trabalhadores com salário mensal entre 1.001 e 1.800 euros recebem um
reajuste de 4%;
c. Trabalhadores com salário mensal entre 1.801 e 2.500 euros recebem um
reajuste de 3%;
d. Trabalhadores com salário mensal acima de 2.501 euros recebem um reajuste
de 2%;*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

    float salario;

    printf ("\nDigite o valor do salário mensal:\n");
    scanf ("%f", &salario);

    if (salario < 1001 ){
        printf ("O salário de %.2f receberá um resjuste de 5%%. O total do rejuste é %.2f. Logo o novo salário é de %.2f euros.\n" , salario, salario*0.05 , salario*1.05);       
 
    }else if (salario >= 1001 && salario <= 1800){
        printf ("O salário de %.2f receberá um resjuste de 4%%. O total do rejuste é %.2f. Logo o novo salário é de %.2f euros.\n" , salario, salario*0.04 ,salario*1.04);
 
    }else if (salario >= 1801 && salario <= 2500){
        printf ("O salário de %.2f receberá um resjuste de 3%%. O total do rejuste é %.2f. Logo o novo salário é de %.2f euros.\n" , salario, salario*0.03 , salario*1.03); 
 
    }else if (salario >= 2501){
        printf ("O salário de %.2f receberá um resjuste de 2%%. O total do rejuste é %.2f. Logo o novo salário é de %.2f euros.\n" , salario, salario*0.02 , salario*1.02);
    }else{
        printf ("Valor inválido");
    }

    return 0;
}