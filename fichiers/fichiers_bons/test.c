#include "constructeur.h"
#include <string.h>
#include <stdio.h>

int main()
{
    //imp : afficher le donjon apres chaque modif 

    // donjon d; 
    // initialiser_donjon (&d, 30, 40); 

    // salle s1; 
    // initialiser_salle (&s1, 5, 5, 2, 2);
    // entitee e1;
    // initialiser_entitee (&s1, &e1, 2, 2, 'F');
    // inserer_entitee_dans_salle (&s1, &e1);
    // afficher_salle(&s1);
    // entitee e2;
    // initialiser_entitee (&s1, &e2, 2, 3, 'O');
    // inserer_entitee_dans_salle (&s1, &e2);
    // entitee e3;
    // initialiser_entitee (&s1, &e3, 3, 1, 'E');
    // inserer_entitee_dans_salle (&s1, &e3); 
    // inserer_salle(&d, &s1);    
    // afficher_donjon(&d); 

    // salle s2; 
    // initialiser_salle (&s2, 5, 5, 3, 10);
    // inserer_salle(&d, &s2);    
    // afficher_donjon(&d); 

    // salle s3;
    // initialiser_salle (&s3, 3, 3, 10, 15);
    // inserer_salle(&d, &s3);    
    // afficher_donjon(&d); 

    // salle s4; 
    // initialiser_salle (&s4, 3, 10, 25, 15); 
    // inserer_salle(&d, &s4);    
    // afficher_donjon(&d); 

    // salle s5; 
    // initialiser_salle (&s5, 4, 6, 14, 14);
    // inserer_salle(&d, &s5);    
    // afficher_donjon(&d); 
    
    // salle s6; 
    // initialiser_salle (&s6, 3, 4, 36, 18);
    // inserer_salle(&d, &s6);    
    // afficher_donjon(&d); 

    // // inserer_entitee_dans_salle(&s);

    
    // sauvegarder_donjon_dans_fichier(&d);

    // liberer_salle(&s1);
    // liberer_salle(&s2);
    // liberer_salle(&s3);
    // liberer_salle(&s4);
    // // liberer_salle(&s5);
    // // liberer_salle(&s6);
    // liberer_donjon(&d);

    // fonction_finale (); 

    donjon d; 
    initialiser_donjon(&d, -10, -10); 

    salle s; 
    initialiser_salle(&s, -10, -10, 0, 0); 

    char choix; 

// On peut pas initialiser un donjon a NULL ce qu'on peut faire c initialiser un donjon avec des valeurs impossible (p/ex avec une hauteur et largeur de -10), dans la fonction d'initialisation de donjon on protege l'init de donjon pour pas que ca soit en dessous de largeur 5 et hauteur 5, donc l'utilisateur pourra tester et ce sera refuser, et vu que ce sera refusé il ne pensera pas a essayer -10 => donc dans la fonction d'init de donjon on limite comme j'ai dit avant et on acepte quand meme si les mesures sont de -10 comme ca on pourra initialiser ici a -10 pour ensuite verifier si le donjon est de -10 alors c comme si le donjon etait NULL et donc que y avait pas de donjon. 

// meme chose pour les salles (chiffre aléatoire); 

    do {
        afficher_menu();
        scanf(" %c", &choix);
        switch (choix) {
            case 'd':
                // Code pour créer un donjon
                d = creation_donjon(); 
                break;
            case 's':
                // Code pour créer une salle
                char sauv; 
                s = creation_salle();
                insertion_salle(&d, &s);
                
                break;
            case 'i':                
                if (d.hauteur_dj != -10) {
                    if (s.hauteur_salle != -10) {
                        printf ("Vous allez inserer la derniere salle creee dans le donjon");
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
            case 'a':
                // Code pour afficher le donjon
                afficher_donjon(&d);
                break;
            case 'q':
                printf("\nAu revoir !\n\n");
                // Code pour libérer la mémoire et quitter proprement le programme
                break;
            default:
                printf("Choix invalide. Veuillez sélectionner une option valide.\n");
                break;
        }
    } while (choix != 'q');


    return 0;
}



    // donjon *d;
    // salle *s;
    // salle *s = NULL;

//     donjon *d = NULL;  


// // On peut pas initialiser un donjon a NULL ce qu'on peut faire c initialiser un donjon avec des valeurs impossible (p/ex avec une hauteur et largeur de -10), dans la fonction d'initialisation de donjon on protege l'init de donjon pour pas que ca soit en dessous de largeur 5 et hauteur 5, donc l'utilisateur pourra tester et ce sera refuser, et vu que ce sera refusé il ne pensera pas a essayer -10 => donc dans la fonction d'init de donjon on limite comme j'ai dit avant et on acepte quand meme si les mesures sont de -10 comme ca on pourra initialiser ici a -10 pour ensuite verifier si le donjon est de -10 alors c comme si le donjon etait NULL et donc que y avait pas de donjon. 

// // meme chose pour les salles (chiffre aléatoire); 

//     do {
//         afficher_menu();
//         scanf(" %c", &choix);
//         switch (choix) {
//             case 'd':
//                 // Code pour créer un donjon
//                 *d = creation_donjon(); 
//                 break;
//             case 's':
//                 // Code pour créer une salle
//                 *s = creation_salle();
//                 break;
//             case 'i':
//                 if (d != NULL) {
//                     if (s != NULL) {
//                         inserer_salle(d, s);
//                     }
//                     else {
//                         printf("Aucune salle a inserer\n");
//                     }
//                 }
//                 else {
//                     printf ("Aucun donjon initialise. Initialisez un donjon avant d'ajouter une salle dans le donjon.\n"); 
//                 }
//                 // if (d == NULL) {
//                 //     if 
//                 // }
//                 break;
//             case 'a':
//                 // Code pour afficher le donjon
//                 break;
//             case 'q':
//                 printf("Au revoir !\n");
//                 // Code pour libérer la mémoire et quitter proprement le programme
//                 break;
//             default:
//                 printf("Choix invalide. Veuillez sélectionner une option valide.\n");
//                 break;
//         }
//     } while (choix != 'q');
