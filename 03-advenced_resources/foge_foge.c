#include <stdio.h>
#include <stdlib.h>
#include "foge_foge.h"

MAPA mapa;

void liberaMapa()
{
    for (int i = 0; i < mapa.linhas; i++)
    {
        free(mapa.mapa[i]);
    }
    free(mapa.mapa);
}

void alocaMapa()
{
    ////////////
    // alocação dinâmica de matriz 5 x 10
    // com dois ** você está alocando uma matriz, então você precisa colocar tambem dentro do sizeof o tamanho do tipo que você quer alocar, nesse caso é int*
    // malloc serve para alocar memória em tempo de execução na unha e não deixar para a linguagem decidir de acordo com o escopo
    mapa.mapa = malloc(sizeof(char *) * mapa.linhas); // aloca as linhas
    for (int i = 0; i < mapa.linhas; i++)
    {
        mapa.mapa[i] = malloc(sizeof(char) * (mapa.colunas + 1));
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

    fscanf(file, "%d %d", &mapa.linhas, &mapa.colunas);

    alocaMapa();

    for (int i = 0; i < mapa.linhas; i++)
    {
        fscanf(file, "%s", mapa.mapa[i]);
    }

    fclose(file);
}

void imprimeMapa()
{
    for (int i = 0; i < mapa.linhas; i++)
    {
        printf("%s\n", mapa.mapa[i]);
    }
}

int acabou()
{
    return 0;
}

void move(char direcao)
{

    if (direcao != 'a' && direcao != 's' && direcao != 'w' && direcao != 'd')
    {
        printf("Comando inválido!\n");
        return;
    }


    int x;
    int y;

    for (int i = 0; i < mapa.linhas; i++)
    {
        for (int j = 0; j < mapa.colunas; j++)
        {
            if (mapa.mapa[i][j] == '@')
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direcao)
    {
    case 'a':
        mapa.mapa[x][y - 1] = '@';
        break;
    case 'w':
        mapa.mapa[x - 1][y] = '@';
        break;
    case 's':
        mapa.mapa[x + 1][y] = '@';
        break;
    case 'd':
        mapa.mapa[x][y + 1] = '@';
        break;
    }

    mapa.mapa[x][y] = '.';
}

int main()
{
    leMapa();

    do
    {
        imprimeMapa();

        char comando;
        printf("Digite o comando (w/a/s/d): ");
        scanf(" %c", &comando);

        move(comando);

    } while (!acabou());

    liberaMapa();

    return 0;
}