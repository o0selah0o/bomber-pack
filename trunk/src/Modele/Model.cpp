#include "Model.h"
#include "Map.h"

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
