#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vertex.h"
#include "list_vertex.h"
#include "graph.h"

//Retourne un sommet correctement formé
vertex_t vertex_new(char*name,double x,double y,list_edge_t l){
    vertex_t e;
    e.name=name;
    e.x=x;
    e.y=y;
    e.edges=l;
    return e;
}

//Retourne 0 si deux sommets ne sont pas égasux
int sommets_différents(vertex_t e1,vertex_t e2){
    return ((strcmp( e1.name,e2.name) == 0 ) && e1.x==e2.x &&e1.y==e2.y );
}


