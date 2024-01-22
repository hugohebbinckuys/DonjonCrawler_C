#ifndef CONSTRUCTEUR_H
#define CONSTRUCTEUR_H

typedef int abcisse; 
typedef int ordonne;

typedef struct salle // structure de salle: contient les ino=formations d'une salle (dimensions, contenu et coordonnées) 
{
    int hauteur_salle;
    int largeur_salle;
    char **tab_salle;
    abcisse x;
    ordonne y;
} salle;

typedef struct entitee // structure d'entitee: contient la valeur de l'entitee, la salle dans laquelle elle est et ses coordonnees dans la salle 
{
    abcisse x;
    ordonne y;
    char nom;
    salle *s;

} entitee; 

typedef struct stockage_salle // structure de stockage des salles: contient un tableau de salles, et un nb_d'elements
{
    salle **tab_stockage;
    int nb_element;
} stockage_salle;

typedef struct couloir {
    // coordonnees du début
    abcisse x; 
    ordonne y; 
    int epaisseur; // mettre par defaut 1; 
    char *instructions_direction; 
    int *nombre_cases_deplacement; // va contenir la liste des nombre de déplacements fait pour creer le couloir (qu'il faudra "coupler" avec les instruction de direction (tableau juste au dessus) pour avoir les informations exactes du trajet du couloir, en sachant qu'on a les coordonnées de base du couloir donc on pourra parcourir les instructions_directions*nombrecases_deplacements pour refaire le trajet du couloir dans le cas ou on veut effacer un couloir); 
    abcisse destination_x;
    abcisse destination_y;
}couloir;

typedef struct stockage_couloirs {
    couloir **tab_stockage;
    int nb_element;
}stockage_couloirs;

typedef struct donjon // structure de donjon, contient les dimensions, et un tableau qui contient des tableaux de caracteres et un stockage de salles pour repertorier celles-ci
{
    int hauteur_dj;
    int largeur_dj;
    char **tab_dj; // on crée un tableau de pointeur , chaque pointeur pointe vers un tableau de caractère.
    stockage_salle *stockage; // ai modifié le nom en stockage_s pour pas confondre avec le stockage des couloirs
    // stockage_couloirs *stockage_c; // stockage des couloirs; 
} donjon;


void creer_couloir (couloir *c, abcisse x, ordonne y); 

// donjon

void initialiser_donjon(donjon *d, int h, int l); // aloue la mémoire + rempli le tableau de # en fonction de la hauteur et la largeur désirée
void liberer_donjon(donjon *d); // free le donjon
void afficher_donjon(donjon *d); // affiche le donjon

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
void initialiser_stockage(stockage_salle *sto);
int chevaucher(donjon *dans, salle *s);
void supprimer_salle(donjon *d, int indice_salle);
void debbuger_donjon(donjon *d); // verifie le stockage

// sauvegarde fichier 
void sauvegarder_salle_dans_fichier (salle *s);
void sauvegarder_donjon_dans_fichier (donjon *d);
// void afficher_couloir (int x, int y, couloir *c, donjon *d);


#endif