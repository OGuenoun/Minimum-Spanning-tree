#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <vertex.h>
#include <list_vertex.h>
#include "graph.h"

graph_t * read_graph(char*);

void test_list_vertex_basic() {
  list_vertex_t l;
  vertex_t e;
  fprintf(stderr, "## Test des fonctions basiques du module list_vertex\n");

  fprintf(stderr, "<= Test : une liste est bien vide après sa création\n");
  l = list_vertex_new();
  assert( list_vertex_is_empty(l) );
  assert( 0 == list_vertex_length(l) );
  fprintf(stderr, "=> Test passé avec succès\n" );

  fprintf(stderr, "<= Test : après ajout d'élément(s) dans une liste, le nombre d'élément est correct\n");
  e=vertex_new("A", 0.0, 0.0, NULL);
  l = list_vertex_add_first(l, e);
  assert( ! list_vertex_is_empty(l) );
  assert( 1 == list_vertex_length(l) );

  vertex_t e1 = vertex_new ("B", 1.0, 1.0, NULL);
  l = list_vertex_add_first(l, e1);
  assert( ! list_vertex_is_empty(l) );
  assert( 2 == list_vertex_length(l) );
  fprintf(stderr, "=> Test passé avec succès\n" );

}
void test_non_dans_liste() {
    vertex_t e;
    list_vertex_t l;
    char f1[100];
    printf("Quelle fichier ? \n");
    scanf("%s",f1);
    graph_t* g=read_graph(f1);
    fprintf(stderr, "## Test de la fonction non_dans_liste\n");
    
    fprintf(stderr, "<= Test : avec une liste vide\n");

    l= list_vertex_new();
    e=g->data[0];
    assert(non_dans_liste(l,e));
    fprintf(stderr, "=> Test passé avec succès\n" );

    fprintf(stderr, "<= Test : avec un élément qui appartient à la liste\n");
    vertex_t e2 = g->data[1];
    l=list_vertex_add_first(l,e2);
    assert(!non_dans_liste(l,e2));
    fprintf(stderr, "=> Test passé avec succès\n" );

    fprintf(stderr, "<= Test : avec un élément qui n'appartient pas à la liste\n");
    vertex_t e3 = vertex_new("C", 2.0, 2.0, NULL);
    assert(non_dans_liste(l,e3));
    fprintf(stderr, "=> Test passé avec succès\n" );

    free(g->data);
    free (g);
}
void test_list_vertex_add_last(){
  vertex_t e;
  e=vertex_new("A", 0.0, 0.0, NULL);
  fprintf(stderr, "## Test de la fonction list_vertex_add_last\n");
  list_vertex_t l;
  l= list_vertex_new();
  l=list_vertex_add_last(l,e );
  fprintf(stderr, "=> Test passé avec succès\n" );
  

}
void test_list_vertex_del_first(){
  list_vertex_t l;
  l= list_vertex_new();
  fprintf(stderr, "## Test de la fonction list_vertex_del_first\n");
  fprintf(stderr, "avec une list vide");
  l=list_vertex_del_first(l);
  fprintf(stderr, "=> Test passé avec succès\n" );

  fprintf(stderr, "avec une list non vide");
  vertex_t e1 = vertex_new ("B", 1.0, 1.0, NULL);
  l = list_vertex_add_first(l, e1);
  l=list_vertex_del_first(l);
  fprintf(stderr, "=> Test passé avec succès\n" );


}
   
int main(){
  test_list_vertex_basic();
  test_non_dans_liste();
  test_list_vertex_add_last();
  test_list_vertex_del_first();
  fprintf(stderr, "Tests du fichier 05_list_vertex.c passés avec succès\n");

  return EXIT_SUCCESS;
}



