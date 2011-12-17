Puissance 4
-----------

Jeu de puissance 4 basique sans IA.

Pré-requis
-----------
\n-compilateur C
\n-cmake
\n-make

Compilation
-----------
A la racine du projet:
\n1-cmake -G Unix\ Makefiles
\n2-make

Options
----------
\n--help : affiche l'aide
\n--log : enregistre les coups de chaque joueur dans un fichier log
\n--megafunMode : mode megafun
\n--noGui : désactive l'affichage graphique de la grille pour la partie

Mode megafun
----------
Le puissance 4 megafun est un puissance 4 amélioré. Les règles sont les mêmes que celles d'un puissance 4 classique plus les trois règles suivantes:
\n-Bombes: chaque joueur dispose de trois bombes, chaque bombe peut détruire un pion situé en haut d'une colonne
\n-Switch: déclanché aléatoirement, il intervertit les pions des deux joueurs
\n-Coup critique: déclanché aléatoirement, permet au joueur qui le déclanche de rejouer.

Félix Baylac-Jacqué