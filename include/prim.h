#include "graph.h"


//retourne 1 si le tableau atraiter est vide
int atraiter_est_vide(int * atraiter, int n);

//retourne l'indice de l'élément de plus faible coût
int min_cost_atraiter(int *atraiter,double *cost, int n);

//retourne la liste des arêtes formant l'acm par l'algo Prim
list_edge_t Prim(graph_t graph);