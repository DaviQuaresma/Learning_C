#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct foge_foge
{
char **mapa;
int linhas;
int colunas;
};

typedef struct foge_foge MAPA;

struct posicao
{
    int x;
    int y;
};

typedef struct posicao POSICAO;

void liberaMapa(MAPA* mapa);
void alocaMapa(MAPA* mapa);
void leMapa(MAPA* mapa);
void imprimeMapa(MAPA* mapa);
void encontraMapa(MAPA* mapa, POSICAO* pos, char alvo);
void andaNoMapa(MAPA* mapa, int xorigem, int yorigem, int xdestino, int ydestino);