#include <stdio.h>
#include <stdlib.h>
#include "essai.h"

donjon initialisation_donjon(int Largeur, int Hauteur)
{
    donjon nv;
    nv.largeur = Largeur;
    nv.hauteur = Hauteur;
    nv.tab = (char *)malloc(Largeur * sizeof(char));
    return nv;
}

void afficher_ligne(donjon d)
{
    for (int i = 0; i < d.largeur; i++)
    {
        printf("%c", d.tab[i]);
    }
}

donjon creer_ligne(char *value, int Largeur)
{
    donjon nv = initialisation_donjon(Largeur, NULL);
    for (int i = 0; i < Largeur; i++)
    {
        nv.tab[i] = *value;
    }
    return nv;
}

donjon creer_ligne_vide(donjon d)
{
    nv.tab[0] = "#";
    for (int i = 1; i < tab.largeur - 1; i++)
    {
        nv.tab[i] = " ";
    }
    nv.tab[tab.largeur] = "#";
}

// {
//     donjon nv = initialisation_donjon(Largeur, NULL);
//     for (int i = 0; i < Largeur; i++)
//     {
//         nv.tab[i] = *value;
//     }
//     return nv;
// }

int main()
{
    printf("yo\n");
    donjon nv = creer_ligne("#", 30, 5);
    for (int i = 0; i < 10; i++)
    {
        creer_ligne_vide(nv);
    }
    afficher_ligne(nv);
    return 0;
}