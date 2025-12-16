#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void andaNoMapa(MAPA* mapa, int xorigem, int yorigem, int xdestino, int ydestino)
{
    char personagem = mapa->mapa[xorigem][yorigem];
    mapa->mapa[xdestino][ydestino] = personagem;
    mapa->mapa[xorigem][yorigem] = VAZIO;
}

void encontraMapa(MAPA* mapa, POSICAO* pos, char alvo)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        for (int j = 0; j < mapa->colunas; j++)
        {
            if (mapa->mapa[i][j] == alvo)
            {
                pos->x = i;
                pos->y = j;
                return;
            }
        }
    }
}

void liberaMapa(MAPA* mapa)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        free(mapa->mapa[i]);
    }
    free(mapa->mapa);
}

void alocaMapa(MAPA* mapa)
{
    ////////////
    // alocação dinâmica de matriz 5 x 10
    // com dois ** você está alocando uma matriz, então você precisa colocar tambem dentro do sizeof o tamanho do tipo que você quer alocar, nesse caso é int*
    // malloc serve para alocar memória em tempo de execução na unha e não deixar para a linguagem decidir de acordo com o escopo
    mapa->mapa = malloc(sizeof(char *) * mapa->linhas); // aloca as linhas
    for (int i = 0; i < mapa->linhas; i++)
    {
        mapa->mapa[i] = malloc(sizeof(char) * (mapa->colunas + 1));
    }
    ////////////
}

void leMapa(MAPA* mapa)
{
    FILE *file;
    file = fopen("mapa2.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }

    fscanf(file, "%d %d", &mapa->linhas, &mapa->colunas);

    alocaMapa(mapa);

    for (int i = 0; i < mapa->linhas; i++)
    {
        fscanf(file, "%s", mapa->mapa[i]);
    }

    fclose(file);
}

void imprimeMapa(MAPA* mapa)
{
    for (int i = 0; i < mapa->linhas; i++)
    {
        printf("%s\n", mapa->mapa[i]);
    }
}