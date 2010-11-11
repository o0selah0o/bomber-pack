#include "Map.h"
#include "Node.h"
#include "Water.h"
#include "Tank.h"
#include "Vehicle.h"
#include "SandBags.h"
#include "Wall.h"
#include "Jeep.h"
#include "Sandbags.h"
#include "Grass.h"
#include "Soldier.h"
#include "BotSoldier.h"

#include <fstream>
#include <iostream>
#include <string>
#include "tokenize.h"


Map::Map():Node()
{
	symbole='m';
}

Map::~Map(){
	unsigned int i;
	if(!vehicles.empty()){
		for(i = 0; i < vehicles.size() ; i++){
			//delete vehicles.at(i);
		}
	}
	if(!soldiers.empty()){
		for(i = 0 ; i < soldiers.size() ; i++){
			//delete soldiers.at(i);
		}
	}
	
}

bool Map::ReadFileMap(std::string fichier){
	std::ifstream loadedFile(fichier.c_str());
	std::vector<std::string> parse;
	if ( loadedFile )
	{
		std::string ligne;
		std::string wall="WALL";
		std::string water="WATER";
		std::string sandbags="SANDBAGS";
		std::string size="SIZE";
		int l;
		int h;
		char typeToAdd='w';
		while (std::getline(loadedFile,ligne))
		{	
			if (ligne.find(size)!=std::string::npos){
				std::getline(loadedFile,ligne);
				parse=tokenize(ligne,'|');
				h= std::atoi(parse.at(0).c_str());
				l= std::atoi(parse.at(1).c_str());
				hauteur=h;
				longueur=l;
				addSpecificNode(0, 0,h,l, 'g');
				std::getline(loadedFile,ligne);
			}
			if(ligne.find(wall)!=std::string::npos){
				typeToAdd='w';
			}
			if(ligne.find(water)!=std::string::npos){
				typeToAdd='a';
			}
			if(ligne.find(sandbags)!=std::string::npos){
				typeToAdd='s';
			}
			
			if(ligne.find('|')!=std::string::npos){
				parse= tokenize(ligne,'|');
				int coorx;
				int coory;
				
				std::vector<std::string> caseInf;
				
				caseInf=tokenize(parse.at(0),' ');
				coorx=std::atoi(caseInf.at(0).c_str());
				coory=std::atoi(caseInf.at(1).c_str());
				caseInf=tokenize(parse.at(1),' ');
				h=std::atoi(caseInf.at(1).c_str());
				l=std::atoi(caseInf.at(2).c_str());
				addSpecificNode(coorx,coory,h,l,typeToAdd);
			}
			
		}
	}
	
	return true;
}

bool Map::ReadFileVehicles(std::string fichier){
	std::ifstream loadedFile(fichier.c_str());
	std::vector<std::string> parse;
	int sizecase=0;
	if ( loadedFile )
	{	
		std::string ligne;
		std::string tank="TANK";
		std::string jeep="JEEP";
		char typeToAdd='b';
		while (std::getline(loadedFile,ligne))
		{	
			if(ligne.find(tank)!=std::string::npos){
				typeToAdd='t';
				std::getline(loadedFile,ligne);
			}
			if(ligne.find(jeep)!=std::string::npos){
				typeToAdd='j';
				std::getline(loadedFile,ligne);
			}
			if(ligne.find('|')!=std::string::npos){
				parse= tokenize(ligne,'|');
				int coorx;
				int coory;
				
				std::vector<std::string> caseInf;
				
				caseInf=tokenize(parse.at(0),' ');
				coorx=std::atoi(caseInf.at(0).c_str());
				caseInf=tokenize(parse.at(1),' ');
				coory=std::atoi(caseInf.at(1).c_str());
				addSpecificNode(coorx,coory,sizecase,sizecase,typeToAdd);
			}	
		}
	}
	
	return true;
}


bool Map::ReadFileSoldiers(std::string fichier){
	std::ifstream loadedFile(fichier.c_str());
	std::vector<std::string> parse;
	if ( loadedFile )
	{	
		std::string ligne;
		std::string soldier="SOLDIER";
		std::string bot="BOT";
		char typeToAdd='b';
		while (std::getline(loadedFile,ligne))
		{	
			if(ligne.find(soldier)!=std::string::npos){
				typeToAdd='c';
				std::getline(loadedFile,ligne);
			}
			if(ligne.find(bot)!=std::string::npos){
				typeToAdd='b';
				std::getline(loadedFile,ligne);
			}
			if(ligne.find('|')!=std::string::npos){
				parse= tokenize(ligne,'|');
				int coorx;
				int coory;
				
				std::vector<std::string> caseInf;
				
				caseInf=tokenize(parse.at(0),' ');
				coorx=std::atoi(caseInf.at(0).c_str());
				coory=std::atoi(caseInf.at(1).c_str());
				
				int team= std::atoi(parse.at(1).c_str());
				int nujoueur=std::atoi(parse.at(2).c_str());
				
				addSoldier(coorx,coory,typeToAdd,team,nujoueur);
			}	
		}
	}
	
	return true;
}



void Map::addSpecificNode(int coorx,int coory, int _hauteur, int _longueur, char type ){
	if (type=='t'){
		Tank* tank= new Tank(coorx,coory);
		vehicles.push_back(tank);
	}
	if (type=='w'){
		Wall* wall = new Wall(coorx,coory,_longueur,_hauteur);
		child.push_back(wall);
	}
	if (type=='g'){
		Grass* grass = new Grass(coorx,coory,_longueur,_hauteur);
		child.push_back(grass);
	}
	if (type=='a'){
		Water* water = new Water(coorx,coory,_longueur,_hauteur);
		child.push_back(water);
	}
	if (type=='s'){
		SandBags* sand = new SandBags(coorx,coory,_longueur,_hauteur);
		child.push_back(sand);
	}
	if (type=='j'){
		Jeep* jeep =new Jeep(coorx,coory);
		vehicles.push_back(jeep);
	}
}

void Map::addSoldier(int coorx,int coory,char type, int team, int nujoueur ){
	if (type=='b'){
		BotSoldier* bot= new BotSoldier(nujoueur,team,coorx,coory);
		soldiers.push_back(bot);
	}
	if (type=='c'){
		Soldier* soldier = new Soldier(nujoueur,team,coorx,coory);
		soldiers.push_back(soldier);
	}
}

std::vector<Soldier*> Map::getSoldiers(){
	return soldiers;
}


std::vector<Vehicle*> Map::getVehicles(){
	return vehicles;
} 






