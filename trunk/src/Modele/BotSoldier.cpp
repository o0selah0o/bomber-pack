#include "BotSoldier.h"

BotSoldier::BotSoldier(){
	
}
BotSoldier::~BotSoldier(){
	
}

BotSoldier::BotSoldier(int _nujoueur,int _team,int _x,int _y):Soldier(_nujoueur,_team,_x,_y)
{	
	angle=0;
	speed = 1;
	symbole='b';
	speed = 300;
	dead=false;
	hp=100;
}

