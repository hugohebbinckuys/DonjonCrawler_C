#include "constructeur.h"
#include <string.h>
#include <stdio.h>

int main()
{
    donjon d; 
    initialiser_donjon (&d, 20, 20);
    salle s; 
    initialiser_salle(&s, 10, 10, 12, 12);    
    salle s2; 
    initialiser_salle(&s, 4, 4, 2, 2);
    printf ("debug -> init du donjon et de la salle ok\n");
    debbuger_donjon(&d);
    printf ("10e debugage du stockage du donjon : nb_element : %d\n", d.stockage->nb_element);

    printf ("debug -> debug du donjon ok\n");
    inserer_salle(&d, &s);
    printf ("debugage du stockage du donjon : nb_element : %d\n", d.stockage->nb_element);
    inserer_salle(&d, &s);
    printf ("debugage du stockage du donjon : nb_element : %d\n", d.stockage->nb_element);    
    inserer_salle(&d, &s2);
    printf ("debugage du stockage du donjon : nb_element : %d\n", d.stockage->nb_element);


    printf ("debug -> insertion de la salle dans donjon ok\n");
    afficher_donjon (&d);


    liberer_salle(&s);
    liberer_donjon(&d);
    return 0;
}