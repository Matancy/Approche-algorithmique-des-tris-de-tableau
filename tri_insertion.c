#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#define TAB_MAX 1000
#define TAB_STRING 200


typedef int tableau[TAB_MAX];
typedef char tableauchar[TAB_MAX];
typedef char tableaustring[TAB_STRING][11];

void tri_insertion(tableauchar, int);
void afficher(tableau);
void creationTableauAlea(tableau tab);
void init(tableaustring tabstring);
void convertToChar(tableau tab, tableauchar tabchar);
void afficherString(tableaustring tab);
void concatenateChar(tableauchar tabchar, tableaustring tabstring);




int main()
{
    // tableau favorable = {1, 3, 5, 6, 8, 9, 12, 34, 56, 78};
    // tableau nonfavorable = {78, 56, 34, 12, 9, 8, 6, 5, 3, 1};
    // tableau normal = {12, 45, 2, 4, 23, 90, 65, 45, 99, 19};
    tableau tab;
    tableauchar tabchar;
    tableaustring tabstring;

    int ordre; // Croissant : 0, Décroissant : 1

    printf("Entrez l'ordre de tri :\n");
    printf("\t0 - Croissant\n");
    printf("\t1 - Decroissant\n\n");
    scanf("%d", &ordre);

    creationTableauAlea(tab); //création d'un tableau d'entiers 
    convertToChar(tab, tabchar); //Création d'un tableau de carractères compris entre a et z, à partir du tableu d'entiers
    concatenateChar(tabchar, tabstring); //création d'un tableau de chaînes de carractères 
    printf("Tableau initial : \n");
    afficherString(tabstring);
    tri_insertion(tabstring, ordre);
    printf("Tableau trie : \n");
    afficherString(tabstring);

    // printf("Tableau favorable :\n");
    // afficher(favorable);
    // tri_insertion(favorable, ordre);
    // printf("Tableau trie :\n");
    // afficher(favorable);
    // printf("\n\n");

    // printf("Tableau non favorable :\n");
    // afficher(nonfavorable);
    // tri_insertion(nonfavorable, ordre);
    // printf("Tableau trie :\n");
    // afficher(nonfavorable);
    // printf("\n\n");

    // printf("Tableau normal :\n");
    // afficher(normal);
    // tri_insertion(normal, ordre);
    // printf("Tableau trie :\n");
    // afficher(normal);
    // printf("\n\n");

    return EXIT_SUCCESS;
}

// Tri par insertion des tableaux
void tri_insertion(tableauchar t, int ordre)
{
    int i;
    int j;
    char temp[11]; //variable temporaire pour faire un échange
    for (i = 1; i < TAB_MAX; i++)
    {
        j = i;
        // Ordre croissant
        if ((ordre == 0) && (strcmp(t[i], t[i - 1] == -1)))
        {
            while ((strcmp(t[i], t[i - 1] == -1)) && (j != 0))
            {
                strcpy(temp, t[j - 1]);
                strcpy(t[j - 1], t[j]);
                strcpy(t[j], temp);
                strcpy(j, j - 1);
            }
        }
        // Ordre décroissant
        else if ((ordre == 1) && (strcmp(t[i - 1], t[i]) == -1))
        {
            while ((strcmp(t[j - 1], t[j]) == -1) && (j != 0))
            {
                strcpy(temp, t[j]);
                strcpy(t[j], t[j - 1]);
                strcpy(t[j - 1], temp);
                j = j - 1;
            }
        }
    }
}

//Affichage d'un tableau de chaînes de carractères
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

//fonction pour remplir les cases vides d'un tableau par des espaces
void init(tableaustring tabstring)
{
    for (int i = 0; i < TAB_STRING; i++)
    {
        strcpy(tabstring[i], "          ");
    }
}