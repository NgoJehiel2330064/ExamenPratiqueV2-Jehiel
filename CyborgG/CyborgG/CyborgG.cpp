#include <iostream>
#include <vector>
#include <ctime>
#include "Cyborg.h"
#include "FactoryCyborg.h"
using namespace std;


using namespace std;

static void afficherCyborg()
{
    vector<Cyborg*> cyborgs;
    cout << "VOICI LA LISTE DE VOS 20 CYBORGS : \n";

    // Générer 20 cyborgs
    for (int i = 0; i < 20; i++) {
        cyborgs.push_back(FactoryCyborg::getRandomCyborg());
    }

    // Afficher chaque cyborg
 
    for (int j = 0; j < cyborgs.size(); j++)
    {
        std::cout << j + 1 << " - " + cyborgs[j]->to_string() << std::endl; 
    }


    // Libérer la mémoire (très important)
    for (auto* c : cyborgs) {
        delete c;
    }
    cyborgs.clear();
}


static void afficherImplants()
{
    vector<Implant*> implants;
    cout << "VOICI LA LISTE DES IMPLANTS DISPONIBLES : \n";

    for (int i = 0; i < 10; i++)
        implants.push_back(FactoryCyborg::getRandomImplant());

    for (auto* imp : implants)
        cout << imp->to_string() << "\n";

    for (auto* imp : implants)
        delete imp;
}



int main() {
    srand(time(NULL));

    afficherCyborg();
    afficherImplants();

    cout << "\nVOICI UN NOUVEAU CYBORG : \n";
    Cyborg* nouveau = FactoryCyborg::getRandomCyborg();
    cout << nouveau->to_string() << "\n";
    delete nouveau;

    return 0;
}
