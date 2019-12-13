#include <stdio.h>
#include <stdlib.h>

#define NOMBRE_LIGNE 3
#define NOMBRE_COLONNE 3
#define NOMBRE_TOURS 3

typedef enum ValeurGrille ValeurGrille;
enum ValeurGrille
{
    VIDE, ROND, CROIX
};
typedef enum Boolean Boolean;
enum Boolean
{
    FALSE, TRUE
};
int menu();//prototype de la fonction menu permettant d'afficher le menu
void commencerPartie();//prototype de la fonction commencerPartie permettanr de demander à l'utilisation s'il veut commencer la partie ou pas
void verificationCommencerPartie(char caractere);//prototype de la fonction permettant de verifier si le joueur veut commencer une partie
void initialiseGrille();//prototype de la fonction permettant d'initialiser la grille
void afficheGrille();//prototype de la fonction qui permet d'afficher la grille
void positionnerSymboleSurGrille();//prototype de la fonction permettant de positionner les symboles des joueurs sur la grille
Boolean testeFinTours(int *pointRound, int *pointCroix);//prototype de la fonction permettant de voir si un tour est terminé ou pas

static ValeurGrille magrille[NOMBRE_LIGNE][NOMBRE_COLONNE];// grille(tableau à deux dimensions)du morpion valeurs possibles VIDE, ROND ou CROIX
static int prochainJoueur = ROND;//indique quel sera le prochain joueur a mettre un pion dans la grille ie soit ROND soit CROIX


int main()
{//debut de la fonction main
    int choix;
    choix = menu();
    int tours = 0, pointsRond = 0, pointsCroix = 0;
    switch(choix){
        case 1:
            system("cls");
            commencerPartie();
            while(tours < NOMBRE_TOURS) {
                initialiseGrille();
                afficheGrille();
                do{//cette boucle permet donner la main au joueur de place son symbole et d'afficher la gris
                    positionnerSymboleSurGrille();
                    afficheGrille();
                }while(!testeFinTours(&pointsRond, &pointsCroix));//la boucle continue tant que testeFinTours(&pointsRond, &pointCroix) renvoie false ( 0 )
                tours++;
            }

            printf("Confratitulation au joueur ayant les ");
            if(pointsRond > pointsCroix)
                printf("ronds ayant comme symbole qui gagne avec %d points", pointsRond);
            else
                printf("croix comme symbole qui gagne avec %d points", pointsCroix);
            return TRUE;
            break;
        case 2:
            printf("\n-*- Les joueurs inscrivent tour à tour leur symbole (X pour le premier joueur et O pour le second).).\n\n-*- Le premier qui parvient à aligner trois (3) de ses symboles horizontalement, verticalement ou en diagonale gagne un point.\n\n-*- Le gagnant du jeu sera celui qui aura le plus de point apres trois toursde jeu.\n\n");
            break;
        case 3:
            printf("********** AU REVOIR **********\n");
            return 0;
        default:
            printf("ENTREZ UNE VALEUR VALIDE SVP!");
            break;
    }
    return 0;
}//fin de la fonction main

int menu(){//la fonction menu affiche le menu, recupere et renvoie le choix du joueur
    int menuchoix;
    printf("\t\t\t------------- JEU DE MORPION -------------\n\n");
    printf("\t\t\t\t\t1- JOUER \n");
    printf("\t\t\t\t\t2- REGLES DU JEU \n");
    printf("\t\t\t\t\t3- QUITTER\n\n");
    printf("Tapez 1 pour jouer; 2 pour consulter les regles du jeu ou 3 pour quitter le jeu \n>>");
    scanf("%d", &menuchoix);
    return menuchoix;
}//fin fonction menu

void commencerPartie(){//commencerPartie recupere la valeur entree par l'utilisateur et l'envoi à la fonction verificationCommencerPartie pour une verification
    char valeur;
    do{
        printf("VOULEZ-VOUS COMMENCER UNE NOUVELLE PARTIE? ENTREZ  ' O ' POUR << OUI >> ET ' N ' POUR << NON >>\n>>");
        scanf(" %c", &valeur);
        verificationCommencerPartie(valeur);
    }while(valeur !='O' && valeur !='o' && valeur !='N' && valeur !='n');//tant que la valeur entree par le joueur est differente de O ou N, la boucle s'execute
}//fin de la fonction commencerPartie

void verificationCommencerPartie(char caractere){// verificationCommencerPartie de type void permet de verifier si le joueur veut faire une partie ou non
    if(caractere == 'O' || caractere == 'o'){
        printf("commencer partie\n");
    }
    else if(caractere == 'N' || caractere == 'n'){
        system("cls");
        menu();
        commencerPartie();
    }
    else{
        printf("entrez une valeur valide\n");
    }
}//fin de la fonction verificationCommencerPartie


void initialiseGrille(){// initialiseGrille permet d'iitialiser le contenu de la grille à vide (0)
  int i, j;
  for (i=0; i<NOMBRE_LIGNE; i++){
    for (j=0; j<NOMBRE_COLONNE; j++){
      magrille[i][j] = VIDE;
    }
  }
}//fin de initialiseGrille


void afficheGrille(){//_ indique case vide, O pion joueur 1 et X pion jour 2
  int i, j;
  for (i=0; i<NOMBRE_LIGNE; i++){
    for (j=0; j<NOMBRE_COLONNE; j++){
      switch (magrille[i][j]){
      case VIDE:
        printf("_ ");
        break;
      case ROND:
        printf("O ");
        break;
      case CROIX:
        printf("X ");
        break;
      }
    }
    printf("\n");
  }
}//fin de la fonction afficheGrille

/*
  Saisie les coordonnees du nouveau pion a mettre sur la grille
  Si les coordonnees sont en dehors de la grille ou si la case possede
  deja un pion, la saisie est refusee, un message d'erreur est affichee,
  et le joueur doit rejoue
 */
void positionnerSymboleSurGrille(){
  int numeroligne, numerocolonne;
  Boolean EntreeJuste = FALSE;//on cree une variable de type Boolean pour verifier si une  cellule(ensemble ligne, colonne) est utilisable pour placer un symbole. on considere pour l'initialisation que la case n'est pas utilisable (vaut FALSE) c'est à dire qu'elle est deja rempli.
  printf("Numeros de ligne et de colonne: ");
  do {
     scanf("%d %d", &numeroligne, &numerocolonne);
     printf("\n");
     if((numeroligne > 0) && (numeroligne <= NOMBRE_LIGNE) && (numerocolonne > 0) && (numerocolonne <= NOMBRE_COLONNE)){
         numeroligne--; /* enleve 1 pour etre compatible avec le tableau ayant des
		  indices de 0 a NB_LIG-1 */
         numerocolonne--;
         if(magrille[numeroligne][numerocolonne] != VIDE)//si la case n'est pas vide
             printf("Cette case a deja ete remplie. Veuillez recommencer: \n");
         else{
             EntreeJuste = TRUE;//Sinon si la case est vide et peut recevoir un symbole
             magrille[numeroligne][numerocolonne] = (ValeurGrille)prochainJoueur;//on fait un cast pour pour pouvoir faire correspondre la valeur de prochainJoueur à un symbolz et l'inserer dans la grille.
             if(prochainJoueur == ROND)
                 prochainJoueur = CROIX;
             else
                 prochainJoueur = ROND;
         }
    }
    else
        printf("Indice de ligne ou de colonne incorrect. Veuillez recommencer:\n");
  }while(!EntreeJuste);
}//fin fonction positionnerSymboleSurGrille

/* Teste si l'un des joueurs a gagne (ligne, colonne ou diagonale remplit
   de pions semblables). Dans ce cas affiche un message pour indiquer le
   joueur qui a gagne.
   S'il n'y a pas de gagnant, teste que la grille n'est pas pleine. Si elle
   est pleine, affiche un message indiquant qu'aucun des joueurs a gagne
   Retourne TRUE si la grille est pleine ou si un joueur a gagne
   FALSE sinon
*/
Boolean testeFinTours(int *pointRound, int *pointCroix){
  int i,j;
  int joueurGagnant; /* pour connaitre quel est le gagnant ie soit CROIX soit ROND */
  Boolean estGagne = FALSE;//on cree une variable de type Boolean pour verifier si le tour a été gagné. on suppose que le tour n'a pas été gagné

  /* Teste s'il y a un gagnant */

  if(magrille[1][1] != VIDE){//si la case 1,1 est VIDE, cela signifie que les diagonales, la ligne 1 et la colonne 1 ne sont pas gagnantes
    if(/* colonne 1 */ ((magrille[0][1] == magrille[1][1]) && (magrille[1][1] == magrille[2][1])) ||
	/* ligne 1 */ ((magrille[1][0] == magrille[1][1]) && (magrille[1][1] == magrille[1][2])) ||
	/* diagonale */ ((magrille[0][0] == magrille[1][1]) && (magrille[1][1] == magrille[2][2])) ||
	/* autre diag */ ((magrille[0][2] == magrille[1][1]) && (magrille[1][1] == magrille[2][0]))){
      joueurGagnant = magrille[1][1]; /* ie ROND ou CROIX */
      estGagne = TRUE;
    }
  }

  /* si la case 0,0 est vide, cela signifie que la ligne 0 et le colonne 0 ne sont pas gagnantes */
  if((!estGagne) && (magrille[0][0] != VIDE)){//s'il n'y a pas de gagnant et si magrille
    if( /* ligne 0 */ ((magrille[0][0] == magrille[0][1]) && (magrille[0][1] == magrille[0][2])) ||
	 /* colonne 0*/ ((magrille[0][0] == magrille[1][0]) && (magrille[1][0] == magrille[2][0]))){
      joueurGagnant = magrille[0][0];
      estGagne = TRUE;
    }
  }

  /* si la case 2,2 est vide, cela signifie que la ligne 2 et la colonne 2 ne sont gagnantes */
  if((!estGagne) && (magrille[2][2] != VIDE)){
    if( /* ligne 2 */ ((magrille[2][0] == magrille[2][1]) && (magrille[2][1] == magrille[2][2])) ||
	 /* colonne 2 */ ((magrille[0][2] == magrille[1][2]) && (magrille[1][2] == magrille[2][2]))){
      joueurGagnant = magrille[2][2];
      estGagne = TRUE;
    }
  }
  if(estGagne){
    if(joueurGagnant == ROND){
        *pointRound = *pointRound + 1;
    }
    else{
        *pointCroix = *pointCroix + 1;
    }

    printf("Le joueur ayant les ronds a %d point%c\n", *pointRound, (*pointRound <= 1 ? '.': 's.'));
    printf("Le joueur ayant les croix a %d point%c\n", *pointCroix, (*pointCroix <= 1 ? '.': 's.'));
    return TRUE;
  }

  /* teste si la grille n'est pas pleine */
  for(i=0; i<NOMBRE_LIGNE; i++){
    for(j=0; j<NOMBRE_COLONNE; j++){
      if(magrille[i][j] == VIDE) /* Au moins une case est vide donc le jeu n'est pas fini */
        return FALSE;
    }
  }
  return TRUE;

}


