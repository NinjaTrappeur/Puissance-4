#Déclaration du projet
project(Puissance4)
#Déclaration des chemins
include_directories(include)
#Déclaration de l'exécutable
add_executable(
	puissance4
	src/main.c
	src/grille.c
	include/grille.h
	src/moteur.c
	include/moteur.h
)
