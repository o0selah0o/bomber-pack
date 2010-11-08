

#ifndef __MODEL
#define __MODEL

#include <vector>
#include <string>
#include "Node.h"
#include "Soldier.h"
#include "Vehicle.h"
#include "Map.h"
#include "Projectile.h"
#include "Impact.h"
#include "Body.h"
/**
 Model a une map ( un arbre de nodes) et un vecteur de personnages
 **/
class Model
{
public:
	//constructeur
	Model();
	
	//constructeur avec prefixe du nom des fichiers à lire. si "mapX" alors lira mapX_map.txt, mapX_vehicles.txt ,mapX_soldiers.txt
	Model(std::string fichier);
	
	//destructeur
	~Model();
	
	// méthode qui séléctionne ce que voit le joueur
	std::vector<Node> FieldView();
	
	//getters and setters
	Map getMap();
	
	//getter des soldats
	std::vector<Soldier*> getSoldiers();
	
	//getter des vehicules
	std::vector<Vehicle*> getVehicles();
	
	//ajoute un soldat au tableau des soldats
	void addSoldier(Soldier* _soldier){soldiers.push_back(_soldier);};
	
	//méthode qui effectue les controles avant d'appeler la méthode adéquate du soldat
	bool moveUp(int i,float coeff);
	
	//méthode qui effectue les controles avant d'appeler la méthode adéquate du soldat
	bool moveBack(int i,float coeff);
	
	//méthode qui effectue les controles avant d'appeler la méthode adéquate du soldat
	bool moveRight(int i,float coeff);
	
	//méthode qui effectue les controles avant d'appeler la méthode adéquate du soldat
	bool moveLeft(int i,float coeff);
	
	//Effectue tous les traitements du jeu. COntient l'ia des bots
	void update(float coeff);
	
	//champs de vision du joueur. Non utilisé dans cette version du jeu
	std::vector<Node*> FieldOfView(int _x,int _y,int hauteurfov,int longueurfov);
	
	//getter des projectiles
	std::vector<Projectile*> getProjectiles();
	
	//ajoute un projectiles au tableau des projectiles
	void addProjectiles(Projectile* _projectile);
	
	//effectue les contrôles necessaire avant d'appeler la méthode de tir du soldat
	void fire(int _dx,int _dy,int Soldati);
	
	// Permet de détecter si il y a un véhicule quand un soldat demande à entrer dans véhicule. Retourne le pointeur du véhicule à la position x,y.
	Vehicle* isAtPosition(int _x,int _y,std::vector<Vehicle*> vehicles);
	
	//Effectue les controles nécessaire avant de permettre a un soldat d'entrer dans un véhicule
	bool enterVehicle(int Soldati);
	
	//Effectue les controles nécessaire avant de permettre a un soldat de sortir de son véhicule
	bool leaveVehicle(int Soldati);
	
	//permet de calculer un angle de rotation
	void calcAngle(int _i,int _dx, int _dy);
	
	//permet de savoir si un véhicule est utilisé par le joueur
	char getUsedVehicle();
	
	//vide le tableau contenant les impacts
	void clearImpacts();
	
	//getter du tableau des impacts
	std::vector<Impact*>  getImpacts();
	
	//getter du tableau des "corps craie"
	std::vector<Body*> getBodies();
	
	private:
	
	//Toute la carte de jeu. 
	Map wholeMap;
	
	//tableau contenant les personnages de la carte. Le premier est le joueur, le reste sont des bots
	std::vector<Soldier*> soldiers;
	
	// tableau contenant tous les vehicules de la carte
	std::vector<Vehicle*> vehicles;
	
	// tableau contenant les projectiles de la carte
	std::vector<Projectile*> projectiles;
	
	//tableau contenant les contours de craie des corps
	std::vector<Body*> bodies;
	
	//tableau contenant les impacts a afficher sur la carte
	std::vector<Impact*> impacts;
	
	//determine si un joueur utilise un véhicule ou pas
	char usedVehicle;
	
	//determine la date du dernier tir du joueur (temporisateur
	double lastFired;
};


#endif