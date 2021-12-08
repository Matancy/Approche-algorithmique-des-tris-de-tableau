#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>

#define MAX 10
typedef int typeTab[MAX];

int main()
{
    typeTab tablo = {3,6,54,23,56,18,99,0,67,78};
}


//procedure de tri fusion:
void tri_fusion(typeTab tablo)
{
    typeTab autreTablo;
    int i, j; //compteurs pour les deux tableaux
    int deb; //Indice du début d'un tableau
    int fin; //Indice de fin d'un tableau
    int millieu; //Indice du milleiu d'un tableau
    bool trié; //Vérifie si la première partie partie du tableau est triée
    deb = 0;
    fin = MAX-1;
    while (deb < fin)
    {
        
        millieu = (deb + fin)/2;
        //pour la partie gauche du tableau:
        fin = millieu;
    }
    
}