#include <stdio.h>
#define LARGEUR 10
#define HAUTEUR 10

// Définition d'une structure pour représenter un point dans l'espace
typedef struct
{
    double x;
    double y;
} Point;

// Définition d'une structure pour représenter un rectangle dans l'espace
typedef struct
{
    Point topLeft;     // Coin supérieur gauche
    Point bottomRight; // Coin inférieur droit
} Rectangle;

int main()
{
    // Créez un espace en définissant un rectangle
    Rectangle espace;
    espace.topLeft.x = 0.0;
    espace.topLeft.y = 0.0;
    espace.bottomRight.x = 10.0;
    espace.bottomRight.y = 10.0;

    // Créez des éléments à placer dans l'espace
    Point element1;
    element1.x = 3.0;
    element1.y = 4.0;

    Point element2;
    element2.x = 8.0;
    element2.y = 7.0;

    // Vérifiez si un élément est à l'intérieur de l'espace
    if (element1.x >= espace.topLeft.x && element1.x <= espace.bottomRight.x &&
        element1.y >= espace.topLeft.y && element1.y <= espace.bottomRight.y)
    {
        // printf("Element 1 est à l'interieur de l'espace.\n");
    }
    else
    {
        printf("Element 1 est a l'exterieur de l'espace.\n");
    }

    if (element2.x >= espace.topLeft.x && element2.x <= espace.bottomRight.x &&
        element2.y >= espace.topLeft.y && element2.y <= espace.bottomRight.y)
    {
    }
    else
    {
        printf("Element 2 est a l'exterieur de l'espace.\n");
    }

    // Définition de la taille de l'espace
    // Créez un tableau pour représenter l'espace
    char esp[LARGEUR][HAUTEUR];

    // Initialisez l'esp avec des esps vides
    for (int x = 0; x < LARGEUR; x++)
    {
        for (int y = 0; y < HAUTEUR; y++)
        {
            esp[x][y] = ' ';
        }
    }

    // Placez un élément '#' à une position spécifique dans l'esp
    int x_element = 3;
    int y_element = 4;
    esp[x_element][y_element] = '#';

    // Placez un autre élément 'M' à une autre position
    int x_element2 = 8;
    int y_element2 = 7;
    esp[x_element2][y_element2] = 'M';

    // Affichez l'esp avec les éléments
    for (int y = 0; y < HAUTEUR; y++)
    {
        for (int x = 0; x < LARGEUR; x++)
        {
            printf("%c", esp[x][y]);
        }
        printf("\n");
    }

    return 0;
}