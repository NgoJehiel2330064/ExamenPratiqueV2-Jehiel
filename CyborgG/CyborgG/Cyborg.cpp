#include "Cyborg.h"
#include "FactoryCyborg.h"


Cyborg::Cyborg(int num, int f, int v, int d, int p, string caract)
    : numero(num), force(f), vitesse(v), defense(d), prix(p), caracteristique(caract) {}

Cyborg::Cyborg(int num, int f, int v, int d, int p, string caract, Implant* _imp)
    : numero(num), force(f), vitesse(v), defense(d), prix(p), caracteristique(caract)
{
    if (_imp) AjouterImplant(_imp);
}



void Cyborg::AjouterImplant(Implant* imp)
{
    implants.push_back(imp);

    // multiplicateur selon rareté
    double m = 1.0;
    switch (imp->getRarete()) {
    case Implant::Ordinaire: m = 1.0; break;
    case Implant::Rare:      m = 1.5; break;
    case Implant::Unique:    m = 2.2; break; // plus fort pour “Unique”
    }

    force += int(imp->getForce() * m);
    vitesse += int(imp->getVitesse() * m);
}

Cyborg::~Cyborg()
{
    for (auto c : implants)
    {
        delete c;
        c = nullptr;
    }
}


void Cyborg::AfficherImplant()
{
    for (auto i : implants)
        cout << i->to_string() << "\n";
}



void Cyborg::init()
{
    vector <Cyborg*> Cyborgs;
    cout << "VOICI LA LISTE DE VOS CYBORGS : \n";

    for (int i = 0; i < 20; i++)
    {
       Cyborgs.push_back(FactoryCyborg::getRandomCyborg());
    }

    for (auto i : Cyborgs)
        cout << i+1 << "-" + i->to_string() << "\n";
}


int Cyborg::getAtt()
{
    return force;
}

int Cyborg::getNum() { return numero; }
int Cyborg::getVitesse() { return vitesse; }
int Cyborg::getDefense() { return defense; }
int Cyborg::getPrix() { return prix; }



std::string Cyborg::to_string()
{
    std::string info;

    info += "=== Cyborg #" + std::to_string(numero) + " ===\n";
    info += "Caracteristique : " + caracteristique + "\n";
    info += "Force   : " + std::to_string(force) + "\n";
    info += "Vitesse : " + std::to_string(vitesse) + "\n";
    info += "Defense : " + std::to_string(defense) + "\n";
    info += "Prix    : " + std::to_string(prix) + "\n";

    // Ajout des implants
    if (!implants.empty()) {
        info += "Implants du cyborg:\n";
        for (auto* imp : implants) {
            // transformer rareté en string
            std::string rareteStr;
            switch (imp->getRarete()) {
            case Implant::Ordinaire: rareteStr = "Ordinaire"; break;
            case Implant::Rare:      rareteStr = "Rare"; break;
            case Implant::Unique:    rareteStr = "Unique"; break;
            }

            info += "  - " + imp->getNom() + " [" + rareteStr + "]";
            info += " F+" + std::to_string(imp->getForce());
            info += " V+" + std::to_string(imp->getVitesse());
            info += "\n";
        }
    }
    else {
        info += "Aucun implant\n";
    }

    return info;
}
