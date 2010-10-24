
#
# DESS IA : Correction du TP1 : fichier CMakeLists.txt
#

# Le sous projet
PROJECT(Controller)

# les fichiers 'header'
SET(Controller_inc
	Controleur.h
)

# les fichiers 'source'
SET(Controller_src
	Controleur.cpp
)

# On cree une librairie
ADD_LIBRARY(Controller ${Controller_inc} ${Controller_src})
