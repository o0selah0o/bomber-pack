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

bool Model::moveUp(int i,float coeff){
	char typepred;
	if(soldiers.at(i)->isActiv()){
		int posy=soldiers.at(i)->getPosition().second;
		int nextPosy=posy-(soldiers.at(i)->getSpeed()*coeff)+soldiers.at(i)->getBoundingBox().first;
		typepred= wholeMap.getNodeAtPosXY(soldiers.at(i)->getPosition().first, nextPosy);
		
	}
	else {
		int posy=vehicles.at(i)->getPosition().second;
		int nextPosy=posy-(vehicles.at(i)->getSpeed()*coeff)+vehicles.at(i)->getBoundingBox().first;
		typepred= wholeMap.getNodeAtPosXY(vehicles.at(i)->getPosition().first, nextPosy);		
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	soldiers.at(i)->moveUp(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
}

bool Model::moveBack(int i,float coeff){
	char typepred;
	if(soldiers.at(i)->isActiv()){
		int posy=soldiers.at(i)->getPosition().second+soldiers.at(i)->getBoundingBox().first;
		int nextPosy=posy+(soldiers.at(i)->getSpeed()*coeff);
		typepred= wholeMap.getNodeAtPosXY(soldiers.at(i)->getPosition().first, nextPosy);
		
	}
	else {
		int posy=vehicles.at(i)->getPosition().second;
		int nextPosy=posy+(vehicles.at(i)->getSpeed()*coeff)+vehicles.at(i)->getBoundingBox().first;
		typepred= wholeMap.getNodeAtPosXY(vehicles.at(i)->getPosition().first, nextPosy);		
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	soldiers.at(i)->moveBack(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
}

bool Model::moveLeft(int i,float coeff){
	char typepred;
	if(soldiers.at(i)->isActiv()){
		int posx=soldiers.at(i)->getPosition().first;
		int nextPosx=posx-(soldiers.at(i)->getSpeed()*coeff)+soldiers.at(i)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,soldiers.at(i)->getPosition().second);
	}
	else {
		int posx=vehicles.at(i)->getPosition().first;
		int nextPosx=posx-(vehicles.at(i)->getSpeed()*coeff)+vehicles.at(i)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,vehicles.at(i)->getPosition().second);
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a' or typepred=='s' or typepred=='b'){
		return false;
	} 
	soldiers.at(i)->moveLeft(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
	
}

bool Model::moveRight(int i,float coeff){
	char typepred;
	if(soldiers.at(i)->isActiv()){
		int posx=soldiers.at(i)->getPosition().first;
		int nextPosx=posx+(soldiers.at(i)->getSpeed()*coeff)+soldiers.at(i)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,soldiers.at(i)->getPosition().second);
	}
	else {
		int posx=vehicles.at(i)->getPosition().first;
		int nextPosx=posx+(vehicles.at(i)->getSpeed()*coeff)+vehicles.at(i)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,vehicles.at(i)->getPosition().second);
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	soldiers.at(i)->moveRight(coeff,wholeMap.getBoundingBox().first,wholeMap.getBoundingBox().second);
	return true;
	
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

void Model::update(float coeff){
	srand(time(NULL));	
	bool testrange = false;
	bool testhit = false;
	float x,y,distance;
	for(int i=(int) projectiles.size() - 1;i >= 0;i--){
		if(projectiles.size() > 0)
		{	testrange = false;
			testhit = false;
			for (int j=0;j < (int)soldiers.size();j++) {
				if( !soldiers.at(j)->isDead()){
					if (!testhit and !testrange) {
						x = pow(soldiers.at(j)->getPosition().first - projectiles.at(i)->getPosition().first, 2);
						y = pow(soldiers.at(j)->getPosition().second - projectiles.at(i)->getPosition().second, 2);
						distance = sqrt( x + y );				
					}
					if (distance < 1 and !testhit and !testrange){
						soldiers.at(j)->hit(projectiles.at(i)->getPower());
						projectiles.erase(projectiles.begin()+i);
						testhit=true;
					}
				}
				if(!testhit and !testrange){
					if(projectiles.at(i)->getParcouru() > projectiles.at(i)->getRange()){
						projectiles.erase(projectiles.begin()+i);
						testrange=true;
					}
				}
				if(!testrange and !testhit){
					projectiles.at(i)->parcourir();
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
							if((temps1-temps0) > 0.00005){
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

