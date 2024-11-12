#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // pour PATH_MAX
#include <assert.h>
#include <libgen.h>
#include <unistd.h>
#include "Union_Find.h"


graph_t* read_graph(char*file);
list_edge_t tri_fusion_edge(list_edge_t*l);
list_edge_t prendre_edge(graph_t g);

int main(){
    char file[100];
    graph_t*g=NULL;
     printf("Quelle fichier ? \n");
     scanf("%s",file);
    
    g =read_graph(file);
    list_edge_t l = prendre_edge(*g);
    list_edge_t t =tri_fusion_edge(&l);
    printf("voici votre liste triée en ordre croissant d'arretes:\n");
    list_edge_print(t);
    free(g->data);
    free (g);


    return 0;
}
