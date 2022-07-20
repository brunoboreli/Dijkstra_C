#include <stdio.h>
#include <stdlib.h>
#include "digrafolista.h"



int main() {
    int n, m, i, u, v, w;
    scanf("%d %d", &n, &m);

    Grafo *G = criar_digrafo(n);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
        inserir_arco(G, u, v, w);
        //inserindo 2x pela bidirecionalidade da estrada
        inserir_arco(G, v, u, w);
    }

    G = boreliTransform(G,n);

    //imprimir_arcos(G);

    int *pai = dijkstra(G, 0);

    free(pai);
    destruir_digrafo(G);
return 0;
}