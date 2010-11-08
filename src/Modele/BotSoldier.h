#ifndef __BOTSOLDIER
#define __BOTSOLDIER
#include "Node.h"
#include "Soldier.h"
/** 
 Sous classe de Soldier. Un soldat géré par l'ordinateur
**/

class BotSoldier: public Soldier
{
public:
	//Constructeur
	BotSoldier();
	
	//Destructeur
	~BotSoldier();
	
	//Constructeur avec identifiant, équipe, coordonnées x et y
	BotSoldier(int _nujoueur,int _team,int _x,int _y);
	

private:
	//angle, la direction dans laquelle regarde le soldat
	double angle;
	
};


#endif