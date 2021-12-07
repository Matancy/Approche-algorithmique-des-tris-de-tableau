#include <stdlib.h>
#include <stdio.h>
#define N 10

typedef int tableau[N];
void tri_shaker(tableau);
void inversion(tableau, int, int);
void afficher(tableau);

int main()
{
    tableau t = {12, 45, 2, 4, 23, 90};
    printf("Tableau initial : \n");
    afficher(t);
    tri_shaker(t);
    printf("Tableau trié : \n");
    afficher(t);
    return EXIT_SUCCESS;
}

void tri_shaker(tableau tab)
{
    int indMin, indMax, count, order;
    indMin = 0;     // Indice du min trié dans le tableau
    indMax = N - 1; // Indice du max trié dans le tableau
    count = 0;      // Compteur
    order = 0;      // 0 => Evolution croissante, 1 => Evolution décroissante

    while ((indMax - indMin) != 0) // Tant que l'écart entre le minimum et le max est différent de 0 (soit tableau trié)
    {
        // Partie croissante
        if (order == 0)
        {
            if (tab[count] > tab[count + 1])
            {
                // Si la première valeur est plus grande, on inverse les deux
                inversion(tab, count, count + 1);
            }
            // Incrémentation du compteur
            count = count + 1;
        }
        // Partie décroissante
        else
        {
            // Décrémentation du compteur
            count = count - 1;
        }

        // Inversion en fonction de l'avancée du tri
        if (count == (N - 1) || count == 1)
        {
            // Inversion du mode d'évolution
            if (order == 0)
            {
                order = 1; // Passage en évolution décroissante
            }
            else
            {
                order = 0; // Passage en évolution croissante
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

// Affichage du tableau
void afficher(tableau tab)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", tab[i]);
    }
}