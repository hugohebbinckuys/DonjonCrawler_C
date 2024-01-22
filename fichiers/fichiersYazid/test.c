#include "constructeur.h"
#include <string.h>
#include <stdio.h>

int main()
{
    donjon d; 
    initialiser_donjon (&d, 20, 20);
    couloir c; 
    initialiser_couloir(&c, 5, 5);
    
    liberer_donjon(&d);
    return 0;
}