
#include "menu.h"

// Tableau d'affichage pour le menu d'entrée
char menu[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|****************************************************************|",
"\t|  &&&&&&      &       &&&&&&       &     &      &      &     &  |",
"\t|  &    &     & &      &            & & & &     & &     & &   &  |",
"\t|  &&&&&&    &   &     &            &  &  &    &   &    &  &  &  |",
"\t|  &        & & & &    &            &     &   & & & &   &   & &  |",
"\t|  &       &       &   &&&&&&       &     &  &       &  &     &  |",
"\t|****************************************************************|",
"\t|                                                                |",
"\t|            _____  uuuuuuuuuu                                   |",
"\t|     ___________ uuuuuuu  uuuuu                                 |",
"\t|   ____________ uuuuuuuu  uuuuuu                                |",
"\t|   ___________ uuuuuuuuuuuu                                     |",
"\t|     ________  uuuuuuuuuu   .   .  ~Appuyer sur une touche~  . .|",
"\t|      ________ uuuuuuuuuuuu                                     |",
"\t|        ________uuuuuuuuuuuuuuuu                                |",
"\t|             ____ uuuuuuuuuuuuu                                 |",
"\t|               ____ uuuuuuuuu                                   |",
"\t|________________________________________________________________|",
"                                                                    ",
"                                                                    ",
"\t   ---ECE_PARIS---  Yven-SHUE  Marvin-MARTIN   Anthony-SARKIS     ",

};

// Tableau d'affichage pour les choix des options
char menu1[MAX][LARG] ={
"\t ________________________________________________________________",
"\t| haut => 8                                        droite => 6   |",
"\t| bas  => 2                                        gauche => 4   |",
"\t|                                                                |",
"\t|                _                                               |",
"\t|               |_|   Demarrer une nouvelle partie               |",
"\t|                _                                               |",
"\t|               |_|   Reprendre la partie                        |",
"\t|                _                                               |",
"\t|               |_|   Choix de la difficulte                     |",
"\t|                _                                               |",
"\t|               |_|   Regles du jeu             _______________  |",
"\t|                _                             (_____________(o) |",
"\t|      /|       |_|   Quitter le jeu           /           /     |",
"\t|      |/                                     /           /      |",
"\t|      |/                                    /    MENU   /       |",
"\t|      |/                                   /           /        |",
"\t|     _|_                                  /___________/         |",
"\t|    (___)                                (__________(o)         |",
"\t|________________________________________________________________|"
};

// Tableau d'affichage pour les choix des difficultés
char menudiff[MAX][LARG] ={
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|           1. Vitesse de depart                                 |",
"\t|                _                                               |",
"\t|               |_|  Pacman de vitesse lente                     |",
"\t|                _                                               |",
"\t|               |_|  Pacman de vitesse moyenne (par defaut)      |",
"\t|                _                                               |",
"\t|               |_|  Pacman de vitesse rapide                    |",
"\t|                                                                |",
"\t|            2. Presence des bordures           _______________  |",
"\t|                _                             (_____________(o) |",
"\t|      /|       |_|  OFF (par defaut)          /           /     |",
"\t|      |/        _                            /           /      |",
"\t|      |/       |_|  ON                      /  OPTION   /       |",
"\t|      |/                                   /           /        |",
"\t|     _|_                                  /___________/         |",
"\t|    (___)                                (__________(o)         |",
"\t|________________________________________________________________|"
};

// Tableau d'affichage pour les régles
char menuregle[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                ~Bienvenu sur le jeux PACMAN~                   |",
"\t|                                                                |",
"\t|   En controllant pacman symbolisé par un X vous devrez manger  |",
"\t|   un maximun de diamants mais attention au fur et a mesure que |",
"\t|   vous avancerez la difficulte augmentera, des fontomes        |",
"\t|   seront la pour vous barrer le passage mais bien heuresement  |",
"\t|   vous aurez 5 vies pour vous en echapper. Pour les meilleurs  |",
"\t|   d'entre vous qui auront le courage d'arriver a la fin vous   |",
"\t|   vous challengerez dans un labyrinthe transforme en snake     |",
"\t|   Bon jeux et attention a votre queue !       _______________  |",
"\t|                                              (_____________(o) |",
"\t|      /|                                      /           /     |",
"\t|      |/                                     /           /      |",
"\t|      |/                                    /   REGLES  /       |",
"\t|      |/                                   /           /        |",
"\t|     _|_       ~Appuyer sur une touche~    /___________/        |",
"\t|    (___)                                (__________(o)         |",
"\t|________________________________________________________________|"
};

// Tableau d'affichage en cas de defaite
char gameover[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|      &&&&&&&        &        &      &     & & & &              |",
"\t|      &             & &       & &  & &     &                    |",
"\t|      &  &&&&      &   &      &  &&  &     & & & &              |",
"\t|      &     &     & & & &     &      &     &                    |",
"\t|      &&&&&&&    &       &    &      &     & & & &              |",
"\t|                                                                |",
"\t|                    & & & & &  &        &  & & & &    & & &     |",
"\t|                    &       &   &      &   &          &   &     |",
"\t|                    &       &    &    &    & & & &    & & &     |",
"\t|                    &       &     &  &     &          &  &      |",
"\t|        ____        & & & & &      &&      & & & &    &   &     |",
"\t|      ,'    `,                                                  |",
"\t|     /        \\                                                 |",
"\t|     \\ ()  () /                                                 |",
"\t|      `. /\\ ,'                                                  |",
"\t|   8====| "" |====8                                               |",
"\t|       `LLLU'             ~Appuyer sur une touche~              |",
"\t|________________________________________________________________|"
};

char tableau1[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|            _____  uuuuuuuuuu                                   |",
"\t|     ___________ uuuuuuu  uuuuu                                 |",
"\t|   ____________ uuuuuuuu  uuuuuu                                |",
"\t|   ___________ uuuuuuuuuuuu                                     |",
"\t|     ________  uuuuuuuuuu   .   .   . ~ TABLEAU 1 ~  .   .   .  |",
"\t|      ________ uuuuuuuuuuuu                                     |",
"\t|        ________uuuuuuuuuuuuuuuu                                |",
"\t|             ____ uuuuuuuuuuuuu                                 |",
"\t|               ____ uuuuuuuuu                                   |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                 ~Apuyer sur une touche~                        |",
"\t|                                                                |",
"\t| Saviez vous que la touche 'q' permet de quitter et 'p' pause ? |",
"\t|________________________________________________________________|",
};

char tableau2[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                uuuuuuuuu                                       |",
"\t|              uuuuuuuuuuuuu                                     |",
"\t|             uu   uuuuu   uu                                    |",
"\t|            uuu   uuuuu   uuu                                   |",
"\t|            uuu O uuuuu O uuu  .  .  .  ~ TABLEAU 2 ~  .   .  . |",
"\t|            uuuuuuuuuuuuuuuuu                                   |",
"\t|            uu uuuuu uuuuu uu                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                 ~Apuyer sur une touche~                        |",
"\t|                                                                |",
"\t|________________________________________________________________|",
};


char tableau3[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                uuuuuuuuu                                       |",
"\t|              uuuuuuuuuuuuu                                     |",
"\t|             uu   uuuuu   uu                                    |",
"\t|            uuuO  uuuuuO  uuu                                   |",
"\t|            uuu   uuuuu   uuu  .  .  .  ~ TABLEAU 3 ~  .   .  . |",
"\t|            uuuuuuuuuuuuuuuuu                                   |",
"\t|            uu uuuuu uuuuu uu                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                 ~Appuyer sur une touche~                        |",
"\t|                                                                |",
"\t|________________________________________________________________|",
};

char tableau4[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                uuuuuuuuu                                       |",
"\t|              uuuuuuuuuuuuu                                     |",
"\t|             uu O uuuuu O uu                                    |",
"\t|            uuu   uuuuu   uuu                                   |",
"\t|            uuu   uuuuu   uuu  .  .  .  ~ TABLEAU 4 ~  .   .  . |",
"\t|            uuuuuuuuuuuuuuuuu                                   |",
"\t|            uu uuuuu uuuuu uu                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                 ~Appuyer sur une touche~                       |",
"\t|                                                                |",
"\t|________________________________________________________________|",
};


void affichetableau1(){

    int i,j;
    for(i=0;i<MAX;i++) // Affichage des lignes
    {
        for(j=0;j<LARG;j++) // Affichage des colonnes
        {
              if (i >= 2 && i<=14 && j >=2 && j<=33 ) // Condition pour l'interieur du cadre
            {
                Color(14,0); // couleur du texte en Jaune
                printf("%c",tableau1[i][j]); // Affichage de l'interieur du cadre
                Color(12,0); // Retour a la couleur initial (rouge)
            }

            else if (i>= 17 && i<=18 && j >=2 && j<=65)
            {
                Color(5,0); // couleur du texte en pourpre
                printf("%c",tableau1[i][j]); // Affichage de l'interieur du cadre
                Color(12,0); // Retour a la couleur initial (rouge)
            }
            else { // pour le reste
                printf("%c",tableau1[i][j]); // Affichage du cadre
            }

        }
        printf("\n"); // Retour a la ligne
    }
}

void affichetableau2(){

    int i,j;
    for(i=0;i<MAX;i++) // Affichage des lignes
    {
        for(j=0;j<LARG;j++) // Affichage des colonnes
        {
              if (i >= 2 && i<=14 && j >=2 && j<=32 ) // Condition pour l'interieur du cadre
            {
                Color(5,0); // couleur du texte en pourpre
                printf("%c",tableau2[i][j]); // Affichage de l'interieur du cadre
                Color(12,0); // Retour a la couleur initial (rouge)
            }
            else { // pour le reste
                printf("%c",tableau2[i][j]); // Affichage du cadre
            }

        }
        printf("\n"); // Retour a la ligne
    }
}
void affichetableau3(){

    int i,j;
    for(i=0;i<MAX;i++) // Affichage des lignes
    {
        for(j=0;j<LARG;j++) // Affichage des colonnes
        {
              if (i >= 2 && i<=14 && j >=2 && j<=32 ) // Condition pour l'interieur du cadre
            {
                Color(6,0); // couleur du texte en kaki
                printf("%c",tableau3[i][j]); // Affichage de l'interieur du cadre
                Color(12,0); // Retour a la couleur initial (rouge)
            }
            else { // pour le reste
                printf("%c",tableau3[i][j]); // Affichage du cadre
            }

        }
        printf("\n"); // Retour a la ligne
    }
}

void affichetableau4(){

    int i,j;
    for(i=0;i<MAX;i++) // Affichage des lignes
    {
        for(j=0;j<LARG;j++) // Affichage des colonnes
        {
              if (i >= 2 && i<=14 && j >=2 && j<=32 ) // Condition pour l'interieur du cadre
            {
                Color(11,0); // couleur du texte en truquoise
                printf("%c",tableau4[i][j]); // Affichage de l'interieur du cadre
                Color(12,0); // Retour a la couleur initial (rouge)
            }
            else { // pour le reste
                printf("%c",tableau4[i][j]); // Affichage du cadre
            }

        }
        printf("\n"); // Retour a la ligne
    }
}



// Fonction d'affichage du tableau game over
void affichegameover(){

    int i,j;
    for(i=0;i<MAX;i++) // Affichage des lignes
    {
        for(j=0;j<LARG;j++) // Affichage des colonnes
        {
              if (i >= 3 && i<=5 && j >=2 && j<=65 ) // condition pour le 'game'
            {
                Color(14,0); // couleur texte en jaune
                printf("%c",gameover[i][j]); // Affichage
                Color(12,0); // retour a la couleur de base qui est rouge
            }

            else if (i >= 9 && i<=11 && j >=2 && j<=65 ) // Condition pour le 'over'
            {

                Color(14,0); // couleur texte en jaune
                printf("%c",gameover[i][j]); // Affichage
                Color(12,0); // retour a la couleur de base qui est rouge
            }

            else if (i >= 10 && i<=18 && j >=2 && j<=19 ) // Condition pour la téte de mort
            {

                Color(14,0); // couleur texte en jaune
                printf("%c",gameover[i][j]); // Affichage
                Color(12,0); // retour a la couleur de base qui est rouge
            }
            else // Pour le reste du tableau
            {
                printf("%c",gameover[i][j]); // Affichage
            }

        }
        printf("\n"); // retour à la ligne
    }
}

// Fonction pour la couleur avec 2 paramétre le texte et le fond
void Color(int colorTexte,int colorFond){
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,colorFond*16+colorTexte); // 16 couleurs pour chaque paramétre
}

// Fonction pour le positionnement du curseur avec 2 paramétre x (abscisse) et y (ordonée)
void Locate(int x,int y){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE); // récupére un descripteur sur le périphérique de sortie (index de l'entrée)
    COORD C; // coordonnée
    C.X=(SHORT)x;
    C.Y=(SHORT)y;
    SetConsoleCursorPosition(H,C); // repositionner le curseur en fonction du descripteur et de la coordonnée
}
 // Fonction d'affichage du tableau d'entrée de jeux
void affiche(){

    int i,j;
    for(i=0;i<MAX;i++) // Affichage des lignes
    {
        for(j=0;j<LARG;j++) // Affichage des colonnes
        {
              if (i >= 2 && i<=18 && j >=2 && j<=65 ) // Condition pour l'interieur du cadre
            {
                Color(14,0); // couleur du texte en Jaune
                printf("%c",menu[i][j]); // Affichage de l'interieur du cadre
                Color(12,0); // Retour a la couleur initial (rouge)
            }
            else { // pour le reste
                printf("%c",menu[i][j]); // Affichage du cadre
            }

        }
        printf("\n"); // Retour a la ligne
    }
}

 // Fonction d'affichage du tableau des regles
void afficheregle(){

    int i,j;
    for(i=0;i<MAX;i++)// Affichage des lignes
    {
        for(j=0;j<LARG;j++) // Affichage des colonnes
        {
             if (i >= 13 && i<=18 && j >=2 && j<=11 ) // Condition pour le texte des regles
            {
                Color(14,0); // Texte de couleur jaune
                printf("%c",menuregle[i][j]); // Affichage du decor "plume"
                Color(12,0);  // Retour a la couleur initial (rouge)
            }
            else if (i >= 11 && i<=18 && j >=43 && j<=64 )
            {

                Color(14,0); // Texte de couleur jaune
                printf("%c",menuregle[i][j]); // Affichage du decor "papier rouleau"
                Color(12,0);  // Retour a la couleur initial (rouge)
            }

            else { // pour le reste
                printf("%c",menuregle[i][j]); // Affichage du cadre + texte
            }
        }
        printf("\n"); // retourn a la ligne
    }
}

void Afficher(int x,int y){

    int i,j;
    Locate(0,0); // appel de fonction pour la localisation du curseur
    for(i=0;i<MAX;i++) // Affichage des lignes
    {
        for(j=0;j<LARG;j++) // Affichage des colonnes
        {
            if (i==x && j==y) // si on est sur les coordonnes du curseur
            {
                Color(14,0); // Texte de couleur jaune
                printf("X"); // Afichage du curseur
                Color(12,0);// Retour a la couleur initial (rouge)
            }
            else if (i >= 13 && i<=18 && j >=2 && j<=11 )
            {
                Color(14,0);// Texte de couleur jaune
                printf("%c",menu1[i][j]); // Affichage du decor "plume"
                Color(12,0);// Retour a la couleur initial (rouge)
            }
            else if (i >= 11 && i<=18 && j >=40 && j<=64 )
            {

                Color(14,0);// Texte de couleur jaune
                printf("%c",menu1[i][j]); // Affichage du decor "papier rouleau"
                Color(12,0);// Retour a la couleur initial (rouge)
            }
            else // pour le reste
                printf("%c",menu1[i][j]); // Affichage du cadre + texte


        }
        printf("\n"); // retour a la ligne
    }
}

void affichediff(int x,int y){

    int i,j;
    Locate(0,0); // appel de fonction pour la localisation du curseur
    for(i=0;i<MAX;i++) // Affichage des lignes
    {
        for(j=0;j<LARG;j++)// Affichage des colonnes
        {
            if (i==x && j==y) // si on est sur les coordonnes du curseur
            {
                Color(14,0);// Texte de couleur jaune
                printf("X"); // Afichage du curseur
                Color(12,0);// Retour a la couleur initial (rouge)
            }
            else if (i >= 13 && i<=18 && j >=2 && j<=11 )
            {
                Color(14,0);// Texte de couleur jaune
                printf("%c",menudiff[i][j]); // Affichage du decor "plume"
                Color(12,0);// Retour a la couleur initial (rouge)
            }
            else if (i >= 11 && i<=18 && j >=40 && j<=64 )
            {

                Color(14,0);// Texte de couleur jaune
                printf("%c",menudiff[i][j]); // Affichage du decor "papier rouleau"
                Color(12,0);// Retour a la couleur initial (rouge)
            }
            else // pour le reste
                printf("%c",menudiff[i][j]);
        }
        printf("\n"); // retour a la ligne
    }
}

// Fonction pour empecher le deplacement en dehors des cases sur le tableau du menu
void TryMove(int* x,int* y,int vx,int vy){

    if (menu1[*x+vx][*y+vy]=='|') // pour empecher le deplacement à droite ou gauche si présence de '|'
        return; // sortie

    (*x)+=vx;
    (*y)+=vy;
}

// Fonction pour empecher le deplacement en dehors des cases sur le tableau des difficultées
void TryMovediff(int* x,int* y,int vx,int vy){

    if (menudiff[*x+vx][*y+vy]=='|') // pour empecher le deplacement à droite ou gauche si présence de '|'
        return; // sortie

    (*x)+=vx;
    (*y)+=vy;
}

// Fonction pour le deplacement sur le tableau du menu
void mouvement(char touche,int* x, int* y){
            switch(touche) // en fonction de la touche recu
         {
            case '8': // si on appuie sur la touche '8'
            TryMove(x,y,-2,0); // on monte en haut (x = -2 pour la case qui sera à 2 lignes au dessus)
            break; // sortie de condition

            case '2': // si on appuie sur la touche '2'
            TryMove(x,y,2,0); // on descend en bas (x = 2 pour la case qui sera à 2 lignes en dessous)
            break; // sortie de condition
        }
}

// Fonction pour le deplacement sur le tableau des difficultées
void mouvementdiff(char touche,int* x, int* y){
            switch(touche) // en fonction de la touche recu
         {

            case '8': // si on appuie sur la touche '8'
            TryMovediff(x,y,-2,0); // on monte en haut (x = -2 pour la case qui sera à 2 lignes au dessus)
            break; // sortie de condition

            case '2': // si on appuie sur la touche '2'
            TryMovediff(x,y,2,0); // on descend en bas (x = 2 pour la case qui sera à 2 lignes en dessous)
            break; // sortie de condition

#define MAX 23 // on définit le tableau de 23 lignes
#define LARG 69 // et 69 colonnes
        }
}

// fonction pour l'ensemble du menu
void menu_fct(game_t* game){

    int vitesse=100; // vitesse de base réglé sur moyenne
    int bord=0; // Bordure réglé sur off de base
    int height = 20,width = 50;
    int nb_ghost=4;

    Color(12,0);// Texte de couleur rouge
    affiche(); // Appel de la fonction d'affichage pour le début de jeu
    int x = 5; // Positionnement du curseur sur la ligne 5
    int y = 18; // et sur la colonne 18
    char touche = 0; // Initialisation de la variable pour l'entrée du clavier
    touche = getch(); // La variable est affecté a l'entrée de sortie (du clavier)
    if (touche){ // Condition de si la variable a recu une entrée (si une touche a été appuyé)

        system("cls");                  // Effacer l'affichage précedent
        while(touche!=27){               // Boucle tant que la touche echape n'est pas pressé
           Afficher(x,y);               // Appel de la fonction d'affichage pour le menu
           if(kbhit){               // si une touche a été touché et donc en attente de la lecture du caractére
               touche = getch();                // On réafecte l'entrée a la variable "touche"
            }
            mouvement(touche,&x,&y);                // Déplacement du curseur en fonction de la touche pressé et des coordonnées
            if (x==15){x=5;}                 // Condition pour si le curseur descend en dessous de la derniere case autorisé il remonte automatiquement
            if (x==3){x=13;}                // et inversement pour au dessus il redescend
            if(x == 13 && touche =='\r' ){               // si l'utilisateur appuie sur "entrer" quand le curseur est sur la case "quitter le jeu"
                return EXIT_SUCCESS;                 // on arrete le programme
            }



            if (x== 5  &&  touche=='\r'){ // Si l'utilisateur appuie sur "entrer" quand le curseur est sur la premiere case "nouvelle partie"
                 game_t* game = game_create(height,width); // niveau reglé sur tableau 1
                game->level=1;
                game->life=5; // vie reglé sur 5
                game->border=bord;

                niveaux(game,vitesse);}




            // Si l'utilisateur appuie sur "entrer" quand le curseur est sur la deuxiéme case "reprendre partie"
            if (x==  7 &&   touche=='\r'){
                game_t* game = game_create(height,width); // On commence le jeux avec le tableau et la vie de la précedente partie

                game->level=read_save(0);
                game->life=read_save(1);
                game->border=bord;
                if ((game->level==3) || (game->level==4)){print_ennemies(game,nb_ghost);}
                niveaux(game,vitesse);}


            if(x == 11 && touche =='\r' ){              // Si l'utilisateur appuie sur "entrer" quand le curseur est sur la quatriéme case "Regles"

                system("cls");           //Effacer l'affichange précedent
                afficheregle(x,y);          // Appel de la fonction d'affichage pour les regles

                 while(touche!=121){             // Boucle tant que la touche y n'est pas pressé
                     if (touche){                // Condition de si la variable a recu une entrée (si une touche a été appuyé)

                        touche = getch();                // On réafecte l'entrée à la variable "touche"
                        touche = 121;                    // On sort de la boucle en attribuant y a la variable "touche"
                     }
                 }
            }

            if(x == 9 && touche =='\r' ){                        // Si l'utilisateur appuie sur "entrer" quand le curseur est sur la troisiéme case "choix de la difficulté"
                x=5 ;                                   // Positionnement du curseur sur la ligne 5
                y=18;                               // et sur la colonne 18

                while(touche!=126){                                              // Boucle tant que la touche 'DEL' n'est pas pressé
                    affichediff(x,y);                                       // Appel de la fonction d'affichage pour le choix des difficultés
                    touche = getch();                                                       // On réafecte l'entrée à la variable "touche"
                    mouvementdiff(touche,&x,&y);                                                // Déplacement du curseur en fonction de la touche pressé et des coordonnées
                    if (x==11){x=5;}                                                 // Condition pour si le curseur descend en dessous de la derniere case autorisé il remonte automatiquement
                    if (x==3){x=9;}                                              // et inversement pour au dessus il redescend

                    int choix =0; // Variable initialisé pour les choix (qui servira a rentrer dans la condition des bordures)

                    if(x == 5 && touche == '\r' ){ // Si l'utilisateur appuie sur "entrer" quand le curseur est sur la premiére case "vitesse lente"
                        choix = 1; // Choix vraie
                        vitesse=200;} // vitesse à 200

                    if(x == 7 && touche == '\r' ) { // Si l'utilisateur appuie sur "entrer" quand le curseur est sur la deuxieme case "vitesse moy"
                        choix = 1; // Choix vraie
                        vitesse=100;} // vitesse à 100

                    if(x == 9 && touche == '\r' ) { // Si l'utilisateur appuie sur "entrer" quand le curseur est sur la troisieme case "vitesse rapide"
                        choix = 1; // Choix vraie
                        vitesse=50;} // vitesse à 50

                    //choix des bordures
                    if(choix == 1 ){ // condition si un choix a été effectue precedement pour la vitesse

                        x=13; // positionnement du curseur sur la ligne 13

                        while(touche!=126){ // Boucle tant que la touche 'DEL' n'est pas pressé

                            affichediff(x,y); // Appel de la fonction d'affichage pour le choix des difficultés
                            touche = getch(); // On réafecte l'entrée à la variable "touche"
                            mouvementdiff(touche,&x,&y); // Déplacement du curseur en fonction de la touche pressé et des coordonnées

                            if (x==17){x=13;} // Condition pour si le curseur descend en dessous de la derniere case autorisé il remonte automatiquement
                            if (x==11){x=15;} // et inversement pour au dessus il redescend

                            if(x==13 && touche == '\r') {  // Si l'utilisateur appuie sur "entrer" quand le curseur est sur la premiere case "Bordure off"
                                bord=0; // on affecte 0 pour la variable border (faux)
                                touche = 126; // pour sortir des deux dernieres boucles
                                x=5; //position du X sur l ecran du menu
                            }

                            if(x==15 && touche == '\r') { // Si l'utilisateur appuie sur "entrer" quand le curseur est sur la deuxieme case "Bordure on"
                                bord=1; // On affecte 1 (vraie) pour la variable border
                                touche = 126; // pour sortir des deux dernieres boucles
                                x=5; // position du X sur l ecran du menu
                            }
                        }
                    }
                }
            }
        }
    }
}
