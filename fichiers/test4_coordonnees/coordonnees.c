#include <stdio.h>
#include <stdlib.h>
#include "coordonnees.h"

// -------- lignes -------- //

ligne initialisation_ligne(int larg)
{
    ligne nv;                                            // creation ligne
    nv.largeur = larg;                                   // init de nv.largeur = parametre larg
    nv.caracteres = (char *)malloc(larg * sizeof(char)); // init de nv.caracteres => malloc de chaque caractere du tableau de caracteres de nv
    return nv;                                           // renvoie la ligne nv qui n'a pas encore de caractere dans son tableau de caracteres
}

ligne creer_ligne_pleine(int larg)
{
    ligne l = initialisation_ligne(larg); // initialisation ligne l
    for (int i = 0; i < larg; i++)
    {                          // boucle qui itère sur chaque caractere du tableau caracteres de la ligne l
        l.caracteres[i] = '#'; // on ajouter au tableau de caracteres de la ligne l le caractere '#';
    }
    return l; // renvoie de la ligne pleine l
}

void afficher_ligne(ligne l)
{
    for (int i = 0; i < l.largeur; i++)
    {                                  // boucle qui itere sur chaque caractere du tableau de caracteres de l;
        printf("%c", l.caracteres[i]); // affichage du caractere courant
    }
    printf("\n"); // une fois la ligne affiché on revient à la ligne pour qu'on puisse plus tard enchainer l'affichage des lignes sans revenir a la ligne manuellement apres chaque lignes affichées
}

// essai des coordonnées //

coordonnes definir_coordonnes(int X, int Y)
{
    coordonnes c;
    c.x = X;
    c.y = Y;
    return c;
}

int main()
{
    coordonnes c1;
    c1.x = 10;
    c1.y = 12;

    return 0;
}