#include <stdio.h>

int main() {
    int a = 5;
    int b = 2;

    double pontos = (double)a / (double)b;
    printf("Result of casting: %f\n", pontos);

    double pi = 3.14159;
    int inteiro = (int)pi;
    printf("Value of inteiro after casting: %d\n", inteiro);

    return 0;
}