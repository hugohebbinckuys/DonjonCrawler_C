#include <stdio.h>
#include <stdlib.h>
#include "constructeur.h"
#include <string.h>

void initialiser_stockage(stockage_salle *sto)
{
    sto->tab_stockage = malloc(sizeof(salle *)*10); // malloc du tableau qui stockera les salles; // mais pb car on sait pas encore cb de salles on devra allouer
    // sto->tab_stockage = NULL; 
    sto->nb_element = 0; 
    // pas encore de salles dans le tableau de salles


    //tentative de debug ://
    salle s; 
    initialiser_salle(&s, 10, 10, 1, 1);
    sto->tab_stockage[sto->nb_element] = &s; 
    sto->nb_element +=1; 
}

void initialiser_donjon(donjon *d, int h, int l)
{
    stockage_salle sto;
    initialiser_stockage(&sto);
    d->stockage = &sto; 
    printf ("debug nb_elements dans stockage du donjon %d\n", sto.nb_element); 
    printf ("debug element[0] (=salle[0]) dans stockage de salles du donjon : \n");
    // afficher_salle (sto.tab_stockage[0]);

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

// void inserer_dans_salle(salle *s)
// {
//     char element;
//     printf("quel element voulez-vous mettre dans la salle ? ");
//     scanf(" %c", &element);
//     int x, y;
//     printf("A quel endroit souhaitez-vous placer cet element ? ");
//     for (int i = 0; i < 1; i++)
//     {
//         printf("\nhauteur :");
//         scanf(" %d", &x);
//         if (x < 0 || x > s->hauteur_salle - 1)
//         {
//             i--;
//             printf("Veuillez placer l'element dans la salle");
//         }
//     }
//     for (int j = 0; j < 1; j++)
//     {
//         printf("\nlargeur :");
//         scanf(" %d", &y);
//         if (y < 0 || y > s->largeur_salle - 1)
//         {
//             j--;
//             printf("Veuillez placer l'element dans la salle");
//         }
//     }
//     s->tab_salle[x][y] = element;
// }

void liberer_salle(salle *s)
{
    for (int i = 0; i < s->hauteur_salle; i++)
    {
        free(s->tab_salle[i]); // libere chaque tab de car
    }
    free(s->tab_salle); // libere chaque pointeur de tab de car
}

int chevaucher(donjon *dans, salle *s)
{
    int x_new = s->x;
    int y_new = s->y;
    printf ("debug CH1 nb_element de stockage_salles du donjon : %d\n", dans->stockage->nb_element);
    // si    x_old  <= x_new <= x_old_f
    int i;
    printf("debug CH2\n");
    for (i = 0; i <= dans->stockage->nb_element; i++)
    {
        printf("debug CH3\n");
        printf ("debug stockage[i]->x : %d", dans->stockage->tab_stockage[i]->x);
        int x_old = dans->stockage->tab_stockage[i]->x; // coordone de la salle
        printf ("debug CH4"); 
        int x_old_f = x_old + dans->stockage->tab_stockage[i]->largeur_salle; // coordone x de fin de salle
        printf ("debug CH5"); 
        int y_old = dans->stockage->tab_stockage[i]->y;
        int y_old_f = y_old + dans->stockage->tab_stockage[i]->hauteur_salle; // coordone y de fin de salle
        if (x_old <= x_new && x_new <= x_old_f || y_old <= y_new && y_new <= y_old_f)
        {
            return i; // retourne l'indice a supprimer.
        }
    }
    return -1;
}

void inserer_salle(donjon *dans, salle *s)
{
    printf("debug1\n");
    int i;
    int j;
    int cpt_x = 0;
    int cpt_y = 0;
    int y = s->y;
    int x = s->x;

    for (i = y; i < y + s->hauteur_salle && i < dans->hauteur_dj; i++)
    {
        printf("debug2\n");
        for (j = x; j < x + s->largeur_salle && j < dans->largeur_dj; j++)
        {
            printf("debug3\n");
            if (chevaucher(dans, s) != -1)
            {
                printf("debug4\n"); // 4 marche pas
                supprimer_salle(dans, chevaucher(dans, s));
                inserer_salle(dans, s);
            }
            else
            {
                printf("debug\n");
                dans->tab_dj[i][j] = s->tab_salle[i - y][j - x];
            }
        printf("debugIMP\n");
        }
    }
    dans->stockage ->tab_stockage[dans->stockage ->nb_element] = s;
    dans->stockage ->nb_element += 1;
    // printf ("%d\n", dans->stockage ->nb_element);
}

void debbuger_donjon(donjon *d)
{
    printf("nombre de salles dans donjon -> %d\n", d->stockage ->nb_element);
    int i;
    for (i = 0; i < d->stockage ->nb_element; i++)
    {

        if (d->stockage ->tab_stockage[i] == NULL)
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
            printf("x:%d , y:%d , hauteur: %d , largeur: %d", d->stockage ->tab_stockage[i]->x, d->stockage ->tab_stockage[i]->y, d->stockage ->tab_stockage[i]->hauteur_salle, d->stockage ->tab_stockage[i]->largeur_salle);
            printf("}\n");
        }
    }
}

void supprimer_salle(donjon *d, int indice_salle)
{
    salle *salle_a_supprimer = d->stockage ->tab_stockage[indice_salle];

    for (int i = salle_a_supprimer->y; i < salle_a_supprimer->y + salle_a_supprimer->hauteur_salle; i++)
    {
        for (int j = salle_a_supprimer->x; j < salle_a_supprimer->x + salle_a_supprimer->largeur_salle; j++)
        {
            d->tab_dj[i][j] = ' ';
        }
    }

    d->stockage ->tab_stockage[indice_salle] = NULL; // NULL dans le tableau pour ne pas bouger les i
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
    if (entitee_dans_salle_Valide(nom))
    {
        if ((x>=0 && x<=s->hauteur_salle) && (y>=0 && y<=s->largeur_salle)){
            ceci->x = x;
            ceci->y = y;
            ceci->nom = nom;
            printf("Affectation reussi !\n");
        }
        else {
            printf ("L'entité n'est pas dans la salle\n");
            // initialiser_entitee(s, ceci, x, y, nom);
        }
    }
    else
    {
        printf("Merci de fournir un nom d'entitée Valide a savoir {CMWOAPBESFO#}");
    }
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
    if ((ceci->x >= 0 && ceci->x <= dans->largeur_salle || ceci->y >= 0 && ceci->y <= dans->hauteur_salle))

    {
        dans->tab_salle[ceci->x][ceci->y] = ceci->nom;
    }
    else
    {
        printf("L'entitée sors de la salle \n");
    }
}

void sauvegarder_salle_dans_fichier (salle *s){
    FILE *f; 
    f=fopen("sauvegarde_salle.txt", "w");
    fprintf(f, "TEST \n\n"); 
    fprintf(f, "Voici les informations de la salle : \n"); 
    fprintf(f, "hauteur : %d\nlargeur : %d\nabcisse : %d\nordonnee : %d\n\nApercu de la salle :\n", s->hauteur_salle, s->largeur_salle, s->x, s->y);
    
    for (int i = 0; i < s->hauteur_salle; i++)
    {
        for (int j = 0; j < s->largeur_salle; j++)
        {
            fprintf(f, "%c", s->tab_salle[i][j]); // affiche car par car le donjon
        }
        fprintf(f, "\n"); // saute une ligne entre chaque tab de car pour supérposée les elem.
    }
    fclose(f); 
}

void sauvegarder_donjon_dans_fichier (donjon *d){
    FILE *f; 
    f=fopen("sauvegarde_donjon.txt", "w");
    fprintf(f, "TEST \n\n"); 
    fprintf(f, "Voici les informations du donjon : \n"); 
    fprintf(f, "hauteur : %d\nlargeur : %d\n\nApercu du donjon :\n", d->hauteur_dj, d->largeur_dj);
    for (int i = 0; i<d->hauteur_dj; i++) {
        for (int j = 0; j<d->largeur_dj; j++){
            fprintf(f, "%c", d->tab_dj[i][j]);
        }
        fprintf(f, "\n"); 
    }    
}

void creer_couloir (couloir *c, abcisse x, ordonne y){
    c->x = x; 
    c->y = y; 
    c->epaisseur = 1; 
    c->instructions_direction = (char*)malloc(sizeof(char)*10); // 10 est un test mais jsp faire autrement sinon 
    c->nombre_cases_deplacement = (int*)malloc(sizeof(int)*10);
    printf ("init du couloir ok\n");
    printf ("indiquez les coordonnees x puis y de destination du couloir :\n");
    int x_dest; 
    int y_dest; 
    scanf(" %d", &x_dest); 
    scanf(" %d", &y_dest); 
    c->destination_x = x_dest; 
    c->destination_y = y_dest; 
    int distance_x = c->destination_x - c->x; 
    int distance_y = c->destination_y - c->y; 
    char dep; 
    int nb_dep; 
    for (int i = 0; /* distance_x != 0 && distance_y != 0 */ i<10; i++){
        dep = ' '; 
        if (dep == ' '){
            printf ("saisissez le dep que vous voulez faire (N, S, E, O) : \n");
            scanf(" %s", &dep);
        }
        nb_dep = 0; 
        if (nb_dep == 0) {
            printf ("saisissez le nb de dep que vous voulez faire : \n");
            scanf(" %d", &nb_dep);
        }
        // c->instructions_direction[i] = dep; 
        strcpy(c->instructions_direction[i], &dep);
        c->nombre_cases_deplacement[i] = nb_dep; 
        printf ("debug : \n i:%d\ninstruction : %s \nnb_dep : %d\n", i, c->instructions_direction[i], c->nombre_cases_deplacement[i]);
    }
}