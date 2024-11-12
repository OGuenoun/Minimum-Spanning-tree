#include"vertex.h"
#include"graph.h"


int* new_connexe(graph_t g );

int recherche_representant(int i,int*  tab );

void fusion(int a, int b, int* tab);
//sert à prendre tous les arcs du graphe g pour les classer ensuite en fct de leur cout
list_edge_t prendre_edge(graph_t g);
//fusionner en tenant compte l'ordre croissant des couts des arcs deux ensembles d'arcs
list_edge_t fusionner(list_edge_t l1, list_edge_t l2);
//un tri très connu
list_edge_t tri_fusion_edge(list_edge_t *l);


