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
list_edge_t fusionner( list_edge_t l1, list_edge_t l2);

// on teste juste le fusionnement des 2 listes 
int main(){
    char f1[100],f2[100];
    graph_t*g1=NULL,*g2=NULL;
    printf("Quelle fichier ? \n");
    scanf("%s",f1);
    printf("Quelle fichier ? \n");
    scanf("%s",f2);
    g1=read_graph(f1);
    g2=read_graph(f2);
    list_edge_t l1=prendre_edge(*g1),l2=prendre_edge(*g2);
    assert(!list_edge_is_empty(l1));
    assert(!list_edge_is_empty(l2));

    printf("voici ta liste de tous les arretes de liste 1: \n");
    list_edge_print(l1);
    printf("voici ta liste de tous les arretes de liste 2: \n");
    list_edge_print(l2);

    list_edge_t l=fusionner(l1,l2);
    printf("voici le résultat de la fusion en ordre croissant du cout des arretes :\n");
    list_edge_print(l);


   
    
    free(g1->data);
    free(g2->data);
    free(g1);
    free(g2);


    return 0;
}
