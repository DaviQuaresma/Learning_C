void liberaMapa();
void alocaMapa();
void leMapa();
void imprimeMapa();
int acabou();
void move(char direcao);

struct foge_foge
{
char **mapa;
int linhas;
int colunas;
};

typedef struct foge_foge MAPA;