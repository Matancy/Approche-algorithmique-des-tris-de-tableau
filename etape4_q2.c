#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Taille maximale des tableaux d'entiers et de caracteres.
#define TAB_MAX 500000
// Taille maximale du tableau de chaines de caractères.
// La taille est de 10 car le premier tableau d'entiers donne, après convertion, un tableau d'environ 50 carractères qui donne, après concaténation, un tableau de 10 chaînes de caractères.
// Les caractères sont concaténés entre eux pour donner des chaînes dont la taille est comprise entre 5 et 10. Ce qui donne un tableau de 10 carractères au minimum.
#define TAB_STRING 50000 // Erreur de segmentation quand TAB_STRING = 150000

typedef int tableau[TAB_MAX];
typedef char tableauchar[TAB_MAX];
typedef char tableaustring[TAB_STRING][11];

void afficher(tableau);
void creationTableauAlea(tableau);
void init(tableaustring);
void convertToChar(tableau, tableauchar);
void afficherString(tableaustring);
void concatenateChar(tableauchar, tableaustring);
void copierTableau(tableaustring, tableaustring);

void tri_shaker(tableaustring, int, unsigned long *, unsigned long *);
void tri_rapide(tableaustring, int, int, int, unsigned long *, unsigned long *);  
void tri_insertion(tableaustring, int, unsigned long *, unsigned long *);

int main()
{
    srand(time(NULL)); // Définition pour la fonction aléatoire
    tableau tab;
    tableauchar tabchar;
    tableaustring tabstringInit, tabstringInsert, tabstringShaker, tabstringRapide;

    int ordre;          // Croissant : 0; Décroissant : 1
    double temps;       // Temps cpu du tri
    unsigned long nbComparaison;  // Nombre de comparaisons
    unsigned long nbPermutation; // Nombre de permutations

    nbComparaison = 0;
    nbPermutation = 0;

    init(tabstringInit);                     // Initialisation d'un tableau de chaînes de caractères
    creationTableauAlea(tab);            // Création d'un tableau d'entiers
    convertToChar(tab, tabchar);         // Création d'un tableau de carractères compris entre a et z, à partir du tableu d'entiers
    concatenateChar(tabchar, tabstringInit); // Création d'un tableau de chaînes de carractères
    copierTableau(tabstringInit, tabstringInsert); // Copie de tabStringInit dans tabstringInsert
    copierTableau(tabstringInit, tabstringShaker); // Copie de tabstringInit dans tabstringShaker
    copierTableau(tabstringInit, tabstringRapide); // Copie de tabstringInit dans tabstringRapide

    /**************************************
                TRI PAR INSERTION
     **************************************/
    printf("\n\n\tTRI PAR INSERTION\n\n");

    /* CAS NORMAL */
    printf("Cas normal:\n\n");
    clock_t begin = clock(); // Enregistrement de l'heure de début
    tri_insertion(tabstringInsert, 0, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    clock_t end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n\n\n", nbPermutation);

    nbComparaison = 0; // Initialisation de nbComparaison
    nbPermutation = 0; // Initialisation de nbPermutation
    // CAS FAVORABLE 
    printf("Cas favorable:\n\n");
    begin = clock(); // Enregistrement de l'heure de début
    tri_insertion(tabstringInsert, 0, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);

    nbComparaison = 0; // Initialisation de nbComparaison
    nbPermutation = 0; // Initialisation de nbPermutation
    // CAS DÉFAVORABLE
    printf("Cas défavorable:\n\n");
    tri_rapide(tabstringInsert, 1, TAB_MAX, 0, &nbComparaison, &nbPermutation); // Tri du tableau par ordre décroissant
    begin = clock(); // Enregistrement de l'heure de début
    tri_insertion(tabstringInsert, 0, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);


    /**************************************
                TRI SHAKER
     **************************************/

    // CAS NORMAL
    nbComparaison = 0; // Initialisation de nbComparaison
    nbPermutation = 0; // Initialisation de nbPermutation
    printf("\n\n\tTRI SHAKER\n\n");
    printf("Cas normal:\n\n");
    begin = clock(); // Enregistrement de l'heure de début
    tri_shaker(tabstringShaker, 0, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);

    // CAS FAVORABLE
    nbComparaison = 0; // Initialisation de nbComparaison
    nbPermutation = 0; // Initialisation de nbPermutation
    printf("\n\n\tTRI SHAKER\n\n");
    printf("Cas favorable:\n\n");
    tri_rapide(tabstringShaker, 0, TAB_MAX, 0, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    begin = clock(); // Enregistrement de l'heure de début
    tri_shaker(tabstringShaker, 0, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);

    // CAS DÉFAVORABLE
    nbComparaison = 0; // Initialisation de nbComparaison
    nbPermutation = 0; // Initialisation de nbPermutation
    printf("\n\n\tTRI SHAKER\n\n");
    printf("Cas défavorable:\n\n");
    tri_rapide(tabstringShaker, 1, TAB_MAX, 0, &nbComparaison, &nbPermutation); // Tri du tableau par ordre décroissant
    begin = clock(); // Enregistrement de l'heure de début
    tri_shaker(tabstringShaker, 0, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);


    /**************************************
                TRI RAPIDE    
     **************************************/
    nbComparaison = 0; // Initialisation de nbComparaison
    nbPermutation = 0; // Initialisation de nbPermutation
    printf("\n\n\tTRI RAPIDE\n\n");
    // CAS NORMAL
    printf("Cas normal:");
    begin = clock(); // Enregistrement de l'heure de début
    tri_rapide(tabstringRapide, 0, ordre, TAB_STRING, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);

    // CAS FAVORABLE
    nbComparaison = 0;
    nbPermutation = 0;
    printf("Cas favorable:");
    begin = clock(); // Enregistrement de l'heure de début
    tri_rapide(tabstringRapide, 0, ordre, TAB_STRING, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);

    // CAS DÉFAVORABLE
    nbComparaison = 0;
    nbPermutation = 0;
    printf("Cas défavorable:");
    tri_rapide(tabstringRapide, 1, ordre, TAB_STRING, &nbComparaison, &nbPermutation); // Tri du tableau par ordre décroissant
    begin = clock(); // Enregistrement de l'heure de début
    tri_rapide(tabstringRapide, 0, ordre, TAB_STRING, &nbComparaison, &nbPermutation); // Tri du tableau par ordre croissant
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutation);
    return EXIT_SUCCESS;
}

// Affichage d'un tableau de chaînes de carractères
void afficherString(tableaustring tab)
{
    for (int i = 0; i < TAB_STRING; i++)
    {
        if (strcmp(tab[i], "          ") != 0)
        {
            printf("%s", tab[i]);
            printf("\n");
        }
    }
}

// Fonction de remplissage aléatoire
void creationTableauAlea(tableau tab)
{
    for (int i = 0; i < TAB_MAX; i++)
    {
        int nb;
        do
        {
            nb = rand() % 122;
        } while (nb < 97);
        tab[i] = nb;
    }
}

void convertToChar(tableau tab, tableauchar tabchar)
{
    for (int i = 0; i < TAB_MAX; i++)
    {
        tabchar[i] = tab[i];
    }
}

void concatenateChar(tableauchar tabchar, tableaustring tabstring)
{
    // Génération d'un chiffre
    int nb;
    int pointeur;
    int count;
    int j;
    int ind;
    count = 0;
    pointeur = 0;
    ind = 0;
    for (int i = 0; i < TAB_MAX; i++)
    {
        do
        {
            nb = rand() % 10;
        } while (nb < 5);

        ind = 0;
        if ((pointeur + nb) > TAB_MAX)
        {
            for (int j = pointeur; j < TAB_MAX; j++)
            {
                tabstring[count][ind] = tabchar[j];
                ind = ind + 1;
            }
        }
        else
        {
            for (j = pointeur; j < (pointeur + nb); j++)
            {
                tabstring[count][ind] = tabchar[j];
                ind = ind + 1;
            }
        }
        pointeur = pointeur + nb;
        count = count + 1;
    }
}
//
// Fonctions communes aux trois tris
//

// Fonction pour remplir les cases vides d'un tableau par des espaces
void init(tableaustring tabstring)
{
    for (int i = 0; i < TAB_STRING; i++)
    {
        strcpy(tabstring[i], "          ");
    }
}
// Copier un tableau dans un autre tableau
void copierTableau(tableaustring destination, tableaustring source)
{
    int i;
    for (i = 0; i < TAB_STRING; i++)
    {
        strcpy(destination[i], source[i]); // Copie de destination dans source
    }
}
// Inversion de deux valeurs
void inversion(tableaustring tab, int val1, int val2)
{
    char tmp[11];
    strcpy(tmp, tab[val2]);
    strcpy(tab[val2], tab[val1]);
    strcpy(tab[val1], tmp);
}
// Permutation de deux éléments
void permutation(tableaustring tab, int a, int b)
{
    char tmp[11];
    strcpy(tmp, tab[a]);
    strcpy(tab[a], tab[b]);
    strcpy(tab[b], tmp);
}

//
// Tris
// 
void tri_shaker(tableaustring tab, int ordre_des_donnees, unsigned long *nbrCompare, unsigned long *nbrInverse)
{
    int indMin, indMax, count, order;
    indMin = 0;              // Indice du min trié dans le tableau
    indMax = TAB_STRING - 1; // Indice du max trié dans le tableau
    count = 0;               // Compteur
    order = 0;               // 0 => Evolution croissante, 1 => Evolution décroissante
    int comparaison;         // Négatif quand le premier élément du strcmp est supérieur au second, positif dans le cas inverse et nul sinon
    while ((indMax - indMin) != 0) // Tant que l'écart entre le minimum et le max est différent de 0 (soit tableau trié)
    {
        // Partie croissante
        if (order == 0)
        {
            // Tri croissant
            if (ordre_des_donnees == 0)
            {
                comparaison = strcmp(tab[count], tab[count + 1]);
                *nbrCompare = *nbrCompare + 1;
                if (comparaison > 0)
                {
                    // Si la première valeur est plus grande, on inverse les deux
                    inversion(tab, count, count + 1);
                    *nbrInverse = *nbrInverse + 1;
                }
            }
            // Tri décroissant
            else if (ordre_des_donnees == 1)
            {
                comparaison = strcmp(tab[count], tab[count + 1]);
                *nbrCompare = *nbrCompare + 1;
                if (comparaison < 0)
                {
                    // Si la première valeur est plus petite, on inverse les deux
                    inversion(tab, count + 1, count);
                    *nbrInverse = *nbrInverse + 1;
                }
            }
            // Incrémentation du compteur
            count = count + 1;
        }
        // Partie décroissante
        else
        {
            // Tri croissant
            if (ordre_des_donnees == 0)
            {
                comparaison = strcmp(tab[count - 1], tab[count]);
                *nbrCompare = *nbrCompare + 1;
                if (comparaison > 0)
                {
                    // Si la valeur en dessous est plus grande, on inverse les deux
                    inversion(tab, count - 1, count);
                    *nbrInverse = *nbrInverse + 1;
                }
            }
            // Tri décroissant
            else if (ordre_des_donnees == 1)
            {
                comparaison = strcmp(tab[count - 1], tab[count]);
                *nbrCompare = *nbrCompare + 1;
                if (comparaison < 0)
                {
                    // Si la valeur en dessous est plus petite, on inverse les deux
                    inversion(tab, count, count - 1);
                    nbrInverse = nbrInverse + 1;
                }
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
    }
}
void tri_rapide(tableaustring tab, int debut, int fin, int ordre, unsigned long *nbrCompare, unsigned long *nbrInverse)
{
    int comparaison; // Négatif quand le premier élément du strcmp est supérieur au second, positif dans le cas inverse et nul sinon
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
                comparaison = strcmp(tab[i], tab[pivot]);
                *nbrCompare = *nbrCompare + 1;
                while (((comparaison < 0) || (comparaison == 0)) && (i < fin))
                {
                    i++;
                    comparaison = strcmp(tab[i], tab[pivot]);
                }
                // Approche juste avant le pivot
                comparaison = strcmp(tab[j], tab[pivot]);
                *nbrCompare = *nbrCompare + 1;
                while (comparaison > 0)
                {
                    j--;
                    comparaison = strcmp(tab[j], tab[pivot]);
                }
            }
            // Ordre décroissant
            else
            {
                // Approche jusqu'au pivot
                comparaison = strcmp(tab[i], tab[pivot]);
                *nbrCompare = *nbrCompare + 1;
                while (((comparaison > 0) || (comparaison == 0)) && (i < fin))
                {
                    i++;
                    comparaison = strcmp(tab[i], tab[pivot]);
                }

                // Approche juste avant le pivot
                comparaison = strcmp(tab[j], tab[pivot]);
                *nbrCompare = *nbrCompare + 1;
                while (comparaison < 0)
                {
                    j--;
                    comparaison = strcmp(tab[j], tab[pivot]);
                }
            }
            if (i < j)
            {
                permutation(tab, i, j);
                *nbrInverse = *nbrInverse + 1;
            }
        }
        permutation(tab, pivot, j);
        *nbrInverse = *nbrInverse + 1;
        tri_rapide(tab, debut, j - 1, ordre, nbrCompare, nbrInverse);
        tri_rapide(tab, j + 1, fin, ordre, nbrCompare, nbrInverse);
    }
}
void tri_insertion(tableaustring t, int ordre, unsigned long *nbComparaison, unsigned long *nbPermutation)
{
    int comparaison; // Négatif quand le premier élément du strcmp est supérieur au second, positif dans le cas inverse et nul sinon
    int i;
    int j;
    char temp[11]; // Variable temporaire pour faire un échange
    for (i = 1; i < TAB_STRING; i++)
    {
        j = i;
        // Ordre croissant
        if (ordre == 0)
        {
            comparaison = strcmp(t[i], t[i - 1]);
            *nbComparaison = *nbComparaison + 1;
            if (comparaison < 0) // Si t[i] est inférieur à t[i - 1]
            {
                while ((comparaison < 0) && (j > 0))
                {
                    strcpy(temp, t[j - 1]);
                    strcpy(t[j - 1], t[j]);
                    strcpy(t[j], temp);
                    *nbPermutation = *nbPermutation + 1;
                    j--;
                    comparaison = strcmp(t[j], t[j - 1]);
                    *nbComparaison = *nbComparaison + 1;
                }
            }
        }
        // Ordre décroissant
        else if (ordre == 1)
        {
            comparaison = strcmp(t[i - 1], t[i]);
            *nbComparaison = *nbComparaison + 1;
            if (comparaison < 0) // Si t[i - 1] est inférieur à t[i]
            {
                while ((comparaison < 0) && (j > 0))
                {
                    strcpy(temp, t[j]);
                    strcpy(t[j], t[j - 1]);
                    strcpy(t[j - 1], temp);
                    *nbPermutation = *nbPermutation + 1;
                    j--;
                    comparaison = strcmp(t[j - 1], t[j]);
                    *nbComparaison = *nbComparaison + 1;
                }
            }
        }
        else
        {
            *nbComparaison = *nbComparaison + 1;
        }
    }
}