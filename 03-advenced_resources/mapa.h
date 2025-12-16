struct foge_foge
{
char **mapa;
int linhas;
int colunas;
};

typedef struct foge_foge MAPA;

void liberaMapa(MAPA* mapa);
void alocaMapa(MAPA* mapa);
void leMapa(MAPA* mapa);
void imprimeMapa(MAPA* mapa);