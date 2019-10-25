struct scase {
   char val;
   int isHidden;
};
typedef struct scase scase;

bool CaseMine (int ligne, int col,scase board[20][20]);
