
#
# DESS IA : Correction du TP1 : fichier CMakeLists.txt
#

# Pour definir la version minimum de CMake requise
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Pour définir le repertoire racine du projet
SET(PROJECT_ROOT "..")

# Pour forcer la generation des executables selon un path particulier 
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_ROOT}/bin CACHE PATH "Forced output path" FORCE)

# Pour forcer la generation des librairies selon un path particulier
SET(LIBRARY_OUTPUT_PATH ${PROJECT_ROOT}/bin CACHE PATH "Forced output path" FORCE)

# Option de compilation fine !
ADD_DEFINITIONS (-Wall) 

# Le projet
PROJECT(Battlefield2D)

# Les fichiers 'header'
SET(Battlefield2D_inc
)

# Les fichiers 'source'
SET(Battlefield2D_src
	main.cpp
)

# Les sous repertoire du projet
SUBDIRS(
	Modele
	Vue
	Controller
)

# On cree un executable
ADD_EXECUTABLE(Battlefield2D ${Battlefield2D_inc} ${Battlefield2D_src})

# On lie l'executable avec la librairie 'liste'
TARGET_LINK_LIBRARIES(Battlefield2D
	Modele
	Vue
	Controller
)

