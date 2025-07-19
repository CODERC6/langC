#include <stdio.h>
#include "bibliotheque.h"
#include<string.h>
#define MAX 100
int generer_isbn()
{
    static int isbn_courant = 10000;
    isbn_courant++;
    return isbn_courant;
}

int ajouterLivre(Livre livres[], int nb)
{
    if (nb > MAX)
        return 0;
    printf("Titre du livre : ");
    gets(livres[nb].titre);
    printf("Auteur du livre : ");
    gets(livres[nb].auteur);
    printf("Annee : ");
    scanf("%d",&livres[nb].annee);
    livres[nb].isbn = generer_isbn();
    getchar();
    livres[nb].estEmprunte = 0;
    return 1;
}

void principal()
{
    Livre livres[MAX];
    int nb = 0, choix;
    while(1)
    {
        system("pause");
        system("cls");
        printf("Saisir votre choix: ");
        scanf(" %d", &choix);
        getchar();
        switch(choix)
        {
        case 1:
            if (ajouterLivre(livres, nb) == 1)
            {
                nb++;
             printf("Le livre a ete ajoute avec succes !\n");
            }
            else
            {
                printf("La bibliotheque est pleine.\n");
            }

            break;

            case 8:
            statistiques(livres, nb);
            break;

            case 0:
            printf("Au revoir !\n");
            return;

        default:
            printf("Choix invalide , veuillez reessayer.\n");


              }
               }
                  }

                  void statistiques(Livre livres[], int nb)
{
    int nbEmpruntes = 0;
    int nbDisponibles = 0;
    for (int i = 0; i < nb; i++)
    {
        if (livres[i].estEmprunte == 1)
            nbEmpruntes++;
        else
            nbDisponibles++;
    }
    printf("\nStatistiques de la bibliotheque :\n");
    printf("Nombre total de livres        : %d\n", nb);
    printf("Nombre de livres empruntes    : %d\n", nbEmpruntes);
    printf("Nombre de livres disponibles  : %d\n", nbDisponibles);
}
