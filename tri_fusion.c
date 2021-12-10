#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 10
typedef int typeTab[MAX];

int main()
{
    typeTab tablo = {3, 6, 54, 23, 56, 18, 99, 0, 67, 78};
}

//procedure de tri fusion:
void tri_fusion(typeTab tablo, int deb, int fin, int millieu)
{
    typeTab autreTablo;
    int i, j;        //compteurs pour les deux tableaux
    int deb;         //Indice du début d'un tableau
    int fin;         //Indice de fin d'un tableau
    int millieu;     //Indice du milleiu d'un tableau
    bool estTrie;    //Vérifie si la première partie partie du tableau est triée
    int nbrElements; //Nombre d'éléments d'un tableau
    deb = 0;
    fin = MAX - 1;
    millieu = (deb + fin)/2;
    if ((fin - deb) == 2)
    {
        if (t[i] < t[i-1])
        {
            echange(autreTablo, i);
        }
    }
    else
    {
        tri_fusion(autreTablo, deb, fin, millieu);
    }
}

//tri récursif d'un tableau
void tri_recursif(typeTab t)
{

}

//echange de deux valeurs:
void echange(typeTab t, int i)
{
    int temp; //variable temporaire de stockage
    temp = t[i-1];
    t[i-1] = t[i];
    t[i] = temp;
}

