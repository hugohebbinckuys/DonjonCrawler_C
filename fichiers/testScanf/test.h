#ifndef CONSTRUCTEUR_H
#define CONSTRUCTEUR_H

typedef struct donjon
{
    int hauteur;
    int largeur;
    char **tab; // on crée un tableau de pointeur , chaque pointeur pointe vers un tableau de caractère.
} donjon;

typedef struct donjon salle;

void initialiser_donjon(donjon *d, int h, int l); // aloue la mémoire + rempli le tableau de # en fonction de la hauteur et la largeur désirée
void liberer_donjon(donjon *d);                   // sers a libérer la mémoire aloué
void afficher_donjon(donjon *d);                  // affihce le donjon
void initialiser_salle(salle *s, int h, int l);
void inserer_dans_salle (salle *s);
salle creer_salle (salle *s);

#endif