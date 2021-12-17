#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAB_MAX 20

typedef int tableau[TAB_MAX];
typedef char tableauchar[TAB_MAX];
typedef char tableaustring[TAB_MAX][11];

void creationTableauAlea(tableau);
void convertToChar(tableau, tableauchar);
void afficherInt(tableau);
void afficherChar(tableauchar);
void concatenateChar(tableauchar, tableaustring);

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
    for (int i = 0; i < TAB_MAX; i++)
    {
        printf("%s", tab[i]);
        printf("\n");
    }
    printf("\n");
}
void concatenateChar(tableauchar tabchar, tableaustring tabstring)
{
    // Génération d'un chiffre
    int nb;
    int pointeur;
    int count;
    int j;
    count = 0;
    pointeur = 0;
    for (int i = 0; i < TAB_MAX; i++)
    {
        do
        {
            nb = rand() % 10;
        } while (nb < 5);
        for (j = pointeur; j < pointeur + nb; j++)
        {
            tabstring[count][strlen(tabstring[count])] = tabchar[j];
        }
        count = count + 1;
    }
}

int main()
{
    tableau tab;
    tableauchar tabchar;
    tableaustring tabstring;
    creationTableauAlea(tab);
    convertToChar(tab, tabchar);
    afficherInt(tab);
    afficherChar(tabchar);
    concatenateChar(tabchar, tabstring);
    afficherString(tabstring);
    return EXIT_SUCCESS;
}
