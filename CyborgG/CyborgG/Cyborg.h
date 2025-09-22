#pragma once
#include <string>
#include <iostream>
#include<ctime>
#include <vector>
#include "Implant.h"



using namespace std;

class Cyborg
{
protected:
	int numero;
	int force;
	int vitesse;
	int defense;
	int prix;
	string caracteristique;
	vector<Implant*> implants;


public :
	Cyborg(int num, int force, int vitesse, int defense, int prix,string caract);
	Cyborg(int num, int force, int vitesse, int defense, int prix,string caract,Implant* _imp);
	~Cyborg();

	int getAtt();
	int getNum();
	int getVitesse();
	int getDefense();
	int getPrix();
	void AjouterImplant(Implant* imp);
	void AfficherImplant();

	void init();


	 std::string to_string();
};

