#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"
#include "graph.h"
#include"Union_Find.h"

// tableau de n elements (on travail avec les indices ou chaque ieme case indique l'indice du pere de cette case )
int*  new_connexe(graph_t g){
 int n=g.num_vertex ; 
 int* tab=calloc(n,sizeof(int));
 if(tab==NULL){ 
    printf("erreur d'allocation");
 }
 for (int i=0;i<n;i++){
 
  
  tab[i]=i;

 
  
 }
 return tab;
 }


int recherche_representant(int i,int*  tab ){
    if(*(tab+i)==i){return i;}
    return recherche_representant(tab[i],tab);
}

void fusion(int a, int b, int*  tab){
    tab[a]= b;
    

}

list_edge_t prendre_edge(graph_t g){
    list_edge_t l=NULL;
    int n = g.num_vertex;
    list_edge_t x=g.data[0].edges;
    for(int i=0;i<n;i++){
       x=g.data[i].edges;
      while(x!=NULL){
        
            l=list_edge_add_first(l,x->val);

            

            x=x->next;
         }
        
        
    }
   
  return l ;

} 

 //algo pour trier les somments selon les couts (tri par fusion )
list_edge_t fusionner( list_edge_t l1, list_edge_t l2){
    if (list_edge_is_empty(l1)) {
        return l2;
    }
    if (list_edge_is_empty(l2)) {
        return l1;
    }

    list_edge_t res = NULL ,last = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val.cost <= l2->val.cost) {
            if (res == NULL) {//ici on met l1 en last juste pour qu'on puisse pointer la fin de res  au moment ou une liste est parcourue( puis on fusionne ce qui reste )
                res = l1;
                last = l1;
            } else {
                last->next = l1;
                last = last->next;
            }
            l1 = l1->next;
        } else {
            if (res == NULL) {
                res = l2;
                last = l2;
            } else {
                last->next = l2;
                last = last->next;
            }
            l2 = l2->next;
        }
    }

    if (l1 != NULL) {
        last->next = l1;
    } else {
        last->next = l2;
    }

    return res;
}






list_edge_t tri_fusion_edge(list_edge_t *l) {
    if (list_edge_is_empty(*l) || list_edge_is_empty((*l)->next)) {
        return *l;
    }

    list_edge_t l1 = *l;
    list_edge_t l2 = (*l)->next;
//ici on essaye de trouver le milieu de la liste chainée avec un parcours à double vitesse 
    while (l2 != NULL && l2->next != NULL) {
        l1 = l1->next;
        l2 = l2->next->next;
    }

    list_edge_t lm = l1;
    list_edge_t l3= *l;
    list_edge_t l4= lm->next;
    lm->next = NULL;

    l3 = tri_fusion_edge(&l3);
    l4 = tri_fusion_edge(&l4);

    return fusionner(l3, l4);
}



