#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // pour PATH_MAX
#include <assert.h>
#include <libgen.h>

#include <unistd.h>
#include "Union_Find.h"
#include <time.h> 

graph_t * read_graph(char *);
list_edge_t Kruskal(graph_t g);


int main (){
    char fi[100];
  int cl;
   printf("Quelle fichier ? \n");
   scanf("%s",fi);
  
    graph_t *g=NULL;
    g= read_graph(fi);
    cl=clock();
    list_edge_t l = Kruskal(*g);
    cl = clock()-cl;

    
    //list_edge_print(l);
    printf("Temps mesure en secondes: %lf\n",cl/(double)CLOCKS_PER_SEC);
    return 0;
    

}


