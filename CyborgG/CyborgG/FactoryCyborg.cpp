#include "FactoryCyborg.h"


static Implant::TypeRarete tirerRarete() {
    // 70% Ordinaire, 25% Rare, 5% Unique  -> Unique est dur à obtenir
    int r = Utilitaire::genererNb(1, 100);
    if (r <= 70) return Implant::Ordinaire;
    if (r <= 95) return Implant::Rare;
    return Implant::Unique;
}

Implant* FactoryCyborg::getRandomImplant()
{
    auto type = (Implant::TypeImplant)Utilitaire::genererNb(0, 2);
    auto rare = tirerRarete();

    // plages plus hautes si rareté élevée
    int f = 0, v = 0;
    switch (rare) {
    case Implant::Ordinaire: f = Utilitaire::genererNb(1, 5);  v = Utilitaire::genererNb(1, 5);  break;
    case Implant::Rare:      f = Utilitaire::genererNb(6, 12); v = Utilitaire::genererNb(6, 12); break;
    case Implant::Unique:    f = Utilitaire::genererNb(13, 20); v = Utilitaire::genererNb(13, 20); break;
    }

    string nom = (type == Implant::Tete ? "Veloster" : type == Implant::Bras ? "Blast" : "Raptor");
    return new Implant(nom, f, v, type, rare);
}



Cyborg* FactoryCyborg::getRandomCyborg()
{
    string caracter[] = { "Feu","Eau","Vent","Terre","Glace","Metal","Organique" };
    int index = Utilitaire::genererNb(0, 6);

    Implant* monImp = getRandomImplant();
    Cyborg* cyborg = nullptr;


    cyborg = new Cyborg(Utilitaire::genererNb(10, 50), Utilitaire::genererNb(10, 50), Utilitaire::genererNb(10, 50), Utilitaire::genererNb(10, 50),
        Utilitaire::genererNb(10, 50), caracter[index], monImp);

    return cyborg;
}