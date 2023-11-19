typedef struct lista lista;
typedef struct fila fila;

fila* criaFila();
void insere(fila *fila, int senha);
float removee(fila *fila);
int filaVazia(fila* fila);
void imprime(fila *fila);