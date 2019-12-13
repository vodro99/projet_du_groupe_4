---------------------Ceci est une petite description de notre projet----------------------

**************************Defintion du jeu **********************************************
Le morpion est un jeu de r�flexion se pratiquant � deux joueurs au tour par tour et dont 
le but est de cr�er le premier un alignement sur une grille. Le jeu se joue g�n�ralement 
avec papier et crayon.


**************************Principe du jeu ************************************************
Les joueurs inscrivent tour � tour leur symbole sur une grille 3 fois 3. Le premier qui 
parvient � aligner trois de ses symboles horizontalement, verticalement ou en diagonale gagne un point.
Le morpion donne un avantage assez important � celui qui commence.

************************* Diverses Notions utilis�es dans l'�criture du programme *********
Nous avions utilis�: 
1- la notion de tableau � deux dimensions pour la realisation de la
 grille;

2- la notion d'enumeration 

3- la notions de fonctions

4- la notion de bool�en

5- la notion de pointeurs



********************* Les differentes �tapes de d�roulement du programme ****************
Le programme affiche un menu �  l'utilisateur pour qu'il choisisse de jouer, consulter les r�gles du jeu ou quitter lejeu.Si l'utilisateur choisit de jouer, on lui demande s'il veut commencer une partie, s'il tape O (pour OUI) on lui donne la main d'entrer les coordonn�es de son symbole; sinon s'il entre N (pour NON), on lui  r�affiche le menu.Supposons que l'utilisateur entre un caractere diff�rent deux c'est � dire de O et N, on lui dit qu'il a entr� une valeur invalide et on lui reaffiche le menu pour qu'il fasse � nouveau son choix.

Le pogramme initialise ensuite la grillle � VIDE et on demande au joueur d'entrer les coordonn�es  de son symbole. c'est le joueur ayant le ROND comme symbole qui joue le premier ensuite celui ayant la croix comme symboles et ainsi de suite.

Le joueur qui arrive � positionner son symbole sur trois cases cons�cutives de la grille de mani�re verticale,  horizontale ou diagonale gagne un point. le gagnant est celui qui aurait gagn� plus de point apr�s trois tours.
A la fin du jeu on affiche le gagnant et le perdant du jeu ainsi que leur score respectif.


 
