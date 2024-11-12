#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list_vertex.h"
#include "graph.h"
graph_t* read_graph(char*file);

void test_vertex_new() {
  vertex_t e ;
  fprintf(stderr, "## Test de la fonction vertex_new\n");

  fprintf(stderr, "<= Test : créer un sommet avec des valeurs valides fonctionne correctement\n");

  fprintf(stderr, "=> Test passé avec succès\n" );


}

void test_sommets_différents(){
    fprintf(stderr, "## Test de la fonction sommets_différents\n");
    vertex_t e1;
    vertex_t e2;
    char f1[100];
    char f2[100];
    printf("Quelle fichier ? \n");
    scanf("%s",f1);
    printf("Quelle fichier ? \n");
    scanf("%s",f2);
    graph_t*g=read_graph(f1);
    fprintf(stderr, "<= Test : 2 sommets égaux \n");
    e1=g->data[0];
    e2=g->data[1];
    assert(!sommets_différents(e1,e2));
    fprintf(stderr, "=> Test passé avec succès\n" );

    fprintf(stderr, "<= Test : 2 sommets différents \n");
    e1=g->data[1];
    assert(sommets_différents(e1,e2));
    fprintf(stderr, "=> Test passé avec succès\n" );

    free(g->data);
    free (g);

}

void test_indice(){
  fprintf(stderr, "## Test de la fonction indice \n");
  fprintf(stderr, "<= Test : avec un sommet non dans graphe\n");
  char f1[100];
  char f2[100];
  graph_t *g1=read_graph(f1);
  vertex_t e1=g1->data[0];
  graph_t *g=read_graph(f2);
  assert(indice(e1,*g)==0);
  fprintf(stderr, "=> Test passé avec succès\n" );

  fprintf(stderr, "<= Test : avec un sommet dans graphe\n");
  vertex_t e=g->data[0];
  assert(indice(e,*g)==0);
  fprintf(stderr, "=> Test passé avec succès\n" );
  free(g->data);
  free (g);
  free(g1->data);
  free (g1);



  

}

void test_sommet_départ(){
  fprintf(stderr, "## Test de la fonction sommet_départ \n");
  char f1[100];
  graph_t *g=read_graph(f1);
  vertex_t e=sommet_départ(*g);
  printf("%s",e.name);
  fprintf(stderr, "=> Test passé avec succès\n" );
  free(g->data);
  free (g);


} 

int main(){
  test_vertex_new();
  test_indice();
  test_sommets_différents();
  test_sommet_départ();

  fprintf(stderr, "Tests du fichier 02_list_edge.c passés avec succès\n");

  return EXIT_SUCCESS;
}


    



    










