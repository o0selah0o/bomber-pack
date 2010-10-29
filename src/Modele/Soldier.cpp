#include "Node.h"
#include "Soldier.h"
#include "Bullet.h"

Soldier::Soldier():Node()
{
	
}

Soldier::Soldier(int _nujoueur, int _team,int _x, int _y):Node(_x,_y){
	team=_team;
	nujoueur=_nujoueur;
	longueur=20;
	hauteur=10;
	speed=200;
	activ=true;
	symbole='c';
}

Soldier::~Soldier(){
	
}

void Soldier::moveUp(float coeff){
	y=y-(speed * coeff);
}

void Soldier::moveBack(float coeff){
	y=y+(-1 * speed * coeff);
}

void Soldier::moveLeft(float coeff){
	x=x-(speed * coeff);
}

void Soldier::moveRight(float coeff){
	x=x+(-1 * speed * coeff);
}

bool Soldier::isActiv(){
	return activ;
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
}


Bullet* Soldier::fire(int _dx,int _dy){
	Bullet* bul=new Bullet(x,y,_dx,_dy);
	return bul;
	
}