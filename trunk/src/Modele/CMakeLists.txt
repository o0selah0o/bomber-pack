
#
# DESS IA : Correction du TP1 : fichier CMakeLists.txt
#

# Le sous projet
PROJECT(Modele)

# les fichiers 'header'
SET(Modele_inc
	BotSoldier.h
	Map.h
	Obus.h
	Soldier.h
	Wall.h
	Bullet.h
	Model.h
	Projectile.h
	Tank.h
	Water.h
	Jeep.h
	Node.h
	SandBags.h
	Vehicle.h
	Aircraft.h
	tokenize.h
	Grass.h
	
)

# les fichiers 'source'
SET(Modele_src
	BotSoldier.cpp
	Map.cpp
	tokenize.cpp
	Obus.cpp
	Soldier.cpp
	Wall.cpp
	Bullet.cpp
	Model.cpp
	Projectile.cpp
	Tank.cpp
	Water.cpp
	Jeep.cpp
	Node.cpp
	SandBags.cpp
	Vehicle.cpp
	Aircraft.cpp
	Grass.cpp
)

# On cree une librairie
ADD_LIBRARY(Modele ${Modele_inc} ${Modele_src})
