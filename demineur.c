#include <stdio.h>

struct scase {
   char val;
   int isHidden;
};


void main(){

    struct scase tab[20][20];
   
    for(int a = 0;a<20;a++){
        for(int z = 0;z<20;z++){
            tab[a][z].val = '0';
            tab[a][z].isHidden = 0;
        }
    }

    int tab[40][2];
    for(int a=0;a<40;a++)
    {
        srand (time (NULL)); 
        tab[a][0] = Random();
        tab[a][1] = Random();
    }

    for(int a = 0;a<20;a++){
        for(int z = 0;z<20;z++){
            printf("\t%c",tab[a][z].val);
        }
    printf("\n");
    }

}

int Random ()
{
return ((rand () % (21)));
} 

