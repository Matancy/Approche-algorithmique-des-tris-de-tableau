#include <stdlib.h>
#include <stdio.h>

void tri_insertion_permutation(typeTab t);
void tri_insertion_decalage(typeTab t);
#define MAX 10
typedef int typeTab[10];
int main()
{
    int choixOrdre; //Sert à définir l'ordre dans lequel l'utilisateur veut trier son tableau
    int choixTri;   //Sert à définir quel tri l'utilisateur souhaite utiliser
    typeTab t = {54, 50, 21, 12, 76, 23, 78, 1, 0, 56};
    printf("Dans quel ordre voulez-vous trier votre tableau:\n");
    printf("\t1 - Tri par insertion avec permutations successives\n");
    printf("\t2 - Tri par insertion avec décalage à droite puis insertion\n\n");
    scanf("%d", choixOrdre);
    switch (choixOrdre)
    {
    case 1:

        break;

    default:
        break;
    }
    printf("Indiquez le tri que vous souhaitez utiliser pour trier votre tableau (1 ou 2):\n");
    printf("\t1 - Tri par insertion avec permutations successives\n");
    printf("\t2 - Tri par insertion avec décalage à droite puis insertion\n");
    scanf("%d", &choixTri);
    switch (choixTri)
    {
    case 1:
        tri_insertion_permutation();
        break;
    case 2:
        tri_insertion_decalage();
        break;
    }
}

void tri_insertion_permutation(typeTab t)
{
    int i;
    int j;
    int temp; //variable temporaire pour faire un échange
    for (i = 1; i < MAX; i++)
    {
        j = i;
        if (t[i] < t[i - 1])
        {
            while (t[j] < t[j - 1])
            {
                temp = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp;
                j = j - 1;
            }
            j = i;
        }
    }
    for (i = 0; i < MAX; i++)
    {
        printf("%d", t[i]);
    }
    return EXIT_SUCCESS;
}

void tri_insertion_decalage(typeTab t)
{
    int conserve; //conserve la valeur t[i]
    int i;
    int j;
    for (i=0; i < MAX; i++) //on parcours le tableau à trier
    {
        j = i;
        conserve = t[i];
        do
        {
            if(conserve < t[j])
            {
                t[i] = t[j]; //on met la valeur t[j] dans l'espace libéré
            } 
            j--;
        }while((t[j] > conserve) && (j >= 0));
        t[j] = conserve;
    }
}