#ifndef __BOTSOLDIER
#define __BOTSOLDIER
#include "Node.h"
#include "Soldier.h"
/** 
 Sous classe de Soldier. Un soldat géré par l'ordinateur
**/

public class BotSoldier: public Soldier
{
public:
	BotSoldier();
	~BotSoldier();
	//méthode gérant le comportement d'un soldat ennemi
	void agir();

	
	
}


#endif