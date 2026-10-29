# Jeu du Morpion en C

Projet réalisé dans le cadre du BTS SIO option SLAM (devoir des vacances).

Auteur : Korotoumou KEITA

## Description

Ce programme est un jeu de morpion (tic-tac-toe) pour deux joueurs, écrit en langage C. Il se joue dans le terminal : les deux joueurs jouent à tour de rôle sur le même ordinateur.

## Règles du jeu

- Le jeu se joue sur une grille de 3 cases sur 3.
- Le joueur 1 joue avec les **X**, le joueur 2 avec les **O**.
- À chaque tour, le joueur choisit une case vide en tapant son numéro (de 1 à 9).
- Le premier joueur qui aligne 3 symboles (en ligne, en colonne ou en diagonale) gagne.
- Si les 9 cases sont remplies sans alignement, la partie est un **match nul**.

Numérotation des cases :

```
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

## Fonctionnalités

- Affichage de la grille à chaque tour, avec le numéro des cases libres
- Alternance automatique entre le joueur X et le joueur O
- Vérification de la victoire (lignes, colonnes, diagonales)
- Détection du match nul
- Contrôle des saisies : case déjà prise, numéro hors de 1 à 9, saisie qui n'est pas un nombre

## Prérequis

- Un compilateur C (`gcc`)
- Un terminal (Linux, macOS, ou Codespaces sur GitHub)

## Compilation et lancement

```bash
gcc main.c -o jeu
./jeu
```

## Exemple de partie

```
=== MORPION ===
Joueur 1 : X, Joueur 2 : O

 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9

Joueur X, choisissez une case (1-9) : 5
```

## Structure du code

| Fonction | Rôle |
|---|---|
| `initialiser()` | Remplit la grille de cases vides |
| `afficher()` | Affiche la grille dans le terminal |
| `jouer(joueur)` | Demande une case au joueur et vérifie la saisie |
| `a_gagne(symbole)` | Vérifie si un joueur a aligné 3 symboles |
| `grille_pleine()` | Vérifie si toutes les cases sont remplies |
| `main()` | Boucle principale du jeu |

## Utilisation de Git et GitHub

Le projet a été développé dans GitHub Codespaces, avec des commits réguliers pour suivre l'évolution du code.

## Améliorations possibles

- Ajouter un mode contre l'ordinateur
- Ajouter un compteur de scores sur plusieurs parties
- Proposer de rejouer à la fin d'une parties