#include "Obus.h"
#include "Math.h"

Obus::Obus(){
	
}

Obus::~Obus(){
	
}

Obus::Obus(int _x,int _y,int _dx,int _dy,int _h,int _l){
	_x=_x+_l/2;
	_y=_y+_h/2;
	power=100;
	speed=2;
	range=1000;
	dx=_dx;
	dy=_dy;
	parcouru=0;
	double xb,yb,facteur,distanceDA;
	if( ( _x < _dx) and (_y < _dy)){
		distanceDA= pow(_dx - _x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur= (int) 110/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if( ( _x > dx) and (_y < _dy)){
		distanceDA= pow(_dx - _x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur= (int) 110/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if( ( _x > _dx) and (_y > _dy)){
		distanceDA= pow(dx - x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur=(int) 110/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if( ( _x < _dx) and (_y > _dy)){
		distanceDA= pow(_dx - _x,2) + pow(_dy - _y,2);
		distanceDA=sqrt(distanceDA);
		facteur=(int) 110/distanceDA;
		xb= ((_dx-_x)* facteur)+_x;
		yb= ((_dy-_y)* facteur)+_y;
		x=xb;
		y=yb;
	}
	if (_x==_dx and  _y < _dy){
		x=_dx;
		y=_y+110;
	}
	if (_y==_dy and _x <_dx){
		x=_x+110;
		y=_dy;
	}
	
	if (_y==_dy and _dx < _x){
		x=_x-110;
		y=_dy;
	}
	
	if (_x==_dx and _dy < _y){
		x=_dx;
		y=_y-110;
	}
}