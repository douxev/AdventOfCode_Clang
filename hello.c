#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Je mets le prototype en haut. Comme c'est un tout
petit programme je ne le mets pas dans un .h, mais
en temps normal (dans un vrai programme), j'aurais placé
le prototype dans un fichier .h bien entendu */

int sommeTableau(int tableau[], int tailleTableau);

double moyenneTableau(int tableau[], int tailleTableau);

int main(int argc, char *argv[])
{
    int tableau[] = {10, 30, 20, 15};
    int ioanr;
    int printable;
    printable = sommeTableau(tableau, 4);
    printf("La Somme Fait : %d", printable);
    double printeuble;
    printeuble = moyenneTableau(tableau, 4);
    printf("La moyenne est de : %f", printeuble);
    return 0;
}

int sommeTableau(int tableau[], int tailleTableau)
{
    int somme = 0;

    for (int i = 0 ; i < tailleTableau ; i++)
    {
        somme += tableau[i];
    }

    return somme;
}


double moyenneTableau(int tableau[], int tailleTableau)
{
    int somme = 0;

    somme = sommeTableau(tableau, tailleTableau);

    return (double)somme / (double)tailleTableau;
    
}