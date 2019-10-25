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
  bool end = false;
  scase tab[20][20];
  fill(tab);
  setVal(tab);
  putMine(tab);
  hidden = getHidden(tab);
  printf("%d : hidden\n",hidden);
  mine = getMine(tab);
  printf("%d mine\n",mine);
  printf("%d : is WIn\n",isWin(tab));

  while (end != true){
    char inputChar;
    int x, y;

    print_tableau (tab);
    /*printf("Entrer 'q'  pour quitter: ");
    scanf("%c", &inputChar);

    if (inputChar == 'q'){
      exit(-1);
    }*/

    printf("Entrer votre numéro de cologne x: ");
    scanf("%d", &x);

    printf("Entrer votre numéro de cologne y: ");
    scanf("%d", &y);

    play(x, y, tab);

  }
  return 0;
}
