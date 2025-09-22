#pragma once
#include <string>
#include <iostream>
using namespace std;

class Implant
{
public:
    enum TypeImplant { Tete, Jambe, Bras };
    enum TypeRarete { Ordinaire, Rare, Unique };

    Implant(string nom, int force, int vitesse, TypeImplant type, TypeRarete rarete);
    ~Implant();

    int getForce();
    int getVitesse();
    string getNom();
    TypeImplant getType();
    TypeRarete getRarete();


    string to_string();

private:
    string nom;
    int force;
    int vitesse;
    TypeImplant type;
    TypeRarete rarete;
};
