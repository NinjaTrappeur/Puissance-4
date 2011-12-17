#Puissance 4

Jeu de puissance 4 basique sans IA.

##Pré-requis

* Compilateur C
* Cmake
* Make

##Compilation

A la racine du projet:
1. cmake -G Unix\ Makefiles
2. make

##Options

* --help : affiche l'aide
* --log : enregistre les coups de chaque joueur dans un fichier log
* --megafunMode : mode megafun
* --noGui : désactive l'affichage graphique de la grille pour la partie

##Mode megafun

Le puissance 4 megafun est un puissance 4 amélioré. Les règles sont les mêmes que celles d'un puissance 4 classique plus les trois règles suivantes:
* Bombes: chaque joueur dispose de trois bombes, chaque bombe peut détruire un pion situé en haut d'une colonne
* Switch: déclanché aléatoirement, il intervertit les pions des deux joueurs
* Coup critique: déclanché aléatoirement, permet au joueur qui le déclanche de rejouer.

Félix Baylac-Jacqué