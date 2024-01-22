#include "constructeur.h"
#include <string.h>
#include <stdio.h>

int main()
{
    donjon d; 
    initialiser_donjon (&d, 20, 20);
    salle s; 
    initialiser_salle (&s, 10, 10, 1, 1); 
    afficher_donjon(&d);
    afficher_salle(&s);
    inserer_salle(&d, &s); // impossible d'inserer dans une salle; 

    liberer_donjon(&d);
    liberer_salle(&s);
    return 0;
}