#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // pour PATH_MAX
#include <assert.h>
#include <libgen.h>

#include <unistd.h>
#include "Union_Find.h"


int recherche_representant(int i,int*  tab );

int main (){
int tab[7];
tab[0]=1;
tab[1]=1;
tab[2]=2;
tab[3]=4;
tab[4]=5;
tab[5]=6;
tab[6]=2;
printf("rep de quel sommet\n");
int t;
scanf("%d",&t);
int r=recherche_representant(t,tab);
printf("le rep de %d est %d",t,r);
  
    
    return 0;
    

}
