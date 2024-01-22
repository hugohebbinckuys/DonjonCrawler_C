#ifndef CONSTRUCTEUR_H
#define CONSTRUCTEUR_H

typedef int abcisse;
typedef int ordonne;

typedef struct salle
{
    int hauteur_salle;
    int largeur_salle;
    char **tab_salle;
    abcisse x;
    ordonne y;
} salle;

typedef struct entitee
{
    abcisse x;
    ordonne y;
    char nom;
    salle *s;

} entitee;

typedef struct stockage_salle
{
    salle **tab_stockage;
    int nb_element;
} stockage_salle;

typedef struct donjon
{
    int hauteur_dj;
    int largeur_dj;
    char **tab_dj; // on crée un tableau de pointeur , chaque pointeur pointe vers un tableau de caractère.
    stockage_salle *stockage;

} donjon;

typedef struct sequence
{
    int valeur;
    char *direction;

} sequence;

typedef struct couloir
{
    int distance_x;
    int distance_y;
    sequence *sequence_deplacements;
    int taille_sequence_tab;
    char **tab_car;
} couloir;

// donjon

void initialiser_donjon(donjon *d, int h, int l); // aloue la mémoire + rempli le tableau de # en fonction de la hauteur et la largeur désirée
void liberer_donjon(donjon *d);
void afficher_donjon(donjon *d); // affihce le donjon

// salle
void initialiser_salle(salle *s, int h, int l, abcisse x, ordonne y);
void liberer_salle(salle *s); // sers a libérer la mémoire aloué
void afficher_salle(salle *s);
void inserer_salle(donjon *dans, salle *s);
int retirer_salle(donjon *dans, salle *s);

// entitée dans la salle

int entitee_dans_salle_Valide(char ceci);
void initialiser_entitee(salle *dans, entitee *ceci, abcisse x, ordonne y, char nom);
void inserer_entitee_dans_salle(salle *dans, entitee *ceci);

// Point d'acces
// int point_dacces_Valide(char ceci);

// void initialiser_point_acces(point_dacces *ceci, abcisse x, ordonne y, char nom);

// int entitee_chevauche(salle *s, entitee *ceci);

// stockage
int chevaucher(donjon *dans, salle *s);
void supprimer_salle(donjon *d, int indice_salle);
void debbuger_donjon(donjon *d); // verifie le stockage

// Couloir : séquence
int sequence_valide(char *ceci);
void initialiser_sequence(sequence *ceci, int valeur, char *direction);
void afficher_sequence(sequence *ceci);
void afficher_couloir(couloir *c);

// Couloir : couloir
void initialiser_couloir(couloir *ceci, int distance_x, int distance_y);
void afficher_couloir(couloir *ceci);

#endif