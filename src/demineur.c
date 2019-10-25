#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/affichage.h"


/**
 * Fonction pour savoir si le move est dans le tableau
 */
bool MoveValide(int ligne, int col)
{

	return (ligne >= 0) && (ligne < 20) &&
		(col >= 0) && (col < 20);
}



/**
 * Fonction permettant savoir si une case est occupée par une mine
 */
bool CaseMine (int ligne, int col,scase tab[20][20])
{
	if (tab[ligne][col].val == 'X')
		return (true);
	else
		return (false);
}

/**
 * Fonction permettant d'afficher le tableau selon la valeurs des cases
 */
