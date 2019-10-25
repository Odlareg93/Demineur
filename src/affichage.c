#include "../include/affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Fonction pour afficher le tableau
 */
void
print_tableau (scase tab[20][20])
{
  for (int i = 0; i < 20; ++i)
    {
      for (int j = 0; j < 20; ++j)
	{
	  if (tab[i][j].isHidden == 0)
	    {

	      if (tab[i][j].val == '0')
		{
		  printf (" ");
		  //printf("%s%c%s ",BLEU, tab[i][j].val,RESET);
		}


	      if (tab[i][j].val == '1' || tab[i][j].val == '2'
		  || tab[i][j].val == '3')
		{
		  printf ("%s%c%s ", BLEU, tab[i][j].val, RESET);
		}

	      if (tab[i][j].val == '4' || tab[i][j].val == '5'
		  || tab[i][j].val == '6')
		{
		  printf ("%s%c%s ", JAUNE, tab[i][j].val, RESET);
		}

	      if (tab[i][j].val == '7' || tab[i][j].val == '8')
		{
		  printf ("%s%c%s ", ROUGE, tab[i][j].val, RESET);
		}


	    }

	  else if (tab[i][j].isHidden == 1)
	    {
	      printf ("■ ");

	    }
	}
      printf ("\n");

    }
}
