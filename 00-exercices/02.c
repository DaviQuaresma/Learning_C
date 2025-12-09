#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lê uma palavra do stdin, retorna um buffer alocado com a palavra.
// O chamador é responsável por chamar free() no ponteiro retornado.
char *chooseWord(void)
{
    char *word = malloc(100);
    if (word == NULL) {
        fprintf(stderr, "Erro ao alocar memoria\n");
        return NULL;
    }

    printf("Digite uma palavra:\n");
    if (fgets(word, 100, stdin) == NULL)
    {
        free(word);
        return NULL;
    }

    // Remove o '\n' que fgets inclui no final
    size_t len = strlen(word);
    if (len > 0 && word[len - 1] == '\n') {
        word[len - 1] = '\0';
    }

    return word;
}

int verifyVowal(char *word)
{
    char vogals[] = "aeiouAEIOU";
    int vogalQtd = 0;

    // Percorre cada caractere da palavra
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = word[i];
        
        // strchr procura UM caractere na string de vogais
        if (strchr(vogals, c) != NULL)
        {
            vogalQtd++;
        }
    }
    
    return vogalQtd;
}

void changeToUpper(char *word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = word[i];

        if (c >= 'a' && c <= 'z')
        {
            // Converte minuscula para maiuscula
            word[i] = c - ('a' - 'A');
            // Ou pode usar: word[i] = c - 32;
        }
    }
}

int main(void)
{
    char *word = chooseWord();
    if (word == NULL)
    {
        printf("Nenhuma palavra lida.\n");
        return 1;
    }

    int vogalQtd = verifyVowal(word);
    printf("\nTotal de vogais: %d\n", vogalQtd);

    changeToUpper(word);  // Modifica a palavra diretamente
    printf("Palavra em maiusculo: %s\n", word);

    free(word);
    return 0;
}