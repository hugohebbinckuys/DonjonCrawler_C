#ifndef COORDONNEES_H
#define COORDONNEES_H

typedef struct coordonnes
{
    int x;
    int y;
} coordonnes;

typedef struct ligne
{
    int largeur;
    char *caracteres;
} ligne;

typedef struct donjon
{
    int hauteur;
    ligne *lignes;
} donjon;

#endif