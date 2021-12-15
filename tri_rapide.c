#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define TAB_MAX 10

typedef int tableau[TAB_MAX];

void tri_rapide(tableau, int, int, int);
void permutation(tableau, int, int);
void afficher(tableau);
void creationTableauAlea(tableau, int);

int main()
{
    // tableau normal = {12, 45, 2, 4, 23, 90, 65, 45, 99, 19};
    // tableau favorable = {1, 3, 5, 6, 8, 9, 12, 34, 56, 78};
    // tableau nonfavorable = {78, 56, 34, 12, 9, 8, 6, 5, 3, 1};
    tableau tab;

    int ordre; // Croissant : 0, Décroissant : 1

    printf("Entrez l'ordre de tri :\n");
    printf("\t0 - Croissant\n");
    printf("\t1 - Decroissant\n\n");
    scanf("%d", &ordre);

    creationTableauAlea(tab, TAB_MAX);
    tri_rapide(tab, 0, TAB_MAX, ordre);
    afficher(tab);

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
void tri_rapide(tableau tab, int debut, int fin, int ordre)
{
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
                while (tab[i] <= tab[pivot] && i < fin)
                {
                    i++;
                }

                // Approche juste avant le pivot
                while (tab[j] > tab[pivot])
                {
                    j--;
                }
            }
            // Ordre décroissant
            else
            {
                // Approche jusqu'au pivot
                while (tab[i] >= tab[pivot] && i < fin)
                {
                    i++;
                }

                // Approche juste avant le pivot
                while (tab[j] < tab[pivot])
                {
                    j--;
                }
            }
            if (i < j)
            {
                permutation(tab, i, j);
            }
        }

        permutation(tab, pivot, j);
        tri_rapide(tab, debut, j - 1, ordre);
        tri_rapide(tab, j + 1, fin, ordre);
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
    for (int i = 0; i < TAB_MAX; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

// Fonction de remplissage aléatoire
void creationTableauAlea(tableau tab, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        int nb;
        do
        {
            nb = rand() % RAND_MAX;
        } while (nb == 0);
        tab[i] = nb;
    }
}