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

/**
 * Fonction permettant de propager
 */
void propagate(int x_pos , int y_pos,scase tab[20][20]){

    if (x_pos < 0 || x_pos >= W) // Position X hors plateau
        return ;

    if (y_pos < 0 || y_pos >= H) // Position Y hors plateau
        return ;

    if (tab[x_pos][y_pos].val == ' ' && tab[x_pos][y_pos].isHidden == 0) //Deja éxploré
        return ;

    if (tab[x_pos][y_pos].val == 'X' ) //BOMB
        return ;

    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == ' '){
        tab[x_pos][y_pos].isHidden = 0;
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '1'){
        tab[x_pos][y_pos].isHidden = 0;
        return ;
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '2'){
        tab[x_pos][y_pos].isHidden = 0;
        return ;
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '3'){
        tab[x_pos][y_pos].isHidden = 0;
        return ;
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '4'){
        tab[x_pos][y_pos].isHidden = 0;
        return ;
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '5'){
        tab[x_pos][y_pos].isHidden = 0;
        return ;
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '6'){
        tab[x_pos][y_pos].isHidden = 0;
        return ;

    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '7'){
        tab[x_pos][y_pos].isHidden = 0;
        return ;

    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '8'){
        tab[x_pos][y_pos].isHidden = 0;
        return ;

    }


    if (tab[x_pos][y_pos].val == ' '){
        propagate(x_pos + 1 ,y_pos,tab);
        propagate(x_pos - 1,y_pos,tab);
        propagate(x_pos,y_pos + 1,tab);
        propagate(x_pos,y_pos - 1,tab);
    }
}






void
fill (scase tab[20][20])
{
  for (int a = 0; a < 20; a++)
    {
      for (int z = 0; z < 20; z++)
	{
	  tab[a][z].val = '0';
	  tab[a][z].isHidden = 1;
	}
    }
}

/**
 * \fn void setVal(struct scase tab[20][20])
 * \brief Determine la valeur de la case en fonction du nombre de mine autour
 *
 * \param le tableau du demineur à remplire
 */

void
setVal (scase tab[20][20])
{
  for (int a = 0; a < 20; a++)
    {
      for (int z = 0; z < 20; z++)
	{
	  int nbVal = 0;
	  if (tab[a][z].val != 'x')
	    {

	      if (a > 0 && tab[a - 1][z].val == 'x')
		nbVal++;
	      if (z > 0 && tab[a][z - 1].val == 'x')
		nbVal++;
	      if (a < 19 && tab[a + 1][z].val == 'x')
		nbVal++;
	      if (z < 19 && tab[a][z + 1].val == 'x')
		nbVal++;
	      if (a > 0 && z > 0 && tab[a - 1][z - 1].val == 'x')
		nbVal++;
	      if (a < 19 && z < 19 && tab[a + 1][z + 1].val == 'x')
		nbVal++;
	      if (a > 0 && z < 19 && tab[a - 1][z + 1].val == 'x')
		nbVal++;
	      if (a < 19 && z < 19 && tab[a + 1][z - 1].val == 'x')
		nbVal++;

	      char c = nbVal + '0';
	      tab[a][z].val = c;
	    }
	}
    }
}

/**
 * \fn void putMine(struct scase tab[20][20])
 * \brief Place les mines de manière aléatoires
 *
 * \param le tableau du demineur à remplire
 */
void
putMine (scase tab[20][20])
{

  for (int a = 0; a < 40; a++)
    {

      int u = rand () % 20 + 1;
      int y = rand () % 20 + 1;
      tab[u][y].val = 'x';
    }
}

/**
 * \fn int getHidden(struct scase tab[20][20])
 * \brief compte le nombre de case cachés
 *
 * \param le tableau du demineur à compter
 * \return retourne le nombre de case caché dans le demineur
 */
int
getHidden (scase tab[20][20])
{
    int compteur = 0;
    for (int a = 0; a < 20; a++)
    {
      for (int z = 0; z < 20; z++)
	{
	  if(tab[a][z].isHidden == 1)
        compteur++;
	}
    }
    return compteur;
}

/**
 * \fn int getMine(struct scase tab[20][20])
 * \brief compte le nombre de mine
 *
 * \param le tableau du demineur à compter
 * \return retourne le nombre de mine
 */
int
getMine (scase tab[20][20])
{
    int compteur = 0;
    for (int a = 0; a < 20; a++)
    {
      for (int z = 0; z < 20; z++)
	{
	  if(tab[a][z].val == 'x')
        compteur++;
	}
    }
    return compteur;
}


/**
 * \fn int isWin(struct scase tab[20][20])
 * \brief Verifie la victoire
 *
 * \param le tableau du demineur à compter
 * \return retourne 1 si l'utilisateur a gagné 0 si il n'a pas gagné
 */
int
isWin (scase tab[20][20])
{
    if ( getHidden(tab) == getMine(tab) )
        return 1;
    else
        return 0;
}
