#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "graph.h"
#include <time.h> 

graph_t * read_graph(char *);
list_edge_t Prim(graph_t g);


int main (){
  char fi[100];
  int cl;
  graph_t *g=NULL;
  printf("Quelle fichier ? \n");
  scanf("%s",fi);
  g= read_graph(fi);
  cl=clock();
  list_edge_t l = Prim(*g);
  cl = clock()-cl;

    
    //list_edge_print(l);
  printf("Temps mesure en secondes: %lf\n",cl/(double)CLOCKS_PER_SEC);
return 0;
    

}
