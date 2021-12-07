#include <stdlib.h>
#include <stdio.h>
#define N 10

typedef int tableau[N];
void tri_shaker(tableau);
void inversion(tableau, int, int);
void afficher(tableau);

// Inversion de deux valeurs
void inversion(tableau tab, int val1, int val2)
{
    int tmp;
    tmp = tab[val2];
    tab[val2] = tab[val1];
    tab[val1] = tmp;
}

// Affichage du tableau
void afficher(tableau tab)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", tab[i]);
    }
}