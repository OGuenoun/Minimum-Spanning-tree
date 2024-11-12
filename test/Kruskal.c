#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // pour PATH_MAX
#include <assert.h>
#include <libgen.h>

#include <unistd.h>
#include "Union_Find.h"

graph_t * read_graph(char *);
list_edge_t Kruskal(graph_t g);


int main (){
    char fi[100];
     printf("Quelle fichier ? \n");
     scanf("%s",fi);
  
    graph_t *g=NULL;
    g= read_graph(fi);
    
    list_edge_t f = Kruskal(*g);
    
    //list_edge_print(f);
    return 0;
    

}
