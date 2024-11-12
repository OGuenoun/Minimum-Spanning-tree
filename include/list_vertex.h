#ifndef _LISTVERTEX_H
#define _LISTVERTEX_H
#include "vertex.h"

typedef struct _link_vertex {
  vertex_t val; 
  struct _link_vertex*next; 
} * list_vertex_t;


list_vertex_t list_vertex_new();
int list_vertex_is_empty(list_vertex_t l);
list_vertex_t list_vertex_add_first( list_vertex_t l,vertex_t e);
list_vertex_t list_vertex_del_first( list_vertex_t l );
list_vertex_t list_vertex_add_last(list_vertex_t l,vertex_t e);

//Retourne 1 si un sommet n'appartient pas à la liste
int non_dans_liste(list_vertex_t l,vertex_t e);

// Retourne le nombre d'éléments de la liste l
int list_vertex_length(list_vertex_t l);


#endif