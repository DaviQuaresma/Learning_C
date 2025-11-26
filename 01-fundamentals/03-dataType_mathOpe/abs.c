#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = abs(10);
    int b = abs(-10);

    // a receberá o valor 10, que é o valor absoluto de -10.
    // b também receberá o valor 10, pois o valor absoluto de 10 já é 10.
    
    // A função abs() é útil em diversas situações onde você precisa trabalhar com a magnitude de um número, 
    // ignorando seu sinal. No caso do jogo de adivinhação, isso garante que o jogador sempre perca pontos, e 
    // não ganhe, caso chute um número menor que o número secreto.
    
    printf("Valor absoluto de 10: %d\n", a);
    printf("Valor absoluto de -10: %d\n", b);
}