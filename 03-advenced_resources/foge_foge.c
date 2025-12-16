#include <stdio.h>
#include <stdlib.h>
#include "foge_foge.h"
#include "mapa.h"

MAPA mapa;

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
    leMapa(&mapa);

    do
    {
        imprimeMapa(&mapa);
        char comando;
        printf("Digite o comando (w/a/s/d): ");
        scanf(" %c", &comando);

        move(comando);

    } while (!acabou());

    liberaMapa(&mapa);

    return 0;
}