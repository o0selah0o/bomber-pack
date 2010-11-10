#include "Model.h"
#include "Map.h"
#include "math.h"
#include "time.h"
#include "Jeep.h"
#include <iostream>
Model::Model(){
	
}

Model::~Model()
{
	unsigned int i;
	for(i = 0; i < vehicles.size() ; i++){
		delete vehicles.at(i);
	}
	for(i = 0 ; i < soldiers.size() ; i++){
		delete soldiers.at(i);
	}
	for(i = 0 ; i < impacts.size() ; i++){
		delete impacts.at(i);
	}
	for(i = 0 ; i < bodies.size() ; i++){
		delete bodies.at(i);
	}
}

Model::Model(std::string fichier){
	wholeMap = Map();
	
	if(!wholeMap.ReadFileMap(fichier + "_map.txt")){
		std::cout << "echec chargement fichier map" << std::endl;
	}
	
	if(!wholeMap.ReadFileVehicles(fichier + "_vehicles.txt")){
		std::cout << "echec chargement fichier vehicles" << std::endl;
	}
	
	if(!wholeMap.ReadFileSoldiers(fichier + "_soldiers.txt")){
		std::cout << "echec chargement fichier soldiers" << std::endl;
	}
	vehicles=wholeMap.getVehicles();
	soldiers=wholeMap.getSoldiers();
	lastFired=clock();
	usedVehicle='n';
}

Map Model::getMap(){
	return wholeMap;
}

std::vector<Soldier*> Model::getSoldiers(){
	return soldiers;
}

std::vector<Body*> Model::getBodies(){
	return bodies;
}

std::vector<Vehicle*> Model::getVehicles(){
	return vehicles;
}

std::vector<Impact*> Model::getImpacts(){
	return impacts;
}

bool Model::enterVehicle(int Soldati){
	Soldier* soldier=soldiers.at(Soldati);
	int soldatiX=soldier->getPosition().first;
	int soldatiY=soldier->getPosition().second;
	if(soldiers.at(Soldati)->isActiv()){
		Vehicle* vehicleN=isAtPosition(soldatiX,soldatiY-15,vehicles);
		Vehicle* vehicleS=isAtPosition(soldatiX,soldatiY+15,vehicles);
		Vehicle* vehicleE=isAtPosition(soldatiX+15,soldatiY,vehicles);
		Vehicle* vehicleO=isAtPosition(soldatiX-15,soldatiY,vehicles);
		if(vehicleN ==NULL and vehicleS ==NULL and vehicleE ==NULL and vehicleO ==NULL){
			return false;
			
		}
		else{
			if (vehicleN !=NULL and !vehicleN->isDestroyed()){
				soldier->enterVehicle(vehicleN);
				usedVehicle=vehicleN->getSymbole();
			}
			if (vehicleS !=NULL and !vehicleS->isDestroyed()){
				soldier->enterVehicle(vehicleS);
				usedVehicle=vehicleS->getSymbole();
			}
			if (vehicleE !=NULL and !vehicleE->isDestroyed()){
				soldier->enterVehicle(vehicleE);
				usedVehicle=vehicleE->getSymbole();
			}
			if (vehicleO !=NULL and !vehicleO->isDestroyed()){
				soldier->enterVehicle(vehicleO);
				usedVehicle=vehicleO->getSymbole();
			}
			return true;
		}
	}
	else{
		return false;
	}
	return false;
}

bool Model::leaveVehicle(int Soldati){
	Soldier* soldier=soldiers.at(Soldati);
	if(!soldier->isActiv()){
		soldier->getVehicle()->setUsed(false);
		soldier->leaveVehicle();
		usedVehicle='n';
	}	
	return true;
}

bool Model::moveUp(int i,float coeff){
	char typepred;
	Soldier* soldier=soldiers.at(i);
	int speed=soldier->getSpeed();
	int _hauteur=soldier->getBoundingBox().first;
	
	int _centerX=soldier->getCenterX();
	int _centerY=soldier->getCenterY();
	Vehicle* vehipred;
	
	if(soldier->isActiv()){
		int nextPosy=_centerY-(speed*coeff+5)-_hauteur+5;
		typepred= wholeMap.getNodeAtPosXY(_centerX, nextPosy)->getSymbole();
		vehipred=isAtPosition(_centerX,nextPosy,vehicles);
	}
	else {
		vehipred=soldier->getVehicle();
		_hauteur=vehipred->getBoundingBox().second;
		speed=vehipred->getSpeed();
		_centerX=vehipred->getCenterX();
		_centerY=vehipred->getCenterY();
		int nextPosy=_centerY-(speed*coeff+5)-_hauteur/2;
		typepred= wholeMap.getNodeAtPosXY(_centerX, nextPosy)->getSymbole();
		vehipred=isAtPosition(_centerX,nextPosy,vehicles);
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a'  or vehipred!=NULL){
		return false;
	} 
	soldier->moveUp(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
}

bool Model::moveBack(int i,float coeff){
	char typepred;
	Soldier* soldier=soldiers.at(i);
	int speed=soldier->getSpeed();
	int _hauteur=soldier->getBoundingBox().first;
	
	int _centerX=soldier->getCenterX();
	int _centerY=soldier->getCenterY();
	Vehicle* vehipred;
	
	if(soldier->isActiv()){
		int nextPosy=_centerY+(speed*coeff);
		typepred= wholeMap.getNodeAtPosXY(_centerX, nextPosy)->getSymbole();
		vehipred=isAtPosition(_centerX,nextPosy,vehicles);
	}
	else {
		vehipred=soldier->getVehicle();
		_hauteur=vehipred->getBoundingBox().second;
		speed=vehipred->getSpeed();
		_centerX=vehipred->getCenterX();
		_centerY=vehipred->getCenterY();
		int nextPosy=_centerY+(speed*coeff+5)+_hauteur/2;
		typepred= wholeMap.getNodeAtPosXY(_centerX, nextPosy)->getSymbole();
		vehipred=isAtPosition(_centerX,nextPosy,vehicles);
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a'  or vehipred!=NULL){
		return false;
	} 
	soldier->moveBack(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
}

bool Model::moveLeft(int i,float coeff){
	char typepred;
	Soldier* soldier=soldiers.at(i);
	int speed=soldier->getSpeed();
	int _longueur=soldier->getBoundingBox().first;
	
	int _centerX=soldier->getCenterX();
	int _centerY=soldier->getCenterY();
	Vehicle* vehipred;
	
	if(soldier->isActiv()){
		int nextPosx=_centerX-(speed*coeff)-_longueur;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,_centerY)->getSymbole();
		vehipred=isAtPosition(nextPosx,_centerY,vehicles);
	}
	else {
		vehipred=soldier->getVehicle();
		_longueur=vehipred->getBoundingBox().second;
		speed=vehipred->getSpeed();
		_centerX=vehipred->getCenterX();
		_centerY=vehipred->getCenterY();
		int nextPosx=_centerX-(speed*coeff+5)-_longueur/2;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,_centerY)->getSymbole();
		vehipred=isAtPosition(nextPosx,_centerY,vehicles);
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a'  or vehipred != NULL){
		return false;
	} 
	soldier->moveLeft(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
	
}

bool Model::moveRight(int i,float coeff){
	char typepred;
	Soldier* soldier=soldiers.at(i);
	int speed=soldier->getSpeed();
	int _longueur=soldier->getBoundingBox().first;
	
	int _centerX=soldier->getCenterX();
	int _centerY=soldier->getCenterY();
	Vehicle* vehipred;
	
	if(soldier->isActiv()){
		int nextPosx=_centerX+(speed*coeff);
		typepred= wholeMap.getNodeAtPosXY(nextPosx,_centerY)->getSymbole();
		vehipred=isAtPosition(nextPosx,soldiers.at(i)->getCenterY(),vehicles);
	}
	else {
		vehipred=soldier->getVehicle();
		_longueur=vehipred->getBoundingBox().second;
		speed=vehipred->getSpeed();
		_centerX=vehipred->getCenterX();
		_centerY=vehipred->getCenterY();
		int nextPosx=_centerX+(speed*coeff+5)+_longueur/2;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,_centerY)->getSymbole();
		vehipred=isAtPosition(nextPosx,_centerY,vehicles);
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a' or vehipred != NULL ){
		return false;
	}
	
	soldier->moveRight(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
	
}

void Model::fire(int _dx,int _dy,int Soldati){
	int tlaps = 25;
	Soldier* soldier=soldiers.at(Soldati);
	if (soldier->getVehicle() != NULL)
		tlaps = 100;
	
	double elapsed= (clock() - lastFired) / (CLOCKS_PER_SEC / (double) 1000.0);
	if (elapsed >= tlaps){
		Projectile* proj = soldier->fire(_dx,_dy);
		if(proj != NULL ){
			projectiles.push_back(proj);
			lastFired=clock();
		}
	}
}

std::vector<Projectile*> Model::getProjectiles()
{
	return projectiles;
}

void Model::addProjectiles(Projectile* _projectile)
{
	projectiles.push_back(_projectile);
}

std::vector<Node*> Model::FieldOfView(int _x,int _y,int hauteurfov,int longueurfov){
	return wholeMap.cross(_x,_y,hauteurfov,longueurfov);
}

Vehicle* Model::isAtPosition(int _x,int _y,std::vector<Vehicle*> vehicles){
	unsigned int i;
	unsigned int length= vehicles.size();
	int xno,yno,xse,yse;
	Vehicle* vehipred;
	for(i=0;i<length;i++)
	{	
		vehipred=vehicles.at(i);
		xno=vehipred->getPosition().first;
		yno=vehipred->getPosition().second;
		xse=vehipred->getPosition().first+ vehipred->getBoundingBox().second;
		yse=vehipred->getPosition().second + vehipred->getBoundingBox().first;
		if( (xno) < _x and (yno) < _y and (xse) > _x and (yse) > _y)
			return vehipred;  
	}
	return NULL;
	
}
void Model::clearImpacts(){
	impacts.clear();
}

void Model::calcAngle(int _i,int _dx, int _dy){
	Soldier* soldier=soldiers.at(_i);
	double angle = atan2( abs(soldier->getPosition().second - _dy), abs(soldier->getPosition().first - _dx)) * 180 / 3.14;
	soldier->setAngle((-angle + 90));
}


char Model::getUsedVehicle(){
	return usedVehicle;
}


void Model::update(float coeff){
	srand(time(NULL));	
	bool testrange = false;
	bool testhit = false;
	bool testblock = false;
	float x,y,distance;
	Soldier* soldierJ,soldierI;
	Projectile* projectileI;
	int projectileIX;
	int projectileIY;
	int projectileICenterX;
	int projectileICenterY;
	int soldierJX;
	int soldierJY;
	for(int i=(int) projectiles.size() - 1;i >= 0;i--){
		if(projectiles.size() > 0)
		{	testrange = false;
			testhit = false;
			testblock = false;
			projectileI=projectiles.at(i);
			projectileIX=projectileI->getPosition().first;
			projectileIY=projectileI->getPosition().second;
			projectileICenterX=projectileI->getCenterX();
			projectileICenterY=projectileI->getCenterY();
			
			char symTemp = projectiles.at(i)->getSymbole();
			for (int j=0;j < (int)soldiers.size();j++)
			{	
				if(!soldiers.at(j)->isDead()){
					soldierJ=soldiers.at(j);
					soldierJX=soldierJ->getPosition().first;
					soldierJY=soldierJ->getPosition().second;
					
					if (!testhit and !testrange and !testblock) {
						x = pow(soldierJX - projectileIX, 2);
						y = pow(soldierJY - projectileIY, 2);
						distance = sqrt( x + y );				
					}
					if (distance < 10 and !testhit and !testrange and !testblock and symTemp == 'o' ){
						soldierJ->hit(projectileI->getPower());
						if(symTemp == 'f'){
							impacts.push_back(new Impact(projectileIX,projectileIY,50,50,'s'));
						}
						if(symTemp == 'o'){
							impacts.push_back(new Impact(projectileIX,projectileICenterY,50,50,'h'));
						}
						projectiles.erase(projectiles.begin()+i);
						testhit=true;
					}
					if (distance < 25 and !testhit and !testrange and !testblock and symTemp == 'f' and projectileI->getParcouru() > 80 ){
						soldierJ->hit(projectileI->getPower());
						if(symTemp == 'f'){
							impacts.push_back(new Impact(projectileIX,projectileIY,50,50,'s'));
						}
						if(symTemp == 'o'){
							impacts.push_back(new Impact(projectileICenterX,projectileICenterY,50,50,'h'));
						}
						projectiles.erase(projectiles.begin()+i);
						testhit=true;
					}
				}
				
				if(!testhit and !testrange and !testblock){
					if(projectileI->getParcouru() > projectileI->getRange()){
						if(projectileI->getSymbole() == 'f'){
							impacts.push_back(new Impact(projectileIX,projectileIY,50,50,'s'));
						}
						if(projectileI->getSymbole() == 'o'){
							impacts.push_back(new Impact(projectileIX,projectileIY,50,50,'i'));
						}
						projectiles.erase(projectiles.begin()+i);
						testrange=true;
					}
				}
				
				if(!testrange and !testhit and !testblock){
					char typepred= wholeMap.getNodeAtPosXY( projectileIX, projectileIY)->getSymbole();
					if (typepred == 's' or typepred== 'w'){
						if(projectileI->getSymbole() == 'f'){
							impacts.push_back(new Impact(projectileIX,projectileIY,50,50,'s'));
						}
						if(projectileI->getSymbole() == 'o'){
							impacts.push_back(new Impact(projectileIX,projectileIY,50,50,'i'));
						}
						projectiles.erase(projectiles.begin()+i);
						testblock=true;
					} 
				}
				
				if(!testrange and !testhit and !testblock){
					projectileI->parcourir(coeff);
				}
			}	
		}
	}	
	for(int i = 0; i < (int)soldiers.size(); i++)
    {	
		Soldier* soldierI=soldiers.at(i);
		if(soldierI->isDead() and i!=0){
			if(soldierI->isActiv()){
				bodies.push_back(new Body(soldierI->getCenterX(),soldierI->getCenterY()));
				soldiers.at(i)->setActiv(false);
			}
			
		}
		
        if(soldierI->getSymbole() == 'b'  and !soldierI->isDead())
        {
			Vehicle* ecra=isAtPosition(soldierI->getPosition().first,soldierI->getPosition().second,vehicles);
			if( ecra !=NULL){
				if(ecra->isUsed()){
					soldierI->setDead(true);
				}
			}	
			
		}
	}	
	
	
	int distanceMax = 10000;
    int direction = 0;
	int temps0= clock()/1000;
	int temps1;
    for(int i = 0; i < (int)soldiers.size(); i++)
    {	
		Soldier* soldierI=soldiers.at(i);
        if(soldierI->getSymbole() == 'b'  and !soldierI->isDead())
        {
			float alea= (rand()/(double)RAND_MAX);
			
            for(int j = 0; j < (int)soldiers.size(); j++)
            {	
				soldierJ=soldiers.at(j);
                if(soldierI->getTeam() != soldiers.at(j)->getTeam() and !soldiers.at(j)->isDead())
                {	direction=j;
                    float x = pow(soldierI->getPosition().first - soldierJ->getPosition().first, 2);
                    float y = pow(soldierI->getPosition().second - soldierJ->getPosition().second, 2);
                    float distance = sqrt( x + y );
                    if(distance < 200 and i != j)
					{
						if(projectiles.size() < 100)
						{	
							temps1=clock()/1000;
							if((temps1-temps0) > 0.995){
								float devia= (rand()/(double)RAND_MAX);
								projectiles.push_back(soldierI->fire((int)soldierJ->getPosition().first+(devia * 10.0), (int)soldierJ->getPosition().second-(devia * 10.0)));
								temps0=clock()/1000;
							}
							
						}   
						
                    }
					if(distance < distanceMax)
                    {
                        distanceMax = (int) distance;
                        direction = j;
						calcAngle(i,soldiers.at(direction)->getPosition().first, soldiers.at(direction)->getPosition().second);
                    }
				}
            }
			
			if(!soldiers.at(i)->isDead() and !soldiers.at(direction)->isDead()){
				int x = soldierI->getPosition().first;
				int y = soldierI->getPosition().second;
				int dx = soldiers.at(direction)->getPosition().first;
				int dy = soldiers.at(direction)->getPosition().second;
				if(i != 0){
					if (distanceMax < 190){
						if(alea < 0.3)
							moveRight(i,coeff);
						if(alea >= 0.3 and alea < 0.53)
							moveLeft(i,coeff);
						if(alea >= 0.53 and alea < 0.76)
							moveUp(i,coeff);
						if(alea >= 0.76 and alea <= 1.0)
							moveBack(i,coeff);
						
					}
					else{
						if(x < dx){
							if(alea < 0.7)
								moveRight(i,coeff);
							if(alea >= 0.7 and alea < 0.8)
								moveLeft(i,coeff);
							if(alea >= 0.8 and alea < 0.9)
								moveUp(i,coeff);
							if(alea >= 0.9 and alea <= 1.0)
								moveBack(i,coeff);
						}
						
						if(x > dx){
							if(alea < 0.7)
								moveLeft(i,coeff);
							
							if(alea >= 0.7 and alea < 0.8)
								moveRight(i,coeff);
							if(alea >= 0.8 and alea < 0.9)
								moveUp(i,coeff);
							if(alea >= 0.9 and alea <= 1.0)
								moveBack(i,coeff);
						}
						if(y > dy){
							if(alea < 0.7)
								moveUp(i,coeff);
							if(alea >= 0.7 and alea < 0.8)
								moveLeft(i,coeff);
							if(alea >= 0.8 and alea < 0.9)
								moveRight(i,coeff);
							if(alea >= 0.9 and alea <= 1.0)
								moveBack(i,coeff);
							
						}
						if(y < dy){
							if(alea < 0.7)
								moveBack(i,coeff);
							if(alea >= 0.7 and alea < 0.8)
								moveLeft(i,coeff);
							if(alea >= 0.8 and alea < 0.9)
								moveUp(i,coeff);
							if(alea >= 0.9 and alea <= 1.0)
								moveRight(i,coeff);
							
						}
					}
				}	
			}	
        }
    }
}	

