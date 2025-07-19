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

             case 2:
           afficherLivre(livres,nb);
            break;


            case 0:
            printf("Au revoir !\n");
            return;



        default:
            printf("Choix invalide , veuillez reessayer.\n");


              }
               }
                  }

    void afficherLivre(Livre livres[], int nb)
{
    if (nb == 0)
    {
        printf("Aucun livre enregistre pour le moment.\n");
        return;
    }

    printf("\nListe des livres enregistres :\n\n");
    printf("Y'a %d Enregistre !!!",nb);
    for (int i = 0; i < nb; i++)
    {
        printf("\nLivre %d\n", i + 1);
        printf("Titre  : %s\n", livres[i].titre);
        printf("Auteur : %s\n", livres[i].auteur);
        printf("Annee  : %d\n",livres[i].annee);
        printf("ISBN   : %d\n", livres[i].isbn);
        if (livres[i].estEmprunte == 1)
        {
            printf("Etat   : Emprunte\n");
        }
        else
        {
            printf("Etat   : Disponible\n");
        }
    }
}

