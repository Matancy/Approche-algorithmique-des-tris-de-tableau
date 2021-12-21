#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define TAB_MAX 1000
#define TAB_STRING 200

typedef int tableau[TAB_MAX];
typedef char tableauchar[TAB_MAX];
typedef char tableaustring[TAB_STRING][11];

void creationTableauAlea(tableau);
void convertToChar(tableau, tableauchar);
void afficherInt(tableau);
void afficherChar(tableauchar);
void afficherString(tableaustring);
void concatenateChar(tableauchar, tableaustring);
void init(tableaustring);

int main()
{
    srand(time(NULL)); // Définition pour la fonction aléatoire

    tableau tab;
    tableauchar tabchar;
    tableaustring tabstring;
    creationTableauAlea(tab);
    convertToChar(tab, tabchar);
    afficherInt(tab);
    afficherChar(tabchar);
    init(tabstring);
    concatenateChar(tabchar, tabstring);
    afficherString(tabstring);
    return EXIT_SUCCESS;
}

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
void afficherInt(tableau tab)
{
    for (int i = 0; i < TAB_MAX; i++)
    {
        printf("%d", tab[i]);
    }
    printf("\n");
}
void afficherChar(tableauchar tab)
{
    for (int i = 0; i < TAB_MAX; i++)
    {
        printf("%c", tab[i]);
    }
    printf("\n");
}
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
            for (int j = pointeur; j < (TAB_MAX - pointeur); j++)
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
void init(tableaustring tabstring)
{
    for (int i = 0; i < TAB_STRING; i++)
    {
        strcpy(tabstring[i], "          ");
    }
}
