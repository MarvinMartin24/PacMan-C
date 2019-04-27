#include "niveaux.h"


// Procédure permettant de un pause en miliseconde
void delay(int number_of_miliseconds){
	clock_t start_time = clock();
	while (clock() < start_time + number_of_miliseconds);
}

// Procédure permettant de sauvegarder dans un fichier le niveau et la vie
void save(game_t* game){

	//variable (pointer)
    FILE *file;

	// ouverture du mode fichier en mode ecriture
    file = fopen("save.txt", "w");

    // Traitement de l'erreur d'ouverture du fichier
    if ( file == NULL)
    {
        printf("Impossible d'ouvrir en ecriture\n");

    }
    else // ouverture du fichier reussie
    {
		// impression des donnees (level sur la premier ligne et life sur la ligne)
		fprintf(file, "%d\n", game->level);
		fprintf(file, "%d", game->life);

	// fermeture du fichier file
    fclose(file);
    }
}

int read_save(int index){

	//Variables
	FILE *file;
	int level[2];


    // ouverture du mode fichier en mode lecture
    file = fopen("save.txt", "r");

    // Traitement de l'erreur d'ouverture du fichier
    if ( file == NULL)
    {
        printf("Impossible d'ouvrir en lecture\n");

    }
    else // ouverture du fichier réussie
    {
		// recuperation des donnees dans la liste
		fscanf(file,"%d",&level[0]);
		fscanf(file,"\n%d",&level[1]);
		// fermeture du fichier
    	fclose(file);
	}
	// revoyant le level si parametre est 1 et life si 2
	if (index==0){
		return level[0];
	}
	else if (index==1){
		return level[1];
	}
}

//Procédure remplissant d'espace le board (nettoyage)
void clear_board(game_t* game){

		for (int j=0; j<game->dimension.y;j++)
        {
            for (int k=0; k<game->dimension.x;k++)
            {
                game->board[j][k]=' ';
            }
        }

}

void niveaux(game_t* game, int vitesse)
{

	int height = 20,width = 50;
	int nb_apple = 5;
	int nb_gost = 4;
	int rX = 0, rY = 0;
	int i = 0;
	int ctr=0;
	int ctr_for_snake = 1;
	int score=0, duree=0;
	int orignal_speed=vitesse;
	int dub=0;



	obstacle_t hit;
	int index_obs_hit;
	int counter_obstacle_hit_border=0;
	char touch=0;
	int can_keep_moving;


    clear_board(game);

	system("cls");
	printf("border %d",game->border);
	if (game->border==1){game_map(game);}


    while(game->level<5){


	if(game->level==1){
        system("cls");
        affichetableau1();
        getch();
        system("cls");
        vitesse=orignal_speed;
		print_apples(game, nb_apple);
	}



	do{

		save(game);    // sauvegarde du jeu
        duree++;
		can_keep_moving=1;

        if (kbhit()){                       // deplacement du pac-man
			touch = getch();

            if(touch=='2'){
				can_keep_moving=0;
            	game_down(game);
            } else if(touch=='8'){
				can_keep_moving=0;
            	game_up(game);
            } else if(touch=='6'){
				can_keep_moving=0;
            	game_right(game);
            } else if(touch=='4'){
				can_keep_moving=0;
            	game_left(game);
            } else if(touch=='p'){
                getch();
            }else if(touch=='q'){
				free(game);
                system("cls");
                return;

            }
		}

		if (can_keep_moving==1){
			game_keep_moving(game);
		}


		check_obstacle_hit_wall(game);      //check borders

		game_display(game);             //affichage du jeu



		//check head contact
        if(game_has_hit(game,&hit,&index_obs_hit)){
			if(hit.obstacle_type=='E'){                 //perte de vie

				game->life--;
			}
			if(hit.obstacle_type=='P'){                 //augmentation du score
				remove_obstable(game, index_obs_hit);
                score+=10;
            }
		}
        if (game->life==0){   //game over
			save(game);
            system("cls");
            affichegameover();
            getch();
            return;}

		if (score>=(nb_apple*10)){game->level=2;}   // passage au niveau suivant


		gotoXY(10,3);
		printf(" _____________");
		gotoXY(10,4);
		printf("|");
		Color(15,0);
		printf("  Niveau : %d ", game->level);
		Color(12,0);
		printf("|");
		gotoXY(10,25);
		printf(" _________\t\t\t _______");
		gotoXY(10,26);
		printf("|");
		Color(15,0);
        printf("Score: %d ",score);
        Color(12,0);
        printf("|");
        printf("\t\t\t");
        printf("|");
        Color(15,0);
        printf("vies=%d ",game->life);
        Color(12,0);
        printf("|");

        delay(vitesse);
		ctr++;

	}while ((game->level==1));






	// si tableau 2
	if (game->level == 2){
        system("cls");
        affichetableau2(); // afiche écran de transistion
        getch();
        system("cls");
        vitesse=orignal_speed;
		score=50;
        print_ennemies(game, nb_gost); //affiche les fantomes
        print_apples(game, nb_apple); // affiche les pomme
        //repositionnement du X
        game->board[game->snake_position[0].y][game->snake_position[0].x]=' ';
        do{
    	game->snake_position[0] = position_create(randomX(width),randomY(height));
        }while (game->snake_position[0].x!=' ');
	}


    do {

		save(game); // sauvegarder tableau 2
        duree++;
		can_keep_moving=1; // continuer mouvement

        if (kbhit()){
			touch = getch(); // entrée clavier

            if(touch=='2'){
				can_keep_moving=0; //arret
            	game_down(game);	// descente
            } else if(touch=='8'){
				can_keep_moving=0;
            	game_up(game);		//monter
            } else if(touch=='6'){
				can_keep_moving=0;
            	game_right(game);	//droite
            } else if(touch=='4'){
				can_keep_moving=0;
            	game_left(game);	//gauche
            } else if(touch=='p'){
                getch();			//pause
            }else if(touch=='q'){
				free(game);			//quitter
                system("cls");
                return;
            }
		}

		if (can_keep_moving==1){
			game_keep_moving(game);
		}


		check_obstacle_hit_wall(game);
		obstacle_tracking(game);

		for(int i=0; i<game->obstacles_count; i++){
			game_obstacle_move(game,i);
		}

		game_display(game);


		//check head contact
        if(game_has_hit(game,&hit,&index_obs_hit)){
			if(hit.obstacle_type=='E'){ // si on est sur un fantome
				game->life--; // retire 1 point de vie
			}
			if(hit.obstacle_type=='P'){ // si on est sur une pomme
				remove_obstable(game, index_obs_hit);
                score+=10; // ajoute 10 de score

            }
		}
		 if (game->life==0){ // si vie = 0
            system("cls");
            affichegameover();// afficher l ecran de game over
            getch();
            return;}

		if (score>=(20*nb_apple)){game->level=3;}

// affichage du niveau vie et score
		gotoXY(10,3); // placer a la position ligne 3
		printf(" ___________");
		gotoXY(10,4);
		printf("|");
		Color(15,0);
		printf("  Niveau : %d ", game->level);
		Color(12,0);
		printf("|");
		gotoXY(10,25);
		printf(" ________\t\t\t ______");
		gotoXY(10,26);
		printf("|");
		Color(15,0);
        printf("Score: %d ",score);
        Color(12,0);
        printf("|");
        printf("\t\t\t");
        printf("|");
        Color(15,0);
        printf("vies=%d ",game->life);
        Color(12,0);
        printf("|");

        delay(vitesse);	//attente
		ctr++;
	}while (game->level==2); // tant qu'on est sur le tableau 2





	if (game->level==3){
        system("cls");
        affichetableau3();
        getch();
        system("cls");

        game_maze(game);                    //creation des murs
		score=100;

        print_apples(game, nb_apple);
        game->board[game->snake_position[0].y][game->snake_position[0].x]=' ';
        do{
    	game->snake_position[0] = position_create(randomX(width),randomY(height));
        }while (game->snake_position[0].x!=' ');

	}


	do{

		save(game);

        duree++;
		can_keep_moving=1;

        if (kbhit()){
			touch = getch();

            if(touch=='2'){
				can_keep_moving=0;
            	game_down(game);
            } else if(touch=='8'){
				can_keep_moving=0;
            	game_up(game);
            } else if(touch=='6'){
				can_keep_moving=0;
            	game_right(game);
            } else if(touch=='4'){
				can_keep_moving=0;
            	game_left(game);
            } else if(touch=='p'){
                getch();
            }else if(touch=='q'){
				free(game);
                system("cls");
                return;
            }
		}

		if (can_keep_moving==1){
			game_keep_moving(game);
		}


		check_obstacle_hit_wall(game);
		obstacle_tracking(game);


		// si aucune pomme manger � la frenquence d'apparition des obstacles de change pas : vitesse constante
			// dans se cas ctr_for_snake=1 et donc ctr%1=0
		if (ctr % ctr_for_snake == 0){
			// faire bouger tous des obstacles � vitesse differente
			game_obstacle_move_diverty(game, ctr);
		}
		//Ralentir les obstacles quand le snake mange une pomme (en meme temps la vitesse de la loop augmente)
			// Ne afficher les obstacles � chaque boucle realiser, la frequence d�pend de ctr_for_snake qui depend du nb de pommes manger
		if (ctr % ctr_for_snake == 1){
			// faire bouger tous des obstacles � vitesse differente
			game_obstacle_move_diverty(game, ctr);
		}

		game_display(game);



		//check head contact
        if(game_has_hit(game,&hit,&index_obs_hit)){
			if(hit.obstacle_type=='E'){
				game->life--;
			}
			if(hit.obstacle_type=='P'){
				remove_obstable(game, index_obs_hit);
                score+=10;
				ctr_for_snake+=1;
				vitesse-=20;
            }
		}
		 if (game->life==0){
            system("cls");
            affichegameover();
            getch();
            return;}

		if (score>=(30*nb_apple)){game->level=4;}


		gotoXY(10,3);
		printf(" _____________");
		gotoXY(10,4);
		printf("|");
		Color(15,0);
		printf("  Niveau : %d ", game->level);
		Color(12,0);
		printf("|");
		gotoXY(10,25);
		printf(" _________\t\t\t _______");
		gotoXY(10,26);
		printf("|");
		Color(15,0);
        printf("Score: %d ",score);
        Color(12,0);
        printf("|");
        printf("\t\t\t");
        printf("|");
        Color(15,0);
        printf("vies=%d ",game->life);
        Color(12,0);
        printf("|");


        delay(vitesse);
		ctr++;

	}while(game->level==3);



	if (game->level==4){
        system("cls");
        affichetableau4();
        getch();
        system("cls");
        game_maze(game);
		score=150;
		vitesse=orignal_speed;
		ctr_for_snake=1;

		print_apples(game, nb_apple);





		game->board[game->snake_position[0].y][game->snake_position[0].x]=' ';
        do{
    	game->snake_position[0] = position_create(randomX(width),randomY(height));
        }while (game->snake_position[0].x!=' ');

	 }

    int temps=duree;

	do{
		save(game);
        duree++;


		if (duree%15==0){
			for (i=0;i<3;i++){     //spawn temporaire des yukunkun
		        do{
				rX = randomX(width);
				rY = randomY(height);
			}while(game->board[rY][rX] != ' ' || rX==game->dimension.x-1 || rX==0 || rY==game->dimension.y-1 || rY==0);
				game_add_obstacle(game, obstacle_create('*',rX,rY));
		        }
		}

        if (duree%25==1){          //disparition des yukunkun
            for (int i=0; i<game->obstacles_count; i++){
                if(game->obstacles[i].obstacle_type=='*'){
                    game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x]=' ';
					remove_obstable(game,i);
                }
            }
        }






		can_keep_moving=1;

        if (kbhit()){
			touch = getch();

            if(touch=='2'){
				can_keep_moving=0;
            	game_down(game);
            } else if(touch=='8'){
				can_keep_moving=0;
            	game_up(game);
            } else if(touch=='6'){
				can_keep_moving=0;
            	game_right(game);
            } else if(touch=='4'){
				can_keep_moving=0;
            	game_left(game);
            } else if(touch=='p'){
                getch();
            }else if(touch=='q'){
				free(game);
                system("cls");
                return;
            }
		}

		if (can_keep_moving==1){
			game_keep_moving(game);
		}


		check_obstacle_hit_wall(game);
		obstacle_tracking(game);

		// si aucune pomme manger � la frenquence d'apparition des obstacles de change pas : vitesse constante
			// dans se cas ctr_for_snake=1 et donc ctr%1=0
		if (ctr % ctr_for_snake == 0){
			// faire bouger tous des obstacles � vitesse differente
			game_obstacle_move_diverty(game, ctr);
		}
		//Ralentir les obstacles quand le snake mange une pomme (en meme temps la vitesse de la loop augmente)
			// Ne afficher les obstacles � chaque boucle realiser, la frequence d�pend de ctr_for_snake qui depend du nb de pommes manger
		if (ctr % ctr_for_snake == 1){
			// faire bouger tous des obstacles � vitesse differente
			game_obstacle_move_diverty(game, ctr);
		}

		game_display(game);



		//check head contact
        if(game_has_hit(game,&hit,&index_obs_hit)){
			if(hit.obstacle_type=='E'){
                game->life--;
                score=nb_apple*30;
			}
			if(hit.obstacle_type=='P'){
				remove_obstable(game, index_obs_hit);
                score+=10;
                dub+=1;  //compteur du nombre de pommes mangees

				game_snake_size_up(game);               // transformation en snake
				ctr_for_snake+=1;
				vitesse-=20;
            }
            if(hit.obstacle_type=='*'){
				for (i=0;i<5;i++){game_snake_size_up(game);}
				remove_obstable(game, index_obs_hit);
                score+=50;
            }
		}

		if (dub==5){ ;          // si toute les pommes sont mangees, fin de la partie
		game->level=1;
		printf("\tVICTORY");
		nb_apple*=2;
		score=0;
		game->snake_size=1;
		clear_board(game);
		getch();
		system("cls");}



		//check body contact
		if(game_snake_hit_no_head(game,&hit)!=0){    //les ennemies coupent la queue du snake
			if(hit.obstacle_type=='E'){
				// cut the snake at the impact position
				game_snake_cut(game,game_snake_hit_no_head(game,&hit));
			}
		}



         if (game->life==0){
            system("cls");
            score=0;
            game->level=1;
            affichegameover();
            getch();
            return;}


		gotoXY(10,3);
		printf(" _____________");
		gotoXY(10,4);
		printf("|");
		Color(15,0);
		printf("  Niveau : %d ", game->level);
		Color(12,0);
		printf("|");
		gotoXY(10,25);
		printf(" _________\t\t\t _______");
		gotoXY(10,26);
		printf("|");
		Color(15,0);
        printf("Score: %d ",score);
        Color(12,0);
        printf("|");
        printf("\t\t\t");
        printf("|");
        Color(15,0);
        printf("vies=%d ",game->life);
        Color(12,0);
        printf("|");


        delay(vitesse);
		ctr++;



	}while(game->level==4);
}
	game_free(game);
}