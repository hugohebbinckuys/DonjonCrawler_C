#include <stdio.h>
#include <stdlib.h>
#include "test.h"

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

ligne creer_ligne_vide(int larg)
{
    ligne l = initialisation_ligne(larg); // initialisation de la ligne l
    l.caracteres[0] = '#';                // on definit '#' comme premier caractere du tableau de caracteres de la ligne l pour faire la bordure gauche de la ligne
    for (int i = 1; i < l.largeur; i++)
    {                          // boucle qui itère sur chaque element du tableau de caracteres de la ligne l en commançant au deuxieme element car le premier a deja ete assigné juste au dessus
        l.caracteres[i] = ' '; // on ajouter au tableau de caracteres de la ligne l le caractere vide ' ' pour faire le "corps" du donjon;
    }
    l.caracteres[larg - 1] = '#'; // on definit '#' comme dernier caractere du tableau de caracteres de la ligne l pour faire la bordure droite de la ligne
    return l;                     // renvoie de la ligne vide l
}

// -------- donjon -------- //

donjon initialisation_donjon(int haut)
{
    donjon nv;                                         // creation du donjon nv
    nv.hauteur = haut;                                 // initialisation de la hauteur du donjon nv
    nv.lignes = (ligne *)malloc(haut * sizeof(ligne)); // init de nv.lignes => malloc de chaque ligne du tableau de lignes de nv
    return nv;                                         // renvoie le donjon nv qui n'a pas encore de ligne dans son tableau de lignes
}

donjon creer_donjon_vide(int haut, int larg)
{
    donjon d = initialisation_donjon(haut); // initialisation du donjon d
    ligne lp = creer_ligne_pleine(larg);    // creation d'une ligne pleine lp qui sera utilisé pour faire les bordures hautes et basses du donjon
    ligne lv = creer_ligne_vide(larg);      // creation d'une ligne vide lv qui sera utilisé pour faire les bordures latérales et le "corps" du donjon

    d.lignes[0] = lp; // assignation de la première ligne du tableau de lignes du donjon en tant que ligne pleine pour faire la structure extérieure
    for (int i = 1; i < haut - 1; i++)
    {                     // boucle qui parcours la hauteur du donjon en commancant au deuxieme element du tableau de lignes et fini juste avant la dernière ligne
        d.lignes[i] = lv; // on assigne les lignes vides au corps du donjon
    }
    d.lignes[haut - 1] = lp; // assignation de la derniere ligne du tableau de lignes du donjon en tant que ligne pleine pour finir la structure exterieure
    return d;                // on retourne le donjon
}

void afficher_donjon(donjon d)
{
    for (int i = 0; i < d.hauteur; i++)
    {                                // boucle qui parcours la hauteur du donjon
        afficher_ligne(d.lignes[i]); // affichage de chaque ligne du donjon
    }
}

// -------- lignes particulières v2 -------- //

ligne creer_ligne_particuliere_vide_v2(char symbole, int emplacement, int larg)
{
    ligne l = initialisation_ligne(larg);
    for (int i = 0; i < larg; i++)
    {
        l.caracteres[i] = ' ';
    }
    l.caracteres[0] = '#';
    l.caracteres[emplacement] = symbole;
    l.caracteres[larg - 1] = '#';
    return l;
    // autre méthode : on choisit de définir tous les caracteres à ' '; puis de les changer ensuite, c'est plus simple comme ca enft je pense
}

ligne creer_ligne_particuliere_pleine_v2(char symbole, int emplacement, int larg)
{
    ligne l = initialisation_ligne(larg);
    for (int i = 0; i < larg; i++)
    {
        l.caracteres[i] = '#';
    }
    l.caracteres[emplacement] = symbole;
    return l;
    // autre méthode : on choisit de définir tous les caracteres à ' '; puis de les changer ensuite, c'est plus simple comme ca enft je pense
}

int main()
{
    // ------ Création du donjon d(10, 20) ------ //
    donjon d = creer_donjon_vide(30, 40);
    afficher_donjon(d);
    printf("\n\n");

    // ------ Assemblage de lignes pour simuler un donjon //
    ligne lp = creer_ligne_pleine(20); // bordure haute
    ligne lp_particuliere_1 = creer_ligne_particuliere_vide_v2('M', 4, 20);
    ligne lp_particuliere_2 = creer_ligne_particuliere_vide_v2('O', 12, 20);
    ligne lv = creer_ligne_vide(20);

    ligne tab[] = {lp, lp_particuliere_1, lv, lv, lv, lp_particuliere_2, lp};
    for (int i = 0; i < 7; i++)
    {
        afficher_ligne(tab[i]);
        printf("ok");
        free(tab[i].caracteres);
    }

    // ------ Libération de la mémoire ------ //
    for (int i = 0; i < d.hauteur; i++)
    {
        free(d.lignes[i].caracteres);
    }
    // free(d.lignes);

    return 0;
}