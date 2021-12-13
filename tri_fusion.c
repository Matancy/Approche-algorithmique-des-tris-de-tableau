#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define TAB_MAX 50
#include <time.h>

typedef int tableau[TAB_MAX];

void tri_fusion(tableau, tableau, int, int);
void remplir(tableau, tableau, int, int);
void afficher(tableau);
void creationTableauAlea(tableau, int);

int main()
{
    srand(time(NULL)); // Définition pour la fonction aléatoire
    // tableau tablo = {98, 67, 54, 23, 56, 18, 99, 0, 67, 78};
    tableau tab;
    tableau tab_fin = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // tableau tab_fin;

    creationTableauAlea(tab, TAB_MAX);
    // printf("Tableau normal : \n");
    // afficher(tab);
    // printf("Tableau trié : \n");
    tri_fusion(tab, tab_fin, 0, TAB_MAX);
    // afficher(tab_fin);

    return EXIT_SUCCESS;
}

// Tri fusion
void tri_fusion(tableau tab, tableau tab_fin, int min, int max)
{
    // afficher(tab_fin);

    if (max == 2)
    {
    }
    if (max - min <= 1)
    {
        remplir(tab, tab_fin, min, max);
    }
    else
    {
        tri_fusion(tab, tab_fin, min, (max / 2) - 1);
        printf("min : %d \t max : %d\n", min, max);
        tri_fusion(tab, tab_fin, max / 2, max);
    }
}

// Remplir le tableau final
void remplir(tableau tab_init, tableau tab_fin, int min, int max)
{
    int tmp;
    printf("remplir\n");
    int count;
    count = 0;
    // Comparaison des deux entiers
    if (tab_init[min] > tab_init[max])
    {
        // Inversion des deux éléments
        tmp = tab_init[min];
        tab_init[min] = tab_init[max];
        tab_init[max] = tmp;
    }
    for (int i = 0; i < TAB_MAX; i++)
    {
        // Si la zone est vide
        if (tab_fin[i] == 0)
        {
            // Si c'est le premier élément entré
            if (count == 0)
            {
                // Ajout du minimum en premier
                tab_fin[i] = tab_init[min];
                count += 1;
            }
            else if (count == 1)
            {
                // Ajout du maximum en second
                tab_fin[i] = tab_init[max];
                count += 1;
            }
        }
    }
    // afficher(tab_fin);
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
            nb = rand() % 10 * RAND_MAX;
        } while (nb == 0);
        tab[i] = nb;
    }
}