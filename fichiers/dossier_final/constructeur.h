#ifndef CONSTRUCTEUR_H
#define CONSTRUCTEUR_H

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef int abcisse; // Meilleur visiblité des coordonée
typedef int ordonne;

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef struct salle // structure de salle: contient les informations d'une salle (dimensions, contenu et coordonnées)
{
    int hauteur_salle;
    int largeur_salle;
    char **tab_salle; // tableau de pointeur de car pour afficher graphiquement la salle
    abcisse x;        // coordonnée de la salle au sein du dj
    ordonne y;
    char *fichier; // fichier ou inserer la salle si souhaité
} salle;

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef struct entitee // structure d'entitee: contient la valeur de l'entitee, la salle dans laquelle elle est et ses coordonnees dans la salle
{
    abcisse x;
    ordonne y;
    char nom;
    salle *s;

} entitee;

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef struct stockage_salle // structure de stockage des salles: contient un tableau de salles, et un nb_d'elements
{
    salle **tab_stockage; // tableau de pointeur de salle afin de garder une trace de toute les salle et en supprimer si shouaité
    int nb_element;
} stockage_salle;

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef struct sequence // sequence de déplacement symboliser par une direction(chaine de car) et un valeur , nombre de déplacement dans cette direction
{
    int valeur;
    char *direction;

} sequence;

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef struct point // crée une structure point pour facilité l'accés a l'abcisse et a l'ordonné pour les couloirs.
{
    abcisse x;
    ordonne y;
} point;

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef struct couloir
{
    point *depart;
    point *arrivee;
    sequence *sequence_deplacements;
    int taille_sequence_tab;
    char **tab_car;

} couloir;

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef struct stockage_couloir
{
    couloir **tab_stockage;
    int nb_element;
} stockage_couloir;

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef struct donjon // structure de donjon, contient les dimensions, et un tableau qui contient des tableaux de caracteres et un stockage de salles pour repertorier celles-ci
{
    int hauteur_dj;
    int largeur_dj;
    char **tab_dj; // on crée un tableau de pointeur , chaque pointeur pointe vers un tableau de caractère.
    stockage_salle *stockage;
    stockage_couloir *stockage_couloir; // ai modifié le nom en stockage_s pour pas confondre avec le stockage des couloirs
} donjon;

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

typedef struct menu {
    char **tab_menu; 
}menu; 

/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

//                                                  | donjon |

void initialiser_donjon(donjon *d, int h, int l); // aloue la mémoire + rempli le tableau de # en fonction de la hauteur et la largeur désirée
void liberer_donjon(donjon *d);                   // free le donjon
void afficher_donjon(donjon *d);                  // affiche le donjon

//                                                  | salle |
void initialiser_salle(salle *s, int h, int l, abcisse x, ordonne y);
void liberer_salle(salle *s); // sers a libérer la mémoire aloué
void afficher_salle(salle *s);
void inserer_salle(donjon *dans, salle *s);
// int retirer_salle(donjon *dans, salle *s);

//                                                 | entitée |

int entitee_dans_salle_Valide(char ceci);
void initialiser_entitee(salle *dans, entitee *ceci, abcisse x, ordonne y, char nom);
void inserer_entitee_dans_salle(salle *dans, entitee *ceci);

//                                                 | stockage |

void initialiser_stockage_salle(stockage_salle *sto_s);
void initialiser_stockage_couloir(stockage_couloir *sto_c);
int chevaucher(donjon *dans, salle *s);
void supprimer_salle(donjon *d, int indice_salle);
void debbuger_donjon(donjon *d); // verifie le stockage
void afficher_stockage_couloir(donjon *d);

//                                                  |COULOIR|

//                                                  |séquence|
int sequence_valide(char *ceci);
void initialiser_sequence(sequence *ceci, int valeur, char *direction);
void afficher_sequence(sequence *ceci);

//                                              Couloir : couloir

void initialiser_couloir(couloir *ceci, point *depart, point *arrivee);
void tracer_couloir(donjon *dans, couloir *ceci);
void entourer_couloir(donjon *dans);
void enlever_tracer_couloir(donjon *dans);
void inserer_couloir(donjon *dans, couloir *ceci);
void supprimer_couloir(donjon *dans, int indice_couloir);
void liberer_couloir(couloir *c);

//                                            |Fonction annexes |

int est_egale(char *ceci, char *cela);
void concatenerChaines(char *destination, char *source);
int longueur_chaine(char *chaine);
char *entourer_caracteres(char *s);

//                                             | sauvegarde fichier |

void sauvegarder_salle_dans_fichier(salle *s);
void sauvegarder_donjon_dans_fichier(donjon *d);

//                                                  |DJ CRAWLER|

menu creer_menu(); 
void afficher_menu(menu *m);
void afficher_menu_debut ();
donjon creation_donjon();
salle creation_salle();
void insertion_salle(donjon *d, salle *s);
couloir *creation_couloir ();

void initialiser_point(point *p, int x, int y);
void ajouter_mur(donjon *dans, point *ceci);
void supprimer_mur(donjon *dans, point *ceci);

void fonction_finale();
int main_menu();
void titre_ascii() ;
void manuel();

#endif