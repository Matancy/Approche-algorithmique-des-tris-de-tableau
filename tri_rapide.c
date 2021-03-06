#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define TAB_MAX 1000000   // Taille maximale des tableaux d'entiers et de caractères.
#define TAB_STRING 100000 // Taille maximale du tableau de chaînes de caractères. 
                          // La taille est de 10 car le premier tableau d'entiers donne, après convertion, un tableau d'environ 50 carractères qui donne, après concaténation, un tableau de 10 chaînes de caractères.
                          // Les caractères sont concaténés entre eux pour donner des chaînes dont la taille est comprise entre 5 et 10. Ce qui donne un tableau de 10 carractères au minimum.

typedef int tableau[TAB_MAX];
typedef char tableauchar[TAB_MAX];
typedef char tableaustring[TAB_STRING][11];

void tri_rapide(tableaustring, int, int, int, int *, int *);
void permutation(tableaustring, int, int);
void creationTableauAlea(tableau);
void afficherString(tableaustring);
void convertToChar(tableau, tableauchar);
void concatenateChar(tableauchar, tableaustring);
void init(tableaustring);

int main()
{
    srand(time(NULL)); // Définition pour la fonction aléatoire
    // tableau normal = {12, 45, 2, 4, 23, 90, 65, 45, 99, 19};
    // tableau favorable = {1, 3, 5, 6, 8, 9, 12, 34, 56, 78};
    // tableau nonfavorable = {78, 56, 34, 12, 9, 8, 6, 5, 3, 1};
    tableau tab;
    tableauchar tabchar;
    tableaustring tabstring;

    int ordre; // Croissant : 0, Décroissant : 1
    double temps; // Temps cpu du tri
    int nbrCompare = 0; // Compte le nombre de comparaisons
    int nbrInverse = 0; // Compte le nombre de permutations
    printf("Entrez l'ordre de tri :\n");
    printf("\t0 - Croissant\n");
    printf("\t1 - Decroissant\n\n");
    scanf("%d", &ordre);

    init(tabstring);                     // Initialisation d'un tableau de chaînes de caractères
    creationTableauAlea(tab);            // Création d'un tableau d'entiers
    convertToChar(tab, tabchar);         // Création d'un tableau de carractères compris entre a et z, à partir du tableu d'entiers
    concatenateChar(tabchar, tabstring); // Création d'un tableau de chaînes de carractères
    printf("\n\n\tTRI RAPIDE\n\n");
    //printf("\nTableau intial : \n\n");
    //afficherString(tabstring);

    clock_t begin = clock(); // On enregistre l'heure dans une variable nommée begin
    tri_rapide(tabstring, 0, TAB_STRING, ordre, &nbrCompare, &nbrInverse);
    clock_t end = clock(); // On enregitre de nouveau l'heure dans une seconde variable nommée end
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure au début du tri et l'heure à la fin du tri
    printf("Temps cpu du tri: %f sec \n\n" ,temps);
    printf("Nombre de comparaisons: %d\n\n" ,nbrCompare);
    printf("Nombre de permutations: %d\n\n" ,nbrInverse);
    //printf("\nTableau trié : \n\n");
    //afficherString(tabstring);

    // printf("Tableau normal : \n");
    // afficher(normal);
    // printf("Tableau trie : \n");
    // tri_rapide(normal, 0, TAB_MAX - 1, ordre);
    // afficher(normal);
    // printf("\n\n");

    // printf("Tableau favorable :\n");
    // afficher(favorable);
    // tri_rapide(favorable, 0, TAB_MAX - 1, ordre);
    // printf("Tableau trie :\n");
    // afficher(favorable);
    // printf("\n\n");

    // printf("Tableau non favorable :\n");
    // afficher(nonfavorable);
    // tri_rapide(nonfavorable, 0, TAB_MAX - 1, ordre);
    // printf("Tableau trie :\n");
    // afficher(nonfavorable);
    // printf("\n\n");

    return EXIT_SUCCESS;
}

// Tri rapide
void tri_rapide(tableaustring tab, int debut, int fin, int ordre, int *nbrCompare, int *nbrInverse)
{
    int comparaison; // Négatif quand le premier élément du strcmp est supérieur au second, positif dans le cas inverse et nul sinon
    int pivot, i, j;
    if (debut < fin)
    {
        pivot = debut;
        i = debut;
        j = fin;
        while (i < j)
        {
            // Ordre croissant
            if (ordre == 0)
            {
                // Approche jusqu'au pivot
                comparaison = strcmp(tab[i], tab[pivot]);
                *nbrCompare = *nbrCompare + 1;
                while (((comparaison < 0) || (comparaison == 0)) && (i < fin))
                {
                    i++;
                    comparaison = strcmp(tab[i], tab[pivot]);
                }
                // Approche juste avant le pivot
                comparaison = strcmp(tab[j], tab[pivot]);
                *nbrCompare = *nbrCompare + 1;
                while (comparaison > 0)
                {
                    j--;
                    comparaison = strcmp(tab[j], tab[pivot]);
                }
            }
            // Ordre décroissant
            else
            {
                // Approche jusqu'au pivot
                comparaison = strcmp(tab[i], tab[pivot]);
                *nbrCompare = *nbrCompare + 1;
                while (((comparaison > 0) || (comparaison == 0)) && (i < fin))
                {
                    i++;
                    comparaison = strcmp(tab[i], tab[pivot]);
                }

                // Approche juste avant le pivot
                comparaison = strcmp(tab[j], tab[pivot]);
                *nbrCompare = *nbrCompare + 1;
                while (comparaison < 0)
                {
                    j--;
                    comparaison = strcmp(tab[j], tab[pivot]);
                }
            }
            if (i < j)
            {
                permutation(tab, i, j);
                *nbrInverse = *nbrInverse + 1;
            }
        }
        permutation(tab, pivot, j);
        *nbrInverse = *nbrInverse + 1;
        tri_rapide(tab, debut, j - 1, ordre, nbrCompare, nbrInverse);
        tri_rapide(tab, j + 1, fin, ordre, nbrCompare, nbrInverse);
    }
}

// Permutation de deux éléments
void permutation(tableaustring tab, int a, int b)
{
    char tmp[11];
    strcpy(tmp, tab[a]);
    strcpy(tab[a], tab[b]);
    strcpy(tab[b], tmp);
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