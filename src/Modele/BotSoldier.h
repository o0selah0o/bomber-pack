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
	BotSoldier();
	~BotSoldier();
	BotSoldier(int _nujoueur,int _team,int _x,int _y);
	void moveUp(float coeff);
	
	void moveBack(float coeff);
	
	void moveLeft(float coeff);
	
	void moveRight(float coeff);
	
};


#endif