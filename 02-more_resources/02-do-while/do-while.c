#include <stdio.h> 

int main() 
{ 
    int contador = 0; 
    int notas[5]; // Declara um array de inteiros com 5 elementos 

    do 
    { 
        printf("Digite a nota %d: ", contador + 1); 
        scanf("%d", &notas[contador]); // Lê a nota e armazena no array 
        contador++; 
    } while (contador < 5); 

    printf("As notas digitadas foram:\n"); 
    contador = 0; 

    do 
    { 
        printf("Nota %d: %d\n", contador + 1, notas[contador]); // Imprime a nota armazenada no array 
        contador++; 
    } while (contador < 5); 

    return 0; 
}