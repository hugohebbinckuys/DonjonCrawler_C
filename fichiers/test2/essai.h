#ifndef ESSAI_H
#define ESSAI_H

typedef struct ligne
{
    int largeur;
    char *tab;
} ligne;

typedef struct donjon
{
    int hauteur;
    ligne *tab;
} donjon;

ligne initialisation_ligne(int Largeur);
ligne creer_ligne(int Largeur, char value);
ligne creer_ligne_vide(int Largeur);
donjon creer_donjon(int Hauteur, int Largeur);
void afficher_ligne(ligne l);

#endif