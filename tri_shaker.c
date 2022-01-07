#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define TAB_MAX 500000 // Taille maximale des tableaux d'entiers

typedef int tableau[TAB_MAX];

void tri_shaker(tableau, int, unsigned long *, unsigned long *);
void inversion(tableau, int, int);
void creationTableauAlea(tableau, int);

int main()
{
    srand(time(NULL)); // Définition pour la fonction aléatoire

    tableau tab;

    int ordre;                   // Ordre croissant 0 ou décroissant 1
    double temps;                // Temps cpu du tri
    unsigned long nbComparaison; // Nombre de comparaisons
    unsigned long nbPermutation; // Nombre de permutations

    nbComparaison = 0;
    nbPermutation = 0;

    printf("Entrez l'ordre de tri : \n");
    printf("\t 0 - Croissant \n");
    printf("\t 1 - Decroissant \n");
    scanf("%d", &ordre);

    creationTableauAlea(tab, TAB_MAX); // Création d'un tableau d'entiers
    printf("\n\n\tTRI SHAKER\n\n");
    //printf("\nTableau initial : \n\n");
    //afficherString(tabstring);

    clock_t begin = clock(); // Enregistrement du temps de début
    tri_shaker(tab, ordre, &nbComparaison, &nbPermutation);
    clock_t end = clock();                          // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul du temps d'exécution

    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    //printf("\nTableau trié : \n\n");
    //afficherString(tabstring);

    return EXIT_SUCCESS;
}

void tri_shaker(tableau tab, int ordre_des_donnees, unsigned long *nbComparaison, unsigned long *nbPermutation)
{
    int indMin, indMax, count, order;
    indMin = 0;           // Indice du min trié dans le tableau
    indMax = TAB_MAX - 1; // Indice du max trié dans le tableau
    count = 0;            // Compteur
    order = 0;            // 0 => Evolution croissante, 1 => Evolution décroissante

    while ((indMax - indMin) != 0) // Tant que l'écart entre le minimum et le max est différent de 0 (soit tableau trié)
    {
        // Partie croissante
        if (order == 0)
        {
            // Tri croissant
            if ((ordre_des_donnees == 0) && (tab[count] > tab[count + 1]))
            {
                // Si la première valeur est plus grande, on inverse les deux
                inversion(tab, count, count + 1);
                *nbPermutation = *nbPermutation + 1;
            }
            // Tri décroissant
            else if ((ordre_des_donnees == 1) && (tab[count] < tab[count + 1]))
            {
                // Si la première valeur est plus petite, on inverse les deux
                inversion(tab, count + 1, count);
                *nbPermutation = *nbPermutation + 1;
            }
            // Incrémentation du compteur
            count = count + 1;
            *nbComparaison = *nbComparaison + 1;
        }
        // Partie décroissante
        else
        {
            if ((ordre_des_donnees == 0) && (tab[count - 1] > tab[count]))
            {
                // Si la valeur en dessous est plus grande, on inverse les deux
                inversion(tab, count - 1, count);
                *nbPermutation = *nbPermutation + 1;
            }
            else if ((ordre_des_donnees == 1) && (tab[count - 1]) < tab[count])
            {
                // Si la valeur en dessous est plus petite, on inverse les deux
                inversion(tab, count, count - 1);
                *nbPermutation = *nbPermutation + 1;
            }
            // Décrémentation du compteur
            count = count - 1;
            *nbComparaison = *nbComparaison + 1;
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
                *nbPermutation = *nbPermutation + 1;
            }
            else
            {
                order = 0;           // Passage en évolution croissante
                indMin = indMin + 1; // Incrémentation de l'indice minimum
                count = count + 1;
                *nbPermutation = *nbPermutation + 1;
            }
        }
    }
}

// Inversion de deux valeurs
void inversion(tableau tab, int val1, int val2)
{
    int tmp;
    tmp = tab[val2];
    tab[val2] = tab[val1];
    tab[val1] = tmp;
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