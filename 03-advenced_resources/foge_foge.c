#include <stdio.h>
#include <stdlib.h>
#include "foge_foge.h"
#include "mapa.h"

MAPA mapa;
POSICAO heroi;

int acabou()
{
    return 0;
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

    if (novo_x >= mapa.linhas) return;
    
    if (novo_y >= mapa.colunas) return;

    if (mapa.mapa[novo_x][novo_y] != VAZIO) return;

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

    } while (!acabou());

    liberaMapa(&mapa);

    return 0;
}