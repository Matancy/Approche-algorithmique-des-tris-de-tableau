#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define TAB_MAX 100
#define TAB_STRING 5

typedef int tableau[TAB_MAX];
typedef char tableauchar[TAB_MAX];
typedef char tableaustring[TAB_STRING][11];

void tri_shaker(tableaustring, int);
void inversion(tableaustring, int, int);
void creationTableauAlea(tableau);
void afficherString(tableaustring);
void convertToChar(tableau, tableauchar);
void concatenateChar(tableauchar, tableaustring);
void init(tableaustring);

int main()
{
    srand(time(NULL)); // Définition pour la fonction aléatoire
    // tableau favorable = {1, 3, 5, 6, 8, 9, 12, 34, 56, 78};
    // tableau nonfavorable = {78, 56, 34, 12, 9, 8, 6, 5, 3, 1};
    // tableau normal = {12, 45, 2, 4, 23, 90, 65, 45, 99, 19};
    int ordre; // Ordre croissant 0 ou décroissant 1
    tableau tab;
    tableauchar tabchar;
    tableaustring tabstring;
    printf("Entrez l'ordre de tri : \n");
    printf("\t 0 - Croissant \n");
    printf("\t 1 - Decroissant \n");
    scanf("%d", &ordre);
    
    init(tabstring);                     // Initialisation d'un tableau de chaînes de caractères
    creationTableauAlea(tab);            // Création d'un tableau d'entiers
    convertToChar(tab, tabchar);         // Création d'un tableau de carractères compris entre a et z, à partir du tableu d'entiers
    concatenateChar(tabchar, tabstring); // Création d'un tableau de chaînes de carractères
    printf("\n\nTRI SHAKER\n\n");
    printf("\nTableau initial : \n\n");
    afficherString(tabstring);
    tri_shaker(tabstring, ordre);
    printf("\nTableau trie : \n\n");
    afficherString(tabstring);

    // Tri favorable
    // printf("Tableau initial favorable : \n");
    // afficher(favorable);
    // tri_shaker(favorable, ordre);
    // printf("Tableau trie : \n");
    // afficher(favorable);
    // printf("\n\n");

    // // Tri non favorable
    // printf("Tableau initial non favorable : \n");
    // afficher(nonfavorable);
    // tri_shaker(nonfavorable, ordre);
    // printf("Tableau trie : \n");
    // afficher(nonfavorable);
    // printf("\n\n");

    // // Tri normal
    // printf("Tableau initial normal : \n");
    // afficher(normal);
    // tri_shaker(normal, ordre);
    // printf("Tableau trie : \n");
    // afficher(normal);
    // printf("\n\n");
    return EXIT_SUCCESS;
}

void tri_shaker(tableaustring tab, int ordre_des_donnees)
{
    int indMin, indMax, count, order;
    indMin = 0;              // Indice du min trié dans le tableau
    indMax = TAB_STRING - 1; // Indice du max trié dans le tableau
    count = 0;               // Compteur
    order = 0;               // 0 => Evolution croissante, 1 => Evolution décroissante
    int comparaison;         // Négatif quand le premier élément du strcmp est supérieur au second, positif dans le cas inverse et nul sinon

    while ((indMax - indMin) != 0) // Tant que l'écart entre le minimum et le max est différent de 0 (soit tableau trié)
    {
        // Partie croissante
        if (order == 0)
        {
            // Tri croissant
            if (ordre_des_donnees == 0)
            {
                comparaison = strcmp(tab[count], tab[count + 1]);
                if (comparaison > 0)
                {
                    // Si la première valeur est plus grande, on inverse les deux
                    inversion(tab, count, count + 1);
                }
            }
            // Tri décroissant
            else if (ordre_des_donnees == 1)
            {
                comparaison = strcmp(tab[count], tab[count + 1]);
                if (comparaison < 0)
                {
                    // Si la première valeur est plus petite, on inverse les deux
                    inversion(tab, count + 1, count);
                }
            }
            // Incrémentation du compteur
            count = count + 1;
        }
        // Partie décroissante
        else
        {
            // Tri croissant
            if (ordre_des_donnees == 0)
            {
                comparaison = strcmp(tab[count - 1], tab[count]);
                if (comparaison > 0)
                {
                    // Si la valeur en dessous est plus grande, on inverse les deux
                    inversion(tab, count - 1, count);
                }
            }
            // Tri décroissant
            else if (ordre_des_donnees == 1)
            {
                comparaison = strcmp(tab[count - 1], tab[count]);
                if (comparaison < 0)
                {
                    // Si la valeur en dessous est plus petite, on inverse les deux
                    inversion(tab, count, count - 1);
                }
            }
            // Décrémentation du compteur
            count = count - 1;
        }
        // Inversion en fonction de l'avancée du tri
        if ((count == indMax) || (count == indMin))
        {
            // Inversion du mode d'évolution
            if (order == 0)
            {
                order = 1;           // Passage en évolution décroissante
                indMax = indMax - 1; // Décrémentation de l'indice maximum
                count = count - 1;
            }
            else
            {
                order = 0;           // Passage en évolution croissante
                indMin = indMin + 1; // Incrémentation de l'indice minimum
                count = count + 1;
            }
        }
    }
}

// Inversion de deux valeurs
void inversion(tableaustring tab, int val1, int val2)
{
    char tmp[11];
    strcpy(tmp, tab[val2]);
    strcpy(tab[val2], tab[val1]);
    strcpy(tab[val1], tmp);
}

// Affichage d'un tableau de chaînes de carractères
void afficherString(tableaustring tab)
{
    for (int i = 0; i < TAB_STRING; i++)
    {
        if (strcmp(tab[i], "          ") != 0)
        {
            printf("%s", tab[i]);
            printf("\n");
        }
    }
}

// Fonction de remplissage aléatoire
void creationTableauAlea(tableau tab)
{
    for (int i = 0; i < TAB_MAX; i++)
    {
        int nb;
        do
        {
            nb = rand() % 122;
        } while (nb < 97);
        tab[i] = nb;
    }
}

void convertToChar(tableau tab, tableauchar tabchar)
{
    for (int i = 0; i < TAB_MAX; i++)
    {
        tabchar[i] = tab[i];
    }
}

void concatenateChar(tableauchar tabchar, tableaustring tabstring)
{
    // Génération d'un chiffre
    int nb;
    int pointeur;
    int count;
    int j;
    int ind;
    count = 0;
    pointeur = 0;
    ind = 0;
    for (int i = 0; i < TAB_MAX; i++)
    {
        do
        {
            nb = rand() % 10;
        } while (nb < 5);

        ind = 0;
        if ((pointeur + nb) > TAB_MAX)
        {
            for (int j = pointeur; j < TAB_MAX; j++)
            {
                tabstring[count][ind] = tabchar[j];
                ind = ind + 1;
            }
        }
        else
        {
            for (j = pointeur; j < (pointeur + nb); j++)
            {
                tabstring[count][ind] = tabchar[j];
                ind = ind + 1;
            }
        }
        pointeur = pointeur + nb;
        count = count + 1;
    }
}

// Fonction pour remplir les cases vides d'un tableau par des espaces
void init(tableaustring tabstring)
{
    for (int i = 0; i < TAB_STRING; i++)
    {
        strcpy(tabstring[i], "          ");
    }
}