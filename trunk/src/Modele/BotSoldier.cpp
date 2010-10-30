#include "BotSoldier.h"

BotSoldier::BotSoldier(){
	
}
BotSoldier::~BotSoldier(){
	
}

BotSoldier::BotSoldier(int _nujoueur,int _team,int _x,int _y):Soldier(_nujoueur,_team,_x,_y)
{
	speed = 1;
	symbole='b';
	speed = 600;
	dead=false;
}

void BotSoldier::moveUp(float coeff){
	float deca=(int)	(speed * coeff);
	y= y - deca;
}

void BotSoldier::moveBack(float coeff){
	float deca=(int)	(speed * coeff);
	y=y + deca;
}

void BotSoldier::moveLeft(float coeff){
	float deca=(int)	(speed * coeff )	;
	x=x - deca ;
}

void BotSoldier::moveRight(float coeff){
	float deca=	(int)(speed* coeff )	;
	x=x + deca;
}