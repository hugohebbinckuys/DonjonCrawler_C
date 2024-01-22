#include <stdio.h>
#include <stdlib.h>
#include "constructeur.h"
#include <string.h>

void initialiser_stockage(stockage_salle *sto)
{
    sto->tab_stockage = (salle **)malloc(sizeof(salle *) * 10);
    for (int i = 0; i < 10; i++)
    {
        sto->tab_stockage[i] = NULL;
    }
    sto->tab_stockage = NULL;
    sto->nb_element = 0;
}

void initialiser_donjon(donjon *d, int h, int l)
{
    stockage_salle sto;

    initialiser_stockage(&sto);

    d->hauteur_dj = h; // asigne la hauteur passé en paramètre h est aussi la longueur de notre tableau de pointeur
    d->largeur_dj = l; // assigne la largeur passée en parametre l est aussi la longueur de notre taleau de caractère

    d->tab_dj = (char **)malloc(sizeof(char *) * d->hauteur_dj); // aloue au tableau le nombre de pointeur ( hauteur) -> suite
    // et force le typage en ** qui signifie pointeur de pointeur car le tab étant deja un pointeur contient des pointeur

    for (int i = 0; i < d->hauteur_dj; i++) // on parcours le tableau de pointeur
    {
        d->tab_dj[i] = (char *)malloc(sizeof(char) * d->largeur_dj); // on alloue chaque pointeur qui fera la taille de la largeur donc de notre tableau de caractère

        for (int j = 0; j < d->largeur_dj; j++) // parcours le tableau de caractère
        {
            if (i == 0 || i == d->hauteur_dj - 1 || j == 0 || j == d->largeur_dj - 1)
            // i correspond a chaque tableau de car et j chaque car présent dans les tableau de car.
            // si i = 0 || i == d->hateur = der tableau de car alors on affiche tout les dash -> correspond a la premiere et derniers ligne du donjon
            // si j = 0 || j ==d->largeur-1 = der car du tableau de car alors on affiche un dash , permet d'avoir toujours un dash au début et a la fin de chaque tab pour faire les murs du donjon
            {
                d->tab_dj[i][j] = '#';
            }
            else
            {
                d->tab_dj[i][j] = ' ';
            }
        }
        d->tab_dj[i][d->largeur_dj] = '\0'; // ajoute le car de fin a chaque tab de car pour pouvoir les afficher apres dans une loop
    }
}
void liberer_donjon(donjon *d) // libere la mémoire
{
    for (int i = 0; i < d->hauteur_dj; i++)
    {
        free(d->tab_dj[i]); // libere chaque tab de car
    }
    free(d->tab_dj); // libere chaque pointeur de tab de car
                     // Libérer la salle si elle a été allouée
}
void afficher_donjon(donjon *d) // affiche le donjon
{
    for (int i = 0; i < d->hauteur_dj; i++)
    {
        for (int j = 0; j < d->largeur_dj; j++)
        {
            printf("%c", d->tab_dj[i][j]); // affiche car par car le donjon
        }
        printf("\n"); // saute une ligne entre chaque tab de car pour supérposée les elem.
    }
}

void initialiser_salle(salle *s, int h, int l, abcisse x, ordonne y)
{

    s->hauteur_salle = h;
    s->largeur_salle = l;
    s->tab_salle = (char **)malloc(sizeof(char *) * s->hauteur_salle);
    s->x = x;
    s->y = y;

    for (int i = 0; i < s->hauteur_salle; i++)
    {
        s->tab_salle[i] = (char *)malloc(sizeof(char) * (s->largeur_salle + 1)); // +1 pour le caractère de fin de chaîne '\0'

        for (int j = 0; j < s->largeur_salle; j++)
        {
            if (i == 0 || i == s->hauteur_salle - 1 || j == 0 || j == s->largeur_salle - 1)
            {
                s->tab_salle[i][j] = '#';
            }
            else
            {
                s->tab_salle[i][j] = ' ';
            }
        }
        s->tab_salle[i][s->largeur_salle] = '\0';
    }
}

void afficher_salle(salle *s)
{

    for (int i = 0; i < s->hauteur_salle; i++)
    {
        for (int j = 0; j < s->largeur_salle; j++)
        {
            printf("%c", s->tab_salle[i][j]); // affiche car par car le donjon
        }
        printf("\n"); // saute une ligne entre chaque tab de car pour supérposée les elem.
    }
}

void inserer_dans_salle(salle *s)
{
    char element;
    printf("quel element voulez-vous mettre dans la salle ? ");
    scanf(" %c", &element);
    int x, y;
    printf("A quel endroit souhaitez-vous placer cet element ? ");
    for (int i = 0; i < 1; i++)
    {
        printf("\nhauteur :");
        scanf(" %d", &x);
        if (x < 0 || x > s->hauteur_salle - 1)
        {
            i--;
            printf("Veuillez placer l'element dans la salle");
        }
    }
    for (int j = 0; j < 1; j++)
    {
        printf("\nlargeur :");
        scanf(" %d", &y);
        if (y < 0 || y > s->largeur_salle - 1)
        {
            j--;
            printf("Veuillez placer l'element dans la salle");
        }
    }
    s->tab_salle[x][y] = element;
}

void liberer_salle(salle *s)
{
    for (int i = 0; i < s->hauteur_salle; i++)
    {
        free(s->tab_salle[i]); // libere chaque tab de car
    }
    free(s->tab_salle); // libere chaque pointeur de tab de car
}

void inserer_salle(donjon *dans, salle *s)
{
    int i;
    int j;
    int cpt_x = 0;
    int cpt_y = 0;
    int y = s->y;
    int x = s->x;

    for (i = y; i < y + s->hauteur_salle && i < dans->hauteur_dj; i++)
    {
        for (j = x; j < x + s->largeur_salle && j < dans->largeur_dj; j++)
        {
            if (chevaucher(dans, s) != -1)
            {
                supprimer_salle(dans, chevaucher(dans, s));
                inserer_salle(dans, s);
            }
            else
            {
                dans->tab_dj[i][j] = s->tab_salle[i - y][j - x];
            }
        }
    }
    dans->stockage->tab_stockage[dans->stockage->nb_element] = s;
    dans->stockage->nb_element += 1;
    // printf ("%d\n", dans->stockage->nb_element);
}

void debbuger_donjon(donjon *d)
{
    printf("nombre de salles dans donjon -> %d\n", d->stockage->nb_element);
    int i;
    for (i = 0; i < d->stockage->nb_element; i++)
    {

        if (d->stockage->tab_stockage[i] == NULL)
        {
            printf("[");
            printf("%d", i);
            printf("] ->");
            printf("{");
            printf("Null");
            printf("}\n");
        }
        else
        {
            printf("[");
            printf("%d", i);
            printf("] ->");
            printf("{");
            printf("x:%d , y:%d , hauteur: %d , largeur: %d", d->stockage->tab_stockage[i]->x, d->stockage->tab_stockage[i]->y, d->stockage->tab_stockage[i]->hauteur_salle, d->stockage->tab_stockage[i]->largeur_salle);
            printf("}\n");
        }
    }
}

int chevaucher(donjon *dans, salle *s)
{
    int x_new = s->x;
    int y_new = s->y;

    // si    x_old  <= x_new <= x_old_f
    int i;
    for (i = 0; i < dans->stockage->nb_element; i++)
    {
        int x_old = dans->stockage->tab_stockage[i]->x;                       // coordone de la salle
        int x_old_f = x_old + dans->stockage->tab_stockage[i]->largeur_salle; // coordone x de fin de salle

        int y_old = dans->stockage->tab_stockage[i]->y;
        int y_old_f = y_old + dans->stockage->tab_stockage[i]->hauteur_salle; // coordone y de fin de salle

        if (x_old <= x_new && x_new <= x_old_f || y_old <= y_new && y_new <= y_old_f)
        {
            return i; // retourne l'indice a supprimer.
        }
    }
    return -1;
}
void supprimer_salle(donjon *d, int indice_salle)
{

    salle *salle_a_supprimer = d->stockage->tab_stockage[indice_salle];

    for (int i = salle_a_supprimer->y; i < salle_a_supprimer->y + salle_a_supprimer->hauteur_salle; i++)
    {
        for (int j = salle_a_supprimer->x; j < salle_a_supprimer->x + salle_a_supprimer->largeur_salle; j++)
        {
            d->tab_dj[i][j] = ' ';
        }
    }

    d->stockage->tab_stockage[indice_salle] = NULL; // NULL dans le tableau pour ne pas bouger les i
}

int entitee_dans_salle_Valide(char ceci) // verifie si ce n'est pas une lettre qui n'a psa de sens pour dans la salle
{
    char nomValide[] = "#CMWOAPBESFO";
    const char *nom = nomValide;

    while (*nom != '\0')
    {
        if (ceci == *nom)
        {
            return 1;
        }
        nom++;
    }
    return 0;
}

void initialiser_entitee(salle *s, entitee *ceci, abcisse x, ordonne y, char nom)
{
    printf("tentative d'initialisation d'entitée : (%d %d)\n", x, y);
    if (entitee_dans_salle_Valide(nom))
    {
        if ((x >= 0 && x < s->largeur_salle) && (y >= 0 && y < s->hauteur_salle))
        {
            ceci->x = x;
            ceci->y = y;
            ceci->nom = nom;
            printf("Affectation reussi !\n");
        }
        else
        {
            printf("L'entitee sort de la salle\n");
        }
    }
    else
    {
        printf("Merci de fournir un nom d'entitée Valide a savoir {CNOW#}\n");
    }
    printf("Initialisation entitee finalisee\n");
}

/* int entitee_chevauche(salle *s, entitee *ceci)
{
    int x_pos = ceci->x;
    int y_pos = ceci->y;

    if (s->tab_salle[x_pos][y_pos] != ' ')
    {
        return 1;
    }
    return 0;
}*/

void inserer_entitee_dans_salle(salle *dans, entitee *ceci)
{
    if ((ceci->x > 0 && ceci->x < dans->largeur_salle || ceci->y > 0 && ceci->y < dans->hauteur_salle))

    {
        dans->tab_salle[ceci->x][ceci->y] = ceci->nom;
    }
    else
    {
        printf("L'entitée sors de la salle\n");
    }
}

int sequence_valide(char *ceci)
{
    char *options[] = {"NORD", "OUEST", "SUD", "EST"};
    size_t longueurChaine = 0;

    // Calcul de la longueur de la chaîne
    while (ceci[longueurChaine] != '\0')
    {
        ++longueurChaine;
    }

    // Comparaison avec chaque option
    for (size_t i = 0; i < sizeof(options) / sizeof(options[0]); ++i)
    {
        const char *option = options[i];
        size_t j;
        for (j = 0; j < longueurChaine && option[j] != '\0'; ++j)
        {
            if (ceci[j] != option[j])
            {
                break; // Les caractères ne correspondent pas, passer à l'option suivante
            }
        }

        if (j == longueurChaine && option[j] == '\0')
        {
            return 1; // La chaîne correspond à une option valide
        }
    }

    return 0; // La chaîne ne correspond à aucune option valide
}

void initialiser_sequence(sequence *ceci, int valeur, char *direction)
{

    if (sequence_valide(direction))
    {

        int longueur = 0;
        int i;

        while (direction[longueur] != '\0')
        {
            longueur++;
        }

        ceci->direction = malloc(sizeof(char) * longueur + 1);
        for (i = 0; i <= longueur; i++)
        {
            ceci->direction[i] = direction[i];
        }
        ceci->valeur = valeur;
    }
    else
    {
        printf("La direction n'est pas valide");
    }
}
void afficher_sequence(sequence *ceci)
{
    printf("{%d : %s}\n", ceci->valeur, ceci->direction);
}

void initialiser_couloir(couloir *ceci, int distance_x, int distance_y)
{
    ceci->taille_sequence_tab = 0;
    int dist_x;
    int dist_y;

    ceci->sequence_deplacements = malloc((distance_x + distance_y) * sizeof(sequence));

    while (distance_x > 0 && distance_y > 0)
    {
        printf("Entrez une distance en x a parcourir\n");
        scanf("%d", &dist_x);
        distance_x -= dist_x;

        printf("Entrez une distance en y a parcourir\n");
        scanf("%d", &dist_y);
        distance_y -= dist_y;

        initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], dist_x, "EST");
        ceci->taille_sequence_tab++;

        initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], dist_y, "SUD");
        ceci->taille_sequence_tab++;
    }
    
}
void afficher_couloir(couloir *ceci)
{

}