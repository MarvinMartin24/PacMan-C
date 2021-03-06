#ifndef NIVEAUX_H_INCLUDED
#define NIVEAUX_H_INCLUDED
#include <conio.h>
#include <time.h>
#include "game.h"
#include <math.h>




// ProcÚdure permettant de un pause en miliseconde
void delay(int number_of_miliseconds);


//ProcÚdure remplissant d'espace le board (nettoyage)
void clear_board(game_t* game);



void niveaux(game_t* game, int vitesse);

// ProcÚdure permettant de sauvegarder dans un fichier le niveau et la vie
void save(game_t* game);
int read_save();
#endif // NIVEAUX_H_INCLUDED
