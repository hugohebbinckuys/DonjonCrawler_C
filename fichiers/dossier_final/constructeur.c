#include <stdio.h>
#include <stdlib.h>
#include "constructeur.h"
#include <string.h>
#include <stdio.h>

//                                               |  STOCKAGE  |

void initialiser_stockage_salle(stockage_salle *sto_s) // initiallise le stockage pour les salles.(Le stockage est un liste qui contient des pointeur vers de salles)

{
    sto_s->tab_stockage = (salle **)malloc(sizeof(salle *) * 10); // malloc de l'espace necessaire pour stocker les salles, 10 salles au Maximum.
    for (int i = 0; i < 10; i++)
    {
        sto_s->tab_stockage[i] = NULL; // chaque pointeur vaut null au depart.
    }

    sto_s->nb_element = 0; // nb_element est le nombre d'element(pointeurs) dans le tableau de stockage.
}

void initialiser_stockage_couloir(stockage_couloir *sto_c)
{
    sto_c->tab_stockage = (couloir **)malloc(sizeof(couloir *) * 20); // malloc de l'espace necessaire pour stocker les couloirs, 20 couloirs au Maximum.
    for (int i = 0; i < 20; i++)
    {
        sto_c->tab_stockage[i] = NULL; // chaque pointeur vaut null au depart.
    }

    sto_c->nb_element = 0; // nb_element est le nombre d'element(pointeurs) dans le tableau de stockage.
}
// void initialiser_stockage_salle_couloirs(stockage_salle *sto); a ajouter

// changer le nom en debugger_stockage salle;
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

void afficher_stockage_couloir(donjon *d)
{
    printf("nombre de salles dans donjon -> %d\n", d->stockage_couloir->nb_element);
    int i;
    for (i = 0; i < d->stockage_couloir->nb_element; i++)
    {

        if (d->stockage_couloir->tab_stockage == NULL)
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
            printf("{Point depart : x = %d , y = %d} , {Point arrivee : x =  %d , y = %d }\n", d->stockage_couloir->tab_stockage[i]->arrivee->x, d->stockage_couloir->tab_stockage[i]->arrivee->y, d->stockage_couloir->tab_stockage[i]->depart->x, d->stockage_couloir->tab_stockage[i]->depart->y);
            for (int j = 0; j < d->stockage_couloir->tab_stockage[i]->taille_sequence_tab; j++)
            {
                afficher_sequence(&d->stockage_couloir->tab_stockage[i]->sequence_deplacements[j]);
            }
            printf("}");
            printf("}\n");
        }
    }
}

//                                               | STOCKAGE |

//                                                | DONJON |

void initialiser_donjon(donjon *d, int h, int l) // initialise le donjon avec sa hauteur et sa largeur.
{

    d->stockage = (stockage_salle *)malloc(sizeof(stockage_salle));
    d->stockage_couloir = (stockage_couloir *)malloc(sizeof(stockage_couloir));

    initialiser_stockage_salle(d->stockage);
    initialiser_stockage_couloir(d->stockage_couloir);

    d->hauteur_dj = h; // asigne la hauteur passe en parametre h est aussi la longueur de notre tableau de pointeur
    d->largeur_dj = l; // assigne la largeur passee en parametre l est aussi la longueur de notre taleau de caractere

    d->tab_dj = (char **)malloc(sizeof(char *) * d->hauteur_dj); // aloue au tableau le nombre de pointeur ( hauteur) -> suite
    // et force le typage en ** qui signifie pointeur de pointeur car le tab etant deja un pointeur contient des pointeur

    for (int i = 0; i < d->hauteur_dj; i++) // on parcours le tableau de pointeur
    {
        d->tab_dj[i] = (char *)malloc(sizeof(char) * d->largeur_dj); // on alloue chaque pointeur qui fera la taille de la largeur donc de notre tableau de caractere

        for (int j = 0; j < d->largeur_dj; j++) // parcours le tableau de caractere
        {
            if (i == 0 || i == d->hauteur_dj - 1 || j == 0 || j == d->largeur_dj - 1)
            // i correspond a chaque tableau de car et j chaque car present dans les tableau de car.
            // si i = 0 || i == d->hateur = der tableau de car alors on affiche tout les dash -> correspond a la premiere et derniers ligne du donjon
            // si j = 0 || j ==d->largeur-1 = der car du tableau de car alors on affiche un dash , permet d'avoir toujours un dash au debut et a la fin de chaque tab pour faire les murs du donjon
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

void afficher_donjon(donjon *d) // affiche le donjon
{
    menu m = creer_menu(); 
    int compteur = d->hauteur_dj; // compteur pour afficher le menu 
    int indice_compteur = 0;
    
    printf("\n");
    for (int i = 0; i < d->hauteur_dj; i++) // boucle pour afficher caractere par caractere du donjon les caracteres 
    {
        for (int j = 0; j < d->largeur_dj + 1; j++)
        {
            if (j == d->largeur_dj)
            {
                if (i < 10)
                {
                    printf("  0%d", i);
                }
                else
                {
                    printf("  %d", i);
                }
            }
            else
            {
                printf("%c", d->tab_dj[i][j]); // affiche car par car le donjon
            }

        }
        compteur --; // decrementation du menu pour l'aficher en bas du donjon 
        if (compteur < 11){ // 8 = nombre de propositions dans le menu 
            printf ("       %s", m.tab_menu[indice_compteur]);
            indice_compteur ++; 
        }
        printf("\n"); // saute une ligne entre chaque tab de car pour superposee les elem.
    }
    //  Tout le code en dessous permet d'afficher des coordonnee x , y de chaque case du dj pour facilite la lecture du donjon et l'ajout d'elements.
    int nb_espace = 0;
    for (int k = 0; k < d->largeur_dj; k++)
    {
        nb_espace++;
        if (k == 0)
        {
            for (int z = 0; z < d->largeur_dj; z++)
            {
                printf(" ");
            }
            printf("\n");
        }
        if (k > 9)
        {
            printf("%d", k / 10);
        }
        else
        {
            printf("%d", k / 10);
        }
    }
    printf("\n");
    for (int l = 0; l < d->largeur_dj; l++)
    {
        if (l > 9)
        {
            printf("%d", l % 10);
        }
        else
        {
            printf("%d", l);
        }
    }
    printf("\n\n");
}

void liberer_donjon(donjon *d) // libere la memoire
{
    for (int i = 0; i < d->hauteur_dj; i++)
    {
        free(d->tab_dj[i]); // libere chaque tab de car
    }
    free(d->tab_dj); // libere chaque pointeur de tab de car
                     // Liberer la salle si elle a ete allouee
}

void sauvegarder_donjon_dans_fichier(donjon *d)
{ // sauvegarde le donjon dans un fichier
    FILE *f;
    f = fopen("sauvegarde_donjon.txt", "w");
    fprintf(f, "TEST \n\n");
    fprintf(f, "Voici les informations du donjon : \n");
    fprintf(f, "hauteur : %d\nlargeur : %d\n\nApercu du donjon :\n", d->hauteur_dj, d->largeur_dj);
    for (int i = 0; i < d->hauteur_dj; i++)
    {
        for (int j = 0; j < d->largeur_dj; j++)
        {
            fprintf(f, "%c", d->tab_dj[i][j]);
            fflush(f);
        }
        fprintf(f, "\n");
        fflush(f);
    }
}

//                                                | DONJON |

//                                                | SALLES |

void initialiser_salle(salle *s, int h, int l, abcisse x, ordonne y) // initialise une salle  avec une hauteur , largeur et une coordonee x,y d'insertion dans le donjon.
{
    s->hauteur_salle = h;
    s->largeur_salle = l;
    s->tab_salle = (char **)malloc(sizeof(char *) * s->hauteur_salle); // alloue l'espace pour le tableau de pointeur qui construira graphiquement la salle.
    s->x = x;
    s->y = y;

    for (int i = 0; i < s->hauteur_salle; i++)
    {
        s->tab_salle[i] = (char *)malloc(sizeof(char) * (s->largeur_salle + 1)); // alloue l'espace pour tout les caractere de chaque pointeur vers une sale, +1 pour le caractere de fin de chaîne '\0'

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
        printf("\n"); // saute une ligne entre chaque tab de car pour superposee les elem.
    }
}

void inserer_salle(donjon *dans, salle *s)
{
    // debbuger_donjon(dans);
    int indiceChevauchante = chevaucher(dans, s); // chevauche renvoie -1 si la salle passée en paramettre en chevauche aucune dans le donjon , sinon elle renvoie l'indice de celle ci au sein du stockage_salle

    if (indiceChevauchante != -1) // dans le cas ou la salle chevauche
    {
        // Une salle chevauchante a ete trouvee
        printf("la salle chevauche une salle existante, suppression de la salle precedent et mise en place de la nouvelle salle...");
        supprimer_salle(dans, indiceChevauchante); // supprime la salle du donjon et du tableau de stockage(remplace ça valeur par NULL pour pas deplacer les indice).
    }
    else {
        int y_debut = s->y;
        int x_debut = s->x;
        int y_fin = y_debut + s->hauteur_salle;
        int x_fin = x_debut + s->largeur_salle;
        if (x_fin > dans->largeur_dj || y_fin > dans->hauteur_dj)
        { // si la salle depasse du donjon.
            // mettre en place le fait de re demander.
            printf("Impossible d'inserer la salle car elle depasse le donjon. Annulation...\n");
        }
        else
        {
            for (int i = y_debut; i < y_fin && i < dans->hauteur_dj; i++)
            {
                for (int j = x_debut; j < x_fin && j < dans->largeur_dj; j++)
                {
                    if (indiceChevauchante != -1)
                    {
                        // Si une salle chevauchante a ete trouvee, utilise l'indice pour supprimer la salle
                        dans->tab_dj[i][j] = s->tab_salle[i - y_debut][j - x_debut];
                    }
                    else
                    {
                        dans->tab_dj[i][j] = s->tab_salle[i - y_debut][j - x_debut];
                    }
                }
            }
            // dans->stockage->tab_stockage[dans->stockage->nb_element] = s; // ajoute la salle au tableau de stockage_salle
            dans->stockage->nb_element++;                                 // incremente le nombre d'element du tableau de stockage 
            int nb_elt = dans->stockage->nb_element++;
            debbuger_donjon(dans);
        }
    }
}

int chevaucher(donjon *dans, salle *s)
{ // verifie si une salle passee en parametre chevauche une salle du donjon.

    int x_new = s->x;                   // coordonnee x de la nouvelle salle(salle a inserer)
    int y_new = s->y;                   // coordonnee y
    int largeur_new = s->largeur_salle; // largeur de la nouvelle salle
    int hauteur_new = s->hauteur_salle; // hauteur de la nouvelle salle

    int i;
    for (i = 0; i < dans->stockage->nb_element; i++)
    {
        if (dans->stockage->tab_stockage[i] == NULL)
        { // si on rencontre un pointeur NULL du tableau on passe a l'iteration suivante car NULL ne possede pas d'attribut l'isible
            continue;
        }

        int x_old = dans->stockage->tab_stockage[i]->x; // prend les coordonnee  x, y de la salle a l'indice i dans le tableau de stockage
        int y_old = dans->stockage->tab_stockage[i]->y;
        int largeur_old = dans->stockage->tab_stockage[i]->largeur_salle; // prend la largeur et la hauteur de la salle a l'indice i dans le tableau de stockage
        int hauteur_old = dans->stockage->tab_stockage[i]->hauteur_salle;

        // verifier le chevauchement en termes de coordonnees et de tailles
        if ((x_old < x_new && x_new < x_old + largeur_old) && (y_old < y_new && y_new < y_old + hauteur_old))
        {
            return i; // ll y a chevauchement , donc retourne l'indice de la salle chevauche.
        }
    }

    return -1; // Pas de chevauchement 
}

void supprimer_salle(donjon *d, int indice_salle) // supprime une salle du donjon a l'aide de sont indice dans le tableau de stockage.
{
    salle *salle_a_supprimer = d->stockage->tab_stockage[indice_salle]; // recupere la salle sous forme de la structure salle
    for (int i = salle_a_supprimer->y; i < salle_a_supprimer->y + salle_a_supprimer->hauteur_salle; i++) // parcours l'intervalle ou la salle etait disposee pour remplacer tout les # par des ' '
    {
        for (int j = salle_a_supprimer->x; j < salle_a_supprimer->x + salle_a_supprimer->largeur_salle; j++)
        {
            d->tab_dj[i][j] = ' ';
        }
    }
    d->stockage->tab_stockage[indice_salle] = NULL; // NULL dans le tableau de stockage_salle pour ne pas bouger les indices
}

void liberer_salle(salle *s) // libere la memoire alloue pour la salle
{
    for (int i = 0; i < s->hauteur_salle; i++)
    {
        free(s->tab_salle[i]); // libere chaque tab de car
    }
    free(s->tab_salle); // libere chaque pointeur de tab de car
}

void sauvegarder_salle_dans_fichier(salle *s)
{ // sauvgarde la salle dans un fichier
    FILE *f;
    char nom_fichier[30];
    printf("comment voulez-vous appeler votre fichier de sauvegarde de la salle ?\n");
    scanf("%s", nom_fichier);

    int taille_nom = strlen(nom_fichier);
    s->fichier = (char *)malloc(sizeof(char) * (taille_nom + 1));
    s->fichier = nom_fichier;

    printf("voici le nom du fichier de sauvegarde : %s\n", s->fichier); 
    f = fopen(nom_fichier, "w");
    fprintf(f, "\n\nTEST \n\n");
    fprintf(f, "Voici les informations de la salle : \n");
    fprintf(f, "hauteur : %d\nlargeur : %d\nabcisse : %d\nordonnee : %d\n\nApercu de la salle :\n", s->hauteur_salle, s->largeur_salle, s->x, s->y);

    for (int i = 0; i < s->hauteur_salle; i++)
    {
        for (int j = 0; j < s->largeur_salle; j++)
        {
            fprintf(f, "%c", s->tab_salle[i][j]); // affiche car par car le donjon
        }
        fprintf(f, "\n"); // saute une ligne entre chaque tab de car pour superposee les elem.
    }
    fclose(f);
}

//                                                | SALLE |

//                                               | ENTITEE |

void initialiser_entitee(salle *s, entitee *ceci, abcisse x, ordonne y, char nom)
{
    printf("tentative d'initialisation d'entitee : (%d %d)\n", x, y);
    if (entitee_dans_salle_Valide(nom))
    {
        if ((x >= 0 && x < s->largeur_salle) && (y >= 0 && y < s->hauteur_salle))
        {
            ceci->x = x;
            ceci->y = y;
            ceci->nom = nom;
            printf("Affectation reussi !\n");
            printf("Initialisation entitee finalisee\n");
        }
        else
        {
            printf("L'entitee sort de la salle\n");
        }
    }
    else
    {
        printf("Merci de fournir un nom d'entitee Valide a savoir {CMWOAPBESFO#}\n");
    }
}

int entitee_dans_salle_Valide(char ceci) // verifie si ce n'est pas une lettre qui n'a psa de sens pour dans la salle
{
    char nomValide[] = "#CMWOAPBESFO"; // lettre autorisee
    const char *nom = nomValide;

    while (*nom != '\0')
    {
        if (ceci == *nom)
        {
            return 1; // si la lettre correspond a une des valide retourn 1
        }
        nom++;
    }
    return 0; // si la lettre passer en parametre n'est pas autorisee retourne 0
}

void inserer_entitee_dans_salle(salle *dans, entitee *ceci) // insere l'entitee dans la salle
{
    // cette verification est inutile car elle est deja faites dans initialise.
    if ((ceci->x >= 0 && ceci->x < dans->largeur_salle || ceci->y >= 0 && ceci->y < dans->hauteur_salle))
    {
        dans->tab_salle[ceci->x][ceci->y] = ceci->nom;
    }
    else
    {
        printf("L'entitee n'a pas ete inseree\n");
    }
}

//                                              | ENTITEE |

//                                             |  COULOIR  |

//                                          |  COULOIR : SEQUENCE |

void initialiser_sequence(sequence *ceci, int valeur, char *direction) // initialise une sequence avec une valeur et une direction

{

    if (sequence_valide(direction)) // verifie si la direction de la sequence est bien une valide (NORD , EST , SUD , OUEST).
    {

        int longueur = 0;
        int i;

        while (direction[longueur] != '\0')
        {
            longueur++;
        }

        ceci->direction = malloc(sizeof(char) * longueur + 1); // alloue la memoire pour la chaine de caractere direction.
        for (i = 0; i <= longueur; i++)
        {
            ceci->direction[i] = direction[i];
        }
        ceci->valeur = valeur;
    }
    else
    {

        printf("La direction n'est pas valide"); // si ce n'est pas une sequence valide
    }
}

int sequence_valide(char *ceci) // verifie siune chaine de caractere (direction) est valide.
{
    char *options[] = {"NORD", "OUEST", "SUD", "EST"};
    size_t longueurChaine = 0;

    // calcul de la longueur de la chaine
    while (ceci[longueurChaine] != '\0')
    {
        ++longueurChaine;
    }

    // comparaison avec chaque option
    for (size_t i = 0; i < sizeof(options) / sizeof(options[0]); ++i)
    {
        const char *option = options[i];
        size_t j;
        for (j = 0; j < longueurChaine && option[j] != '\0'; ++j)
        {
            if (ceci[j] != option[j])
            {
                break; // les caracteres ne correspondent pas, passer a l option suivante
            }
        }

        if (j == longueurChaine && option[j] == '\0')
        {
            return 1; // La chaîne correspond a une option valide
        }
    }

    return 0; // La chaine ne correspond a aucune option valide
}

void afficher_sequence(sequence *ceci)
{
    printf("{%d : %s}\n", ceci->valeur, ceci->direction);
}

//                                          |  COULOIR : SEQUENCE |

couloir *creation_couloir()
{
    couloir *c = malloc(sizeof(couloir)); // Alloue dynamiquement de la memoire pour le couloir

    int x_dep, y_dep, x_arr, y_arr;

    point *dep = malloc(sizeof(point));
    point *arr = malloc(sizeof(point));

    printf("Coordonnee x du point de depart du couloiur : \n");
    scanf("%d", &x_dep);
    printf("Coordonnee y du point de depart du couloiur : \n");
    scanf("%d", &y_dep);

    printf("Coordonnee x du point d' arriver du couloiur : \n");
    scanf("%d", &x_arr);
    printf("Coordonnee y du point d'arriver du couloiur : \n");
    scanf("%d", &y_arr);

    initialiser_point(dep, x_dep, y_dep);
    initialiser_point(arr, x_arr, y_arr);

    initialiser_couloir(c, dep, arr);

    return c;
}

void initialiser_point(point *p, int x, int y)
{
    p->x = x;
    p->y = y;
}

void liberer_couloir(couloir *c)
{
    free(c->depart);
    free(c->arrivee);
    free(c->sequence_deplacements);
    free(c);
}

void initialiser_couloir(couloir *ceci, point *depart, point *arrivee) // initialise les sequences necessaire au parcours du point d'arriver au point de depart
{
    ceci->depart = depart;                   // assigne au couloir sont point(x,y) de depart.
    ceci->arrivee = arrivee;                 // assigne au couloir sont point(x,y) d'arriver.
    int distance_x = arrivee->x - depart->x; // calcule la distance a parcourir en axe X
    int distance_y = arrivee->y - depart->y; // calcule la distance a parcourir en axe Y.

    int nb_seq = 0; // le nombre de sequence entree par l'utilisateur , pour restreindre a un maximum de 10 sequence par couloir.

    ceci->taille_sequence_tab = 0;
    ceci->sequence_deplacements = malloc((11) * sizeof(sequence)); // malloc le tableau de sequence du couloir a un maximum de 11 valeur , on en veux au maximum 10, 1 en plus au cas ou.

    int vous_avez = 0; 
    while ((distance_x != 0 || distance_y != 0) && nb_seq <= 10) // tant que la distane_x et la distance_y ne sont pas parcouru entiermeent , et que le nb_sequence n'a pas atteint 10
    {
        char direction[5]; // stockera la direction sous forme de chaine de car
        int valeur;

        if (vous_avez == 0){
            printf("Vous avez %d en axe X et %d en Axe Y a parcourir\n sachant l'origine situe au coin superieur gauche", distance_x, distance_y);
            vous_avez = 1; 
        }
        printf("Veuiller Entrez une direction parmis : NORD , OUEST , EST SUD qui correspond a la direction que vous voulez pour votre couloir : \n");
        scanf("%s", &direction);

        if (!sequence_valide(direction)) // si la direction choisi par le user est pas valide !(NORD EST SUD OUEST).
        {
            printf("Veuillez fournir une direction parmis NORD, OUEST , EST , SUD \n");
            scanf("%s", &direction);
        }
        else
        {
            printf("Veuillez entrez un valeur numerique qui correspond a la taille de cette partie du couloir dans cette direction : \n");
            scanf("%d", &valeur); // demande au user de rentree une valeur a parcourir dans la direction choisi plus haut.

            if (nb_seq == 9) // si le nb_seq atteint 9 , juste avant 10 , on complete la distance_x et y necessaire automatiquement et on rajoute le tout dans le tableau de sequence.
            {

                if (distance_x < 0) // faut enlever ça je crois
                {
                    initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], -distance_x, "OUEST");
                    ceci->taille_sequence_tab++;
                    distance_x += -distance_x;
                }

                else if (distance_x > 0 && distance_y > 0) // si la dist x et y est > 0 on soustrait ce qui faut a ces derniers pour avoir 0 de meme pour le reste.
                {
                    initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], distance_x, "EST");
                    ceci->taille_sequence_tab++;
                    distance_x -= distance_x;

                    initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], distance_y, "SUD");
                    ceci->taille_sequence_tab++;
                    distance_y -= distance_y;
                }
                else if (distance_x < 0 && distance_y > 0)
                {
                    initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], -distance_x, "OUEST");
                    ceci->taille_sequence_tab++;
                    distance_x += -distance_x;

                    initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], distance_y, "SUD");
                    ceci->taille_sequence_tab++;
                    distance_y -= distance_y;
                }
                else if (distance_x > 0 && distance_y < 0)
                {
                    initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], distance_x, "EST");
                    ceci->taille_sequence_tab++;
                    distance_x -= distance_x;

                    initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], -distance_y, "NORD");
                    ceci->taille_sequence_tab++;
                    distance_y += -distance_y;
                }
                else if (distance_x < 0 && distance_y < 0)
                {
                    initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], -distance_x, "OUEST");
                    ceci->taille_sequence_tab++;
                    distance_x += -distance_x;

                    initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], -distance_y, "NORD");
                    ceci->taille_sequence_tab++;
                    distance_y += -distance_y;
                }
            }

            else if (est_egale(direction, "NORD")) // on initialise une sequendce avec comme direction NORD si le user ecrit nord et la valeur choisi par le user. De meme pour le reste
            {
                initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], valeur, direction);
                ceci->taille_sequence_tab++;
                distance_y += valeur;
                printf("Vous avez %d en axe X et %d en Axe Y a parcourir\n sachant l'origine situe au coin superieur gauche \n", distance_x, distance_y);
                nb_seq++;
            }

            else if (est_egale(direction, "SUD"))
            {
                initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], valeur, direction);
                ceci->taille_sequence_tab++;
                distance_y -= valeur;
                printf("Vous avez %d en axe X et %d en Axe Y a parcourir\n sachant l'origine situee au coin superieur gauche \n", distance_x, distance_y);
                nb_seq++;
            }
            else if (est_egale(direction, "OUEST"))
            {
                initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], valeur, direction);
                ceci->taille_sequence_tab++;
                distance_x += valeur;
                printf("Vous avez %d en axe X et %d en Axe Y a parcourir\n sachant l'origine situee au coin superieur gauche \n", distance_x, distance_y);
                nb_seq++;
            }
            else if (est_egale(direction, "EST"))
            {
                initialiser_sequence(&ceci->sequence_deplacements[ceci->taille_sequence_tab], valeur, direction);
                ceci->taille_sequence_tab++;
                distance_x -= valeur;
                printf("Vous avez %d en axe X et %d en Axe Y a parcourir\n sachant l'origine situee au coin superieur gauche\n", distance_x, distance_y);
                nb_seq++;
            }
        }
    }
}

void tracer_couloir(donjon *dans, couloir *ceci) // trace un chemins de "s" dans le donjon a l'aide du tableau de sequence.
{
    int x = ceci->depart->x; // coordonee de depart x
    int x_f = ceci->arrivee->x;
    int y = ceci->depart->y; // coordonnee de depart y
    int y_f = ceci->arrivee->y;
    int i;
    int j;
    for (i = 0; i < ceci->taille_sequence_tab; i++) // parcours le tableau de sequence
    {

        if (est_egale(ceci->sequence_deplacements[i].direction, "NORD")) // si la direction de la sequene a l'indice i est NORD on ecrit un "s" n fois ou n est la valeur de la sequence a l'indice i. de meme pour le reste
        {
            for (j = 0; j < ceci->sequence_deplacements[i].valeur; j++)
            {
                dans->tab_dj[y][x] = 's';
                y--;
            }
        }
        else if (est_egale(ceci->sequence_deplacements[i].direction, "SUD"))
        {
            for (j = 0; j < ceci->sequence_deplacements[i].valeur; j++)
            {
                dans->tab_dj[y][x] = 's';
                y++;
            }
        }
        else if (est_egale(ceci->sequence_deplacements[i].direction, "OUEST"))
        {
            for (j = 0; j < ceci->sequence_deplacements[i].valeur; j++)
            {
                dans->tab_dj[y][x] = 's';
                x--;
            }
        }
        else if (est_egale(ceci->sequence_deplacements[i].direction, "EST"))
        {
            for (j = 0; j < ceci->sequence_deplacements[i].valeur - 1; j++)
            {
                dans->tab_dj[y][x] = 's';
                x++;
            }
        }
    }
}

void entourer_couloir(donjon *dans) // entoure chaque s dans le donjon par un # pour faire le bord(du chemin) du couloir
{
    int y;
    int x;
    for (y = 0; y < dans->hauteur_dj; y++)
    {
        for (x = 0; x < dans->largeur_dj; x++)
        {
            if (dans->tab_dj[y][x] == 's')
            {
                if (x > 0 && dans->tab_dj[y][x - 1] == ' ') // verifie si au cases adjacente il y'a un ' ' si oui on insere un # a la place , de meme pour toute les autre cases.

                // ! pour les cases [x-1] et [y-1] il faut s'assurer que x > 0 de meme pour y > 0 pour pas avoir d'indice negatif !.
                {
                    dans->tab_dj[y][x - 1] = '#';
                }
                if (dans->tab_dj[y][x + 1] == ' ')
                {
                    dans->tab_dj[y][x + 1] = '#';
                }
                if (y > 0 && dans->tab_dj[y - 1][x] == ' ')
                {
                    dans->tab_dj[y - 1][x] = '#';
                }
                if (dans->tab_dj[y + 1][x] == ' ')
                {
                    dans->tab_dj[y + 1][x] = '#';
                }

                if (dans->tab_dj[y - 1][x - 1] == ' ')
                {
                    dans->tab_dj[y - 1][x - 1] = '#';
                }
                if (dans->tab_dj[y - 1][x + 1] == ' ')
                {
                    dans->tab_dj[y - 1][x + 1] = '#';
                }
                if (dans->tab_dj[y + 1][x - 1] == ' ')
                {
                    dans->tab_dj[y + 1][x - 1] = '#';
                }
                if (dans->tab_dj[y + 1][x + 1] == ' ')
                {
                    dans->tab_dj[y + 1][x + 1] = '#';
                }
            }
        }
    }
}

void enlever_tracer_couloir(donjon *dans)
{
    int x;
    int y;
    for (y = 0; y < dans->hauteur_dj; y++)
    {
        for (x = 0; x < dans->largeur_dj; x++)
        {
            if (dans->tab_dj[y][x] == 's')
            {
                dans->tab_dj[y][x] = ' ';
            }
        }
    }
}

void inserer_couloir(donjon *dans, couloir *ceci) // regroupe toute les fonction sur les couloir pour insere dans le donjon.
{
    tracer_couloir(dans, ceci);
    entourer_couloir(dans);
    enlever_tracer_couloir(dans);
    dans->stockage_couloir->tab_stockage[dans->stockage_couloir->nb_element] = ceci;
    dans->stockage_couloir->nb_element++;
}

void supprimer_couloir(donjon *dans, int indice_couloir)
{
    int x_d = dans->stockage_couloir->tab_stockage[indice_couloir]->depart->x;
    int y_d = dans->stockage_couloir->tab_stockage[indice_couloir]->depart->y;

    int x_f = dans->stockage_couloir->tab_stockage[indice_couloir]->arrivee->x;
    int y_f = dans->stockage_couloir->tab_stockage[indice_couloir]->arrivee->y;

    int i;
    int j;

    for (i = y_d - 1; i < y_f; i++)
    {
        for (j = x_d + 1; j < x_f; j++)
        {
            if (j > 0 && dans->tab_dj[i][j - 1] == '#') // verifie si au cases adjacente il i'a un '#' si oui on insere un # a la place , de meme pour toute les autre cases.

            // ! pour les cases [j-1] et [i-1] il faut s'assurer que j > 0 de meme pour i > 0 pour pas avoir d'indice negatif !.
            {
                dans->tab_dj[i][j - 1] = ' ';
            }
            if (dans->tab_dj[i][j + 1] == '#')
            {
                dans->tab_dj[i][j + 1] = ' ';
            }
            if (i > 0 && dans->tab_dj[i - 1][j] == '#')
            {
                dans->tab_dj[i - 1][j] = ' ';
            }
            if (dans->tab_dj[i + 1][j] == '#')
            {
                dans->tab_dj[i + 1][j] = ' ';
            }

            if (dans->tab_dj[i - 1][j - 1] == '#')
            {
                dans->tab_dj[i - 1][j - 1] = ' ';
            }
            if (dans->tab_dj[i - 1][j + 1] == '#')
            {
                dans->tab_dj[i - 1][j + 1] = ' ';
            }
            if (dans->tab_dj[i + 1][j - 1] == '#')
            {
                dans->tab_dj[i + 1][j - 1] = ' ';
            }
            if (dans->tab_dj[i + 1][j + 1] == '#')
            {
                dans->tab_dj[i + 1][j + 1] = ' ';
            }
        }
    }
    dans->stockage_couloir->tab_stockage[indice_couloir] = NULL;
}

//                                             |  COULOIR  |

//                                               | ANNEXES |

int longueur_chaine(char *chaine)
{
    int longueur = 0;
    while (chaine[longueur] != '\0')
    {
        longueur++;
    }
    return longueur;
}

int est_egale(char *ceci, char *cela)
{
    int i = 0;
    while (ceci[i] != '\0' && cela[i] != '\0')
    {
        if (ceci[i] != cela[i])
        {
            return 0;
        }
        i++;
    }

    return (ceci[i] == '\0' && cela[i] == '\0');
}
void concatenerChaines(char *destination, char *source)
{
    // Trouver la fin de la chaîne de destination
    int i = 0;
    while (destination[i] != '\0')
    {
        i++;
    }

    // Copier la chaîne source a la fin de la chaîne de destination
    int j = 0;
    while (source[j] != '\0')
    {
        destination[i] = source[j];
        i++;
        j++;
    }
}

//                                               | ANNEXES |

//                                             | DJ CRAWLER |

//                                             | DJ CRAWLER |


menu creer_menu() {
    menu m; 
    m.tab_menu = (char **)malloc(sizeof(char*)*10); 
    for (int i = 0; i<10; i++) {
        m.tab_menu[i] = (char*)malloc(sizeof(char)*45);
    }
    m.tab_menu[0] = "Que souhaitez-vous faire ?\0";
    m.tab_menu[1] = "d -> Creer un donjon ?\0";
    m.tab_menu[2] = "s -> Creer une salle ?\0";
    m.tab_menu[3] = "c -> Creer un couloir ?\0";
    m.tab_menu[4] = "z -> Supprimer un couloir ?\0";
    m.tab_menu[5] = "i -> Inserer une salle dans le donjon ?\0";
    m.tab_menu[6] = "m -> Ajouter un mur ?\0";
    m.tab_menu[7] = "x -> Supprimer un mur ?\0";
    m.tab_menu[8] = "a -> Afficher le donjon ?\0";    
    m.tab_menu[9] = "h -> Afficher le manuel ?\0"; 
    m.tab_menu[10] = "q -> Quitter ?\0"; 
    return m; 
}

void afficher_menu (menu *m) { // fonction pour tester la structure 
    for (int i=0; i<11; i++) {
        printf ("%s", m->tab_menu[i]);
        printf ("\n");
    }
}

void afficher_menu_debut () {
    printf ("\n                                                                       Que souhaitez-vous faire ?\n");
    printf ("                                                                        d -> Creer un donjon ?\n");
    printf ("                                                                        s -> Creer une salle ?\n");
    printf ("                                                                        c -> Creer un couloir ?\n");
    printf ("                                                                        z -> Supprimer un couloir ?\n");
    printf ("                                                                        i -> Inserer la salle dans le donjon ?\n");
    printf ("                                                                        m -> Ajouter un mur ?\n");
    printf ("                                                                        x -> Supprimer un mur ?\n");
    printf ("                                                                        a -> Afficher le donjon ?\n");
    printf ("                                                                        h -> afficher le manuel ?\n");
    printf ("                                                                        q -> Quitter ?\n\n");
}

donjon creation_donjon () {
    int passage_hauteur = 0; 
    int passage_largeur = 0; 
    int h_dj; 
    int l_dj; 

    do  {
        printf ("Quelle hauteur voulez-vous donner a votre donjon ?\n");
        scanf("%d", &h_dj);
        if (h_dj < 10){
            printf ("Un donjon ne peut pas avoir une hauteur de moins de 10\n");
            continue; 
        }
        else {
            passage_hauteur = 1;
        }
    }
    while (passage_hauteur == 0);
    do {
        printf ("Quelle largeur voulez-vous donner a votre donjon ?\n");
        scanf("%d", &l_dj);
        if (l_dj < 10){
            printf ("Un donjon ne peut pas avoir une largeur de moins de 10\n");
            continue; 
        }
        else {
            passage_largeur = 1; 
        }
    }
    while (passage_largeur == 0);

    donjon d; 
    initialiser_donjon (&d, h_dj, l_dj); 
    // afficher_donjon(&d); pas besoin prcq dans la fonction principal on  va retourner au menu => affiche le donjon; 
    sauvegarder_donjon_dans_fichier(&d);
    return d; 
}

salle creation_salle() {
    int h_s; 
    int l_s; 
    int passage_hauteur = 0; 
    int passage_largeur = 0; 

    abcisse x; 
    ordonne y; 
    int passage_x = 0; 
    int passage_y = 0; 

    do  {
        printf ("Quelle hauteur voulez-vous donner a votre salle ?\n");
        scanf("%d", &h_s);
        if (h_s < 2){
            printf ("Une salle ne peut pas avoir une hauteur de moins de 2\n");
            continue; 
        }
        else {
            passage_hauteur = 1;
        }
    }
    while (passage_hauteur == 0);
    do {
        printf ("Quelle largeur voulez-vous donner a votre salle ?\n");
        scanf("%d", &l_s);
        if (l_s < 2){
            printf ("Une salle ne peut pas avoir une largeur de moins de 2\n");
            continue; 
        }
        else {
            passage_largeur = 1; 
        }
    }
    while (passage_largeur == 0);
    do {
        printf ("Quelle coordonne x pour la salle :");
        scanf("%d", &x);
        if (x>0){
            passage_x =1;
        }
        else {
            printf ("La salle ne peut pas etre aux coordonnee x 0 ou inferieur, merci de saisir des coordonnees valides\n");
            continue; 
        }
    }    
    while (passage_x == 0);    
    
    do {
        printf ("Quelle coordonne y pour la salle :");
        scanf("%d", &y);
        if (y>0){
            passage_y =1;
        }
        else {
            printf ("La salle ne peut pas etre aux coordonnee y 0 ou inferieur, merci de saisir des coordonnees valides\n");
            continue; 
        }
    }    
    while (passage_y == 0);

    salle s; 
    initialiser_salle (&s, h_s, l_s, x, y);
    afficher_salle (&s);

    char insertion = ' '; 
    char elt;
    char elements_acceptes [13] = "CMWOAPBESFO#\0";
    int passage = 0; // marqueur de passage de la boucle 
    do {
        printf ("Voulez-vous inserer une entitee dans la salle ? 'o' ou 'n' ");
        scanf(" %c", &insertion);
        if (insertion == 'o'){
            entitee e;
            while (passage == 0){
                printf ("Saisissez l'entitee que vous voulez inserer {CMWOAPBESFO#} : ");
                scanf (" %c", &elt);   
                for (int i = 0; i<13; i++) {
                    if (elements_acceptes[i] != elt){
                        continue; 
                    }
                    else {
                        passage = 1;
                        break; 
                    }
                }
                if (passage == 1) {
                    break;
                }
                else {
                    printf ("L'entitee est invalide\n");
                }
            }
            passage = 0; 
            abcisse x; 
            printf ("Saisissez les coordonnes x de l'entitee dans la salle : ");
            scanf("%d", &x);
            ordonne y; 
            printf ("Saisissez les coordonnes y de l'entitee dans la salle : ");
            scanf("%d", &y);
            initialiser_entitee(&s, &e, x, y, elt); 
            inserer_entitee_dans_salle(&s, &e);
            afficher_salle(&s);
        }
        else if (insertion == 'n'){
            continue; 
        }
        else {
            printf("veuillez inserer 'o' ou 'n'\n");
            continue;
        }
    } 
    while (insertion != 'n');

    printf ("Voulez-vous sauvegarder la salle ? 'o' ou 'n' \n");
    char sauv = ' ';
    int arret = 0; 
    while (arret==0){
        scanf (" %c", &sauv); //' %c' espace important sinon bug 
        if (sauv == 'n') {
            arret = 1;
        }
        else if (sauv == 'o') {
            arret = 1; 
            sauvegarder_salle_dans_fichier(&s);
        }
        else {
            printf ("Veuillez saisir 'o' ou 'n' \n");
            continue; 
        }
    }
    // afficher_salle (&s);

    return s; 
}

void insertion_salle (donjon *d, salle *s) {
    printf ("\nvoulez-vous inserer la salle dans le donjon ? 'o' ou 'n' : ");
    char sauv; 
    int passage = 0;
    do {
        scanf(" %c", &sauv);
        if (sauv == 'o'){
            if (d->hauteur_dj != -10) {
                if (s->hauteur_salle != -10) {
                    inserer_salle(d, s);
                    printf ("\nSalle inseree avec succes :\n\n");
                    // donjon *d1;
                    // initialiser_donjon(d1, d.hauteur_dj, d.largeur_dj);
                    sauvegarder_donjon_dans_fichier(d);
                    passage = 1; 
                }
                else {
                    printf("Aucune salle a inserer\n");
                    passage = 1; 
                }  
            }
            else {
                printf ("Aucun donjon initialise. Initialisez un donjon avant d'ajouter une salle dans le donjon.\n"); 
                passage = 1; 
            }
        }
        else if (sauv != 'n' && sauv != 'o'){
            printf ("Veuillez saisir 'o' ou 'n' ");
        }
    }
    while (passage = 0); 
}

void ajouter_mur(donjon *dans, point *ceci) // permet d'ajouter un mur dans le donjon a un point donnee
{
    dans->tab_dj[ceci->y][ceci->x] = '#';
}

void supprimer_mur(donjon *dans, point *ceci)
{
    dans->tab_dj[ceci->y][ceci->x] = ' ';
}

void fonction_finale(){
    main_menu();

    donjon d; 
    initialiser_donjon(&d, -10, -10); 
    
    salle s; 
    initialiser_salle(&s, -10, -10, 0, 0); 

    char choix; 
    int arret_menu = 0; 

    int indice_couloir_a_supprimer;

    do {
        if (arret_menu == 0) {
            afficher_menu_debut(); 
        }
        else {
            afficher_donjon(&d);
            printf ("Que voulez-vous faire ? \n");
        }
        scanf(" %c", &choix);
        switch (choix) {
            case 'd':
                // Code pour creer un donjon
                d = creation_donjon(); 
                arret_menu = 1; 
                break;
            case 's':
                // Code pour creer une salle
                s = creation_salle();
                insertion_salle(&d, &s);
                break;
            case 'y':
                if (d.stockage)
            case 'i':                
                if (d.hauteur_dj != -10) {
                    if (s.hauteur_salle != -10) {
                        printf ("Vous allez inserer la derniere salle creee dans le donjon ");
                        // inserer_salle(&d, &s);
                        insertion_salle(&d ,&s); 
                        // printf ("Salle inseree avec succes\n");
                        // donjon *d1;
                        // initialiser_donjon(d1, d.hauteur_dj, d.largeur_dj);
                        // sauvegarder_donjon_dans_fichier(d1);
                        printf ("donjon sauvegarde\n");
                    }
                    else {
                        printf("Aucune salle a inserer\n");
                    }
                }
                else {
                    printf ("Aucun donjon initialise. Initialisez un donjon avant d'ajouter une salle dans le donjon.\n"); 
                }
                break;
            case 'c':
            if (d.hauteur_dj != -10)
            {
                couloir *c;
                c = creation_couloir();
                // printf(" dans le switch case : %d", c->arrivee->x);
                inserer_couloir(&d, c);
            }
            else
            {
                printf("\nCreez un donjon avant de faire un couloir\n");
            }
            break;
            case 'z':
                if (d.hauteur_dj != -10) {
                    if (d.stockage_couloir->nb_element != 0){ 
                        do {
                            printf ("Il y a %d couloirs, Saisissez l'indice du couloir que vous voulez supprimer (indice du premier couloir : 1) : ", d.stockage_couloir->nb_element);
                            scanf("%d", &indice_couloir_a_supprimer);
                            if (indice_couloir_a_supprimer<1 || indice_couloir_a_supprimer > d.stockage_couloir->nb_element +1){
                                printf ("Veuillez saisir un indice valide");
                                continue; 
                            }
                            else {
                                // printf ("ok?\n");
                                // afficher_stockage_couloir(&d);
                                supprimer_couloir (&d,(indice_couloir_a_supprimer-1));
                                // printf ("Normalement c supprime\n");
                            }
                        }
                        while (indice_couloir_a_supprimer<1 || indice_couloir_a_supprimer > d.stockage_couloir->nb_element +1);
                    }
                    else {
                        printf ("Il n'y a pas de couloir a supprimer\n");
                        continue; 
                    }
                }
                else {
                    printf ("Il n'y a pas encore de donjon, impossible de supprimer un couloir");
                }
                break;
            case 'm' : 
                abcisse mur_x; 
                ordonne mur_y; 
                point mur; 
                if (d.hauteur_dj != 10) {
                    do {    
                        printf ("Saisissez les coordonnees x du mur que vous voulez placer :\n"); 
                        scanf ("%d", &mur_x); 
                        mur.x = mur_x; 
                        if (mur_x < 0 || mur_x>d.hauteur_dj){
                            printf ("Coordonnees invalides\n"); 
                            continue; 
                        }
                        printf ("Saisissez les coordonnees y du mur que vous voulez placer :\n"); 
                        scanf ("%d", &mur_y); 
                        mur.y = mur_y; 
                        if (mur_y < 0 || mur_y>d.hauteur_dj){
                            printf ("Coordonnees invalides\n"); 
                            continue; 
                        }
                        ajouter_mur(&d, &mur);  
                    }
                    while (mur_x < 0 || mur_x>d.hauteur_dj || mur_y <0 || mur_y>d.largeur_dj);
                    printf ("insertion du mur ok\n");
                }
                break;
            case 'x' : 
                abcisse mur_sup_x; 
                ordonne mur_sup_y; 
                point mur_sup; 
                if (d.hauteur_dj != 10) {
                    do {    
                        printf ("Saisissez les coordonnees x du mur que vous voulez supprimer :\n"); 
                        scanf ("%d", &mur_sup_x); 
                        mur_sup.x = mur_sup_x; 
                        if (mur_sup_x < 0 || mur_sup_x>d.hauteur_dj){
                            printf ("Coordonnees invalides\n"); 
                            break;
                        }
                        printf ("Saisissez les coordonnees y du mur que vous voulez placer :\n"); 
                        scanf ("%d", &mur_sup_y); 
                        mur_sup.y = mur_sup_y; 
                        if (mur_sup_y < 0 || mur_sup_y>d.hauteur_dj){
                            printf ("Coordonnees invalides\n"); 
                            break;
                        }
                        if (d.tab_dj[mur_sup.y][mur_sup.y] == '#'){
                            supprimer_mur(&d, &mur_sup);
                            printf ("Suppression du mur ok\n");
                            break; 
                        }  
                        if (d.tab_dj[mur_sup.y][mur_sup.y] != '#'){
                            printf ("Aucun mur a ces coordonnes\n");
                            break;
                        }
                    }
                    while (mur_x < 0 || mur_x>d.hauteur_dj || mur_y <0 || mur_y>d.largeur_dj);
                }
                break;
            case 'a':
                if (d.hauteur_dj == -10){
                    printf ("\nAucun donjon a afficher \n");
                }
                break;
                // afficher_donjon(&d); on peut break et ca va nous faire revenir au debut du while => affiche le donjon; 
            case 'h':
                manuel();
                break;
            case 'q':
                for (int z = 0; z<d.stockage->nb_element; z++){
                    liberer_salle(d.stockage->tab_stockage[z]);
                }
                liberer_donjon(&d);
                printf("\nAu revoir !\n\n");
                // Code pour liberer la memoire et quitter proprement le programme
                break;
            default:
                printf("Choix invalide. Veuillez selectionner une option valide.\n");
                break;
        }
    } while (choix != 'q');    
}

int main_menu()
{
    int i;
    titre_ascii();
    int choix;
    for (i = 0; i < 5; i++)
    {
        printf("\n");
    }

    printf("                                                                      1 - START\n\n");
    printf("                                                                      2 - AFFICHER  MANUEL\n\n");
    scanf("                                                                             %d", &choix);
    if (choix == 2) {
        manuel();
    }
}

void titre_ascii()
{

    system("cls");
    printf("\n");
    printf("\n");

    printf("                                                                 ____   ___  _   _     _  ___  _   _ \n");
    printf("                                                                |  _ \\ / _ \\| \\ | |   | |/ _ \\| \\ | |\n");
    printf("                                                                | | | | | | |  \\| |_  | | | | |  \\| | \n");
    printf("                                                                | |_| | |_| | |\\  | |_| | |_| | |\\  |\n");
    printf("                                                                |____/ \\___/|_| \\_|\\___/ \\___/|_| \\_|_ _  ___\n");
    printf("                                                                / ___|  _ \\    / \\ \\      / / |   | ____|  _ \\ \n");   
    printf("                                                               | |   | |_) |  / _ \\ \\ /\\ / /| |   |  _| | |_) |\n");
    printf("                                                               | |___|  _ <  / ___ \\ V  V / | |___| |___|  _ < \n");
    printf("                                                                \\____|_| \\_\\/_/   \\_\\_/\\_/  |_____|_____|_| \\_\\ \n");
}

void manuel () {
    printf ("----------------------------------\n\n");
    printf ("Voici le manuel de creation de Donjon : \n\n\n"); 
    printf ("Le dungeon crawler ou est un genre de jeu video de role dont le gameplay met l'exploration de donjons en avant. \nLe joueur controle generalement son personnage et se deplace de case en case. Le donjon y est souvent labyrinthique et \n rempli d'ennemis, ce qui implique une mecanique de combat.\n"); 
    printf ("Ici, le but de l'application est de creer la map du Dungeon Crawler\n"); 
    printf ("Le but est donc de generer avec nos outils un donjon avec des salles, des entitees, des mur, des couloirs...\n"); 
    printf ("\nUn menu s'affiche des que vous appuyez sur 1 dans le menu principal.\n"); 
    printf ("Appuyez donc sur 1 pour lancer le createur\n"); 
    printf ("Des propositions s'offrent a vous : \n"); 
    printf ("Chaque lettre vous enverra vers une etape de creation. \n"); 
    printf ("Par exemple, si vous voulez creer un donjon, appuyez sur d\n\n"); 
    printf ("Quelques petites precisions :\n"); 
    printf ("Les structures de couloirs sont des structures complexes, il se peut qu'a la suppression de couloirs de caracteres soient mal supprimes.\n"); 
    printf("Ainsi, vous avez la possibilite de supprimer des murets directement dans le donjon a l'emplacement que vous voulez en pressant la touche x\n"); 
    printf ("Meme chose pour l'insertion de murets. Si vous voulez creer un obstacle sous forme de mur, vous pouvez appuyer sur m\n");
    printf ("\nDes qu'une question suppose de repondre par oui ou non, vous devez specifier 'o' pour oui, et 'n' pour non.\n");
    printf ("\nNous vous supposons, pour une creation et un confort optimal de mettre votre terminal en plein ecran. \n");
    printf ("\nA vous de jouer !! \n"); 
    printf ("\n----------------------------------\n");
}