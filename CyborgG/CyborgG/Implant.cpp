#include "Implant.h"

Implant::Implant(string n, int f, int v, TypeImplant t, TypeRarete r)
    : nom(n), force(f), vitesse(v), type(t), rarete(r) {
}

Implant::TypeRarete Implant::getRarete() { return rarete; }

Implant::~Implant() {}

int Implant::getForce() { return force; }
int Implant::getVitesse() { return vitesse; }
string Implant::getNom() { return nom; }
Implant::TypeImplant Implant::getType() { return type; }

string Implant::to_string()
{
    string info;
    info.append("Implant nom : " + nom + "\n");
    info.append(" Force : " + std::to_string(force) + "\n");
    info.append(" Vitesse : " + std::to_string(vitesse) + "\n");
    return info;
}
