#include <stdio.h>

#define W 5
#define H 5

int tab [H][W] =  {{0,0,0,0,0},
                    {0,0,0,0,0},
                    {0,0,0,0,0},
                    {0,0,0,0,0},
                    {0,0,0,0,0}};


void propagate(int x_pos , int y_pos ){

    if (x_pos < 0 || x_pos >= W) // Position X hors plateau
        return ;    

    if (y_pos < 0 || y_pos >= J) // Position Y hors plateau
        return ;

    if (tab[x_pos][y_pos] == '1' )
        return ; 

    if (tab[x_pos][y_pos] == '2' )
        printf("get rekt son") ; 
    
    if (tab[x_pos][y_pos] == 0){
        propagate(x_pos + 1 ,y_pos);
        propagate(x_pos - 1,y_pos);
        propagate(x_pos,y_pos + 1);
        propagate(x_pos,y_pos - 1);
    }
}

int main(){
    for (int i = 0; i < H; i++)
    {
        printf("\n");
        for (int j = 0; j < W; j++)
        {
            printf("%d",tab[i][j]);
        }
        
    }
    return 0;
    
}