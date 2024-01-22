#include "constructeur.h"
#include <string.h>
#include <stdio.h>

int main () {
    fonction_finale(); 
    // donjon d; 
    // salle s, s2; 
    // initialiser_donjon(&d, 20, 20); 
    // initialiser_salle (&s, 10, 10, 2, 2); 
    // inserer_salle(&d, &s); 

    // initialiser_salle (&s2, 10, 10, 2, 2);
    // inserer_salle(&d, &s2); 
    // printf ("DEBUGGAE3\n"); 
    // debbuger_donjon(&d);

    return 0; 
}



// // int main () {
// //     menu m; 
// //     m = creer_menu (); 
// //     afficher_menu(&m);
// //     // creation_donjon ();
// //     donjon d; 
// //     initialiser_donjon (&d, 20, 20);

// //     salle s; 
// //     initialiser_salle (&s, 5, 5, 6, 7);
// //     entitee e;
// //     initialiser_entitee(&s, &e, 0, 1, 'E');
// //     inserer_entitee_dans_salle(&s, &e);
// //     inserer_salle (&d, &s);
// //     afficher_donjon (&d);

// //     couloir c; 
// //     point dep = {2, 2}; 
// //     point arr = {8, 8}; 

// //     initialiser_couloir (&c, &dep, &arr);
// //     inserer_couloir(&d, &c);
// //     afficher_donjon(&d);
// //     printf ("ICI : ");
// //     afficher_stockage_couloir(&d);
// //     supprimer_couloir(&d, 0);
// //     afficher_donjon(&d);

// //     return 0; 
// // }

// int main () {
//     donjon d; 
//     initialiser_donjon(&d, -10, -10); 
//     donjon *pt_d = &d; 

//     salle s; 
//     initialiser_salle(&s, -10, -10, 0, 0); 

//     char choix; 
//     int arret_menu = 0; 

//     int indice_couloir_a_supprimer;

//     do {
//         if (arret_menu == 0) {
//             afficher_menu_debut(); 
//         }
//         else {
//             afficher_donjon(&d);
//             printf ("Que voulez-vous faire ? \n");
//         }
//         scanf(" %c", &choix);
//         switch (choix) {
//             case 'd':
//                 // Code pour créer un donjon
//                 d = creation_donjon(); 
//                 arret_menu = 1; 
//                 break;
//             case 's':
//                 // Code pour créer une salle
//                 char sauv; 
//                 s = creation_salle();
//                 insertion_salle(&d, &s);
//                 break;
//             case 'y':
//                 if (d.stockage)
//             case 'i':                
//                 if (d.hauteur_dj != -10) {
//                     if (s.hauteur_salle != -10) {
//                         printf ("Vous allez inserer la derniere salle creee dans le donjon");
//                         // inserer_salle(&d, &s);
//                         insertion_salle(&d ,&s); 
//                         // printf ("Salle inseree avec succes\n");
//                         // donjon *d1;
//                         // initialiser_donjon(d1, d.hauteur_dj, d.largeur_dj);
//                         // sauvegarder_donjon_dans_fichier(d1);
//                         printf ("donjon sauvegarde\n");
//                     }
//                     else {
//                         printf("Aucune salle a inserer\n");
//                     }
//                 }
//                 else {
//                     printf ("Aucun donjon initialise. Initialisez un donjon avant d'ajouter une salle dans le donjon.\n"); 
//                 }
//                 break;
//             case 'c':
//             if (d.hauteur_dj != -10)
//             {
//                 couloir *c;
//                 c = creation_couloir();
//                 printf(" dans le switch case : %d", c->arrivee->x);
//                 inserer_couloir(&d, c);
//             }
//             else
//             {
//                 printf("\nCreez un donjon avant de faire un couloir\n");
//             }
//             break;
//             case 'z':
//                 if (d.hauteur_dj != -10) {
//                     if (d.stockage_couloir->nb_element != 0){ 
//                         do {
//                             printf ("Il y a %d couloirs, Saisissez l'indice du couloir que vous voulez supprimer (indice du premier couloir : 1) : ", d.stockage_couloir->nb_element);
//                             scanf("%d", &indice_couloir_a_supprimer);
//                             if (indice_couloir_a_supprimer<1 || indice_couloir_a_supprimer > d.stockage_couloir->nb_element +1){
//                                 printf ("Veuillez saisir un indice valide");
//                                 continue; 
//                             }
//                             else {
//                                 // printf ("ok?\n");
//                                 // afficher_stockage_couloir(&d);
//                                 supprimer_couloir (&d,(indice_couloir_a_supprimer-1));
//                                 printf ("Normalement c supprime\n");
//                             }
//                         }
//                         while (indice_couloir_a_supprimer<1 || indice_couloir_a_supprimer > d.stockage_couloir->nb_element +1);
//                     }
//                     else {
//                         printf ("Il n'y a pas de couloir a supprimer\n");
//                         continue; 
//                     }
//                 }
//                 else {
//                     printf ("Il n'y a pas encore de donjon, impossible de supprimer un couloir");
//                 }
//                 break;
//             case 'm' : 
//                 abcisse mur_x; 
//                 ordonne mur_y; 
//                 point mur; 
//                 if (d.hauteur_dj != 10) {
//                     do {    
//                         printf ("Saisissez les coordonnees x du mur que vous voulez placer :\n"); 
//                         scanf ("%d", &mur_x); 
//                         mur.x = mur_x; 
//                         if (mur_x < 0 || mur_x>d.hauteur_dj){
//                             printf ("Coordonnees invalides\n"); 
//                             continue; 
//                         }
//                         printf ("Saisissez les coordonnees y du mur que vous voulez placer :\n"); 
//                         scanf ("%d", &mur_y); 
//                         mur.y = mur_y; 
//                         if (mur_y < 0 || mur_y>d.hauteur_dj){
//                             printf ("Coordonnees invalides\n"); 
//                             continue; 
//                         }
//                         ajouter_mur(&d, &mur);  
//                     }
//                     while (mur_x < 0 || mur_x>d.hauteur_dj || mur_y <0 || mur_y>d.largeur_dj);
//                     printf ("insertion du mur ok\n");
//                 }
//                 break;
//             case 'x' : 
//                 abcisse mur_sup_x; 
//                 ordonne mur_sup_y; 
//                 point mur_sup; 
//                 if (d.hauteur_dj != 10) {
//                     do {    
//                         printf ("Saisissez les coordonnees x du mur que vous voulez supprimer :\n"); 
//                         scanf ("%d", &mur_sup_x); 
//                         mur_sup.x = mur_sup_x; 
//                         if (mur_sup_x < 0 || mur_sup_x>d.hauteur_dj){
//                             printf ("Coordonnees invalides\n"); 
//                             continue; 
//                         }
//                         printf ("Saisissez les coordonnees y du mur que vous voulez placer :\n"); 
//                         scanf ("%d", &mur_sup_y); 
//                         mur_sup.y = mur_sup_y; 
//                         if (mur_sup_y < 0 || mur_sup_y>d.hauteur_dj){
//                             printf ("Coordonnees invalides\n"); 
//                             continue; 
//                         }
//                         if (d.tab_dj[mur_sup.y][mur_sup.y] == '#'){
//                             supprimer_mur(&d, &mur_sup);
//                             printf ("Suppression du mur ok\n");
//                         }  
//                         else {
//                             printf ("Aucun mur a ces coordonnes\n");
//                         }
//                     }
//                     while (mur_x < 0 || mur_x>d.hauteur_dj || mur_y <0 || mur_y>d.largeur_dj);
//                 }
//                 break;
//             case 'a':
//                 if (d.hauteur_dj == -10){
//                     printf ("\nAucun donjon a afficher \n");
//                 }
//                 break;
//                 // afficher_donjon(&d); on peut break et ca va nous faire revenir au debut du while => affiche le donjon; 
//             case 'r':
//                 break;
//             case 'q':
//                 printf("\nAu revoir !\n\n");
//                 // Code pour libérer la mémoire et quitter proprement le programme
//                 break;
//             default:
//                 printf("Choix invalide. Veuillez sélectionner une option valide.\n");
//                 break;
//         }
//     } while (choix != 'q');    

//     // printf ("%d", d.stockage_couloir->nb_element);

//     return 0; 
// }

// // On peut pas initialiser un donjon a NULL ce qu'on peut faire c initialiser un donjon avec des valeurs impossible (p/ex avec une hauteur et largeur de -10), dans la fonction d'initialisation de donjon on protege l'init de donjon pour pas que ca soit en dessous de largeur 5 et hauteur 5, donc l'utilisateur pourra tester et ce sera refuser, et vu que ce sera refusé il ne pensera pas a essayer -10 => donc dans la fonction d'init de donjon on limite comme j'ai dit avant et on acepte quand meme si les mesures sont de -10 comme ca on pourra initialiser ici a -10 pour ensuite verifier si le donjon est de -10 alors c comme si le donjon etait NULL et donc que y avait pas de donjon. 

// // meme chose pour les salles (chiffre aléatoire); 
