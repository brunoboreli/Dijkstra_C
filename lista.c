#include <stdlib.h>
#include <stdio.h>
#include "lista.h"



No* criar_lista(){
	return NULL;
}


void imprimir_lista(No *q){
	while(q != NULL){
		printf("%d peso(%d)", (q->valor)+1, q->peso);
		if(q->prox!=NULL) printf(" -> ");
		q = q->prox;
	}
	printf("\n");


}

void insere_final(No **p, int x){

	No *aux, *q;

	q = (No*) malloc(sizeof(No));
	q -> valor = x;
	q -> prox = NULL;

	if(*p == NULL){
		*p = q;
	}
	else{
	   aux = *p;
	   while(aux->prox != NULL){
                aux = aux->prox;
           }
	   aux -> prox = q;
	}
}

void insere_inicio(No **p, int x, int w){

	No *q;
	q = (No*) malloc(sizeof(No));
	q -> valor = x;
	q -> peso  = w;
    q -> prox = *p;
	*p = q;
}


void remove_final(No **p){
	No  *q = *p;

	if(q == NULL) return;
	if(q->prox == NULL){
		*p = NULL;
		free(q);
		return;
	}
	
	while(q -> prox -> prox != NULL){
		q = q->prox;
	}
	free(q->prox);
	q -> prox = NULL;
}

void remove_inicio(No **p){
	No *q = *p;
	
	if(*p == NULL)return;


	*p = q->prox;
	free(q);
}

void remove_valor(No **p, int x){
	No *q, *tmp;
	q = *p;

	if(*p == NULL) return;
	if(q->valor == x){
		*p = q->prox;
		free(q);
		return;
	}

	while(q->prox != NULL){
		if(q->prox->valor == x)break;
		q = q->prox;
	}
	if(q->prox==NULL)return;
	tmp = q->prox;
	q->prox = tmp ->prox;
	free(tmp);
}

void libera_lista(No** p){
	No *q;
	while(*p != NULL){
		q = *p;
		*p = (*p) ->prox;
		free(q);
	}

}


