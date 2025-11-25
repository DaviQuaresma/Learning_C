#include <stdio.h>

int main() {

    int secret = 7;
    
    printf("Chuta um numero!\n");
    int num;
    scanf("%d", &num);

    if (!num)
    {
        printf("Você digitou zero ou nada!\n");
        return 1;
    }

    if (num == secret)
    {
        printf("Parabéns! Você acertou o número secreto.\n");
    } else if (num < secret) {
        printf("Tente um número maior!\n");
    } else {
        printf("Tente um número menor!\n");
    }
    
    return 0;
}