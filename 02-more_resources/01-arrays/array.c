#include <stdio.h>

int main()
{
    int notas[5]; // Declara um array de inteiros com 5 elementos

    notas[0] = 85; // Grava o valor 85 na primeira posição do array
    notas[1] = 90; // Grava o valor 90 na segunda posição do array

    printf("%d", notas[0]); // Imprime o valor da primeira posição do array

    char palavrasecreta[20]; // Declara um array de caracteres com 20 elementos

    palavrasecreta[0] = 'M';
    palavrasecreta[1] = 'E';
    palavrasecreta[2] = 'L';

    int numero = 3;
    palavrasecreta[numero] = 'A';

    palavrasecreta[4] = 'N';
    palavrasecreta[5] = 'C';
    palavrasecreta[6] = 'I';
    palavrasecreta[7] = 'A';

    for (int i = 0; i < 8; i++)
    {
        printf("%c", palavrasecreta[i]);
    }

    sprintf(palavrasecreta, "MELANCIA"); // Grava a string "MELANCIA" no array de caracteres
    printf("\n%s\n", palavrasecreta); // Imprime a string armazenada no array de caracteres

    return 0;
}