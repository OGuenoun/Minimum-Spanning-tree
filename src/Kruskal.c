#include <stdio.h>
#include <stdlib.h>
#include "list_edge.h"
#include "vertex.h"

#include "Union_Find.h"
 list_edge_t Kruskal(graph_t g){
    list_edge_t ACM=NULL;
    list_edge_t l=prendre_edge(g);
    l= tri_fusion_edge(&l);
    
    int*  tab=new_connexe(g);
     if (tab == NULL) {
        printf("Erreur lors de l'allocation du tableau Union_Find\n");
        return NULL;
    }
    int valeur_acm=0;
    while(l->next!=NULL){
        int b= l->val.id_arrival;
        int a=l->val.id_departure;
        int x=recherche_representant(a,tab);
        int y=recherche_representant(b,tab);
        if(x!=y){  
            
            ACM=list_edge_add_first(ACM,l->val);
            //printf( " voici acm pour moment : \n");
            //list_edge_print(ACM);
            valeur_acm=valeur_acm+l->val.cost;
            fusion(x,y,tab);
            //printf("tab[%d]=%d\n",x,tab[x]);
            //printf("tab[%d]=%d\n",y,tab[y]);
          
        }
        l=l->next;
    }
    //vérification de l'état ACM : il faut qu'il y est un seul connexe dans notre ACM <=> quelque soit i : rep(i)=cte;
    int i = 0;
    int c= recherche_representant(l->val.id_arrival,tab);
    while(i<g.num_vertex){

        if(recherche_representant(i,tab)!=c){
            printf("ceci nest pas un acm vu qu'il y a plus qu'un connexe .\n" );
            return NULL;
            
        }
        i++;


    }
    printf("voici la valeur de votre acm : %d\n",valeur_acm);
    
    
return ACM;

}