#include <stdio.h>
#define MAX_ATTEMPTS 3

int main() {

    int secret = 7;
    
    for (int i = 0; i < MAX_ATTEMPTS; i++)
    {
        printf("Tentativa %d de 3\n", i + 1);

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
            break;
        } else if (num < secret) {
            printf("Tente um número maior!\n");
        } else {
            printf("Tente um número menor!\n");
        }
    }
    
    return 0;
}