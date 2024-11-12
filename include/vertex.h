#ifndef _VERTEX_H
#define _VERTEX_H
#include "list_edge.h"


// Definition du type sommet

typedef struct {
    char * name;
    double x,y;
    list_edge_t edges;
} vertex_t;

//Retourne un sommet correctement formé
vertex_t vertex_new(char*name,double x,double y,list_edge_t l);


//Retourne 0 si deux sommets ne sont pas égaux
int sommets_différents(vertex_t e1,vertex_t e2);



#endif

