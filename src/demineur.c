#include <stdio.h>

struct scase {
   char val;
   int isHidden;
};


bool MoveValide(int ligne, int col)
{

	return (ligne >= 0) && (ligne < SIDE) &&
		(col >= 0) && (col < SIDE);
}




bool CaseMine (int ligne, int col, char board[][MAXSIDE])
{
	if (board[ligne][col] == '*')
		return (true);
	else
		return (false);
}


void print_tableau(int tab[20][20]){



}



void main(){

    struct scase tab[20][20];

    for(int a = 0;a<20;a++){
        for(int z = 0;z<20;z++){
            tab[a][z].val = '0';
            tab[a][z].isHidden = 0;
        }
    }




    for(int a = 0;a<20;a++){
        for(int z = 0;z<20;z++){
            printf("\t%c",tab[a][z].val);
        }
    printf("\n");
    }

}
