//TAD FUNÇÕES

typedef struct no No;

struct no{
	int valor;
	int peso;
	No *prox;
};

No* criar_lista();

void imprimir_lista(No *q);
void insere_final(No **p, int x);
void insere_inicio(No **p, int x, int w);

void remove_final(No **p);
void remove_inicio(No **p);
void remove_valor(No **p, int x);


void libera_lista(No** p);


