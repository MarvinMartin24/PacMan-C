#ifndef GAME_H
#define GAME_H

// Librairie
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <assert.h>
#include "position.h"
#include "obstacle.h"
#include "random.h"


// Define Char
#define SNAKE_CHAR 'x'
#define VOID_CHAR ' '

// structure principale GAME_T
typedef struct game_t {
    char** board;
    int border;
    int life;
    int level;
    position_t dimension;
    position_t* snake_position;
    int snake_size;
    position_t direction;
    position_t* direction_obstacles;
    position_t* track_direction_obstacles;
    obstacle_t* obstacles;
    int* obstacle_hit_wall;
    int obstacles_count;
} game_t;

// Procédure déplacant le curseur en (x,y)
void gotoXY(int x, int y);

// Fonction de Creation et d'initialisation de la struct Game
game_t* game_create(int height, int width);

// Procédure creant des bordures dans la matrice board
void game_map(game_t* game);

// Procédure creant un labyrinthe dans la matrice board
void game_maze(game_t* game);

// Procédure permettant le deplacement du snake/pacman en donnant en parametre game et le deplacement (utile au game_keep_moving)
void game_move(game_t* game, position_t offset);

// Procédure permettant un mouvement permanant dans la meme direction de la tete du snake
void game_keep_moving(game_t* game);

// Procédure permettant à la tete du snake de monter
void game_up(game_t* game);

// Procédure permettant à la tete du snake de descendre
void game_down(game_t* game);

// Procédure permettant à la tete du snake de tourner à gauche
void game_left(game_t* game);

// Procédure permettant à la tete du snake de tourner à droite
void game_right(game_t* game);

// Procédure permettant l'agrandir la taille du snake
void game_snake_size_up(game_t* game);

// Procédure permettant d'ajouter different type d'obstacles
void game_add_obstacle(game_t* game, obstacle_t obstacle);

// Procédure permettant de couper la queue du snake à l'indice 'index' donné en parametre
void game_snake_cut(game_t* game,int index);

// Fonction renvoyant zero si pas de conctact entre snake et les obstacles sinon renvoie l'indice du contact
int game_snake_hit_no_head(game_t* game, obstacle_t* obstacle);

// Fonction renvoyent un booleen : true correspondant au snake mord ca queue sinon false
bool game_snake_hit_snake(game_t* game);

// Procédure permettant de retirer l'obstacle [index]
void remove_obstable(game_t* game,int index);

// Fonction renvoyent un booleen : true correspondant impact snake-obstacle (et memorize l'obstacle et l'index de l'obstacle)
bool game_has_hit(game_t* game, obstacle_t* obstacle,int* index);

// Procédure permentant d'afficher le board à l'écran
void game_display(game_t* game);

// Procédure librant l'espace allouer à la fin du jeu
void game_free(game_t* game);

// Procédure qui compte le nombre de fois d'un obstacle touche un mur et stock cela pour chaque obstacle dans obstacle_hit_wall
void check_obstacle_hit_wall (game_t* game);

// Procédure permettant le mouvement de l'obstacles à l'indice 'index'
void game_obstacle_move( game_t* game, int index);

// Procédure permettant le mouvement des obstacles avec un rapide sur 2
void game_obstacle_move_diverty( game_t* game , int ctr);

// Fonction qui renvoie le minimum entre 4 distances (utile pour obstacle_tracking )
int minimun_distance_obstacle(int d1, int d2, int d3, int d4);

// Procédure 'IA' placant dans la liste de direction 'track_direction_obstacles' les deplacements intelligent des obstacles
void obstacle_tracking(game_t* game);

// Procédure permettant d'afficher des pommes à l'écran
void print_apples(game_t* game, int nb_apple);

// Procédure permettant d'afficher des ennemies à l'écran
void print_ennemies(game_t* game, int nb_ghost);

#endif /* end of include guard: GAME_H */
