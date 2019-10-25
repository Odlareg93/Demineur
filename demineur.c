#include <stdio.h>

struct scase {
   char val;
   int isHidden;
};

struct scase tab[20][20];

void main(){
 
    fill();

    putMine();
    
    aff();


}

void fill()
{
    for(int a = 0;a<20;a++){
        for(int z = 0;z<20;z++){
            tab[a][z].val = '0';
            tab[a][z].isHidden = 1;
        }
    }
}

void aff(){
    for(int a = 0;a<20;a++){
        for(int z = 0;z<20;z++){
            printf("\t%c",tab[a][z].val);
        }
    printf("\n");
    }
}

void putMine(){

    for(int a=0;a<40;a++)
    {
        
        int u = rand()%20+1;
        int y = rand()%20+1;
        tab[u][y].val = 'x';
        printf("1 : %d 2 : %d \n",u,y);
    }
    
}
