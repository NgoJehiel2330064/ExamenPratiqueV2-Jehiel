#pragma once

#include "Implant.h"
#include "Utilitaire.h"
#include "Cyborg.h"



class FactoryCyborg
{
public:
	static Cyborg* getRandomCyborg();
	static Implant* getRandomImplant();
};

