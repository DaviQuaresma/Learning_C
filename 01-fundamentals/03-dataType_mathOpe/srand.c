#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sec = time(0);
    
    // A função srand() é como dar uma "chave inicial" para o gerador de números aleatórios do computador. Imagine 
    // que o rand() é uma máquina que produz números, mas ela precisa de uma semente para começar a trabalhar de 
    // forma diferente a cada vez.
    srand(sec);

    int n1 = rand();
    int n2 = rand();

    printf("Numeros aleatorios: \n%d \n%d\n", n1, n2);
    return 0;
}