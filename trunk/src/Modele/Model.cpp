#include "Model.h"
#include "Map.h"
#include "math.h"
#include "time.h"
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
}

Map Model::getMap(){
	return wholeMap;
}

std::vector<Soldier*> Model::getSoldiers(){
	return soldiers;
}

std::vector<Vehicle*> Model::getVehicles(){
	return vehicles;
}

bool Model::enterVehicle(int Soldati){
	if(soldiers.at(Soldati)->isActiv()){
		Vehicle* vehicleN=isAtPosition(soldiers.at(Soldati)->getPosition().first,soldiers.at(Soldati)->getPosition().second-15,vehicles);
		Vehicle* vehicleS=isAtPosition(soldiers.at(Soldati)->getPosition().first,soldiers.at(Soldati)->getPosition().second+15,vehicles);
		Vehicle* vehicleE=isAtPosition(soldiers.at(Soldati)->getPosition().first+15,soldiers.at(Soldati)->getPosition().second,vehicles);
		Vehicle* vehicleO=isAtPosition(soldiers.at(Soldati)->getPosition().first-15,soldiers.at(Soldati)->getPosition().second,vehicles);
		if(vehicleN !=NULL and vehicleS !=NULL and vehicleE !=NULL and vehicleO !=NULL){
			return false;
		}
		else{
			if (vehicleN !=NULL and !vehicleN->isDestroyed()){
				soldiers.at(Soldati)->enterVehicle(vehicleN);
			}
			if (vehicleS !=NULL and !vehicleS->isDestroyed()){
				soldiers.at(Soldati)->enterVehicle(vehicleS);
			}
			if (vehicleE !=NULL and !vehicleE->isDestroyed()){
				soldiers.at(Soldati)->enterVehicle(vehicleE);
			}
			if (vehicleO !=NULL and !vehicleO->isDestroyed()){
				soldiers.at(Soldati)->enterVehicle(vehicleO);
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
	if(!soldiers.at(Soldati)->isActiv()){
		soldiers.at(Soldati)->setActiv(true);
		soldiers.at(Soldati)->getVehicle()->setUsed(false);
		soldiers.at(Soldati)->leaveVehicle();
	}	
	return true;
}

bool Model::moveUp(int i,float coeff){
	char typepred;
	Vehicle* vehipred;
	if(soldiers.at(i)->isActiv()){
		int posy=soldiers.at(i)->getPosition().second;
		int nextPosy=posy-(soldiers.at(i)->getSpeed()*coeff+10)+soldiers.at(i)->getBoundingBox().first;
		typepred= wholeMap.getNodeAtPosXY(soldiers.at(i)->getPosition().first, nextPosy)->getSymbole();
		vehipred=isAtPosition(soldiers.at(i)->getPosition().first,nextPosy,vehicles);
	}
	else {
		int posy=vehicles.at(i)->getPosition().second;
		int nextPosy=posy-(vehicles.at(i)->getSpeed()*coeff+10)+vehicles.at(i)->getBoundingBox().first;
		typepred= wholeMap.getNodeAtPosXY(vehicles.at(i)->getPosition().first, nextPosy)->getSymbole();
		vehipred=isAtPosition(vehicles.at(i)->getPosition().first,nextPosy,vehicles);
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a'  or vehipred!=NULL){
		return false;
	} 
	soldiers.at(i)->moveUp(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
}

bool Model::moveBack(int i,float coeff){
	char typepred;
	Vehicle* vehipred;
	if(soldiers.at(i)->isActiv()){
		int posy=soldiers.at(i)->getPosition().second+soldiers.at(i)->getBoundingBox().first;
		int nextPosy=posy+(soldiers.at(i)->getSpeed()*coeff-10);
		typepred= wholeMap.getNodeAtPosXY(soldiers.at(i)->getPosition().first, nextPosy)->getSymbole();
		vehipred=isAtPosition(soldiers.at(i)->getPosition().first,nextPosy,vehicles);
	}
	else {
		int posy=vehicles.at(i)->getPosition().second;
		int nextPosy=posy+(vehicles.at(i)->getSpeed()*coeff-10)+vehicles.at(i)->getBoundingBox().first;
		typepred= wholeMap.getNodeAtPosXY(vehicles.at(i)->getPosition().first, nextPosy)->getSymbole();
		vehipred=isAtPosition(vehicles.at(i)->getPosition().first,nextPosy,vehicles);
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a'  or vehipred!=NULL){
		return false;
	} 
	soldiers.at(i)->moveBack(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
}

bool Model::moveLeft(int i,float coeff){
	char typepred;
	Vehicle* vehipred;
	if(soldiers.at(i)->isActiv()){
		int posx=soldiers.at(i)->getPosition().first;
		int nextPosx=posx-(soldiers.at(i)->getSpeed()*coeff+25)+soldiers.at(i)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,soldiers.at(i)->getPosition().second)->getSymbole();
		vehipred=isAtPosition(soldiers.at(i)->getPosition().first,nextPosx,vehicles);
	}
	else {
		int posx=vehicles.at(i)->getPosition().first;
		int nextPosx=posx-(vehicles.at(i)->getSpeed()*coeff+25)+vehicles.at(i)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,vehicles.at(i)->getPosition().second)->getSymbole();
		vehipred=isAtPosition(nextPosx,vehicles.at(i)->getPosition().second,vehicles);
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a'  or vehipred != NULL){
		return false;
	} 
	soldiers.at(i)->moveLeft(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
	
}

bool Model::moveRight(int i,float coeff){
	char typepred;
	Vehicle* vehipred;
	if(soldiers.at(i)->isActiv()){
		int posx=soldiers.at(i)->getPosition().first;
		int nextPosx=posx+(soldiers.at(i)->getSpeed()*coeff-10)+soldiers.at(i)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,soldiers.at(i)->getPosition().second)->getSymbole();
		vehipred=isAtPosition(nextPosx,soldiers.at(i)->getPosition().second,vehicles);
	}
	else {
		int posx=vehicles.at(i)->getPosition().first;
		int nextPosx=posx+(vehicles.at(i)->getSpeed()*coeff-10)+vehicles.at(i)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,vehicles.at(i)->getPosition().second)->getSymbole();
		vehipred=isAtPosition(nextPosx,vehicles.at(i)->getPosition().second,vehicles);
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a' or vehipred != NULL ){
		return false;
	}
	
	soldiers.at(i)->moveRight(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
	
}

void Model::fire(int _dx,int _dy,int Soldati){
	if (soldiers.at(Soldati)->getVehicle()==NULL){
		double elapsed= (clock() - lastFired) / (CLOCKS_PER_SEC / (double) 1000.0);
		if (elapsed > 50.0){
			Projectile* proj=soldiers.at(Soldati)->fire(_dx,_dy);
			if(proj != NULL ){
				projectiles.push_back(proj);
				lastFired=clock();
			}
		}
	}
	else {
		if ((clock()-lastFired) > 0){
			Projectile* proj=soldiers.at(Soldati)->fire(_dx,_dy);
			if(proj != NULL ){
				projectiles.push_back(proj);
				lastFired=clock();
			}
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
	Vehicle* res=NULL;
	for(i=0;i<length;i++){
		xno=vehicles.at(i)->getPosition().first;
		yno=vehicles.at(i)->getPosition().second;
		xse=vehicles.at(i)->getPosition().first+ vehicles.at(i)->getBoundingBox().second;
		yse=vehicles.at(i)->getPosition().second + vehicles.at(i)->getBoundingBox().first;
		if( (xno) < _x and (yno) < _y and (xse) > _x and (yse) > _y){
			 res=vehicles.at(i);
		}  
	}
	return res;
}

void Model::calcAngle(int _i,int _dx, int _dy){
	double angle = atan2( abs(soldiers.at(_i)->getPosition().second - _dy), abs(soldiers.at(_i)->getPosition().first - _dx)) * 180 / 3.14;
	soldiers.at(_i)->setAngle((-angle + 90));
}

void Model::update(float coeff){
	srand(time(NULL));	
	bool testrange = false;
	bool testhit = false;
	bool testblock = false;
	float x,y,distance;
	for(int i=(int) projectiles.size() - 1;i >= 0;i--){
		if(projectiles.size() > 0)
		{	testrange = false;
			testhit = false;
			testblock = false;
			for (int j=0;j < (int)soldiers.size();j++) {
				if( !soldiers.at(j)->isDead()){
					if (!testhit and !testrange and !testblock) {
						x = pow(soldiers.at(j)->getPosition().first - projectiles.at(i)->getPosition().first, 2);
						y = pow(soldiers.at(j)->getPosition().second - projectiles.at(i)->getPosition().second, 2);
						distance = sqrt( x + y );				
					}
					if (distance < 13 and !testhit and !testrange and !testblock){
						soldiers.at(j)->hit(projectiles.at(i)->getPower());
						projectiles.erase(projectiles.begin()+i);
						testhit=true;
					}
				}
				if(!testhit and !testrange and !testblock){
					if(projectiles.at(i)->getParcouru() > projectiles.at(i)->getRange()){
						projectiles.erase(projectiles.begin()+i);
						testrange=true;
					}
				}
				
				if(!testrange and !testhit and !testblock){
					char typepred= wholeMap.getNodeAtPosXY( projectiles.at(i)->getPosition().first, projectiles.at(i)->getPosition().second)->getSymbole();
					if (typepred == 's' or typepred== 'w'){
						projectiles.erase(projectiles.begin()+i);
						testblock=true;
					} 
				}
				
				if(!testrange and !testhit and !testblock){
					projectiles.at(i)->parcourir(coeff);
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
        if(soldiers.at(i)->getSymbole() == 'b'  and !soldiers.at(i)->isDead())
        {
			float alea= (rand()/(double)RAND_MAX);
			
            for(int j = 0; j < (int)soldiers.size(); j++)
            {	
                if(soldiers.at(i)->getTeam() != soldiers.at(j)->getTeam() and !soldiers.at(j)->isDead())
                {	direction=j;
                    float x = pow(soldiers.at(i)->getPosition().first - soldiers.at(j)->getPosition().first, 2);
                    float y = pow(soldiers.at(i)->getPosition().second - soldiers.at(j)->getPosition().second, 2);
                    float distance = sqrt( x + y );
                    if(distance < 200 and i != j)
					{
						if(projectiles.size() < 100)
						{	
							temps1=clock()/1000;
							if((temps1-temps0) > 0.995){
								float devia= (rand()/(double)RAND_MAX);
								projectiles.push_back(soldiers.at(i)->fire((int)soldiers.at(j)->getPosition().first+(devia * 10.0), (int)soldiers.at(j)->getPosition().second-(devia * 10.0)));
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
				int x = soldiers.at(i)->getPosition().first;
				int y = soldiers.at(i)->getPosition().second;
				int dx = soldiers.at(direction)->getPosition().first;
				int dy = soldiers.at(direction)->getPosition().second;
				if(i!=0){
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

