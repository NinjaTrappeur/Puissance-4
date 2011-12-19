cmake_minimum_required(VERSION 2.6)
#ajoute des options au compilateur
add_definitions(-Wall)
#Déclaration du projet
project(Puissance4)
#Déclaration des chemins
include_directories(include)
#Déclaration de l'exécutable
add_executable(
	puissance4
	src/main.c
	src/grid.c
	include/grid.h
	src/engine.c 
	include/engine.h
	src/megafunMode.c
	include/megafunMode.h
)
