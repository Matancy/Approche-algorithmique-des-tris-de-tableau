#include <stdlib.h>
#include <stdio.h>
#define MAX 10

typedef int tableau[MAX];

void tri_insertion(tableau, int);
void afficher(tableau);

int main()
{
    tableau favorable = {1, 3, 5, 6, 8, 9, 12, 34, 56, 78};
    tableau nonfavorable = {78, 56, 34, 12, 9, 8, 6, 5, 3, 1};
    tableau normal = {12, 45, 2, 4, 23, 90, 65, 45, 99, 19};

    int choixOrdre; // Croissant : 0, Décroissant : 1

    printf("Entrez l'ordre de tri :\n");
    printf("\t0 - Croissant\n");
    printf("\t1 - Decroissant\n\n");
    scanf("%d", &choixOrdre);

    printf("Tableau favorable :\n");
    afficher(favorable);
    tri_insertion(favorable, choixOrdre);
    printf("Tableau trie :\n");
    afficher(favorable);
    printf("\n\n");

    printf("Tableau non favorable :\n");
    afficher(nonfavorable);
    tri_insertion(nonfavorable, choixOrdre);
    printf("Tableau trie :\n");
    afficher(nonfavorable);
    printf("\n\n");

    printf("Tableau normal :\n");
    afficher(normal);
    tri_insertion(normal, choixOrdre);
    printf("Tableau trie :\n");
    afficher(normal);
    printf("\n\n");

    return EXIT_SUCCESS;
}

// Tri par insertion des tableaux
void tri_insertion(tableau t, int ordre)
{
    int i;
    int j;
    int temp; //variable temporaire pour faire un échange
    for (i = 1; i < MAX; i++)
    {
        j = i;
        // Ordre croissant
        if ((ordre == 0) && (t[i] < t[i - 1]))
        {
            while (t[j] < t[j - 1] && (j != 0))
            {
                temp = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp;
                j = j - 1;
            }
        }
        // Ordre décroissant
        else if ((ordre == 1) && (t[i - 1] < t[i]))
        {
            while (t[j - 1] < t[j] && (j != 0))
            {
                temp = t[j];
                t[j] = t[j - 1];
                t[j - 1] = temp;
                j = j - 1;
            }
        }
    }
}

// Affichage d'un tableau
void afficher(tableau tab)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}