#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"
list_edge_t Prim(graph_t graph);
graph_t * read_graph(char*);
int main(){
    char f1[100];
    printf("Quelle fichier ? \n");
     scanf("%s",f1);
    graph_t*g0=read_graph(f1);
    list_edge_t acm0=Prim(*g0);
    list_edge_print(acm0);
    
    

    return 0;
}