#include <stdlib.h>
#include <stdio.h>
#define TAB_MAX 20

typedef int tableau[TAB_MAX];
typedef char tableauchar[TAB_MAX];
typedef char tableaustring[TAB_MAX][11];

void creationTableauAlea(tableau);
void convertToChar(tableau, tableauchar);
void afficherInt(tableau);
void afficherChar(tableauchar);
void concatenateChar(tablleauchar, tableaustring);

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

int main()
{
    tableau tab;
    tableauchar tabchar;
    tableaustring tabstring;
    creationTableauAlea(tab);
    convertToChar(tab, tabchar);
    afficherInt(tab);
    afficherChar(tabchar);
    return EXIT_SUCCESS;
}
