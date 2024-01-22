#include "constructeur.h"
#include <string.h>
#include <stdio.h>

int main()
{
    donjon d; 
    initialiser_donjon (&d, 20, 40); 

    salle s; 
    initialiser_salle (&s, 4, 4, 0, 0);
    // salle s2; 
    // initialiser_salle (&s2, 2, 2, 5, 5);
    // salle s3; 
    // initialiser_salle (&s, 2, 2, 8, 8);
    // salle s4; 
    // initialiser_salle (&s2, 2, 2, 11, 11); 
    // salle s5; 
    // initialiser_salle (&s, 2, 2, 14, 14);
    salle s6; 
    initialiser_salle (&s6, 6, 4, 15, 10);

    // entitee e;
    // initialiser_entitee (&s, &e, 1, 1, 'F');
    // inserer_entitee_dans_salle (&s, &e); 
    // inserer_entitee_dans_salle(&s);
    
    inserer_salle(&d, &s);    
    inserer_salle(&d, &s6);    
    // inserer_salle(&d, &s2);    
    // inserer_salle(&d, &s3);    
    // inserer_salle(&d, &s4);    
    // inserer_salle(&d, &s5);    
    // inserer_salle(&d, &s6);
    afficher_donjon(&d);

    // sauvegarder_salle_dans_fichier(&s);
    // sauvegarder_donjon_dans_fichier(&d);
    liberer_salle(&s);
    liberer_donjon(&d);
    return 0;
}