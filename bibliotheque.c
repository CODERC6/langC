
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

int supprimerLivre(Livre livres[], int nb)
{
    int isbn;
    printf("ISBN du livre a supprimer : ");
    scanf("%d", &isbn);

    for (int i = 0; i < nb; i++) {
        if (livres[i].isbn == isbn) {
            livres[i] = livres[nb-1];
            nb--;
            printf("Livre supprime avec succes.\n");
            return nb;
        }
    }
    printf("Livre non trouve.\n");
    return nb;
}
void principal()
{
    Livre livres[MAX];
    int nb = 0, choix;
    Emprunt emprunts[MAX];
    int nbEmprunts = 0, nonEmprunt = 0;
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
        case 4:
           nb=supprimerLivre(livres, nb);
            break;

        case 0:
            printf("Au revoir !\n");
            return;

        default:
            printf("Choix invalide , veuillez reessayer.\n");
}
}
}
