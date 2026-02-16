# So Long - 42 Project

## 📝 Description

**So Long** est un petit jeu 2D développé en C utilisant la bibliothèque graphique **MiniLibX**. L'objectif est de guider un personnage à travers une carte, de collecter tous les objets présents et de s'échapper par la sortie, tout en évitant les obstacles et les ennemis (version bonus).

Ce projet fait partie du cursus de l'école 42 et permet de se familiariser avec la gestion des fenêtres, les événements (clavier/souris), les textures et les algorithmes de parsing de carte (Flood Fill).

## ⭐ Fonctionnalités

### Partie Mandataire
- **Parsing de carte** : Lecture et validation de fichiers `.ber`.
- **Validation de carte** :
  - La carte doit être fermée par des murs.
  - Elle doit être rectangulaire.
  - Elle doit contenir au moins un objet (C), une sortie (E) et une position de départ (P).
  - Un chemin valide doit exister vers la sortie et tous les objets.
- **Gameplay** :
  - Déplacement du personnage (Haut, Bas, Gauche, Droite).
  - Compteur de mouvements affiché dans le terminal.
  - Gestion de la fermeture propre de la fenêtre (Croix ou ESC).

### Partie Bonus
- **Ennemis** : Ajout de patrouilles ou d'obstacles mobiles qui font perdre la partie au contact.
- **Sprite Animation** : Animation des sprites (ennemi ou joueur).
- **Compteur à l'écran** : Affichage du nombre de mouvements directement sur la fenêtre de jeu.

## 🛠️ Installation

1. Clonez le dépôt :
```bash
git clone https://github.com/papacolas/42-So_long.git
cd 42-So_long
```

2. Compilez le projet :
- Pour la version standard :
```bash
make
```
- Pour la version bonus :
```bash
make bonus
```

## 🎮 Utilisation

Lancez le jeu en fournissant le chemin vers un fichier de carte `.ber` :

```bash
./so_long playing_maps/map_grande.ber
```

Ou pour le bonus :
```bash
./so_long_bonus playing_maps/map_grande.ber
```

### Cartes disponibles
Le dossier `playing_maps` contient plusieurs cartes valides. Le dossier `problems_map` contient des cartes invalides pour tester le parsing d'erreurs.

## 🕹️ Contrôles

| Touche | Action |
| :---: | :--- |
| `W` / `↑` | Aller en haut |
| `A` / `←` | Aller à gauche |
| `S` / `↓` | Aller en bas |
| `D` / `→` | Aller à droite |
| `ESC` | Quitter le jeu |

## 🧩 Structure du code

- `src/` : Code source de la partie obligatoire.
- `src_bonus/` : Code source de la partie bonus.
- `includes/` : Fichiers d'en-tête (.h).
- `libft/` : Ma bibliothèque libft personnelle.
- `playing_maps/` : Cartes de jeu valides.
- `textures/` : Sprites et images du jeu.

## ⚠️ Règles de la carte (.ber)

Le fichier de carte doit respecter les caractères suivants :
- `0` : Sol vide
- `1` : Mur
- `C` : Item à collecter
- `E` : Sortie (accessible après avoir tout collecté)
- `P` : Position de départ du joueur
- `M` : Ennemi (Bonus uniquement)
