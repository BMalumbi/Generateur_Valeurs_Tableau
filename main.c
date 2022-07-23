#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10
#define NB_ALEA_MAX 15

void initTabAlea(int tableau[], int nbElements);
void afficherTab(int tableau[], int nbElements);
int chercherElementsCommuns(int tableau1[], int tableau2[],int tabCommuns[], int tailleTabs);
int verifierElemTab(int element, int tableau[], int taille);

int main()
{
    // Déclarer les tableaux de nombres
    int tab1[TAILLE], tab2[TAILLE];
    int tabCommuns[TAILLE];

    //Initialiser le générateur aléatoire
    srand(time(NULL));
    // Initialiser les tableaux
    initTabAlea(tab1, TAILLE);
    initTabAlea(tab2, TAILLE);

    //Afficher les tableaux
    printf("Tableau 1: ");
    afficherTab(tab1, TAILLE);
    printf("Tableau 2: ");
    afficherTab(tab2, TAILLE);

    //Chercher les éléments communs
    int nbElemCommuns = 0;
    int nb = chercherElementsCommuns(tab1, tab2, tabCommuns, TAILLE);
    if(nb >0)
    {
        printf("Elements communs: ");
        afficherTab(tabCommuns, nb);
    }
    else{
        printf("Aucun ele,ent commun\n");
    }

    return 0;
}

void initTabAlea(int tableau[], int nbElements)
{
    int nbAlea;

    for (int i = 0; i < nbElements; i++)
    {
        // Générer un entier entre ° et NB_ALEA_MAX
        nbAlea = rand() % NB_ALEA_MAX;
        tableau[i] = nbAlea;
    }
}

void afficherTab(int tableau[], int nbElements)
{
    printf("[");
    for(int i = 0; i < nbElements; i++)
    {
        printf("%d", tableau[i]);
        if(i != nbElements - 1)
            printf(", ");
    }
    printf("]\n");
}

int chercherElementsCommuns(int tableau1[], int tableau2[], int tabCommuns[], int tailleTabs)
{
    int nbElemCommuns = 0;
    for(int i = 0; i < TAILLE; i++)
    {
        for(int j = 0; j < TAILLE; j++)
        {
            if(tableau1[i] == tableau2[j])
            {
                if (!verifierElemTab(tableau1[i], tabCommuns, nbElemCommuns))
                {
                    tabCommuns[nbElemCommuns] = tableau1[i];
                    nbElemCommuns++;
                }
            }
        }
    }
    return nbElemCommuns;
}

int verifierElemTab(int element, int tableau[], int taille)
{
    int reponse = 0;
    for (int i = 0; i < taille; i++)
    {
        if (element == tableau[i])
        {
            reponse = 1;
            break;
        }
    }
    return reponse;
}
