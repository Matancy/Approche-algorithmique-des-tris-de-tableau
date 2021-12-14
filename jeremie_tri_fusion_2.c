#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TAB_MAX 500000

typedef int tableau[TAB_MAX];

void remplirAlea(tableau t);
void afficherTableau(tableau t);
void tri_fusion(tableau t, int deb, int fin, int millieu);
void echange(tableau t);
void fusionner(tableau t, tableau u, int deb, int fin, int millieu);

int main()
{
    int deb;
    int fin;
    int millieu;
    tableau t;
    remplirAlea(t);
    printf("Tableau initial:n");
    afficherTableau(t);
    tri_fusion(t, deb, fin, millieu);
    printf("tableau final:\n");
    return EXIT_SUCCESS;
}

//tri fusion
//pour le tri fusion, pour diviser, il faut prendre fin = millieu + 1 ou deb = millieu - 1, peu importe. On a pas besion de savoir où est-ce que l'on est dans la procédure de découpage 
void tri_fusion(tableau t, int deb, int fin, int millieu)
{
    tableau t; //tableau principal
    tableau u; //tableau pour faire l'échange
    millieu = (deb + fin)/2;
    if ((fin - deb) >= 1)
    {
        deb = millieu + 1;
        tri_fusion(t, deb, fin, millieu);
    }
    else if (((fin - deb) != 0) || ((fin -deb) == 1))
    {
        fusionner(t, u, deb, fin, millieu);
    }
}


//fusionner les parties d'un tableau
void fusionner(tableau t, tableau u, int deb, int fin, int millieu)
{
    int i;
    int j = 0;
    int k; //variable qui stocke l'indice i
    int l; //variable qui peut stocker l'indice j
    int temp; //variable temporaire pour faire un echange
    bool plusGrand = false; //devient vrai quand on a trouvé un élément plus petit dans la partie droite
    for (i=deb; i < fin; i++)
    {
        u[i] = t[i];
    }
    for (i=millieu + 1; i < fin; i++)//on parcours la partie droite
    {
    
        do //on parcours la partie de gauche
        {
            if (u[i] < u[j]) //si l'element de la partie droite est plus petit que l'élément de la partie gauche
            {
                k = i; //on stocke l'indice i pour ne pas l'écraser
                while (u[j] > u[i]) 
                {
                    l = j; //Stockage l'indice de l'élément supérieur
                    t[l] = u[i]; //On met dans le tableau principal, à la place de l'élément supérieur, la valeur qui est inférieure
                    k++; //On passe à l'éléent suivant dans la partie droite du deuxième tableau
                    l++; //On passe à l'indice suivant dans le tableau principal
                    plusGrand = true;
                    t[l] = u[j];
                }
                j = 0;
            }
            j++;
        }while((plusGrand) && (j < millieu));
    }
    
} 

//Remplir un tableau avec des valeurs aléatoires
void remplirAlea(tableau t)
{
    int i;
    for (i = 0; i < TAB_MAX; i++)
    {
        t[i] = rand() % RAND_MAX;
    }
}

//afficher un tableau remplit de valeurs aléatoires
void afficherTableau(tableau t)
{
    int i;
    for (i = 0; i < TAB_MAX; i++)
    {
        printf("%d\n\n", t[i]);
    }
}



