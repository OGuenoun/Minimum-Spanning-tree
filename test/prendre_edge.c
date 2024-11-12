#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // pour PATH_MAX
#include <assert.h>
#include <libgen.h>
#include <unistd.h>
#include "Union_Find.h"


graph_t* read_graph(char*file);
list_edge_t prendre_edge(graph_t g);
void list_edge_print(list_edge_t l);

int main(){
    char file[100];
    graph_t*g=NULL;
     printf("Quelle fichier ? \n");
     scanf("%s",file);
    
    g =read_graph(file);
    list_edge_t l=prendre_edge(*g);
    printf("voici ta liste de tous les arretes : \n");
    list_edge_print(l);
   
    
    free(g->data);
    free (g);


    return 0;
}