#include "lista.h"
#include "pq_heap.h"


//Dados
typedef struct {
    No **L; //Lista de adjacências
    int n;
} Grafo;


//Funções
Grafo* criar_digrafo(int n);
void destruir_digrafo(Grafo *p);

void inserir_arco(Grafo *p, int u, int v, int w);
void remover_arco(Grafo *p, int u, int v);

int tem_arco(Grafo *p, int u, int v);
void imprimir_arcos(Grafo *g);

int* dijkstra(Grafo *p, int u);
Grafo* boreliTransform(Grafo *p, int u);

void imprimir_caminho(Grafo *G,int *pai,int i);



