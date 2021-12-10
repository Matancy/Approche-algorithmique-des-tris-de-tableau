#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef int tableau[MAX];

void tri_rapide(tableau, int, int);
void permutation(tableau, int, int);
void afficher(tableau);

int main()
{
    tableau favorable = {1, 3, 5, 6, 8, 9, 12, 34, 56, 78};
    tableau nonfavorable = {78, 56, 34, 12, 9, 8, 6, 5, 3, 1};
    tableau normal = {12, 45, 2, 4, 23, 90, 65, 45, 99, 19};

    printf("Tableau normal : \n");
    afficher(normal);
    printf("Tableau trie : \n");
    tri_rapide(normal, 0, MAX);
    afficher(normal);
    printf("\n\n");

    printf("Tableau favorable :\n");
    afficher(favorable);
    tri_rapide(favorable, 0, MAX);
    printf("Tableau trie :\n");
    afficher(favorable);
    printf("\n\n");

    printf("Tableau non favorable :\n");
    afficher(nonfavorable);
    tri_rapide(nonfavorable, 0, MAX);
    printf("Tableau trie :\n");
    afficher(nonfavorable);
    printf("\n\n");

    return EXIT_SUCCESS;
}

// Tri rapide
void tri_rapide(tableau tab, int debut, int fin)
{
    int pivot, i, j;
    if (debut < fin)
    {
        pivot = debut;
        i = debut;
        j = fin;
        while (i < j)
        {
            // Approche jusqu'au pivot
            while (tab[i] <= tab[pivot] && i < fin)
                i++;

            // Approche juste avant le pivot
            while (tab[j] > tab[pivot])
                j--;
            if (i < j)
            {
                permutation(tab, i, j);
            }
        }
        permutation(tab, pivot, j);
        tri_rapide(tab, debut, j - 1);
        tri_rapide(tab, j + 1, fin);
    }
}

// Permutation de deux éléments
void permutation(tableau tab, int a, int b)
{
    int tmp;
    tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
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