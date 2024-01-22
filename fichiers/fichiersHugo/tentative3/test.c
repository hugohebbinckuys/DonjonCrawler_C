#include "constructeur.h"
#include <string.h>
#include <stdio.h>

int main()
{
    donjon d; 
    initialiser_donjon (&d, 20, 20);
    salle s; 
    initialiser_salle(&s, 10, 10, 2, 2);
    printf ("debug -> init du donjon et de la salle ok\n");
    // debbuger_donjon(&d);
    printf ("10e debugage du stockage du donjon : nb_element : %d\n", d.stockage->nb_element);

    printf ("debug -> debug du donjon ok\n");
    inserer_salle(&d, &s);
    printf ("debug -> insertion de la salle dans donjon ok\n"); // insertion pas ok debug pas validé //

    salle s2; 
    initialiser_salle(&s2, 10, 10, 2, 2); 
    inserer_salle(&d, &s2);
    afficher_donjon(&d); 


    liberer_salle(&s);
    liberer_donjon(&d);
    return 0;
}