typedef struct {
    char titre[50];
    char auteur[50];
    int annee;
    int isbn;
    int estEmprunte;
} Livre;

typedef struct {
    int isbn;
    char nom_emprunteur[100];
    char date[11];
    char date_retour[11];
} Emprunt;

// D�clarations de fonctions
void menu();
void principal();
int ajouterLivre(Livre[], int);
int supprimerLivre(Livre[], int);
void emprunterLivre(Livre[], Emprunt[], int, int*);
void afficherEmprunts(Emprunt[], int);
void retournerLivre(Livre[], int);
void rechercherLivre(Livre[], int);
void statistiques(Livre[], int);
