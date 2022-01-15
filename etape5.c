#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COVID 17776 // Nombre de valeurs du tableau covid
#define MAX_JOURS 31    // Nombre de valeurs du tableau tableau intermédiaire
typedef char chaine11[11];

typedef struct
{
    int dep;
    chaine11 date;
    int pos;
    int classe;
    int pop;
} covid;

typedef covid typeCovid[MAX_COVID];
typedef covid typeIntermediaire[MAX_JOURS];

void lireFichier(typeCovid, int *);
void triDepartement(typeCovid);
void population22(typeCovid, int *);
void triDate(typeCovid);
void DebutAnnee35(typeCovid, typeIntermediaire);
void tri_rapide(typeCovid, int, int, int);
void inversion(typeCovid, int, int, int);

int main()
{
    typeCovid tabCovid;
    typeIntermediaire tabIntermediaire;
    int nbEnregistrements = 0; // Nombre d'enregistrements dans le tableau tabCovid
    int nbHab22 = 0;           // Nombre d'habitants des Côtes d'Armor
    lireFichier(tabCovid, &nbEnregistrements);
    triDepartement(tabCovid);
    population22(tabCovid, &nbHab22);
    triDate(tabCovid);
    DebutAnnee35(tabCovid, tabIntermediaire);
    return EXIT_SUCCESS;
}

// Lire un fichier
void lireFichier(typeCovid tabCovid, int *nbEnregistrements)
{
    FILE *donnees;
    donnees = fopen("DonneesCovid.data.data", "rb");
    fread(&tabCovid[*nbEnregistrements], sizeof(covid), 1, donnees);
    *nbEnregistrements = *nbEnregistrements + 1;
    while (!feof(donnees))
    {
        fread(&tabCovid[*nbEnregistrements], sizeof(covid), 1, donnees);
        *nbEnregistrements = *nbEnregistrements + 1;
    }
    fclose(donnees);
}

// Trier du tableau sur le departement
void triDepartement(typeCovid tabCovid)
{
    printf("Je commence le tri departement!\n\n");
    tri_rapide(tabCovid, 0, MAX_COVID, 0); // Tri seleon le département
}

// Comptage des habitants des Côtes d'Armor
void population22(typeCovid tabCovid, int *nbHab22)
{
    int i;
    for (i = 0; i < MAX_COVID; i++)
    {
        if (tabCovid[i].dep == 22)
        {
            *nbHab22 = *nbHab22 + tabCovid[i].pop;
        }
    }
}

// Tri du tableau sur la date
void triDate(typeCovid tabCovid)
{
    printf("Je commence le tri date !\n\n");
    tri_rapide(tabCovid, 0, MAX_COVID, 1); // Tri selon le département
}

// Affichage des données par tranche d'âge en Ille-et-Vilaine le 1er janvier 2021
void DebutAnnee35(typeCovid tabCovid, typeIntermediaire tabIntermediaire)
{
    bool janvier = false; // Vrai quand on a trouvé le 01/01/2021
    int nbCas = 0;
    int i = 0; // Premier compteur
    int j;     // Deuxième compteur

    // Enregistrement des données du mois de janvier en Ille-et-Vilaine dans un tableau intermédiaire
    printf("Nombre de cas en Ille-et-Vilaine par classe d'âge, le 1er janvier 2021\n\n");
    if (strcmp(tabCovid[i].date, "2021-01-01") == 0)
    {
        printf("Bonjour ! \n");
        janvier = true;
        j = i;
        for (j = 0; j < MAX_JOURS; j++)
        {
            if (tabCovid[j].dep == 35)
            {
                tabIntermediaire[j] = tabCovid[j];
                nbCas = nbCas + tabCovid[j].pos;
            }
        }
    }
    i++;

    // Si le 1er janvier contient des valeurs
    if (janvier)
    {
        // Affichage des données du mois de janvier en Ille-et-Vialine par trabche d'âge
        for (i = 0; i < MAX_JOURS; i++)
        {
            switch (tabIntermediaire[i].classe)
            {
            case (9):
                printf("[0 - 9] : %d", tabIntermediaire[i].pos);
                break;
            case (19):
                printf("[10 - 19] : %d", tabIntermediaire[i].pos);
                break;
            case (29):
                printf("[20 - 29] : %d", tabIntermediaire[i].pos);
                break;
            case (39):
                printf("[30 - 39] : %d", tabIntermediaire[i].pos);
                break;
            case (49):
                printf("[40 - 49] : %d", tabIntermediaire[i].pos);
                break;
            case (59):
                printf("[50 - 59] : %d", tabIntermediaire[i].pos);
                break;
            case (69):
                printf("[60 - 69] : %d", tabIntermediaire[i].pos);
                break;
            case (79):
                printf("[70 - 79] : %d", tabIntermediaire[i].pos);
                break;
            case (89):
                printf("[80 - 89] : %d", tabIntermediaire[i].pos);
                break;
            case (99):
                printf("[90 - 99] : %d", tabIntermediaire[i].pos);
                nbCas = nbCas + tabCovid[i].pos;
                break;
            }
            printf("\n\nTOTAL: %d", nbCas);
        }
    }
    else
    {
        printf("Aucune valeur covid pour le 1er Janvier\n");
    }
}

// Tri rapide
void tri_rapide(typeCovid tabCovid, int debut, int fin, int champ)
{
    int pivot, i, j;
    if (debut < fin)
    {
        pivot = debut;
        i = debut;
        j = fin;
        while (i < j)
        {
            // Tri sur le département
            if (champ == 0)
            {
                // Approche jusqu'au pivot
                while ((tabCovid[i].dep <= tabCovid[pivot].dep) && (i < fin))
                {
                    i = i + 1;
                }
                // Approche juste avant le pivot
                while (tabCovid[j].dep > tabCovid[pivot].dep)
                {
                    j = j - 1;
                }
            }
            // Tri sur la date
            else if (champ == 1)
            {
                // Approche jusqu'au pivot
                while ((tabCovid[i].date <= tabCovid[pivot].date) && (i < fin))
                {
                    i = i + 1;
                }
                // Approche juste avant le pivot
                while (tabCovid[j].date > tabCovid[pivot].date)
                {
                    j = j - 1;
                }
            }

            if (i < j)
            {
                // Inversion selon le département
                if (champ == 0)
                {
                    inversion(tabCovid, i, j, 0);
                }
                // Inversion selon la date
                else if (champ == 1)
                {
                    inversion(tabCovid, i, j, 1);
                }
            }
        }
        // Inversion selon le département
        if ((i < j) && (champ == 0))
        {
            inversion(tabCovid, pivot, j, 0);
        }
        else if ((i < j) && (champ == 1))
        {
            inversion(tabCovid, pivot, j, 1);
        }
        tri_rapide(tabCovid, debut, j - 1, champ);
        tri_rapide(tabCovid, j + 1, fin, champ);
    }
}

// Inversion de deux valeurs
void inversion(typeCovid tab, int val1, int val2, int champ)
{
    int tmpDep;       // Variable d'échange pour le département
    chaine11 tmpDate; // Variable d'échange pour la date
    // Inversion selon le département
    if (champ == 0)
    {
        tmpDep = tab[val2].dep;
        tab[val2].dep = tab[val1].dep;
        tab[val1].dep = tmpDep;
    }
    // Inversion selon la date
    else if (champ == 0)
    {
        strcpy(tmpDate, tab[val2].date);
        strcpy(tab[val2].date, tab[val1].date);
        strcpy(tab[val1].date, tmpDate);
    }
}