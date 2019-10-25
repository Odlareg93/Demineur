#include <stdio.h>

struct scase {
   char val;
   int isHidden;
};

struct scase tab[20][20];

void main(){
 
    fill();

    putMine();
    
    setVal();
    
    aff();


}

void fill() // Remplis le tableau de case vide et cachés
{
    for(int a = 0;a<20;a++){
        for(int z = 0;z<20;z++){
            tab[a][z].val = '0';
            tab[a][z].isHidden = 1;
        }
    }
}

void aff(){ // Affiche le tableau
    for(int a = 0;a<20;a++){
        for(int z = 0;z<20;z++){
            printf(" %c",tab[a][z].val);
        }
    printf("\n");
    }
}

void setVal(){ // Determine la valeur de la case en fonction du nombre de mine autour
    int nbVal=0;
    for(int a = 0;a<20;a++){
        for(int z = 0;z<20;z++){
            nbVal=0;
            if(tab[a][z].val == 'x'){
                break;
            }
    
            if(tab[a-1][z].val == 'x' ) nbVal++;
            if(tab[a][z-1].val == 'x' ) nbVal++;
            if(tab[a+1][z].val == 'x' ) nbVal++;
            if(tab[a][z+1].val == 'x' ) nbVal++;
            if(tab[a-1][z-1].val == 'x' ) nbVal++;
            if(tab[a+1][z+1].val == 'x' ) nbVal++;
            if(tab[a-1][z+1].val == 'x' ) nbVal++;
            if(tab[a+1][z-1].val == 'x' ) nbVal++;
        
            char c = nbVal+'0';
            tab[a][z].val =  c;
        }
    }
}

void putMine(){ // Place les mines de manière aléatoires

    for(int a=0;a<40;a++)
    {
        
        int u = rand()%20+1;
        int y = rand()%20+1;
        tab[u][y].val = 'x';
        printf("1 : %d 2 : %d \n",u,y);
    }
}
