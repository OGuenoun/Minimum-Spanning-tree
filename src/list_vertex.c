#include <stdio.h>
#include <stdlib.h>
#include "list_vertex.h"


list_vertex_t list_vertex_new(){
     return NULL; 
}

int list_vertex_is_empty(list_vertex_t l){
    return NULL == l;
}

list_vertex_t list_vertex_add_first(list_vertex_t l, vertex_t e){
    list_vertex_t p = calloc( 1, sizeof(*p) );
  if( NULL == p) {
    fprintf(stderr, "list_vertex_add_first : error allocating list link\n");
    return NULL;
  }
  
  p->val  = e;
  p->next = l;
  return p;
}

//Retourne 1 si un sommet n'appartient pas à la liste
int non_dans_liste(list_vertex_t l,vertex_t e){
    list_vertex_t p=l;
    while(p!=NULL && sommets_différents(p->val,e)==0 ){
        p=p->next;
    }
    if (p==NULL){
        return 1;
    }
    return 0;
}

list_vertex_t list_vertex_add_last(list_vertex_t l,vertex_t e ) {
  list_vertex_t c=NULL;
  if(l==NULL){
    return list_vertex_add_first(NULL,e);
  }
  else{
    c=l;
    while(c->next!=NULL){
      c=c->next;
    }
    c->next=list_vertex_add_first(NULL,e);
    return l;
  }}

list_vertex_t list_vertex_del_first( list_vertex_t l ) {
  if(l!=NULL){
  list_vertex_t p = l->next;
  free( l );
  return p;}
  return NULL;
}

int list_vertex_length(list_vertex_t l){
  int len = 0;
  list_vertex_t p;
  for( p=l; NULL != p ; p = p->next ) {
    len ++;
  }
  return len;
}







