

//structs
typedef struct {
    int chave;
    int vertice_idx; 
} t_item;

typedef struct{
    t_item *dados;
    int *track_vtx;
    int tam, n;
} PQ;

//Funções
PQ* pq_criar(int tam);
void pq_destruir(PQ **p);

void pq_adicionar(PQ *p, int v, int distI);

t_item pq_extrai_min(PQ *p);
int prioridade(PQ *p, int v);
void muda_prioridade(PQ *p, int vertice, int newDist);
void swap(t_item *a, t_item *b);

int pq_vazia(PQ* p);

int extraiCusto(PQ *p,int t);