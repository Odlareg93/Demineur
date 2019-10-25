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
  int hidden,mine,r;
  scase tab[20][20];
  fill(tab);
  setVal(tab);
  putMine(tab);
  hidden = getHidden(tab);
  printf("%d : hidden\n",hidden);
  mine = getMine(tab);
  printf("%d mine\n",mine);
  printf("%d : is WIn\n",isWin(tab));



  print_tableau (tab);
  return 0;
}
