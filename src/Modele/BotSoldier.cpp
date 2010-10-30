#include "BotSoldier.h"

BotSoldier::BotSoldier(){
	
}
BotSoldier::~BotSoldier(){
	
}

BotSoldier::BotSoldier(int _nujoueur,int _team,int _x,int _y):Soldier(_nujoueur,_team,_x,_y)
{
	speed = 1;
	symbole='b';
	speed = 400;
	dead=false;
	hp=100;
}

