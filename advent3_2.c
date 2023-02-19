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
    char chaine1[TAILLEMAX] = "";
    char chaine2[TAILLEMAX] = "";
    char chaine3[TAILLEMAX] = "";
    int registered_elves = 0;
    fichier = fopen("input3", "r");

    if (fichier == NULL)
        printf("Impossible d'ouvrir le fichier input3");
    else {
        while(fgets(chaine, TAILLEMAX, fichier) != NULL)
        {
            registered_elves++;
            // store the first 3 lines in 3 variables, then check the common char
            if (registered_elves == 1) {
                strcpy(chaine1, chaine);
            }
            else if (registered_elves == 2) {
                strcpy(chaine2, chaine);
            }
            else if (registered_elves == 3) {
                strcpy(chaine3, chaine);
                registered_elves = 0;
                compare_rucksacks(chaine1, chaine2, chaine3, &totalPoints);

            }




        }
        fclose(fichier);
    }

}

void compare_rucksacks(char *chaine1, char *chaine2, char *chaine3, int *totalPoints) {

    for (int i = 0; i < strlen(chaine1); i++) {
        for (int j = 0; j < strlen(chaine2); j++) {
            for (int k = 0; k < strlen(chaine3); k++) {
                if (chaine1[i] == chaine2[j] && chaine2[j] == chaine3[k]) {
                    printf("La lettre %c est en doublon dans les 3 rucksacks.\n", chaine1[i]);
                    *totalPoints += charValue(chaine1[i]);
                    printf("Total points : %d\n", *totalPoints);
                    i = (int)strlen(chaine1)+1;
                    j = (int)strlen(chaine2)+1;
                    k = (int)strlen(chaine3)+1;

                }
            }
        }
    }
}

int charValue(char caseSensitiveLetter) {
    int pointsAjoutes = 0;
    if (caseSensitiveLetter <= 90 && caseSensitiveLetter >= 65) {
        pointsAjoutes = (caseSensitiveLetter - 38);
    }
    else if (caseSensitiveLetter <= 122 && caseSensitiveLetter >= 97) {
        pointsAjoutes = (caseSensitiveLetter - 96);
    }
    //printf("La lettre %c (%d) en doublon, priorise un total de %d points.\n", caseSensitiveLetter, pointsAjoutes, *totalPoints);
    return pointsAjoutes;
}