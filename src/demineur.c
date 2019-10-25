/**
 * @file demineur.c
 * @brief Fonctions qui constituent la logique du jeu.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/affichage.h"


/**
 * Fonction pour savoir si le move est dans le tableau
 */
bool
MoveValide (int ligne, int col, scase tab[20][20])
{

  return (ligne >= 0) && (ligne < 20) && (col >= 0) && (col < 20);
}



/**
 * Fonction permettant savoir si une case est occupée par une mine
 */
bool
CaseMine (int ligne, int col, scase tab[20][20])
{
  if (tab[ligne][col].val == 'X')
    return (true);
  else
    return (false);
}

/**
 * Fonction permettant de quitter le jeu après une defaite
 */
void
game_over ()
{
  printf ("Vous avez perdu !\n");
  exit (0);

}
/**
 * Fonction permettant de quitter le jeu après une victoire
 */
void
victoire ()
{
  printf ("Vous avez gagné ! ");
  exit (0);
}

/**
 * Fonction permettant de jouer sur une case
 */
void
play (int ligne, int col, scase tab[20][20])
{
  if (MoveValide (ligne, col, tab) == true)
    {
      if (CaseMine (ligne, col, tab) == true)
	{
	  game_over ();
	}
      else
	{
	  //fonction de propagation
	}
    }
}
