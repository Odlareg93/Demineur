#include <stdio.h>
/**
 * \file demineur.c
 * \brief Fichier qui permet de setup le tableau ( Placer les mines, les valeurs )
 */

/**
 * \struct scase    
 * \brief Represente une case du demineur, avec sa valeur qui détermine si c'est une case vide, de valeur, ou un mine, et avec un int qui indique si la case est caché ou pas
 */
struct scase
{
  char val;
  int isHidden;
};


/**
 * \fn void fill(struct scase tab[20][20])
 * \brief Remplis le tableau de case vide et cachés.
 *
 * \param le tableau du demineur à remplire
 */



void
fill (struct scase tab[20][20])
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
setVal (struct scase tab[20][20])
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
putMine (struct scase tab[20][20])
{

  for (int a = 0; a < 40; a++)
    {

      int u = rand () % 20 + 1;
      int y = rand () % 20 + 1;
      tab[u][y].val = 'x';
    }
}
