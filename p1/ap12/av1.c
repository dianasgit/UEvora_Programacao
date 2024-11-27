#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho(char *s){
    return strlen (s);
}

int main(){
    
printf("Tamanho %d\n", tamanho("uevora"));

return 0;
}


/*

void letras_inv(char *s){
    int j = strlen(s);
    for (int i = j-1 ; i > -1 ; i=i-1){
        printf ("%c \n" , s[i]);
    }
}




void sub_cadeia(char *s){
    int n = strlen(s);
  
    for (int i = 0 ; i < n; i=i+1){
        for (int j = 0 ; j < n-i ; j=j+1){
       
        printf ("%c" , s[j]);
        }
        printf ("\n");
    }
}*/










/* void espelho(char s[]){
    
    int n = strlen(s);
    
    for (int i=0 ; i<n ; i=i+1){
        printf("%c" , s[i]);
    }    
    for (int i=n-1 ; i>-1 ; i=i-1){
        printf("%c" , s[i]);
    }
}


void letras (char *s){
    int j = strlen (s);
    for (int i = 0 ; i < j ; i = i+1){
        printf( "%c \n" , s[i]);
    }
}





 int palindromo(char s[]){
    int n = strlen(s);
    
    int inicio = 0;
    int fim = (n-1);
    
    while (inicio <= fim){
        
        if (s[inicio] != s[fim]){
            return 0;
        }
        inicio = inicio+1;
        fim = fim -1;
    }
    return 1;
}
*/