#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "prim.h"
#include "kruskal.h"
#include "read_graph.h"
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Union_Find.h"


// print_usage assure la bonne syntaxe de notre commande en terminal 
void print_usage() {
    printf("Usage: acm nomDuFichierGraphe.txt 0/1 [-v]\n");
    printf("  0: Kruskal \n");
    printf("  1: Prim \n");
    printf("  -v: Optionnel pour afficher les arcs de l'acm\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        print_usage();
        return 1;
    }

    char *file= argv[1];
    int algorithme = atoi(argv[2]);
    int v = (argc == 4 && strcmp(argv[3], "-v") == 0);

    graph_t *g = read_graph(file);

    list_edge_t acm = NULL;
    if (algorithme== 0) {
        acm = Kruskal(*g);
    } else if (algorithme == 1) {
        acm = Prim(*g);
    } else {
        print_usage();
        return 1;
    }
        if (v) {
            printf("Voici votre acm:\n");
            list_edge_print(acm);
        }  
         return 0;
    }

 
