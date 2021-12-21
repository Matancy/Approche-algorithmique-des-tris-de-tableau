#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TAB_MAX 50

typedef int tableau[TAB_MAX];

void remplirAlea(tableau t);
void afficherTableau(tableau t);
void tri_fusion(tableau t, int deb, int fin);
void echange(tableau t);
void fusionner(tableau t, int deb, int fin, int millieu);

int main()
{
    int deb;
    int fin;
    int millieu;
    deb = 0;
    fin = TAB_MAX - 1;
    tableau t; //tableau principal
    remplirAlea(t);
    printf("Tableau initial");
    afficherTableau(t);
    tri_fusion(t, deb, fin);
    printf("\n\n");
    printf("tableau final:\n");
    afficherTableau(t);
    return EXIT_SUCCESS;
}

//tri fusion
//pour le tri fusion, pour diviser, il faut prendre fin = millieu + 1 ou deb = millieu - 1, peu importe. On a pas besion de savoir où est-ce que l'on est dans la procédure de découpage
void tri_fusion(tableau t, int deb, int fin)
{
    int millieu;
    if (fin > deb)
    {
        millieu = (deb + fin) / 2;
        tri_fusion(t, deb, millieu);
        tri_fusion(t, millieu + 1, fin);
        fusionner(t, deb, millieu, fin);
    }
}

//fusionner les parties d'un tableau
void fusionner(tableau t, int deb, int fin, int millieu)
{
    int u[fin - deb+1]; //tableau pour faire l'échange
    int compt1 = deb; //stocke la position de deb
    int deb2 = fin +1; 
    int compt2 = deb2;//stocke la position de deb2
    int i = 0;
    bool estTrie = true; //devient faux quand le tableau est trié 
    for (i = deb; i <= fin; i++)
    {
        u[i - deb] = t[i];
    }
    while ((i <= millieu) && (estTrie)) //on parcours le tableau de gauche
    {   
        if (deb2 == compt1)
        {
            estTrie = false;
        }
        else if (compt2 == (millieu + 1))
        {
            t[i] = u[compt1 - deb];
            compt1++;
        }
        else if (t[compt2] > u[compt1 - deb])
        {
            t[i] = u[compt1 - deb];
            compt1++;
        }
        else
        {
            t[i] = t[compt2];
            compt2++;
        } 
        i++;
    }
}

//Remplir un tableau avec des valeurs aléatoires
void remplirAlea(tableau t)
{
    int i;
    for (i = 0; i < TAB_MAX; i++)
    {
        t[i] = rand() % 10;
    }
}

//afficher un tableau remplit de valeurs aléatoires
void afficherTableau(tableau t)
{
    int i;
    for (i = 0; i < TAB_MAX; i++)
    {
        printf("%d\t", t[i]);
    }
}

