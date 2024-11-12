#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // pour PATH_MAX
#include <assert.h>
#include <libgen.h>
#include <unistd.h>
#include "Union_Find.h"

int*  new_connexe(graph_t g);
graph_t* read_graph(char*file);

int main(){
    char file[100];
     printf("Quelle fichier ? \n");
     scanf("%s",file);
    graph_t*g=NULL;
    
    g =read_graph(file);
    int*  u=new_connexe(*g);
    printf("[");
    for(int i=0;i<g->num_vertex;i++){
        printf(" %d",u[i]);

    }
    printf("]");
    
    free(g->data);
    free (g);


    return 0;
}