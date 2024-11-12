#ifndef _GRAPH_H
#define _GRAPH_H
#include "list_vertex.h"
typedef struct {
    int num_vertex;
    int num_arc;
    vertex_t * data;
} graph_t;

void print_graph(graph_t g);

//Retourne l'indice d'un sommet e dans un graphe et -1 s'il n'appartient pas
int indice(vertex_t e, graph_t g);

//Retourne le sommet de départ de plus faible cout pour l'algo Prim
vertex_t sommet_départ(graph_t g);

list_vertex_t orderedlist_vertex_add(list_vertex_t l,vertex_t e, double * cost,graph_t g);

#endif

