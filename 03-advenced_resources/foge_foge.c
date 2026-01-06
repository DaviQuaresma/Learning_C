#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "foge_foge.h"
#include "mapa.h"

MAPA mapa;
POSICAO heroi;


int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino)
{
    int opcoes[4][2] = {
        {xatual - 1, yatual}, // CIMA
        {xatual + 1, yatual}, // BAIXO
        {xatual, yatual - 1}, // ESQUERDA
        {xatual, yatual + 1}  // DIREITA
    };

    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        int posicao = rand() % 4;

        if (podeandar(&mapa, opcoes[posicao][0], opcoes[posicao][1]))
        {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
        
    }
}

void fantasmas()
{
    MAPA copia;
    copiamapa(&copia, &mapa);

    for (int i = 0; i < mapa.linhas; i++)
    {
        for (int j = 0; j < mapa.colunas; j++)
        {
            if (copia.mapa[i][j] == FANTASMA){

                int xdestino;
                int ydestino;

                int encontrou = praondefantasmavai(i, j, &xdestino, &ydestino);

                if (encontrou)
                {
                    andaNoMapa(&mapa, i, j, xdestino, ydestino);
                }
                
            }
        }
    }

    liberaMapa(&copia);
}

int acabou()
{
    POSICAO pos;
    int fogefogenomapa = encontraMapa(&mapa, &pos, HEROI);
    return !fogefogenomapa;
}

void move(char direcao)
{
    direcao = tolower(direcao);

    if (direcao != ESQUERDA && direcao != CIMA && direcao != BAIXO && direcao != DIREITA)
        return;

    int novo_x = heroi.x;
    int novo_y = heroi.y;

    switch (direcao)
    {
    case ESQUERDA:
        novo_y--;
        break;
    case CIMA:
        novo_x--;
        break;
    case BAIXO:
        novo_x++;
        break;
    case DIREITA:
        novo_y++;
        break;
    }

    if (!podeandar(&mapa, novo_x, novo_y)) return;
    
    andaNoMapa(&mapa, heroi.x, heroi.y, novo_x, novo_y);

    heroi.x = novo_x;
    heroi.y = novo_y;
}

int main()
{
    leMapa(&mapa);
    encontraMapa(&mapa, &heroi, HEROI);

    do
    {
        imprimeMapa(&mapa);
        char comando;
        printf("Digite o comando (w/a/s/d): ");
        scanf(" %c", &comando);

        move(comando);
        fantasmas();

    } while (!acabou());

    liberaMapa(&mapa);

    return 0;
}