#include "Model.h"
#include "Map.h"
#include "math.h"

Model::Model(){
	
}

Model::~Model()
{
	unsigned int i;
	for(i=0;i<vehicles.size();i++){
		delete vehicles.at(i);
	}
	for(i=0;i<soldiers.size();i++){
		delete soldiers.at(i);
	}
}

Model::Model(std::string fichier){
	wholeMap= Map();
	wholeMap.ReadFileMap(fichier);
	wholeMap.ReadFileVehicles(fichier);
	//wholeMap.ReadFileSoldiers(fichier);
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

bool Model::moveUp(){
	char typepred;
	if(soldiers.at(0)->isActiv()){
		int posy=soldiers.at(0)->getPosition().second;
		int nextPosy=posy-soldiers.at(0)->getSpeed();
		typepred= wholeMap.getNodeAtPosXY(vehicles.at(0)->getPosition().first, nextPosy);
		
	}
	else {
		int posy=vehicles.at(0)->getPosition().second;
		int nextPosy=posy-vehicles.at(0)->getSpeed();
		typepred= wholeMap.getNodeAtPosXY(vehicles.at(0)->getPosition().first, nextPosy);		
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	vehicles.at(0)->moveUp();
	return true;
}

bool Model::moveBack(){
	char typepred;
	if(soldiers.at(0)->isActiv()){
		int posy=soldiers.at(0)->getPosition().second;
		int nextPosy=posy+soldiers.at(0)->getSpeed();
		typepred= wholeMap.getNodeAtPosXY(soldiers.at(0)->getPosition().first, nextPosy);
		
	}
	else {
		int posy=vehicles.at(0)->getPosition().second;
		int nextPosy=posy+vehicles.at(0)->getSpeed();
		typepred= wholeMap.getNodeAtPosXY(vehicles.at(0)->getPosition().first, nextPosy);		
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	vehicles.at(0)->moveBack();
	return true;
}

bool Model::moveLeft(){
	char typepred;
	if(soldiers.at(0)->isActiv()){
		int posx=soldiers.at(0)->getPosition().first;
		int nextPosx=posx-soldiers.at(0)->getSpeed();
		typepred= wholeMap.getNodeAtPosXY(nextPosx,soldiers.at(0)->getPosition().second);
	}
	else {
		int posx=vehicles.at(0)->getPosition().first;
		int nextPosx=posx-vehicles.at(0)->getSpeed();
		typepred= wholeMap.getNodeAtPosXY(nextPosx,vehicles.at(0)->getPosition().second);
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	vehicles.at(0)->moveRight();
	return true;
	
}

bool Model::moveRight(){
	char typepred;
	if(soldiers.at(0)->isActiv()){
		int posx=soldiers.at(0)->getPosition().first;
		int nextPosx=posx+soldiers.at(0)->getSpeed();
		typepred= wholeMap.getNodeAtPosXY(nextPosx,soldiers.at(0)->getPosition().second);
	}
	else {
		int posx=vehicles.at(0)->getPosition().first;
		int nextPosx=posx+vehicles.at(0)->getSpeed();
		typepred= wholeMap.getNodeAtPosXY(nextPosx,vehicles.at(0)->getPosition().second);
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	vehicles.at(0)->moveRight();
	return true;
	
}



void Model::update()
{
    //Todo
    // 1 - Faire avancer les balles. Pour chaque balle :
    //        - Verifier que les elements autour ne genent pas
    //        - Verifier que si elle est proche d'un soldat, retirer un point de vie au soldat
	
    // 2 - Pour chaque Bot :
    //        - Verifier position, ajuster pour se rapprocher de l'ennemi le plus proche
    //        - Si ennemi assez proche, tirer
    int distanceMax = 10000;
    int direction = 0;
    for(int i = 0; i < (int)soldiers.size(); i++)
    {
        if(soldiers.at(i)->getSymbole() == 'b')
        {
            for(int j = 0; j < (int)soldiers.size(); j++)
            {
                if(soldiers.at(i)->getTeam() != soldiers.at(j)->getTeam())
                {
                    float x = pow(soldiers.at(i)->getPosition().first - soldiers.at(j)->getPosition().first, 2);
                    float y = pow(soldiers.at(i)->getPosition().second - soldiers.at(j)->getPosition().second, 2);
                    float distance = sqrt( x + y );
                    if(distance < 400)
                        soldiers.at(i)->fire((int)x, (int)y);
                    if(distance < distanceMax)
                    {
                        distanceMax = (int) distance;
                        direction = j;
                    }
                }
            }
            int x = soldiers.at(i)->getPosition().first;
            int y = soldiers.at(i)->getPosition().second;
            int dx = soldiers.at(direction)->getPosition().first;
            int dy = soldiers.at(direction)->getPosition().second;
            if(x < dx)
                soldiers.at(i)->moveRight();
            if(x > dx)
                soldiers.at(i)->moveLeft();
            if(y > dy)
                soldiers.at(i)->moveBack();
            if(y < dy)
                soldiers.at(i)->moveUp();
        }
    }
}	
