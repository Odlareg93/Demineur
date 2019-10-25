/**
 * @file demineur.h
 * @brief Fonctions qui constituent la logique du jeu.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct scase
{
  char val;
  int isHidden;
};

typedef struct scase scase;

bool CaseMine (int ligne, int col, scase board[20][20]);
bool MoveValide (int ligne, int col, scase board[20][20]);
void game_over ();
void victoire ();
void play (int ligne, int col, scase tab[20][20]);
//void print_tableau(scase tab[20][20]);
