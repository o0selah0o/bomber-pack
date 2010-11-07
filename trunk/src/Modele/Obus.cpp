#include "Obus.h"
#include "Math.h"

Obus::Obus(){
	
}

Obus::~Obus(){
	
}

Obus::Obus(int _x,int _y,int _dx,int _dy){
	symbole='f';
	power=100000;
	speed=2;
	range=1000;
	dx=_dx;
	dy=_dy;
	parcouru=0;
	double xb,yb,facteur,distanceDA;
		distanceDA= pow(_dx - _x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur= (int) 110/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}