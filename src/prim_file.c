#define COST_MAX 1000000
#include "graph.h"
#include <stdio.h>
#include"file.h"
list_edge_t Prim_file(graph_t graph){
    int i,n;
    n=graph.num_vertex;
    edge_t * previous_edge=(edge_t*)malloc(n*sizeof(edge_t));
    double * cost=(double*)malloc(n*sizeof(double));
    int*in_tree=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        (previous_edge+i)->id_departure=-1;
        (previous_edge+i)->id_arrival=-1;
        *(cost+i)=COST_MAX;
        in_tree[i]=0;
    }

    vertex_t depart=graph.data[0];
    *(cost+indice(depart,graph))=0;
    int ind_départ=indice(depart,graph);

    file_t* atraiter=creer_file();
    file_t* atteint=creer_file();
    enqueue(atraiter,ind_départ);

    while(!file_is_empty(atraiter)){
        int ind_u=dequeue(atraiter);
        vertex_t u=graph.data[ind_u];
        enqueue(atteint,ind_u);

        for(list_edge_t p=graph.data[ind_u].edges;p!=NULL;p=p->next){
            int ind_v=p->val.id_arrival;
            vertex_t v=graph.data[ind_v];
            if(!in_tree[ind_v]&&p->val.cost < cost[ind_v]){
                cost[ind_v]=p->val.cost;
                previous_edge[ind_v]=p->val;
                if(non_dans_file(atteint,ind_v)){
                    enqueue(atraiter,ind_v);
                }
            }
        }
        in_tree[ind_u]=1;
    }
    int total_cost = 0;
    list_edge_t acm=list_edge_new();
    for(i=0;i<n;i++){
        if (previous_edge[i].id_departure!=(-1)){
            acm=list_edge_add_first(acm,previous_edge[i]);
            total_cost += cost[i];
        }
    }

    printf("Coût total de l'acm %d\n", total_cost);

    free(previous_edge);
    free(cost);
    free(in_tree);
    free_file(atraiter);
    free_file(atteint);

    return acm;

}
