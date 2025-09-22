#include "Utilitaire.h"
#include <cstdlib> 
#include <ctime>  

int Utilitaire::genererNb(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}
