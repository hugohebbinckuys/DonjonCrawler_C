#ifndef TEST_H
#define TEST_H

typedef struct ligne {
    int largeur; 
    char * caracteres; // changer pour "caracteres" 
}ligne; 

typedef struct donjon {
    int hauteur; 
    ligne * lignes; // changer pour "lignes"
}donjon; 

ligne initialisation_ligne (int larg);
ligne creer_ligne_pleine (int larg);
ligne creer_ligne_vide (int larg);
void afficher_ligne (ligne l);

donjon initialisation_donjon (int haut);
donjon creer_donjon_vide (int haut, int larg);
void afficher_donjon (donjon d);

ligne creer_ligne_particuliere (char symbole, int emplacement, int larg);

#endif 