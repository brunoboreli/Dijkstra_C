#include <stdio.h>
#include <stdlib.h>
#include "digrafolista.h"

//definindo 'infinito'
#define INT_MAX   (2147483647)


void inserir_arco(Grafo *p, int u, int v, int w) {
    insere_inicio(&p->L[u], v, w);
}

void remover_arco(Grafo *p, int u, int v) {
    remove_valor(&p->L[u], v);
}

void imprimir_arcos(Grafo *p) {
    int u;
    for (u = 0; u < p->n; u++){
        printf("%d: ", u+1); //imprime como um char
        imprimir_lista(p->L[u]);
        printf("\n");
    }
}

Grafo* criar_digrafo(int n) {
    int i;
    Grafo *g = (Grafo*) malloc(sizeof(Grafo));
    g->n = n;
    g->L = (No**) malloc(n * sizeof(No*));

    for (i = 0; i < n; i++){
        g->L[i] = criar_lista();
    }

    return g;
}

void destruir_digrafo(Grafo *g) {
    int i;

    for (i = 0; i < g->n; i++){
        libera_lista(&g->L[i]);
    }

    free(g->L);
    free(g);
}


//implementando algoritmo
int* dijkstra(Grafo *p, int u){
    int *pai = (int*) malloc(p->n * sizeof(int));
    PQ *Fila = pq_criar(p->n);
    int v;

    for(v = 0; v < p->n; v++){
        pai[v]=-1;
        pq_adicionar(Fila,v,INT_MAX);
    }

    pai[u] = u;
    muda_prioridade(Fila,u,0);

    while(!pq_vazia(Fila)){
        t_item aux = pq_extrai_min(Fila);

       

        int v = aux.vertice_idx;
        int dist_v = prioridade(Fila,v);

        if(dist_v == INT_MAX){
            break;
            
        }
       

        No* t;
        for(t = p->L[v]; t!=NULL; t = t->prox){

            int w = t -> valor;
            int peso = t -> peso;

            if(dist_v + peso < prioridade(Fila,w)){
                muda_prioridade(Fila, w, dist_v+peso);
                
                pai[w] = v;
            }
        }
    }

    int custo = extraiCusto(Fila,p->n-1);
    if(custo != INT_MAX){
        printf("%d\n", custo);
    }
    else{
        printf("-1\n");
    }
    

    pq_destruir(&Fila);

    return pai;
}

Grafo* boreliTransform(Grafo *p, int tam){

    Grafo *new = criar_digrafo(tam);


    for(int i=0; i<tam; i++){

        int peso1,v1,peso2,v2;
        No* aux;
        for(aux = p->L[i]; aux != NULL; aux = aux->prox){
            peso1 = aux->peso;
            v1 = aux->valor;

            No* s;
            for(s = p->L[v1]; s!=NULL; s = s->prox){
                
                peso2 = s->peso;
                v2 = s->valor;
                //printf("%d %d\n", v1,v2);
                if(v2 != i){
                    
                    inserir_arco(new, i, v2, peso1+peso2);
                    //inserir_arco(new, v2, v1, peso1+peso2);
                }

            }

        }


        
    
    }

    return new;
}


void imprimir_caminho(Grafo *G,int *pai,int i){
    

    int aux;//,somaCusto = 0;
    printf("%d ", i+1);

    aux = pai[i];


    while(aux != 0){
        
        printf("%d ", aux+1);
        aux = pai[aux];


    }

    printf("%d\n", aux+1);

   // printf("Custo: %d\n", somaCusto);
}