#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLEMAX 100

// Jeu n°1 de AdventOfCode

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    char chaine[TAILLEMAX] = "";
    int elfeEnCours = 0;
    int nombre;

    int top1 = 3;
    int top2 = 2;
    int top3 = 1;

    fichier = fopen("input1", "r");

    if (fichier == NULL)
        printf("Impossible d'ouvrir le fichier input1");
    else {
        while (fgets(chaine, TAILLEMAX, fichier) != NULL) {

            nombre = atoi(chaine);
            elfeEnCours += nombre;
            // printf("Total compté: %d calories\nAliment: %d\n", elfeEnCours, nombre);

            if (nombre == 0) {
                if (elfeEnCours > top1) {
                    top2 = top1;
                    top1 = elfeEnCours;
                } else if (elfeEnCours > top2) {
                    top3 = top2;
                    top2 = elfeEnCours;
                } else if (elfeEnCours > top3) {
                    top3 = elfeEnCours;
                }

                printf("-Cet elfe transporte : %d calories..\n", elfeEnCours);
                elfeEnCours = 0;
            }

        }
        if (elfeEnCours > top1) {
            top2 = top1;
            top1 = elfeEnCours;
        } else if (elfeEnCours > top2) {
            top3 = top2;
            top2 = elfeEnCours;
        } else if (elfeEnCours > top3) {
            top3 = elfeEnCours;
        }
        printf("Cet elfe transporte : %d calories..\n", elfeEnCours);
        printf("Classement :\n1 : %d\n2 : %d\n3 : %d\n", top1, top2, top3);
        int top = top1 + top2 + top3;
        printf("Au total : %d calories pour le top 3.", top);
        fclose(fichier);
    }
}