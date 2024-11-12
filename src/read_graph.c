#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_edge.h"
#include "graph.h"

graph_t* read_graph(char* file){
    FILE* f;
    graph_t*g=calloc(1,sizeof(graph_t));
    if(g==NULL){
        printf("erreur allocation graphe");
        return NULL;
    }
    
 int nb_vertices, nb_edges;
 int vertex_id;
 double vertex_latitude, vertex_longitude ; // pour la position d’un sommet
 char vertex_name[512] ;
 char tmp_string[512] ;

 f = fopen( file, "r");
 if (NULL == f) {
 fprintf(stderr, "Le fichier graphe n’a pu etre ouvert. Aborts.\n");
 exit(EXIT_FAILURE);
 }
 // Lecture de la premiere ligne du fichier : nombre de sommets et nombre d’arcs
 fscanf(f,"%d %d", &nb_vertices, &nb_edges);
 g->num_vertex = nb_vertices;
 g->num_arc=nb_edges;
 
 g->data=calloc(nb_vertices,sizeof(vertex_t));
    if(g->data==NULL){
        printf("erreur allocation graphe.data");
        return NULL;
    }
 // Avec fgets(), on lit la fin de la première ligne pour passer à la suivante,
 // y compris le caractère de retour à la ligne backslash-n
 fgets(tmp_string, 511, f);
 // vertex name contient désormais le nom du sommet, espaces éventuels inclus.
 // affichage de ce qui a été lu :
 printf("Nb sommets %d ; Nb arcs %d\n", nb_vertices, nb_edges);
 

 // Lecture de la 2ème ligne : texte "Sommets du graphe" qui ne sert a rien.
 // ... Remarque : il conviendrait toutefois de verifier qu’elle est correcte...
 fgets(tmp_string,511,f);
 for(int i=0 ; i<nb_vertices;i++){
     // On est pret à lire le début de la troisième ligne du fichier.
 // Lecture de la ligne de description du premier sommet :
 // On lit d’abord le numero du sommet, sa position et le nom de la ligne
 fscanf(f,"%d %lf %lf ", &vertex_id, &vertex_latitude, &vertex_longitude);
 // vertex id contient alors l’entier numero du sommet,
 // vertex latitude et vertex longitude la position du sommet
 // Le nom du sommet peut contenir des separateurs comme l’espace.
 // => On utilise plutot fgets pour lire toute la fin de ligne, meme les espaces :
 fgets(vertex_name,511,f);
 // fgets a lu toute la ligne, y compris le retour a la ligne.
 // On supprime le retour à la ligne ’backslash-n’
 // qui peut se trouver a la fin de la chaine vertex name
 // en le remplacant par le caractère de fin de chaıne ’backslash-0’
 // Remarque : 32 est le code ascii du caractère espace ’ ’
 // et tous les caractères valides on un code ascii >= 32.
 while ( vertex_name[ strlen(vertex_name) - 1 ] < 32) {
 vertex_name[ strlen(vertex_name) - 1 ] = '\0';
 }
 
 g->data[i].name=strdup( vertex_name);
 g->data[i].x=vertex_latitude; 
 g->data[i].y=vertex_longitude;

 //printf("sommet numero %d: indice %d ; position [%lf ; %lf] ; nom %s\n",i,
 //vertex_id, vertex_latitude, vertex_longitude, vertex_name);


 
 }
  fgets(tmp_string,511,f);

  for(int i=0 ; i<nb_edges;i++){
 
 int vertex_arrive,vertex_depart;
 double cout_edge;
 fscanf(f,"%d %d %lf ", &vertex_depart, &vertex_arrive, &cout_edge);
  edge_t e,w;

 e.id_departure=vertex_depart;
 e.id_arrival=vertex_arrive;
 e.cost=cout_edge;
 g->data[vertex_depart].edges=list_edge_add_first(g->data[vertex_depart].edges,e);

 w.id_departure=vertex_arrive;
 w.id_arrival=vertex_depart;
 w.cost=cout_edge;
 g->data[vertex_arrive].edges=list_edge_add_first(g->data[vertex_arrive].edges,w);

 //printf("arrete entre %d et %d  : cout = %lf \n",vertex_depart,vertex_arrive,cout_edge);
 // vertex name contient désormais le nom du sommet, espaces éventuels inclus.
 // affichage de ce qui a été lu :
 
 }



 // Ne pas oublier de fermer le fichier !
 fclose(f);
 return g;
 }
