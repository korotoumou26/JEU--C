#include <stdio.h>

/* Grille du jeu : 3 lignes, 3 colonnes */
char grille[3][3];

/* Remplit la grille avec des cases vides */
void initialiser() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grille[i][j] = ' ';
}

/* Affiche la grille. Les cases vides montrent leur numéro (1 à 9) */
void afficher() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c = grille[i][j];
            if (c == ' ') c = '1' + (i * 3 + j);
            printf(" %c ", c);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

/* Retourne 1 si le joueur a aligné 3 symboles, sinon 0 */
int a_gagne(char s) {
    for (int i = 0; i < 3; i++) {
        if (grille[i][0] == s && grille[i][1] == s && grille[i][2] == s) return 1; /* ligne */
        if (grille[0][i] == s && grille[1][i] == s && grille[2][i] == s) return 1; /* colonne */
    }
    if (grille[0][0] == s && grille[1][1] == s && grille[2][2] == s) return 1;     /* diagonale */
    if (grille[0][2] == s && grille[1][1] == s && grille[2][0] == s) return 1;     /* diagonale */
    return 0;
}

/* Retourne 1 si toutes les cases sont remplies */
int grille_pleine() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grille[i][j] == ' ') return 0;
    return 1;
}

/* Demande une case au joueur et place son symbole */
void jouer(char joueur) {
    int numero;
    while (1) {
        printf("Joueur %c, choisissez une case (1-9) : ", joueur);
        if (scanf("%d", &numero) != 1) {
            while (getchar() != '\n');          /* vide la saisie incorrecte */
            printf("Entrez un nombre.\n");
            continue;
        }
        if (numero < 1 || numero > 9) {
            printf("La case doit etre entre 1 et 9.\n");
            continue;
        }
        int i = (numero - 1) / 3;
        int j = (numero - 1) % 3;
        if (grille[i][j] != ' ') {
            printf("Cette case est deja prise.\n");
            continue;
        }
        grille[i][j] = joueur;
        break;
    }
}

int main() {
    char joueur = 'X';
    initialiser();

    printf("=== MORPION ===\n");
    printf("Joueur 1 : X, Joueur 2 : O\n");

    while (1) {
        afficher();
        jouer(joueur);

        if (a_gagne(joueur)) {
            afficher();
            printf("Bravo, le joueur %c a gagne !\n", joueur);
            break;
        }
        if (grille_pleine()) {
            afficher();
            printf("Match nul !\n");
            break;
        }
        joueur = (joueur == 'X') ? 'O' : 'X';   /* change de joueur */
    }
    return 0;
}