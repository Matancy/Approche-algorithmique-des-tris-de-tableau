#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAB_MAX 100000

typedef int tableau[TAB_MAX];
void tri_shaker(tableau, int);
void inversion(tableau, int, int);
void afficher(tableau);
void creationTableauAlea(tableau, int);

int main()
{
    srand(time(NULL)); // Définition pour la fonction aléatoire
    // tableau favorable = {1, 3, 5, 6, 8, 9, 12, 34, 56, 78};
    // tableau nonfavorable = {78, 56, 34, 12, 9, 8, 6, 5, 3, 1};
    // tableau normal = {12, 45, 2, 4, 23, 90, 65, 45, 99, 19};
    int ordre; // Ordre croissant 0 ou décroissant 1
    tableau tab;
    printf("Entrez l'ordre de tri : \n");
    printf("\t 0 - Croissant \n");
    printf("\t 1 - Decroissant \n");
    scanf("%d", &ordre);

    creationTableauAlea(tab, TAB_MAX);
    tri_shaker(tab, ordre);
    afficher(tab);

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

void tri_shaker(tableau tab, int ordre_des_donnees)
{
    int indMin, indMax, count, order;
    indMin = 0;     // Indice du min trié dans le tableau
    indMax = TAB_MAX - 1; // Indice du max trié dans le tableau
    count = 0;      // Compteur
    order = 0;      // 0 => Evolution croissante, 1 => Evolution décroissante

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
            }
            // Tri décroissant
            else if ((ordre_des_donnees == 1) && (tab[count] < tab[count + 1]))
            {
                // Si la première valeur est plus petite, on inverse les deux
                inversion(tab, count + 1, count);
            }
            // Incrémentation du compteur
            count = count + 1;
        }
        // Partie décroissante
        else
        {
            if ((ordre_des_donnees == 0) && (tab[count - 1] > tab[count]))
            {
                // Si la valeur en dessous est plus grande, on inverse les deux
                inversion(tab, count - 1, count);
            }
            else if ((ordre_des_donnees == 1) && (tab[count - 1]) < tab[count])
            {
                // Si la valeur en dessous est plus petite, on inverse les deux
                inversion(tab, count, count - 1);
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
        //printf("Min : %d \t Max : %d \t Count : %d \t order : %d \n", indMin, indMax, count, order);
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