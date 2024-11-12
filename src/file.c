#include <stdio.h>
#include <stdlib.h>

#include "file.h"

file_t* creer_file(){
    file_t* file=(file_t*)malloc(sizeof(file_t));
    file->rear=NULL;
    return file;
}

int file_is_empty(file_t*file){
    return file->rear==NULL;
}

void enqueue(file_t*file,int sommet){
    noeud_t*nouveau_noeud=(noeud_t*)malloc(sizeof(noeud_t));
    nouveau_noeud->sommet=sommet;
    if(file->rear==NULL){
        nouveau_noeud->next=nouveau_noeud;
    }else{
        nouveau_noeud->next=file->rear->next;
        file->rear->next=nouveau_noeud;
    }
    file->rear=nouveau_noeud;
}

int dequeue(file_t*file){
    if(file_is_empty(file)){
        return -1;
    }
    noeud_t*front=file->rear->next;
    int sommet=front->sommet;
    if(file->rear==front){
        file->rear=NULL;
    }else{
        file->rear->next=front->next;
    }
    free(front);
    return sommet;
}

void free_file(file_t* file){
    while(!file_is_empty(file)){
        dequeue(file);
    }
    free(file);
}
int non_dans_file(file_t*file,int sommet){
    if(file_is_empty(file)) return 1;
    noeud_t* present=file->rear->next;
    do{
        if(present->sommet==sommet)return 0;
        present=present->next;
    }while(present!=file->rear->next);
    return 1;
}