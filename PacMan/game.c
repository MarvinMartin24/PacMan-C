#include "game.h"


// Procédure déplacant le curseur en (x,y)
void gotoXY(int x, int y){
	COORD mycoord;
	mycoord.X = x;
	mycoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

// Fonction de Creation et d'initialisation de la struct Game
game_t* game_create(int height, int width){

    // allouer en memoire le game
    game_t* game = (game_t*) malloc(sizeof(game_t));


    // allocation dynamique de la matrice board (champ de game) de taille [height][width]
		// allocation de "height" adresses de type char
    game->board = malloc(height*sizeof(char*));

		// creer "height" array de taille "width"
		// assigner l'adresse de chaque premier element de chaque array jusqu'a "height"
    for(int i=0 ; i<height ; i++){
        game->board[i] = malloc(width*sizeof(char));
        for(int j=0 ; j<width ; j++){
            game->board[i][j] = VOID_CHAR;
        }
    }

    // initialisations des champs:  dimension, border, life, level
    game->dimension.x = width;
    game->dimension.y = height;
	game->border=0;
	game->life=5;
	game->level=1;

	// allouer une place en memoire pour chaque partie du corp du snake (initialement de 1)
    game->snake_size = 1;
    game->snake_position = malloc(game->snake_size*sizeof(position_t));

    // initialisation aleatoire de la position de la tete du snake (ou du Pacman) dans une case vide
    do{
    	game->snake_position[0] = position_create(randomX(width),randomY(height));
    }while (game->snake_position[0].x!=' ');

	// initialisation de la direction du snake de maniere aleatoire
	game->direction = randomdirection();

	// initialisation du nombre d'obstacle
    game->obstacles_count = 0;

	// renvoyer la struct game
    return game;
}

// Procédure creant des bordures dans la matrice board
void game_map(game_t* game){

	// variables
	int i=0, j=0;

	// Placement dans la matrice board de tous les murs composant la bordure
	for (i = 0; i < game->dimension.y; i++){
        game->board[i][0] = 186; // left wall '║'
        game->board[i][game->dimension.x-1] = 186 ; // right wall '║'
	}

	for (j = 0; j < game->dimension.x; j++){
        game->board[0][j] = 205;// top wall  '═'
		game->board[game->dimension.y-1][j] = 205; // buttom wall  '═'
	}

	//top left angle '╔'

	game->board[0][0] = 201;

	//top right angle '╗'
	game->board[0][game->dimension.x-1] = 187;

	//buttom left angle '╚'
	game->board[game->dimension.y-1][0] = 200;

	//buttom right angle '╝'
	game->board[game->dimension.y-1][game->dimension.x-1] = 188;

}

// Procédure creant un labyrinthe dans la matrice board
void game_maze(game_t* game){

	// variable
	int i=0;

	// Placement dans la matrice board de tous les murs composant le labyrinthe
	game->board[0][12] = 203;
	for (i = 1; i < 7; i++){
        game->board[i][12] = 186;
	}
	game->board[7][12] = 200;
	for (i = 13; i < 23; i++){
        game->board[7][i] = 205;
	}
	game->board[7][23] = 187;
	for (i = 8; i < 13; i++){
        game->board[i][23] = 186;
	}

	for (i = 21; i < 31; i++){
        game->board[3][i] = 205;
	}
	game->board[3][31] = 187;
	for (i = 4; i < 7; i++){
        game->board[i][31] = 186;
	}
	game->board[7][31] = 200;
	for (i = 32; i < 41; i++){
        game->board[7][i] = 205;
	}
	for (i = 3; i < 7; i++){
        game->board[i][41] = 186;
	}
	game->board[7][41] = 185;
	for (i = 8; i < 16; i++){
        game->board[i][41] = 186;
	}

	for (i = 5; i < 12; i++){
        game->board[i][6] = 186;
	}
	game->board[12][6] = 200;

	for (i = 7; i < 11; i++){
        game->board[12][i] = 205;
	}
	game->board[12][11] = 203;
	for (i = 13; i < 18; i++){
        game->board[i][11] = 186;
	}

	for (i = 12; i < 17; i++){
        game->board[12][i] = 205;
	}
	game->board[12][17] = 187;
	for (i = 13; i < 17; i++){
        game->board[i][17] = 186;
	}
	game->board[16][17] = 200;
	for (i = 18; i < 30; i++){
        game->board[16][i] = 205;
	}
	game->board[16][30] = 188;
	for (i = 13; i < 16; i++){
        game->board[i][30] = 186;
	}
	game->board[13][30] = 204;
	for (i = 31; i < 37; i++){
        game->board[13][i] = 205;
	}
	for (i = 10; i <13 ; i++){
        game->board[i][30] = 186;
	}
}

// Procédure permettant le deplacement du snake/pacman en donnant en parametre game et le deplacement (utile au game_keep_moving)
void game_move(game_t* game, position_t offset){

	// variables
	position_t new_pos;
	position_t old_pos;

	// cas du snake : empeche le retour en arriere
	if (game->snake_size>=2){
            if(offset.x==-game->direction.x && offset.y==-game->direction.y)
                return;
    }

	// memoriser la position actuelle de la tete du snake
	old_pos.x = game->snake_position[0].x;
	old_pos.y = game->snake_position[0].y;

	// Ajouter le deplacement aux positions actuelles
	new_pos.x = old_pos.x + offset.x;
	new_pos.y = old_pos.y + offset.y;

	// Tout sauf les bordures
	if (new_pos.x != game->dimension.x-1 && new_pos.x != 0 && new_pos.y != game->dimension.y-1 && new_pos.y != 0 ){
			// si les nouvelles positions sont des murs
			if (game->board[new_pos.y][new_pos.x] != ' '
			&& game->board[new_pos.y][new_pos.x] != 'P'
			&& game->board[new_pos.y][new_pos.x] != 'E'
			&& game->board[new_pos.y][new_pos.x] != '*'
			&& game->board[new_pos.y][new_pos.x] != SNAKE_CHAR){

				// bloquer la tete du snake devant le mur
				new_pos.x=old_pos.x;
				new_pos.y=old_pos.y;

			}
		}

	// si la tete du snake sort de la matrice, alors il re-apparait à l'oppposé
		//si bordures sont ON, alors le snake perd une vie
    if(new_pos.x>=game->dimension.x-1){
		if (game->border==1){ game->life--;}
        new_pos.x = 1;
    } else if(new_pos.x<1){
		if (game->border==1){ game->life--;}
        new_pos.x = game->dimension.x-2;
    } else if(new_pos.y>=game->dimension.y-1){
		if (game->border==1){ game->life--;}
        new_pos.y = 1;
    } else if(new_pos.y<1){
		if (game->border==1){ game->life--;}
        new_pos.y = game->dimension.y-2;
    }

	// actualiser les positions de la tete du snake dans la matrice board
    game->board[new_pos.y][new_pos.x] = SNAKE_CHAR;

	// si la tete du snake est libre de ce deplacer
	if(new_pos.x != old_pos.x || new_pos.y != old_pos.y){
		// le corp du snake suit la tete: chaque élément prend la place de son précèdant
		for(int i=0; i<game->snake_size; i++){
	        position_t tmp = game->snake_position[i];
	        game->snake_position[i] = new_pos;
	        new_pos = tmp;
		}
		// effacer l'element du corp apres déplacement vers son precedant
		game->board[new_pos.y][new_pos.x] = VOID_CHAR;
	}
	// memoriser dans la direction de la tete snake le déplacement
	game->direction = offset;
}

// Procédure permettant un mouvement permanant dans la meme direction de la tete du snake
void game_keep_moving(game_t* game){
    game_move(game, game->direction);
}

// Procédure permettant à la tete du snake de monter en donnant un deplacement de x=0 et y=-1
void game_up(game_t* game){
    game_move(game, position_create(0,-1));
}

// Procédure permettant à la tete du snake de descendre en donnant un deplacement de x=0 et y=1
void game_down(game_t* game){
    game_move(game, position_create(0,1));
}

// Procédure permettant à la tete du snake de tourner à gauche en donnant un deplacement de x=-1 et y=0
void game_left(game_t* game){
    game_move(game, position_create(-1,0));
}

// Procédure permettant à la tete du snake de tourner à droite en donnant un deplacement de x=1 et y=0
void game_right(game_t* game){
    game_move(game, position_create(1,0));
}

// Procédure permettant l'agrandir la taille du snake (ajouter un element à la liste snake_position)
void game_snake_size_up(game_t* game){

	// variables
		// nouvelle position de l'element
	position_t new_pos;
		// position du dernier (last) et de l'avant dernier (lastlast)
	position_t ll_pos;
	position_t l_pos;

	// taille augmente de 1
    game->snake_size++;

	l_pos = game->snake_position[game->snake_size-2];//penser à que game->size a augmenté mais n'est pas encore actif sur les coordonnées d'ou le dernier est N-2
	ll_pos = game->snake_position[game->snake_size-3];//penser à que game->size a augmenté mais n'est pas encore actif sur les coordonnées d'ou l'avant dernier est N-3

	// allouer une nouvelle place pour le nouvel element de type position_t (deux coordonnées)
	game->snake_position = realloc(game->snake_position, game->snake_size*sizeof(position_t));

    // Gerer la position d'apparition du nouvel element
		// uniquement si la taille du snake est superieur à 1
		//(penser à que game->size a augmenté mais n'est pas encore actif sur les coordonnées d'ou 2)
			// alors le nouvel element se place dans la continuité des deux derniers devant lui
	if(game->snake_size>2){

    	// les 4 cas possibles
        if(ll_pos.x==l_pos.x && ll_pos.y<l_pos.y){
            new_pos = position_create(l_pos.x, l_pos.y+1);
        } else if(ll_pos.x==l_pos.x && ll_pos.y>l_pos.y){
            new_pos = position_create(l_pos.x, l_pos.y-1);
        } else if(ll_pos.y==l_pos.y && ll_pos.x<l_pos.x){
            new_pos = position_create(l_pos.x+1, l_pos.y);
        } else if(ll_pos.y==l_pos.y && ll_pos.x>l_pos.x){
            new_pos = position_create(l_pos.x-1, l_pos.y);
        }
    }
	// si la taille du snake est 1 (Juste tete)
	//(penser à que game->size a augmenté mais n'est pas encore actif sur les coordonnées)
	else{
		// dans ce cas la position du nouvel element depend de la direction de la tete du snake
        new_pos = game->snake_position[game->snake_size-2];
        new_pos.x -= game->direction.x;
        new_pos.y -= game->direction.y;
    }
	// on imprime le dernier element à la matrice board grace à ces positions maintenant fixées
    game->snake_position[game->snake_size-1] = new_pos;
    game->board[new_pos.y][new_pos.x] = SNAKE_CHAR;
}

// Procédure permettant d'ajouter different type d'obstacles
void game_add_obstacle(game_t* game, obstacle_t obstacle){

	// variables
	position_t pos = obstacle.pos;

	// Uniquement si l'obstacle se trouve dans la matrice
    assert(pos.x>=0 && pos.x<game->dimension.x && pos.y>=0 && pos.y<game->dimension.y);

	// on imprime le caratère de l'obstacle dans la matice board grace à ces positions données en paramètre par la struct obstacles
    game->board[pos.y][pos.x] = obstacle.obstacle_type;

	// si il n'y a pas encore d'obstacle, on le cree
	if(game->obstacles_count==0){
		// Initialise le nombre d'obstacle à 1
        game->obstacles_count = 1;
		// alloue dynamiquement une place memoire pour obstacles de type obstacle_t
        game->obstacles = malloc(sizeof(obstacle_t));
		// alloue dynamiquement une place memoire pour une liste de int temoignant du nombres d'impact entre les obstacles et les murs
		game->obstacle_hit_wall = malloc(sizeof(int));
		// alloue dynamiquement une place memoire pour une liste de position des obstacles
		game->direction_obstacles = malloc(sizeof(position_t));
		// alloue dynamiquement une place memoire pour une liste de position "intelligentes" obstacles de type obstacle_t
		game->track_direction_obstacles = malloc(sizeof(position_t));

    }
	// si on ajoute un nouvel obstacle
	else{
		// taille de la liste d'obstacle augmente
        game->obstacles_count++;

		// alloue dynamiquement une nouvel place pour le nouvel element dans toutes les listes dependant du nombres d'obstacle
        game->obstacles = realloc(game->obstacles, game->obstacles_count*sizeof(obstacle_t));
		game->obstacle_hit_wall = realloc(game->obstacle_hit_wall, game->obstacles_count*sizeof(int));
		game->direction_obstacles = realloc(game->direction_obstacles, game->obstacles_count*sizeof(position_t));
		game->track_direction_obstacles = realloc(game->track_direction_obstacles, game->obstacles_count*sizeof(position_t));

    }
	// initialise les listes précedament reservées en memoire
    game->obstacles[game->obstacles_count-1] = obstacle;
	game->obstacle_hit_wall[game->obstacles_count-1] = 0;
	game->direction_obstacles[game->obstacles_count-1] = position_create(0,0);
	game->track_direction_obstacles[game->obstacles_count-1] = position_create(0,0);

}

// Procédure permettant de couper la queue du snake à l'indice 'index' donné en parametre
void game_snake_cut(game_t* game,int index){

	//variables
	int i=0;

	// effacer le reste de la queue
	for(i=index; i<game->snake_size;i++){
		game->board[game->snake_position[i].y][game->snake_position[i].x] = VOID_CHAR;
	}
	// Mettre à jour la taille de snake_size et ajuster en memoire la liste des positions du snake
    game->snake_size=index;
    game->snake_position = realloc(game->snake_position, game->snake_size*sizeof(position_t));
}

// Fonction renvoyant zero si pas de conctact entre snake et les obstacles sinon renvoie l'indice du contact (pour game_snake_cut)
int game_snake_hit_no_head(game_t* game, obstacle_t* obstacle){

	//variables
		//index reste nulle si pas de contact
	int index = 0;
	int i=0, j=0;

	// parcours la liste de position du snake et des obstacles et croise les coordonnées pour verifier les contacts
	for (i=1; i<game->snake_size; i++){
	    for(j=0 ; j<game->obstacles_count ; j++){
			// cas contact
	        if(game->snake_position[i].x==game->obstacles[j].pos.x && game->snake_position[i].y==game->obstacles[j].pos.y){
				// memorize l'ostacle en question (ses caraterisques et l'indice de la liste obstacles)
				*obstacle = game->obstacles[j];
	            index=i;
	        }
	    }
	}
	// revoie l'indice ou zero si pas de contact
	return index;
}

// Fonction renvoyent un booleen : true correspondant au snake mord ca queue sinon false
bool game_snake_hit_snake(game_t* game){
	// si la future position du snake est un X alors return true sinon false
	if(game->board[game->snake_position[0].y+game->direction.y]
		[game->snake_position[0].x+game->direction.x]==SNAKE_CHAR){
			return true;
	}else return false;
}

// Procédure permettant de retirer l'obstacle de la liste obstacles
void remove_obstable(game_t* game,int index){

	//variables
	obstacle_t tmp;
	int i=0;

	// Mettre à jour l'espace memoire de la liste d'obstacle (reduire de 1)
	obstacle_t* new_liste=malloc ( (game->obstacles_count-1)* sizeof(obstacle_t));

	//nouvelle liste avec les obstacles
    for(i=0; i<index; i++){
		new_liste[i]=game->obstacles[i];
	}
	for(i=(index+1); i<game->obstacles_count; i++){
		new_liste[i-1]=game->obstacles[i];
	}
	// met a jour la nouvelle liste
	for (i=0;i<game->obstacles_count;i++){
        game->obstacles[i]=new_liste[i];
	}
	// reduire obstacle_count de 1
    game->obstacles_count--;

	// Liberer la liste temporaire
	free(new_liste);
}

// Fonction renvoyent un booleen : true correspondant impact snake-obstacle (et memorize l'obstacle et l'index de l'obstacle)
bool game_has_hit(game_t* game, obstacle_t* obstacle, int* index){

	// variables
	position_t pos = game->snake_position[0];
	obstacle_t obs;
	int i=0;

	// parcours la liste de position d'obstacles
    for(i=0 ; i<game->obstacles_count ; i++){
		obs = game->obstacles[i];
        // si un l'obstacle[i] et en contact avec la tete du snake, alors true
        if(pos.x==obs.pos.x && pos.y==obs.pos.y){
			// memorize l'obstacle et l'index de l'obstacle
			*index=i;
            *obstacle = obs;
            return true;
        }
    }
	// pas de contact alors false
    return false;
}

// Procédure permentant d'afficher le board à l'écran (avec un centrage)
void game_display(game_t* game){

	//variables
	int i=0, j=0, k=9;

	// pour chaque ligne
    for(i=0 ; i<game->dimension.y ; i++)
    {
		// centrage
        gotoXY(10, 5+i);
		// donne la longueur de la ligne
        for(j=0; j<game->dimension.x; j++)
      {
      	if (game->board[i][j]==SNAKE_CHAR) // si  pacman
      	{
				Color(14,0); //texte en jaune fluo
                printf("%c", game->board[i][j]); // imprime le pacman
           		Color(12,0); // retour texte en rouge
      	}

      	else if (game->board[i][j]== 'E') // si fantome
      	{

      			Color(11,0); // texte turquoise
                printf("%c", game->board[i][j]); // imprime les fantomes
           		Color(12,0); // retour texte en rouge

      	}
      	else if (game->board[i][j]== 'P') // si pomme
      	{
      		Color(2,0); // texte en vert
      		printf("%c", game->board[i][j]); // imprime les fontomes
      		Color(12,0); // retour en rouge
      	}
      	else if(game->board[i][j]== '*') // si yunkunkun
      	{
      		Color(k,0); // couleur en fonction de k qui change a chaque passage
      		printf("%c", game->board[i][j]); // imprime les yunkunkun
      		Color(12,0); // retour couleur rouge
      		k++ ; // itération pour couleur
      	}
      	else // pour le reste
      	{
      		printf("%c", game->board[i][j]);// imprime
      	}

      }
		// saut de ligne pour afficher la ligne suivante
        printf("\n");
    }
}

// Procédure librant l'espace allouer pour le jeu
void game_free(game_t* game){

	// variables
	int i=0 ;

	// liberation du malloc le plus profond au moins profond
    for(i=0 ; i<game->dimension.y ; i++){
        free(game->board[i]);
    }
	free(game->board);
    free(game->snake_position);
    free(game->obstacles);
	free(game->obstacle_hit_wall);
	free(game->direction_obstacles);
	free(game->track_direction_obstacles);
    free(game);
}

// Procédure qui compte le nombre de fois d'un obstacle touche un mur et stock cela pour chaque obstacle dans obstacle_hit_wall
void check_obstacle_hit_wall (game_t* game){

	//variables
	int i=0;

	// pour chaque obstacle (utile que pour les 'E')
	for (i=0; i< game->obstacles_count;i++)
	{
		//L'obstacle se deplace selon l'axe de Y
		if (game->direction_obstacles->x==1 || game->direction_obstacles->x==-1){
			// verifie s'il y a un mur devant lui, si oui, augmente de 1 obstacle_hit_wall
			if (game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x+1] != ' '
			&& game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x+1] != game->obstacles->obstacle_type
			&& game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x+1] != SNAKE_CHAR){
					game->obstacle_hit_wall[i]++;
			}
			// verifie s'il y a un mur devant derriere, si oui, augmente de 1 obstacle_hit_wall
			if (game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x-1] != ' '
			&& game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x-1] != game->obstacles->obstacle_type
			&& game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x-1] != SNAKE_CHAR){
					game->obstacle_hit_wall[i]++;
			}
		}
		//L'obstacle se deplace selon l'axe de X
		if (game->direction_obstacles->y==1 || game->direction_obstacles->y==-1){
			// verifie s'il y a un mur au dessus de lui, si oui, augmente de 1 obstacle_hit_wall
			if (game->board[game->obstacles[i].pos.y+1][game->obstacles[i].pos.x] != ' '
			&& game->board[game->obstacles[i].pos.y+1][game->obstacles[i].pos.x] != game->obstacles->obstacle_type
			&& game->board[game->obstacles[i].pos.y+1][game->obstacles[i].pos.x] != SNAKE_CHAR){
					game->obstacle_hit_wall[i]++;
			}
			// verifie s'il y a un mur en dessous de lui, si oui, augmente de 1 obstacle_hit_wall
			if (game->board[game->obstacles[i].pos.y-1][game->obstacles[i].pos.x] != ' '
			&& game->board[game->obstacles[i].pos.y-1][game->obstacles[i].pos.x] != game->obstacles->obstacle_type
			&& game->board[game->obstacles[i].pos.y-1][game->obstacles[i].pos.x] != SNAKE_CHAR){
					game->obstacle_hit_wall[i]++;
			}
		}
	}
}

// Procédure permettant le mouvement de l'obstacles à l'indice 'index' (uniquement 'E') selon border, le niveau et si les obstacles sont intelligent ou pas
void game_obstacle_move( game_t* game, int index){

	// Variables
	position_t new_pos;
    position_t old_pos;
    position_t offset;
    position_t random_offset;
    position_t track_offset;
	int i=0;



	// Uniquement les E
	if (game->obstacles[index].obstacle_type =='E'){

		// déplacement : Random ou IA

			// level 1 et 2 : Move randomly
		if (game->level<=2){
			random_offset= randomdirection();
		}

			// level 3 et 4 : Move avec IA
		else if( game->level>2){ ;
			track_offset=game->track_direction_obstacles[index];
		}

		// Verifie le nombre de fois que chaque obstacle touche un un mur
			// si ce nombre est paire alors il suit le deplacement
		if (game->obstacle_hit_wall[i] % 2 == 0) {

				// cas random
			if (game->level<=2){
            	offset.x= random_offset.x;
				offset.y= random_offset.y;
			}
				// cas IA
			else if( game->level>2){
				offset.x= track_offset.x;
				offset.y= track_offset.y;
           }
		}
			// si ce nombre est impaire alors il suit l'oppposé du deplacement
		else{
				// cas random
            if (game->level<=2){
				offset.x= -random_offset.x;
				offset.y= -random_offset.y;
            }
				// cas IA
			else if(game->level>2){
					// cas IA pas besoin de rebondir
				offset.x= track_offset.x;
				offset.y= track_offset.y;
            }
		}


		// memorise la position de chaque obstacle
		old_pos.x = game->obstacles[index].pos.x;
        old_pos.y = game->obstacles[index].pos.y;
		// memorise la future position (position + deplacement) de chaque obstacle
		new_pos.x=old_pos.x+offset.x;
        new_pos.y=old_pos.y+offset.y;


		// Si border ON alors l'obstacles rebondi
		if (game->border==1){
			// si l'obstacle touche un mur ou 'P' ou '*', alors il rebondi
			if (game->board[new_pos.y][new_pos.x] != ' '
			&& game->board[new_pos.y][new_pos.x] != SNAKE_CHAR){
						// la future position va a l'opposé du mur
						new_pos.x=old_pos.x-offset.x;
						new_pos.y=old_pos.y-offset.y;
					}
		}

		// Si border OFF, l'obstacle revient de l'autre coté et rebondi contre le labyrinthe ou  le 'P' ou le '*'
		else if(game->border==0){


			// si l'obstacle touche un mur du labyrinthe ou 'P' ou '*' (pas de la bordure donc)
			if (new_pos.x != game->dimension.x-1
				&& new_pos.x != 0 && new_pos.y != game->dimension.y-1
				&& new_pos.y != 0 ){

					if (game->board[new_pos.y][new_pos.x] != ' '
					&& game->board[new_pos.y][new_pos.x] != SNAKE_CHAR){
								// la future position va a l'opposé du labyrinthe, du 'P', du '*'
								new_pos.x=old_pos.x-offset.x;
								new_pos.y=old_pos.y-offset.y;
							}
			}
			else{
				//si l'obstacle ne touche pas le labyrinthe ou le 'P' ou  le '*' mais sort de la matrice
					// l'obstacle revient de l'autre coté
				if(new_pos.x>=game->dimension.x-1){ new_pos.x = 1;}
				else if(new_pos.x<1){ new_pos.x = game->dimension.x-2;}
				else if(new_pos.y>=game->dimension.y-1){ new_pos.y = 1;}
				else if(new_pos.y<1){ new_pos.y = game->dimension.y-2;}
			}
		}
		// Mise à jour de la position dans le board et efface les anciennes positions
		game->obstacles[index].pos=new_pos;
		game->board[old_pos.y][old_pos.x] = VOID_CHAR;
		game->board[new_pos.y][new_pos.x] = game->obstacles[index].obstacle_type;

		// memorise dans la liste de direction le déplacement
			// cas random
		if (game->level<=2){
			game->direction_obstacles[index]=offset;
		}
			// cas IA
		else if(game->level>2){
			game->track_direction_obstacles[index]=offset;
		}
	}
}

// Procédure permettant le mouvement des obstacles avec un rapide sur 2
void game_obstacle_move_diverty( game_t* game , int ctr){

	// variables
	int i=0;

	// Pour tous les obstacles
	for (i=0; i<game->obstacles_count; i++){

		// Pour un obstacle sur deux de la liste d'obstacle
		if (i%2==1){
			// alors ne faire bouger cet obstacle que lorsque ctr(le compteur de la boucle de mouvement) modulo 3 est egale un 1
			// cela revient à ralentir l'obstacle, en ne le faisant pas bouger à toute les boucles
			if (ctr%3==1){
				game_obstacle_move(game,i);
			}
		}
		// le reste a une vitesse normal
		else{
			game_obstacle_move(game,i);
		}
	}
}

// Fonction qui renvoie le minimum entre 4 distances (utile pour obstacle_tracking )
int minimun_distance_obstacle(int d1, int d2, int d3, int d4){

	// Variables
	int tab[4]={d1, d2, d3, d4};
	int min= tab[0];
	int i=0;

	// compare tout les elements de la liste et conserve dans min le minimum
	for(i=0; i<3; i++){
		if (tab[i+1]<tab[i]){
			min=tab[i+1];
		}
	}
	// revoyer le minimum apres avoir traverse toute la liste
	return min;
}

// Procédure 'IA' placant dans la liste de direction 'track_direction_obstacles' les deplacements intelligent des obstacles
void obstacle_tracking(game_t* game){

	// Variables
	int obs_x_right=0, obs_x_left=0, obs_x=0, obs_y_over=0, obs_y_under=0, obs_y=0;
	int dist_right=0, dist_left=0, dist_over=0, dist_under=0;
	position_t opt_dir;
	int snake_pos_x;
	int snake_pos_y;
	int i=0;

	// Pour chaque obstacle 'E'
	for (i=0; i<game->obstacles_count; i++){
		if(game->obstacles->obstacle_type=='E'){

			// memorise la position de la tete du snake (soit du PacMan)
			snake_pos_x = game->snake_position[0].x;
			snake_pos_y = game->snake_position[0].y;

			// memorise les positions au dessus, en dessous, à gauche, à droite de l'obstacle (en x et y)
			obs_x= game-> obstacles[i].pos.x;
			obs_x_right= obs_x+1;
			obs_x_left= obs_x-1;

			obs_y= game-> obstacles[i].pos.y;
			obs_y_under= obs_y+1;
			obs_y_over= obs_y-1;

			// calcul la distance des points entourant 'E' par rapport à la tete de l'obstacle
			dist_right=sqrt(pow((obs_x_right-snake_pos_x),2)+ pow((obs_y-snake_pos_y),2));
			dist_left=sqrt(pow((obs_x_left-snake_pos_x),2)+ pow((obs_y-snake_pos_y),2));
			dist_over=sqrt(pow((obs_x-snake_pos_x),2)+pow((obs_y_over-snake_pos_y),2));
			dist_under=sqrt(pow((obs_x-snake_pos_x),2)+pow((obs_y_under-snake_pos_y),2));

			// si la distance minimum correspond au point à droite de l'obstacle
			if (minimun_distance_obstacle(dist_right,dist_left,dist_over,dist_under)==dist_right) {
				// alors la direction optimale est vers la droite donc déplacement (x=1, y=0)
				opt_dir=position_create(1,0);

			}
			// si la distance minimum correspond au point à gauche de l'obstacle
			else if (minimun_distance_obstacle(dist_right,dist_left,dist_over,dist_under)==dist_left) {
				// alors la direction optimale est vers la gauche donc déplacement (x=-1, y=0)
				opt_dir=position_create(-1,0);

			}
			// si la distance minimum correspond au point au dessus de l'obstacle
			else if (minimun_distance_obstacle(dist_right,dist_left,dist_over,dist_under)==dist_over) {
				// alors la direction optimale est vers le haut donc déplacement (x=0, y=-1)
				opt_dir=position_create(0,-1);

			}
			// si la distance minimum correspond au point en dessous de l'obstacle
			else if (minimun_distance_obstacle(dist_right,dist_left,dist_over,dist_under)==dist_under) {
				// alors la direction optimale est vers le bas donc déplacement (x=0, y=1)
				opt_dir=position_create(0,1);

			}
			// pour chaque obstacle, on stock cette direction optimale dans la liste de direction track_direction_obstacles (champ de la struct game)
			game->track_direction_obstacles[i] = opt_dir;
		}
	}
}

// Procédure permettant d'afficher des pommes à l'écran
void print_apples(game_t* game, int nb_apple){

	// variables
	int rX=0, rY=0, i=0;

	// ajout de "nb_pomme" pommes dans une position aleatoire dans la zone de jeu et dans un espace vide
	for (i=0;i<nb_apple;i++){
		do{
			rX = randomX(game->dimension.x);
			rY = randomY(game->dimension.y);
		}while(game->board[rY][rX] != ' ' || rX==game->dimension.x-1 || rX==0 || rY==game->dimension.y-1 || rY==0);
	game_add_obstacle(game, obstacle_create('P',rX,rY));
	}
}

// Procédure permettant d'afficher des ennemies à l'écran
void print_ennemies(game_t* game, int nb_ghost){
	int rX=0, rY=0, i=0;

	// ajout de "nb_ghost" ennemies dans une position aleatoire dans la zone de jeu et dans un espace vide
	for (i=0;i<nb_ghost;i++)
	{
	   do{
		   rX = randomX(game->dimension.x);
		   rY = randomY(game->dimension.y);
   }while(game->board[rY][rX] != ' ' || rX==game->dimension.x-1 || rX==0 || rY==game->dimension.y-1 || rY==0);
	  game_add_obstacle(game, obstacle_create('E',rX,rY));
	}
}
