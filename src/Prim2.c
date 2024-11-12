#define COST_MAX 1000000
#include <stdlib.h>
#include "graph.h"

list_edge_t Prim2(graph_t graph){
    int i,n;
    n=graph.num_vertex;
    edge_t * previous_edge=(edge_t*)malloc(n*sizeof(edge_t));
    double * cost=(double*)malloc(n*sizeof(double));
    list_vertex_t atraiter=list_vertex_new();
    list_vertex_t atteint=list_vertex_new();
    for(i=0;i<n;i++){
        (previous_edge+i)->id_departure=-1;
        (previous_edge+i)->id_arrival=-1;
        *(cost+i)=COST_MAX;
    }
    vertex_t depart=sommet_départ(graph);
    *(cost+indice(depart,graph))=0;
    atraiter=orderedlist_vertex_add(atraiter,depart,cost,graph);
    while(!list_vertex_is_empty(atraiter)){
        vertex_t u=atraiter->val;
        atraiter= list_vertex_del_first(atraiter);
        atteint=list_vertex_add_first(atteint,u);
        for(list_edge_t p=u.edges;!list_edge_is_empty(p);p=p->next){
            vertex_t v=graph.data[p->val.id_arrival];
            int indice_v=indice(v,graph);
            if(non_dans_liste(atteint,v)&&(p->val).cost<cost[indice_v]){
                *(cost+indice_v)=(p->val).cost;
                *(previous_edge+indice_v)=p->val;
                atraiter=orderedlist_vertex_add(atraiter,v,cost,graph);

            }
        }
    }
    list_edge_t acm=list_edge_new();
    for(i=0;i<n;i++){
        if (previous_edge[i].id_departure!=(-1)){
            acm=list_edge_add_first(acm,previous_edge[i]);
        }
}
   
    return acm;
}