#include <stdio.h>
#include <stdlib.h>
#include "essai.h"

donjon initialisation_donjon(int Hauteur, int Largeur)
{
    donjon nv;
    nv.hauteur = Hauteur;
    nv.tab = (ligne *)malloc(Hauteur * sizeof(ligne));
    for (int i = 0; i < Hauteur; i++)
    {
        nv.tab[i] = initialisation_ligne(Largeur);
    }
}

ligne initialisation_ligne(int Largeur)
{
    ligne nv;
    nv.largeur = Largeur;
    nv.tab = (char *)malloc(Largeur * sizeof(char));
    return nv;
}

ligne creer_ligne(int Largeur, char value)
{
    ligne nv = initialisation_ligne(Largeur);
    for (int i = 0; i < Largeur; i++)
    {
        nv.tab[i] = value;
    }
    return nv;
}
// /!\ attention important ' ou " ! 

ligne creer_ligne_vide(int Largeur)
{
    ligne nv = initialisation_ligne(Largeur);
    nv.tab[0] = '#';
    for (int i = 1; i < Largeur - 1; i++)
    {
        nv.tab[i] = ' ';
    }
    nv.tab[Largeur - 1] = '#';
    return nv;
}

donjon creer_donjon(int Hauteur, int Largeur)
{
    donjon nv = initialisation_donjon(Hauteur, Largeur);
    nv.tab[0] = creer_ligne(Largeur, '#');
    for (int i = 1; i < Hauteur - 1; i++)
    {
        nv.tab[i] = creer_ligne_vide(Largeur);
    }
    nv.tab[Hauteur - 1] = creer_ligne(Largeur, '#');
    return nv;
}

void afficher_ligne(ligne l)
{
    for (int i = 0; i < l.largeur; i++)
    {
        printf("%c", l.tab[i]);
    }
}

int main()
{
    ligne l = creer_ligne(10, '#');
    afficher_ligne(l);
    donjon d = creer_donjon(5, 10);
    for (int i = 0; i < d.hauteur; i++)
    {
        afficher_ligne(d.tab[i]);
    }

    return 0;
}

// ligne initialisation_ligne(int Largeur, int Hauteur)
// {
//     ligne nv;
//     nv.largeur = Largeur;
//     nv.hauteur = Hauteur;
//     nv.tab = (char *)malloc(Largeur * sizeof(char));
//     return nv;
// }

// void afficher_ligne(ligne d)
// {
//     for (int i = 0; i < d.largeur; i++)
//     {
//         printf("%c", d.tab[i]);
//     }
// }

// ligne creer_ligne(char *value, int Largeur)
// {
//     ligne nv = initialisation_ligne(Largeur, NULL);
//     for (int i = 0; i < Largeur; i++)
//     {
//         nv.tab[i] = *value;
//     }
//     return nv;
// }

// ligne creer_ligne_vide(ligne d)
// {
//     nv.tab[0] = "#";
//     for (int i = 1; i < tab.largeur - 1; i++)
//     {
//         nv.tab[i] = " ";
//     }
//     nv.tab[tab.largeur] = "#";
// }

// // {
// //     ligne nv = initialisation_ligne(Largeur, NULL);
// //     for (int i = 0; i < Largeur; i++)
// //     {
// //         nv.tab[i] = *value;
// //     }
// //     return nv;
// // }

// int main()
// {
//     printf("yo\n");
//     ligne nv = creer_ligne("#", 30, 5);
//     for (int i = 0; i < 10; i++)
//     {
//         creer_ligne_vide(nv);
//     }
//     afficher_ligne(nv);
//     return 0;
// }
