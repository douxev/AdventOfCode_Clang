#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLEMAX 100

// Jeu n°3 de AdventOfCode
void compare_rucksacks(char *chaine1, char *chaine2, char *chaine3, int *totalPoints);
int charValue(char caseSensitiveLetter);

int main(int argc, char *argv[]) {
    FILE *fichier = NULL;
    char chaine[TAILLEMAX] = "";
    int totalPoints = 0;

    fichier = fopen("input3", "r");

    if (fichier == NULL)
        printf("Impossible d'ouvrir le fichier input3");
    else {
        while(fgets(chaine, TAILLEMAX, fichier) != NULL)
        {





        }
        fclose(fichier);
    }

}