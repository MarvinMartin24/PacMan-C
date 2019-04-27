#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include "niveaux.h"
#include "game.h"


#define MAX 23
#define LARG 69



void Color(int colorTexte,int colorFond);
void Locate(int x,int y);
void affiche();
void affichetableau1();
void affichetableau2();
void affichetableau3();
void affichetableau4();
void afficheregle();
void affichegameover();
void Afficher(int x,int y);
void affichediff(int x,int y);
void TryMove(int* x,int* y,int vx,int vy);
void TryMovediff(int* x,int* y,int vx,int vy);
void mouvement(char touche,int* x, int* y);
void mouvementdiff(char touche,int* x, int* y);
void menu_fct();



#endif // MENU_H_INCLUDED
