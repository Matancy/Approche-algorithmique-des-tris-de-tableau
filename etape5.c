#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COVID 17776 // Nombre de valeurs du tableau covid
#define MAX_JOURS 31    // Nombre de valeurs du tableau tableau intermédiaire
#define MAX_CLASSE 99   // Nombre de valeurs du tableau tableau intermédiaire
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
typedef int typePosClasse[MAX_CLASSE];

void lireFichier(typeCovid, int *);
void triDepartement(typeCovid);
void population22(typeCovid, int *);
void triDate(typeCovid);
void DebutAnnee35(typeCovid, typePosClasse);
void tri_rapide(typeCovid, int, int, int);
void inversion(typeCovid, int, int, int);

int main()
{
    typeCovid tabCovid;
    typePosClasse tabIntermediaire;
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
    tri_rapide(tabCovid, 0, MAX_COVID, 1); // Tri selon le département
}

// Affichage des données par tranche d'âge en Ille-et-Vilaine le 1er janvier 2021
void DebutAnnee35(typeCovid tabCovid, typePosClasse tabPosClasse)
{
    bool janvier = false; // Si on trouve des valeurs du 1er Janvier
    int nbCas = 0;        // Compteur du nombre de cas au total

    // Initialisation du tableau des classes
    tabPosClasse[9] = 0;
    tabPosClasse[19] = 0;
    tabPosClasse[29] = 0;
    tabPosClasse[39] = 0;
    tabPosClasse[49] = 0;
    tabPosClasse[59] = 0;
    tabPosClasse[69] = 0;
    tabPosClasse[79] = 0;
    tabPosClasse[89] = 0;
    tabPosClasse[90] = 0;

    // Enregistrement des données du 1er Janvier en Ille-et-Vilaine dans un tableau intermédiaire
    printf("Nombre de cas en Ille-et-Vilaine par classe d'age, le 1er janvier 2021 : \n\n");
    for (int j = 0; j < MAX_COVID; j++)
    {
        // printf("Date : %s Dep : %d Classe : %d Pos : %d\n", tabCovid->date, tabCovid->dep, tabCovid->classe, tabCovid->pos);
        // Vérification de la date du 1er Janvier
        if (strcmp(tabCovid[j].date, "2021-01-01") == 0)
        {
            // Vérification du département
            if (tabCovid[j].dep == 35)
            {
                // Enregistrement des données
                janvier = true; // Le 1er janvier contient des valeurs désormais
                // printf("Classe : %d Pos : %d \n", tabCovid->classe, tabCovid->pos);
                tabPosClasse[tabCovid[j].classe] = tabCovid[j].pos; // Cas pour la tranche d'âge
                // Pour ne pas prendre en compte la classe 0 est qui est un résumé
                if (tabCovid[j].classe != 0)
                {
                    nbCas = nbCas + tabCovid[j].pos; // Total de cas
                }
            }
        }
    }

    // Si le 1er janvier contient des valeurs
    if (janvier)
    {
        // Affichage des données du 1er Janvier en Ille-et-Vialine par tranche d'âge
        printf("[0 - 9] : %d\n", tabPosClasse[9]);
        printf("[10 - 19] : %d\n", tabPosClasse[19]);
        printf("[20 - 29] : %d\n", tabPosClasse[29]);
        printf("[30 - 39] : %d\n", tabPosClasse[39]);
        printf("[40 - 49] : %d\n", tabPosClasse[49]);
        printf("[50 - 59] : %d\n", tabPosClasse[59]);
        printf("[60 - 69] : %d\n", tabPosClasse[69]);
        printf("[70 - 79] : %d\n", tabPosClasse[79]);
        printf("[80 - 89] : %d\n", tabPosClasse[89]);
        printf("[90 - 99] : %d\n", tabPosClasse[90]);
        printf("\n\nTOTAL: %d\n", nbCas);
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