#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 500000 // Nombre d'entiers à génerer

typedef int tableau[MAX];

void afficher(tableau);
void creationTableauAlea(tableau, int);
void copierTableau(tableau, tableau);

void tri_shaker(tableau, int, unsigned long *, unsigned long *);
void tri_rapide(tableau, int, int, int, unsigned long *, unsigned long *);
void tri_insertion(tableau, int, unsigned long *, unsigned long *);

int main()
{
    srand(time(NULL)); // Définition pour la fonction aléatoire
    tableau tabnormal1;
    tableau tabnormal2;
    tableau tabnormal3;
    tableau tabfavorable1;
    tableau tabfavorable2;
    tableau tabfavorable3;
    tableau tabdefavorable1;
    tableau tabdefavorable2;
    tableau tabdefavorable3;

    double temps;                // Temps cpu du tri
    unsigned long nbComparaison; // Nombre de comparaisons
    unsigned long nbPermutation; // Nombre de permutations

    nbComparaison = 0;
    nbPermutation = 0;

    // Cas normal
    creationTableauAlea(tabnormal1, MAX);
    copierTableau(tabnormal1, tabnormal2);
    copierTableau(tabnormal1, tabnormal3);

    // Cas favorable
    tri_rapide(tabfavorable1, 0, MAX, 0, &nbComparaison, &nbPermutation);
    copierTableau(tabfavorable1, tabfavorable2);
    copierTableau(tabfavorable1, tabfavorable3);

    // Cas défavorable
    tri_rapide(tabdefavorable1, 0, MAX, 1, &nbComparaison, &nbPermutation);
    copierTableau(tabdefavorable1, tabdefavorable2);
    copierTableau(tabdefavorable1, tabdefavorable3);

    /**************************************
                TRI INSERTION
     **************************************/
    printf("\n\n\tTRI PAR INSERTION - Cas normal - Desordre => Croissant\n\n");

    clock_t begin = clock(); // Enregistrement de l'heure de début
    tri_insertion(tabnormal1, 0, &nbComparaison, &nbPermutation);
    clock_t end = clock();                          // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin

    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    nbComparaison = 0;
    nbPermutation = 0;

    printf("\n\n\tTRI PAR INSERTION - Cas favorable - Croissant => Croissant\n\n");

    begin = clock(); // Enregistrement de l'heure de début
    tri_insertion(tabfavorable1, 0, &nbComparaison, &nbPermutation);
    end = clock();                          // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin

    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    nbComparaison = 0;
    nbPermutation = 0;

    printf("\n\n\tTRI PAR INSERTION - Cas défavorable - Decroissant => Croissant\n\n");

    begin = clock(); // Enregistrement de l'heure de début
    tri_insertion(tabdefavorable1, 0, &nbComparaison, &nbPermutation);
    end = clock();                          // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin

    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    nbComparaison = 0;
    nbPermutation = 0;

    /**************************************
                TRI SHAKER
     **************************************/
    printf("\n\n\tTRI SHAKER - Cas normal - Desordre => Croissant\n\n");

    begin = clock(); // Enregistrement de l'heure de début
    tri_shaker(tabnormal2, 0, &nbComparaison, &nbPermutation);
    end = clock();                                  // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin

    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    nbComparaison = 0;
    nbPermutation = 0;

    printf("\n\n\tTRI SHAKER - Cas favorable - Croissant => Croissant\n\n");

    begin = clock(); // Enregistrement de l'heure de début
    tri_shaker(tabfavorable2, 0, &nbComparaison, &nbPermutation);
    end = clock();                                  // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    nbComparaison = 0;
    nbPermutation = 0;

    printf("\n\n\tTRI SHAKER - Cas defavorable - Decroissant => Croissant\n\n");

    begin = clock(); // Enregistrement de l'heure de début
    tri_shaker(tabnormal2, 1, &nbComparaison, &nbPermutation);
    end = clock();                                  // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    nbComparaison = 0;
    nbPermutation = 0;

    /**************************************
                TRI RAPIDE    
     **************************************/
    printf("\n\n\tTRI RAPIDE - Cas normal - Desordre => Croissant\n\n");

    begin = clock(); // Enregistrement de l'heure de début
    tri_rapide(tabnormal3, 0, MAX, 0, &nbComparaison, &nbPermutation);
    end = clock();                                  // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin

    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    nbComparaison = 0;
    nbPermutation = 0;

    printf("\n\n\tTRI RAPIDE - Cas favorable - Croissant => Croissant\n\n");

    begin = clock(); // Enregistrement de l'heure de début
    tri_rapide(tabfavorable3, 0, MAX, 0, &nbComparaison, &nbPermutation);
    end = clock();                                  // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin

    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    nbComparaison = 0;
    nbPermutation = 0;

    printf("\n\n\tTRI RAPIDE - Cas defavorable - Decroissant => Croissant\n\n");

    begin = clock(); // Enregistrement de l'heure de début
    tri_rapide(tabdefavorable3, 0, MAX, 0, &nbComparaison, &nbPermutation);
    end = clock();                                  // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin

    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    nbComparaison = 0;
    nbPermutation = 0;
    return EXIT_SUCCESS;
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
// Copier un tableau dans un autre tableau
void copierTableau(tableau t, tableau u)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        u[i] = t[i];
    }
}

//
// Tris
//
void tri_shaker(tableau tab, int ordre_des_donnees, unsigned long *nbComparaison, unsigned long *nbPermutation)
{
    int indMin, indMax, count, order;
    indMin = 0;           // Indice du min trié dans le tableau
    indMax = MAX - 1; // Indice du max trié dans le tableau
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
                    i = i + 1;
                    *nbComparaison = *nbComparaison + 1;
                }
                *nbComparaison = *nbComparaison + 1;

                // Approche juste avant le pivot
                while (tab[j] > tab[pivot])
                {
                    j = j - 1;
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
                    i = i + 1;
                    *nbComparaison = *nbComparaison + 1;
                }
                *nbComparaison = *nbComparaison + 1;

                // Approche juste avant le pivot
                while (tab[j] < tab[pivot])
                {
                    j = j - 1;
                    *nbComparaison = *nbComparaison + 1;
                }
                *nbComparaison = *nbComparaison + 1;
            }
            if (i < j)
            {
                inversion(tab, i, j);
                *nbPermutation = *nbPermutation + 1;
            }
        }

        inversion(tab, pivot, j);
        *nbPermutation = *nbPermutation + 1;
        tri_rapide(tab, debut, j - 1, ordre, nbComparaison, nbPermutation);
        tri_rapide(tab, j + 1, fin, ordre, nbComparaison, nbPermutation);
    }
}
void tri_insertion(tableau t, int ordre, unsigned long *nbComparaison, unsigned long *nbPermutation)
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
                *nbComparaison = *nbComparaison + 1;
                *nbPermutation = *nbPermutation + 1;
            }
            *nbComparaison = *nbComparaison + 1;
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
                *nbComparaison = *nbComparaison + 1;
                *nbPermutation = *nbPermutation + 1;
            }
            *nbComparaison = *nbComparaison + 1;
        }
        else
        {
            *nbComparaison = *nbComparaison + 1;
        }
    }
}