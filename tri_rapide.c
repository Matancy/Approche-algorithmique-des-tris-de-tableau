#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define TAB_MAX 500000 // Taille maximale des tableaux d'entiers

typedef int tableau[TAB_MAX];

void tri_rapide(tableau, int, int, int, unsigned long *, unsigned long *);
void permutation(tableau, int, int);
void afficher(tableau);
void creationTableauAlea(tableau, int);

int main()
{
    srand(time(NULL)); // Définition pour la fonction aléatoire
    // tableau normal = {12, 45, 2, 4, 23, 90, 65, 45, 99, 19};
    // tableau favorable = {1, 3, 5, 6, 8, 9, 12, 34, 56, 78};
    // tableau nonfavorable = {78, 56, 34, 12, 9, 8, 6, 5, 3, 1};
    tableau tab;

    int ordre;                    // Croissant : 0, Décroissant : 1
    double temps;                 // Temps cpu du tri
    unsigned long nbComparaison;  // Nombre de comparaisons
    unsigned long nbPermutation; // Nombre de permutations

    nbComparaison = 0;
    nbPermutation = 0;

    printf("Entrez l'ordre de tri :\n");
    printf("\t0 - Croissant\n");
    printf("\t1 - Decroissant\n\n");
    scanf("%d", &ordre);

    creationTableauAlea(tab, TAB_MAX); // Création d'un tableau d'entiers
    printf("\n\n\tTRI RAPIDE\n\n");
    //printf("\nTableau intial : \n\n");
    //afficherString(tabstring);

    clock_t begin = clock(); // Enregistrement du temps de début
    tri_rapide(tab, 0, TAB_MAX, ordre, &nbComparaison, &nbPermutation);
    clock_t end = clock();                          // Enregistrement du temps de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul du temps d'exécution
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
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
void tri_rapide(tableau tab, int debut, int fin, int ordre, unsigned long *nbComparaison, unsigned long *nbPermutation)
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
                    *nbComparaison = *nbComparaison + 1;
                }
                *nbComparaison = *nbComparaison + 1;

                // Approche juste avant le pivot
                while (tab[j] > tab[pivot])
                {
                    j--;
                    *nbComparaison = *nbComparaison + 1;
                }
                *nbComparaison = *nbComparaison + 1;
            }
            // Ordre décroissant
            else
            {
                // Approche jusqu'au pivot
                while (tab[i] >= tab[pivot] && i < fin)
                {
                    i++;
                    *nbComparaison = *nbComparaison + 1;
                }
                *nbComparaison = *nbComparaison + 1;

                // Approche juste avant le pivot
                while (tab[j] < tab[pivot])
                {
                    j--;
                    *nbComparaison = *nbComparaison + 1;
                }
                *nbComparaison = *nbComparaison + 1;
            }
            if (i < j)
            {
                permutation(tab, i, j);
                *nbPermutation = *nbPermutation + 1;
            }
        }

        permutation(tab, pivot, j);
        *nbPermutation = *nbPermutation + 1;
        tri_rapide(tab, debut, j - 1, ordre, &nbComparaison, &nbPermutation);
        tri_rapide(tab, j + 1, fin, ordre, &nbComparaison, &nbPermutation);
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