#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct noeud{
    int sommet;
    struct noeud* next;
}noeud_t;

typedef struct{
    noeud_t* rear;
}file_t;

//creation d'une file
file_t* creer_file();

//verifier si la file est vide
int file_is_empty(file_t*file);

//ajouter un sommet à la file
void enqueue(file_t*file,int sommet);

//supprimer un sommet de la file et le retourne
int dequeue(file_t*file);

//libérer la file
void free_file(file_t* file);

int non_dans_file(file_t*file,int sommet);