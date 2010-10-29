#include "Model.h"
#include "Map.h"
#include "math.h"
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

bool Model::moveUp(float coeff){
	char typepred;
	if(soldiers.at(0)->isActiv()){
		int posy=soldiers.at(0)->getPosition().second;
		int nextPosy=posy-soldiers.at(0)->getSpeed()+soldiers.at(0)->getBoundingBox().first;
		typepred= wholeMap.getNodeAtPosXY(soldiers.at(0)->getPosition().first, nextPosy);
		
	}
	else {
		int posy=vehicles.at(0)->getPosition().second;
		int nextPosy=posy-vehicles.at(0)->getSpeed()+vehicles.at(0)->getBoundingBox().first;
		typepred= wholeMap.getNodeAtPosXY(vehicles.at(0)->getPosition().first, nextPosy);		
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	soldiers.at(0)->moveUp(coeff);
	return true;
}

bool Model::moveBack(float coeff){
	char typepred;
	if(soldiers.at(0)->isActiv()){
		int posy=soldiers.at(0)->getPosition().second+soldiers.at(0)->getBoundingBox().first;
		int nextPosy=posy+soldiers.at(0)->getSpeed();
		typepred= wholeMap.getNodeAtPosXY(soldiers.at(0)->getPosition().first, nextPosy);
		
	}
	else {
		int posy=vehicles.at(0)->getPosition().second;
		int nextPosy=posy+vehicles.at(0)->getSpeed()+vehicles.at(0)->getBoundingBox().first;
		typepred= wholeMap.getNodeAtPosXY(vehicles.at(0)->getPosition().first, nextPosy);		
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	soldiers.at(0)->moveBack(coeff);
	return true;
}

bool Model::moveLeft(float coeff){
	char typepred;
	if(soldiers.at(0)->isActiv()){
		int posx=soldiers.at(0)->getPosition().first;
		int nextPosx=posx-soldiers.at(0)->getSpeed()+soldiers.at(0)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,soldiers.at(0)->getPosition().second);
	}
	else {
		int posx=vehicles.at(0)->getPosition().first;
		int nextPosx=posx-vehicles.at(0)->getSpeed()+vehicles.at(0)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,vehicles.at(0)->getPosition().second);
	}
	
	if (typepred == 's' or typepred== 'w' or typepred =='a' or typepred=='s' or typepred=='b'){
		return false;
	} 
	soldiers.at(0)->moveLeft(coeff);
	return true;
	
}

bool Model::moveRight(float coeff){
	char typepred;
	if(soldiers.at(0)->isActiv()){
		int posx=soldiers.at(0)->getPosition().first;
		int nextPosx=posx+soldiers.at(0)->getSpeed()+soldiers.at(0)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,soldiers.at(0)->getPosition().second);
	}
	else {
		int posx=vehicles.at(0)->getPosition().first;
		int nextPosx=posx+vehicles.at(0)->getSpeed()+vehicles.at(0)->getBoundingBox().second;
		typepred= wholeMap.getNodeAtPosXY(nextPosx,vehicles.at(0)->getPosition().second);
	}
	if (typepred == 's' or typepred== 'w' or typepred =='a'){
		return false;
	} 
	soldiers.at(0)->moveRight(coeff);
	return true;
	
}





void Model::update(float coeff)
{
	std::cout << (int)projectiles.size() << std::endl;
    //Todo
    // 1 - Faire avancer les balles. Pour chaque balle :
    //        - Verifier que les elements autour ne genent pas
    //        - Verifier que si elle est proche d'un soldat, retirer un point de vie au soldat
	//Projectile* tempPointer;
	for(int i=(int) projectiles.size() - 1;i >= 0;i--){
		if(projectiles.size() > 0)
		{
			projectiles.at(i)->parcourir();
			if(projectiles.at(i)->getParcouru() > projectiles.at(i)->getRange()){
				//tempPointer= projectiles.at(i);
				std::cout << "Parcouru : " << i << std::endl;
				projectiles.erase(projectiles.begin()+i);
				//delete tempPointer;
			}
			/*
			 char terrainNode = wholeMap.getNodeAtPosXY(projectiles.at(i)->getPosition().first,projectiles.at(i)->getPosition().second);
			 if(terrainNode == 's'  or terrainNode == 'w'){
			 tempPointer= projectiles.at(i);
			 std::cout << "W ou S : " << i << std::endl;
			 //projectiles.erase(projectiles.begin()+i);
			 //delete tempPointer;
			 }*/
		}
	}
	/*
	 for(int i=(int) projectiles.size() - 1;i >= 0;i--){
	 if(projectiles.size() > 0)
	 {
	 projectiles.at(i)->parcourir();
	 for (int j=0;j < (int)soldiers.size();j++) {
	 float x = pow(soldiers.at(j)->getPosition().first - projectiles.at(i)->getPosition().first, 2);
	 float y = pow(soldiers.at(j)->getPosition().second - projectiles.at(i)->getPosition().second, 2);
	 float distance = sqrt( x + y );
	 if (distance < 5){
	 soldiers.at(j)->hit(projectiles.at(i)->getPower());
	 tempPointer= projectiles.at(i);
	 //projectiles.erase(projectiles.begin()+i);
	 //delete tempPointer;
	 }
	 }
	 }
	 }*/
	
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
                    if(distance < 200 and i != j)
					{
						if(projectiles.size() < 100)
						{
							projectiles.push_back(soldiers.at(i)->fire((int)soldiers.at(j)->getPosition().first, (int)soldiers.at(j)->getPosition().second));
						}
                    }
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
                soldiers.at(i)->moveRight(coeff);
            if(x > dx)
                soldiers.at(i)->moveLeft(coeff);
            if(y > dy)
                soldiers.at(i)->moveUp(coeff);
            if(y < dy)
                soldiers.at(i)->moveBack(coeff);
        }
    }
}

std::vector<Projectile*> Model::getProjectiles()
{
	return projectiles;
}

std::vector<Node*> Model::FieldOfView(int _x,int _y,int hauteurfov,int longueurfov){
	return wholeMap.cross(_x,_y,hauteurfov,longueurfov);
}
