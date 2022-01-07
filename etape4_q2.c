#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tri_shaker.c"
#include "tri_rapide.c"
#include "tri_insertion.c"

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
void copierTableau(tableaustring t, tableaustring u);

int main()
{
    // tableau favorable = {1, 3, 5, 6, 8, 9, 12, 34, 56, 78};
    // tableau nonfavorable = {78, 56, 34, 12, 9, 8, 6, 5, 3, 1};
    // tableau normal = {12, 45, 2, 4, 23, 90, 65, 45, 99, 19};
    srand(time(NULL)); // Définition pour la fonction aléatoire
    tableau tab;
    tableauchar tabchar;
    tableaustring tabstring, tabstring1, tabstring2, tabstring3;

    int ordre;          // Croissant : 0; Décroissant : 1
    double temps;       // Temps cpu du tri
    unsigned long nbComparaison;  // Nombre de comparaisons
    unsigned long nbPermutations; // Nombre de permutations

    nbComparaison = 0;
    nbPermutations = 0;

    printf("Entrez l'ordre de tri :\n");
    printf("\t0 - Croissant\n");
    printf("\t1 - Decroissant\n\n");
    scanf("%d", &ordre);

    init(tabstring1);                     // Initialisation d'un tableau de chaînes de caractères
    creationTableauAlea(tab);            // Création d'un tableau d'entiers
    convertToChar(tab, tabchar);         // Création d'un tableau de carractères compris entre a et z, à partir du tableu d'entiers
    concatenateChar(tabchar, tabstring); // Création d'un tableau de chaînes de carractères
    copierTableau(tabstring, tabstring1);
    copierTableau(tabstring, tabstring2);
    copierTableau(tabstring, tabstring3);
    
    /**************************************
                TRI INSERTION
     **************************************/
    printf("\n\n\tTRI PAR INSERTION\n\n");
    //printf("\nTableau initial : \n\n");
    //afficherString(tabstring);

    clock_t begin = clock(); // Enregistrement de l'heure de début
    tri_insertion(tabstring1, ordre, &nbComparaison, &nbPermutations);
    clock_t end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    //printf("\nTableau trié : \n\n");
    // afficherString(tabstring);
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutations);


    /**************************************
                TRI SHAKER
     **************************************/
    printf("\n\n\tTRI SHAKER\n\n");
     begin = clock(); // Enregistrement de l'heure de début
    tri_shaker(tabstring2, ordre, &nbComparaison, &nbPermutations);
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutations);


    /**************************************
                TRI RAPIDE    
     **************************************/
    printf("\n\n\tTRI RAPIDE\n\n");
    begin = clock(); // Enregistrement de l'heure de début
    tri_rapide(tabstring3, 0, ordre, TAB_STRING, &nbComparaison, &nbPermutations);
    end = clock();   // Enregistrement de l'heure de fin
    temps = (double)(end - begin) / CLOCKS_PER_SEC; // Calcul de la différence entre l'heure de début et l'heure de fin
    printf("Temps cpu du tri: %f sec \n", temps);
    printf("Nombre de comparaisons : %lu \n", nbComparaison);
    printf("Nombre de permutations : %lu \n", nbPermutations);
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

// Fonction pour remplir les cases vides d'un tableau par des espaces
void init(tableaustring tabstring)
{
    for (int i = 0; i < TAB_STRING; i++)
    {
        strcpy(tabstring[i], "          ");
    }
}

// Copier un tableau dans un autre tableau
void copierTableau(tableaustring t, tableaustring u)
{
    int i;
    for (i = 0; i < TAB_STRING; i++)
    {
        strcpy(u[i], t[i]); 
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