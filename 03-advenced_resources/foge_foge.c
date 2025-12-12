#include <stdio.h>
#include <stdlib.h>
#include "foge_foge.h"

char **mapa;
int linhas;
int colunas;

void liberaMapa()
{
    for (int i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    free(mapa);
}

void alocaMapa()
{
    ////////////
    // alocação dinâmica de matriz 5 x 10
    // com dois ** você está alocando uma matriz, então você precisa colocar tambem dentro do sizeof o tamanho do tipo que você quer alocar, nesse caso é int*
    // malloc serve para alocar memória em tempo de execução na unha e não deixar para a linguagem decidir de acordo com o escopo
    mapa = malloc(sizeof(char *) * linhas); // aloca as linhas
    for (int i = 0; i < linhas; i++)
    {
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }
    ////////////
}

void leMapa()
{
    FILE *file;
    file = fopen("mapa2.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fscanf(file, "%d %d", &linhas, &colunas);

    alocaMapa();

    for (int i = 0; i < linhas; i++)
    {
        fscanf(file, "%s", mapa[i]);
    }

    fclose(file);
}

int main()
{

    leMapa();

    for (int i = 0; i < linhas; i++)
    {
        printf("%s\n", mapa[i]);
    }

    liberaMapa();

    return 0;
}