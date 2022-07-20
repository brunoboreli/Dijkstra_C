#include <stdio.h>
#include <stdlib.h>
#include "pq_heap.h"


//definição de macros para navegar na heap
#define F_ESQ(i) (2*i+1) 
#define F_DIR(i) (2*i+2) 
#define PAI(i) ((i-1)/2)


//implementações
PQ* pq_criar(int tam){

    PQ* p = (PQ*) malloc(sizeof(PQ));

    p->dados = (t_item*) malloc(tam * sizeof(t_item));
    p->track_vtx = (int*) malloc(tam * sizeof(int));

    for(int i=0; i<tam; i++){
        p->track_vtx[i] = -1;
    }

    p->n = 0;
    p->tam = tam;

 return p;
}

int pq_vazia(PQ *p) {
  return p->n == 0;
} 

void pq_destruir(PQ **p) {
    free((*p)->dados);
    free(*p);
    *p = NULL;
}

void swap(t_item *a, t_item *b){
    t_item aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


void sobe_no_heap(PQ *p, int pos) {
    if (pos > 0 && p->dados[PAI(pos)].chave > p->dados[pos].chave) {

        //indices para rastrear a posicao dos elementos na heap
        //track_idx é atualizado a cada swap
        p->track_vtx[p->dados[pos].vertice_idx] = PAI(pos);
        p->track_vtx[p->dados[PAI(pos)].vertice_idx] = pos;

        swap(&p->dados[pos], &p->dados[PAI(pos)]);
        sobe_no_heap(p, PAI(pos));
    }
}


void desce_no_heap(PQ *p, int pos){
    if(F_ESQ(pos) < p->n){
        int menor_filho = F_ESQ(pos);
        
        if(F_DIR(pos) < p->n && p->dados[F_ESQ(pos)].chave > p->dados[F_DIR(pos)].chave){
            menor_filho = F_DIR(pos);
        }
        
        if(p->dados[pos].chave > p->dados[menor_filho].chave){

            //indices para rastrear a posicao dos elementos na heap
            //track_idx é atualizado a cada swap
            p->track_vtx[p->dados[pos].vertice_idx] = menor_filho;
            p->track_vtx[p->dados[menor_filho].vertice_idx] = pos;
                

            swap(&p->dados[pos], &p->dados[menor_filho]);
            desce_no_heap(p, menor_filho);
        }
    }
}

void muda_prioridade(PQ *p, int vertice, int newDist){
    //printf("%d\n", vertice);
    int idx = p->track_vtx[vertice];
    p->dados[idx].chave = newDist;
    
    sobe_no_heap(p,idx);
}


void pq_adicionar(PQ *p,int v,int distI){
    
    t_item item;
    
    //chave recebe distI pois o que sera usado para
    //a ordenacao da heap de minimo sera a distancia distI

    //vertice recebe v para sinalizar qual o valor contido 
    //no determinado vertice
    item.chave = distI;
    item.vertice_idx = v;

    //inicializando vetor de indices para
    //rastrear posição do elemento na heap
    //esse vetor será atualizado a cada swap
    p->track_vtx[v] = p->n;

    p->dados[p->n] = item;
    p->n++;

    sobe_no_heap(p,p->n-1);
}
 
int prioridade(PQ *p, int v){

    int idx = p->track_vtx[v];
    //printf("%d %d\n", v, idx);


    return (p->dados[idx].chave);
}


t_item pq_extrai_min(PQ *p) {

    t_item item = p->dados[0];

    p->track_vtx[p->dados[0].vertice_idx] = p->n-1;
    p->track_vtx[p->dados[p->n-1].vertice_idx] = 0;




    swap(&p->dados[0], &p->dados[p->n-1]);
    p->n--;



    desce_no_heap(p, 0);
  return item;
}


int extraiCusto(PQ *p,int t){
    int a = p->track_vtx[t];

    int custo = p->dados[a].chave;

    return custo;
}