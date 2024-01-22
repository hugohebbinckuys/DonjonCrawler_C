#include "constructeur.h"
#include <string.h>
#include <stdio.h>

int main()
{
    donjon d; 
    initialiser_donjon (&d, 20, 20);
    afficher_donjon (&d); 

    couloir c; 
    creer_couloir(&c, 2, 2);
    // afficher_couloir (2, 2,  &c, &d); 

    // salle s; 
    // initialiser_salle(&s, 5, 5, 18, 18);
    // stockage_salle sto; 
    // initialiser_stockage(&sto);
    // afficher_salle(&s);
    // printf ("ok\n"); 
    // inserer_salle(&d, &s); 
    // printf ("OK\n"); 


    // initialiser_entitee(&s, &e, 2, 3, 'E');
    // initialiser_entitee(&s, &e2, 5, 5, 'M');
    // inserer_entitee_dans_salle(&s, &e);
    // inserer_entitee_dans_salle(&s, &e2);
    // printf ("yo");
    // inserer_salle(&d, &s);
    // printf ("yo");
    // afficher_donjon(&d);



    // sauvegarder_salle_dans_fichier(&s);
    sauvegarder_donjon_dans_fichier(&d);
    // liberer_salle(&s);
    liberer_donjon(&d);
    return 0;
}