#include "Node.h"
#include "Soldier.h"
#include "Bullet.h"

Soldier::Soldier():Node()
{
	
}

Soldier::Soldier(int _nujoueur, int _team,int _x, int _y):Node(_x,_y){
	team=_team;
	nujoueur=_nujoueur;
	hp= 10000000;
	longueur=20;
	hauteur=10;
	speed=300;
	activ=true;
	symbole='c';
	dead=false;
}

Soldier::~Soldier(){
	
}

void Soldier::moveUp(float coeff,int h,int l){
	printf("LONGUEUR= %i ET HAUTEUR = %i",l,h);
	float deca=(int)	(speed * coeff);
	if((int)(y - deca)>0)
		y= y - deca;
}

void Soldier::moveBack(float coeff,int h,int l){
	printf("LONGUEUR= %i ET HAUTEUR = %i",l,h);
	int deca=(int)(speed * coeff);
	int temp = y+deca;
	if(temp+5 < l)
		y=y + deca;
}

void Soldier::moveLeft(float coeff,int h,int l){
	printf("LONGUEUR= %i ET HAUTEUR = %i",l,h);
	float deca=(int)	(speed * coeff )	;
	if( (int)(x - deca)>0)
		x=x - deca ;
}

void Soldier::moveRight(float coeff,int h,int l){
	printf("LONGUEUR= %i ET HAUTEUR = %i",l,h);
	int deca=	(int)(speed* coeff );
	int temp = x+deca;
	if(temp-5 < h)
		x=x + deca;
}

bool Soldier::isActiv(){
	return activ;
}

bool Soldier::isDead(){
	return dead;
}

int Soldier::getNuJoueur(){
	return nujoueur;
}

int Soldier::getTeam(){
	return team;
}

void Soldier::setTeam(int t){
	team=t;
}

void Soldier::setNuJoueur(int nu){
	nujoueur=nu;
}

void Soldier::setActiv(bool b){
	activ=b;
}

float Soldier::getSpeed(){
	return speed;
}

void Soldier::hit(int damages){
	hp=hp-damages;
	if(hp <= 0){
		dead=true;
	}
}



Bullet* Soldier::fire(int _dx,int _dy){
	Bullet* bul=new Bullet(x,y,_dx,_dy);
	return bul;
}