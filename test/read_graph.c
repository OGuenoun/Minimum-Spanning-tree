#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // pour PATH_MAX
#include <assert.h>
#include <libgen.h>

#include <unistd.h>
#include "graph.h"

graph_t *read_graph(char* file);

    
int main (){
    char file[100];
    graph_t *g=NULL;
     printf("Quelle fichier ? \n");
     scanf("%s",file);
    g= read_graph(file);
    for(int i=0; i < g->num_vertex; i++){
        list_edge_print(g->data[i].edges);
    }
    free(g->data);
    
    free(g);
    
    return 0;
    

}


