#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include <string.h>

void initialiser_donjon(donjon *d, int h, int l)
{
    d->hauteur = h; // asigne la hauteur passé en paramètre h est aussi la longueur de notre tableau de pointeur
    d->largeur = l; // assigne la largeur passée en parametre l est aussi la longueur de notre taleau de caractère

    d->tab = (char **)malloc(sizeof(char *) * d->hauteur); // aloue au tableau le nombre de pointeur ( hauteur) -> suite
    // et force le typage en ** qui signifie pointeur de pointeur car le tab étant deja un pointeur contient des pointeur
        for (int i = 0; i < d->hauteur; i++) // on parcours le tableau de pointeur
        {
        d->tab[i] = (char *)malloc(sizeof(char *) * d->largeur); // on alloue chaque pointeur qui fera la taille de la largeur donc de notre tableau de caractère

        for (int j = 0; j < d->largeur; j++) // parcours le tableau de caractère
        {
            if (i == 0 || i == d->hauteur - 1 || j == 0 || j == d->largeur - 1)
            // i correspond a chaque tableau de car et j chaque car présent dans les tableau de car.
            // si i = 0 || i == d->hateur = der tableau de car alors on affiche tout les dash -> correspond a la premiere et derniers ligne du donjon
            // si j = 0 || j ==d->largeur-1 = der car du tableau de car alors on affiche un dash , permet d'avoir toujours un dash au début et a la fin de chaque tab pour faire les murs du donjon
            {
                d->tab[i][j] = '#';
            }
            else
            {
                d->tab[i][j] = ' ';
            }
        }
        d->tab[i][d->largeur] = '\0'; // ajoute le car de fin a chaque tab de car pour pouvoir les afficher apres dans une loop
    }
}

void liberer_donjon(donjon *d) // libere la mémoire
{
    for (int i = 0; i < d->hauteur; i++)
    {
        free(d->tab[i]); // libere chaque tab de car
    }
    free(d->tab); // libere chaque pointeur de tab de car
}

void afficher_donjon(donjon *d) // affiche le donjon
{
    int nbr; 
    printf ("indiquez le nombre de donjons que vous voulez faire");
    scanf("%d", &nbr);
    for (int a = 0; a<nbr; a++){
        for (int i = 0; i < d->hauteur; i++)
        {
            for (int j = 0; j < d->largeur; j++)
            {
                printf("%c", d->tab[i][j]); // affiche car par car le donjon
            }
            printf("\n"); // saute une ligne entre chaque tab de car pour supérposée les elem.
        }
}
}

void initialiser_salle (salle *s, int h, int l) {
    s->hauteur = h; 
    s->largeur = l;
    s->tab = (char **)(malloc(sizeof(char *) * s->hauteur));
    for (int i = 0; i<s->hauteur; i++) {
        s->tab[i] = (char*)(malloc(sizeof(char)* s->largeur));
    }
}

void inserer_dans_salle (salle *s){
    char element;
    printf ("quel element voulez-vous mettre dans la salle ? ") ;
    scanf(" %c", &element);
    int x, y;
    printf ("A quel endroit souhaitez-vous placer cet element ? ");
    for (int i =0; i<1; i++) {
        printf ("\nhauteur :");
        scanf (" %d", &x);
        if (x < 0 || x > s->hauteur-1){
            i--;
            printf("Veuillez placer l'element dans la salle");
        }
    }
    for (int j=0; j<1; j++){
        printf ("\nlargeur :");
        scanf (" %d", &y);
        if (y < 0 || y > s->largeur-1){
            j--;
            printf("Veuillez placer l'element dans la salle");
        }
    }
    s->tab[x][y] = element;
}

void supprimer_element_salle (salle *s) {

}

salle creer_salle (salle *s){ 
    int h, l;
    printf ("Hauteur de la salle : ");
    scanf("%d", &h);
    printf ("Largeur de la salle : ");
    scanf("%d", &l);
    initialiser_salle(s, h, l);

    for (int i = 0; i < s->hauteur; i++) // on parcours le tableau de pointeur
        {
        s->tab[i] = (char *)malloc(sizeof(char *) * s->largeur); // on alloue chaque pointeur qui fera la taille de la largeur donc de notre tableau de caractère
        for (int j = 0; j < s->largeur; j++) // parcours le tableau de caractère
            {
            if (i == 0 || i == s->hauteur - 1 || j == 0 || j == s->largeur - 1)
            // i correspond a chaque tableau de car et j chaque car présent dans les tableau de car.
            // si i = 0 || i == d->hateur = der tableau de car alors on affiche tout les dash -> correspond a la premiere et derniers ligne du donjon
            // si j = 0 || j ==d->largeur-1 = der car du tableau de car alors on affiche un dash , permet d'avoir toujours un dash au début et a la fin de chaque tab pour faire les murs du donjon
            {
                s->tab[i][j] = '#';
            }
            else
            {
                s->tab[i][j] = ' ';
            }
        }
        s->tab[i][s->largeur] = '\0'; // ajoute le car de fin a chaque tab de car pour pouvoir les afficher apres dans une loop
    }

    int elts; 
    printf ("Combien voulez-vous d'elements au sein de votre salle ? ");
    scanf("%d", &elts);
    for (int k = 0; k<elts; k++) {
        // appel de la fonction inserer salle 
        inserer_dans_salle (s);
    }
    return *s;
}

void liberer_salle(salle *s) // libere la mémoire
{
    for (int i = 0; i < s->hauteur; i++)
    {
        free(s->tab[i]); // libere chaque tab de car
    }
    free(s->tab); // libere chaque pointeur de tab de car
}

void afficher_salle (salle *s){
    for (int j = 0; j<s->hauteur; j++){
        for (int k = 0; k<s->largeur; k++){
            printf("%c", s->tab[j][k]); // affiche car par car le donjon
        }
        printf("\n");
    }
}


int main () {
    // donjon d; 
    // initialiser_donjon(&d, 10, 20);
    // afficher_donjon(&d);
    // liberer_donjon(&d);
    
    salle s;
    creer_salle(&s);
    // initialiser_salle(&s, 10, 10);
    afficher_salle(&s);
    liberer_salle(&s);
    return 0; 
}