#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLEMAX 1000

// Jeu n°3 de AdventOfCode
void charValue(char caseSensitiveLetter, int *totalPoints);

int main(int argc, char *argv[]) {
    FILE *fichier = NULL;
    char chaine[TAILLEMAX] = "";
    int totalPoints = 0;
    int halfNbOfThisPackage;
    fichier = fopen("input3", "r");

    if (fichier == NULL)
        printf("Impossible d'ouvrir le fichier input3");
    else {
        while(fgets(chaine, TAILLEMAX, fichier) != NULL)
        {
            //printf("%lu caractères : %s", strlen(chaine)-1, chaine);

            halfNbOfThisPackage = ((int)(strlen(chaine)-1)) / 2;

            for (int i = 0; i <= halfNbOfThisPackage; i++) {
                for (int j = halfNbOfThisPackage; j <= halfNbOfThisPackage * 2; j++) {
                    if (chaine[i] == chaine[j]) {
                        charValue(chaine[i], &totalPoints);
                        i = halfNbOfThisPackage;
                        j = halfNbOfThisPackage * 2;
                    }
                }
            }
        }
        fclose(fichier);
    }

}

void charValue(char caseSensitiveLetter, int *totalPoints) {
    int pointsAjoutes = 0;
    if (caseSensitiveLetter <= 90 && caseSensitiveLetter >= 65) {
        pointsAjoutes = (caseSensitiveLetter - 38);
    }
    else if (caseSensitiveLetter <= 122 && caseSensitiveLetter >= 97) {
        pointsAjoutes = (caseSensitiveLetter - 96);
    }
    *totalPoints += pointsAjoutes;
    printf("La lettre %c (%d) en doublon, priorise un total de %d points.\n", caseSensitiveLetter, pointsAjoutes, *totalPoints);
}