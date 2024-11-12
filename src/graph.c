
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "vertex.h"
#include "edge.h"

////Retourne l'indice d'un sommet e dans un graphe et -1 s'il n'appartient pas
int indice(vertex_t e, graph_t g){
    for(int i =0; i<g.num_vertex;i++){
        if(sommets_différents(e,g.data[i])){
            return i;
        }
    }
return -1;
}
vertex_t sommet_départ(graph_t g){
    vertex_t départ;
    double cout_min=(g.data)->edges->val.cost;
    vertex_t*p;
     départ.name=g.data[0].name;
      départ.x=g.data[0].x;
      départ.y=g.data[0].y;
       départ.edges=g.data[0].edges;
    
    for(p=g.data;p<(g.data)+(g.num_vertex);p++){
        for(list_edge_t q=p->edges;q!=NULL;q=q->next){
        if((q->val.cost)<cout_min){
            cout_min=q->val.cost;
              départ.name=g.data[(q->val).id_departure].name;
                départ.x=g.data[(q->val).id_departure].x;
                départ.y=g.data[(q->val).id_departure].y;
                départ.edges=g.data[(q->val).id_departure].edges;

        }} 
    }
   
return(départ);

}
list_vertex_t orderedlist_vertex_add(list_vertex_t l,vertex_t e, double * cost,graph_t g) {
    list_vertex_t c;
  if(l==NULL||cost[indice(e,g)]<cost[indice(l->val,g)]){
    return list_vertex_add_first(l,e);

  }
  else{
    c=l;
    while(c->next!=NULL){
      if(cost[indice(e,g)]<cost[indice(c->next->val,g)]){list_vertex_t a=list_vertex_add_first(c->next,e);
        c->next=a;
        return l;
      }
      c=c->next;
    }
    return list_vertex_add_last(l,e);
  }
}