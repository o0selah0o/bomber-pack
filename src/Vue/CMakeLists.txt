
#
# DESS IA : Correction du TP1 : fichier CMakeLists.txt
#

# Le sous projet
PROJECT(Vue)

# les fichiers 'header'
SET(Vue_inc
	Screen.h
)

# les fichiers 'source'
SET(Vue_src
	Screen.cpp
)

# On cree une librairie
ADD_LIBRARY(Vue ${Vue_inc} ${Vue_src})
