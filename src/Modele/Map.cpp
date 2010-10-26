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
		char typeToAdd='w';

		while (std::getline(loadedFile,ligne))
		{	
			if (ligne.find(size)){
				parse=tokenize(ligne,'|');
				longueur= atoi(parse.at(0).c_str());
				hauteur= atoi(parse.at(1).c_str());
				addSpecificNode(0, 0, longueur, hauteur, 'g');
				std::getline(loadedFile,ligne);
			}
			if(ligne.find(wall)){
				typeToAdd='w';
			}
			if(ligne.find(water)){
				typeToAdd='a';
			}
			if(ligne.find(sandbags)){
				typeToAdd='s';
			}
			
			parse= tokenize(ligne,'|');
			int coorx;
			int coory;
			std::vector<std::string> caseInf;
			caseInf=tokenize(parse.at(0),' ');
			coorx=std::atoi(caseInf.at(0).c_str());
			coory=std::atoi(caseInf.at(1).c_str());
			caseInf=tokenize(parse.at(1),' ');
			int hauteur=std::atoi(caseInf.at(0).c_str());
			int longueur=std::atoi(caseInf.at(1).c_str());
			addSpecificNode(coorx,coory,hauteur,longueur,typeToAdd);
						
		}
	}
	
	return true;
}

bool Map::ReadFileVehicles(std::string fichier){
	std::ifstream loadedFile(fichier.c_str());
	std::vector<std::string> parse;
	if ( loadedFile )
	{
		std::string ligne;
		std::string jeep="JEEP";
		std::string tank="TANK";
		char typeToAdd='w';
		
		while (std::getline(loadedFile,ligne))
		{
			if(ligne.find(tank)){
				typeToAdd='t';
			}
			if(ligne.find(jeep)){
				typeToAdd='j';
			}
			
			parse= tokenize(ligne,'|');
			int coorx;
			int coory;
			std::vector<std::string> caseInf;
			int sizeCase= 10;
			caseInf=tokenize(parse.at(0),' ');
			coorx=std::atoi(caseInf.at(0).c_str());
			coory=std::atoi(caseInf.at(1).c_str());
			addSpecificNode(coorx,coory,sizeCase,sizeCase,typeToAdd);
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
			if(ligne.find(soldier)){
				typeToAdd='c';
			}
			if(ligne.find(bot)){
				typeToAdd='b';
			}
			parse= tokenize(ligne,'|');
			int coorx;
			int coory;
			std::vector<std::string> caseInf;
			caseInf=tokenize(parse.at(0),' ');
			coorx=std::atoi(caseInf.at(0).c_str());
			coory=std::atoi(caseInf.at(1).c_str());
			caseInf=tokenize(parse.at(1),' ');
			int team= std::atoi(caseInf.at(0).c_str());
			caseInf=tokenize(parse.at(2),' ');
			int nujoueur=std::atoi(caseInf.at(0).c_str());
			addSoldier(coorx,coory,typeToAdd,team,nujoueur);
		}
	}
	
	return true;
}


	
void Map::addSpecificNode(int coorx,int coory, int hauteur, int longueur, char type ){
	if (type=='t'){
		Tank tank= Tank(coorx,coory);
		vehicles.push_back(&tank);
	}
	if (type=='w'){
		Wall wall = Wall(coorx,coory,hauteur,longueur);
		child.push_back(&wall);
	}
	if (type=='g'){
		Grass grass = Grass(coorx,coory,hauteur,longueur);
		child.push_back(&grass);
	}
	if (type=='a'){
		Water water = Water(coorx,coory,hauteur,longueur);
		child.push_back(&water);
	}
	if (type=='s'){
		SandBags sand =SandBags(coorx,coory,hauteur,longueur);
		child.push_back(&sand);
	}
	if (type=='j'){
		Jeep jeep =Jeep(coorx,coory);
		vehicles.push_back(&jeep);
	}
}

void Map::addSoldier(int coorx,int coory,char type, int team, int nujoueur ){
	if (type=='b'){
		BotSoldier bot= BotSoldier(nujoueur,team,coorx,coory);
		soldiers.push_back(&bot);
	}
	if (type=='c'){
		Soldier soldier = Soldier(nujoueur,team,coorx,coory);
		soldiers.push_back(&soldier);
	}
}






