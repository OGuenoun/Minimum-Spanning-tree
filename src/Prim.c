#define COST_MAX 1000000
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
int atraiter_est_vide(int * atraiter, int n){
    for(int i=0;i<n;i++){
        if(atraiter[i]==1){
            return 0;
        }
    }
    return 1;
}
int min_cost_atraiter(int *atraiter,double *cost, int n) {
    double min = COST_MAX;
    int i_min = -1;
    for (int i = 0; i < n; i++) {
        if (atraiter[i] && cost[i] < min) {
            min = cost[i];
            i_min = i;
        }
    }
    return i_min;
}



list_edge_t Prim(graph_t graph){
   int n = graph.num_vertex;
    edge_t *previous_edge = (edge_t *)calloc(n, sizeof(edge_t));
    double *cost = (double *)calloc(n, sizeof(double));
    int *atraiter = (int *)calloc(n, sizeof(int));
    int *atteint = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        previous_edge[i].id_departure = -1;
        cost[i] = COST_MAX;
    }
    
    vertex_t depart = sommet_départ(graph);
    int depart_i = indice(depart, graph);
    cost[depart_i] = 0;
    atraiter[depart_i] = 1;
    
    while (!atraiter_est_vide( atraiter,  n)) {
        int u = min_cost_atraiter( atraiter, cost, n);
        atraiter[u] = 0;
        atteint[u] = 1;
        
        vertex_t u_vertex = graph.data[u];
        
        for (list_edge_t p = u_vertex.edges; p != NULL; p = p->next) {
            int v = p->val.id_arrival;
            if (!atteint[v] && p->val.cost < cost[v]) {
                cost[v] = p->val.cost;
                previous_edge[v] = p->val;
                atraiter[v] = 1;
            }
        }
    }
    
    list_edge_t acm = list_edge_new();
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        if (previous_edge[i].id_departure != -1) {
            acm = list_edge_add_first(acm, previous_edge[i]);
            total_cost += cost[i];
        }
    }
    
    printf("Coût total de l'acm %d\n", total_cost);

    free(previous_edge);
    free(cost);
    free(atraiter);
    free(atteint);

    return acm;
}