#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLEMAX 100

// Jeu n°2 de AdventOfCode
//Résumé :
//lost : 0, draw : 3; win : 6
//A X ROCK < [1
//B Y PAPER < [2
//C Z SCISSORS < [3
// X lose
// Y draw
// Z win

void who_wins(char itPlayed, char youPlayed, int *totalPoints);
void chosen_sign(char sign, int *totalPoints);
void have_to_win(char itPlayed, int *totalPoints);
void have_to_lose(char itPlayed, int *totalPoints);
void have_to_draw(char itPlayed, int *totalPoints);

int main(int argc, char *argv[]) {
    FILE *fichier = NULL;
    char chaine[TAILLEMAX] = "";
    int totalPoints = 0;
    fichier = fopen("input2", "r");

    if (fichier == NULL)
        printf("Impossible d'ouvrir le fichier input2");
    else {
        while (fgets(chaine, TAILLEMAX, fichier) != NULL) {
            if (chaine[2] == 'X')
            {
                have_to_lose(chaine[0], &totalPoints);
            }
            else if (chaine[2] == 'Y')
            {
                have_to_draw(chaine[0], &totalPoints);
            }
            else if (chaine[2] == 'Z')
            {
                have_to_win(chaine[0], &totalPoints);
            }
            printf("Total points : %d\n", totalPoints);
        }
        fclose(fichier);
    }
    printf("Total points : %d\n", totalPoints);
}

//lost : 0, draw : 3; win : 6
//A X ROCK < [1
//B Y PAPER < [2
//C Z SCISSORS < [3
// X lose
// Y draw
// Z win
void have_to_win(char itPlayed, int *totalPoints) {
    *totalPoints += 6;
    if (itPlayed == 'A') {
        *totalPoints += 2;
    }
    else if (itPlayed == 'B') {
        *totalPoints += 3;
    }
    else if (itPlayed == 'C') {
        *totalPoints += 1;
    }

}

void have_to_lose(char itPlayed, int *totalPoints) {
    *totalPoints += 0;
    if (itPlayed == 'A') {
        *totalPoints += 3;
    }
    else if (itPlayed == 'B') {
        *totalPoints += 1;
    }
    else if (itPlayed == 'C') {
        *totalPoints += 2;
    }

}
void have_to_draw(char itPlayed, int *totalPoints) {
    *totalPoints += 3;
    if (itPlayed == 'A') {
        *totalPoints += 1;
    }
    else if (itPlayed == 'B') {
        *totalPoints += 2;
    }
    else if (itPlayed == 'C') {
        *totalPoints += 3;
    }

}

void who_wins(const char itPlayed, const char youPlayed, int *totalPoints) {
    chosen_sign(youPlayed, totalPoints);
// if Z and B
    if ((youPlayed == 'Z' && itPlayed == 'B') || (youPlayed == 'X' && itPlayed == 'C') ||
        (youPlayed == 'Y' && itPlayed == 'A')) {

        *totalPoints += 6;
        printf("You win. - Total : %d points.\n", *totalPoints);
    } else if ((youPlayed == 'Z' && itPlayed == 'C') || (youPlayed == 'X' && itPlayed == 'A') ||
               (youPlayed == 'Y' && itPlayed == 'B')) {
        *totalPoints += 3;
        printf("Draw. - Total : %d points.\n", *totalPoints);
    } else if ((youPlayed == 'Z' && itPlayed == 'A') || (youPlayed == 'X' && itPlayed == 'B') ||
               (youPlayed == 'Y' && itPlayed == 'C')) {
        *totalPoints += 0;
        printf("You lose. - Total : %d points.\n", *totalPoints);
    }

}

void chosen_sign(const char sign, int *totalPoints) {

    if (sign == 'X') {
        *totalPoints += 1;
    }
    else if (sign == 'Y') {
        *totalPoints += 2;
    }
    else if (sign == 'Z') {
        *totalPoints += 3;
    }

}