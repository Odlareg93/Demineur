/**
 * @file main.c
 * @brief Permet de lancer le jeu.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/affichage.h"

int
main ()
{
  int r;
  scase tab[20][20];

  for (int a = 0; a < 20; a++)
    {
      for (int z = 0; z < 20; z++)
	{
	  tab[a][z].val = '0';
	  tab[a][z].isHidden = 0;
	}
    }

  print_tableau (tab);
  return 0;
}
