---------------------Ceci est une petite description de notre projet----------------------

**************************Defintion du jeu **********************************************
Le morpion est un jeu de réflexion se pratiquant à deux joueurs au tour par tour et dont 
le but est de créer le premier un alignement sur une grille. Le jeu se joue généralement 
avec papier et crayon.


**************************Principe du jeu ************************************************
Les joueurs inscrivent tour à tour leur symbole sur une grille 3 fois 3. Le premier qui 
parvient à aligner trois de ses symboles horizontalement, verticalement ou en diagonale gagne un point.
Le morpion donne un avantage assez important à celui qui commence.

************************* Diverses Notions utilisées dans l'écriture du programme *********
Nous avions utilisé: 
1- la notion de tableau à deux dimensions pour la realisation de la
 grille;

2- la notion d'enumeration 

3- la notions de fonctions

4- la notion de booléen

5- la notion de pointeurs



********************* Les differentes étapes de déroulement du programme ****************
Le programme affiche un menu à  l'utilisateur pour qu'il choisisse de jouer, consulter les règles du jeu ou quitter lejeu.Si l'utilisateur choisit de jouer, on lui demande s'il veut commencer une partie, s'il tape O (pour OUI) on lui donne la main d'entrer les coordonnées de son symbole; sinon s'il entre N (pour NON), on lui  réaffiche le menu.Supposons que l'utilisateur entre un caractere différent deux c'est à dire de O et N, on lui dit qu'il a entré une valeur invalide et on lui reaffiche le menu pour qu'il fasse à nouveau son choix.

Le pogramme initialise ensuite la grillle à VIDE et on demande au joueur d'entrer les coordonnées  de son symbole. c'est le joueur ayant le ROND comme symbole qui joue le premier ensuite celui ayant la croix comme symboles et ainsi de suite.

Le joueur qui arrive à positionner son symbole sur trois cases consécutives de la grille de manière verticale,  horizontale ou diagonale gagne un point. le gagnant est celui qui aurait gagné plus de point après trois tours.
A la fin du jeu on affiche le gagnant et le perdant du jeu ainsi que leur score respectif.


 
