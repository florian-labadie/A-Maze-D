---

# A-Maze-D : Algorithme de Pathfinding pour Robots Multiples

Le projet A-Maze-D est conçu pour naviguer efficacement plusieurs robots à travers un labyrinthe, de l'entrée à la sortie. L'objectif est de maximiser le nombre de robots atteignant la sortie dans le temps le plus court possible.

## Table des matières
1. [Introduction]
2. [Configuration]
3. [Description de l'Entrée]
4. [Format de Sortie]
5. [Utilisation]
6. [Exemples]
7. [Contributeurs]
8. [Licence]

## Introduction

L'algorithme A-Maze-D résout le problème de navigation des robots à travers un labyrinthe. Il lit une configuration de labyrinthe depuis l'entrée standard, détermine la validité de la configuration du labyrinthe,
et calcule les chemins les plus courts pour tous les robots de l'entrée à la sortie.

## Configuration

Clonez le dépôt depuis GitHub :

```bash
git clone https://git@github.com:florian-labadie/A-Maze-D.git
cd a-maze-d
```

Compilez le programme si nécessaire :

```bash
make
```

## Description de l'Entrée

Le programme lit la configuration du labyrinthe depuis l'entrée standard. Le format d'entrée inclut :
- Le nombre de robots à l'entrée
- Les descriptions des pièces avec leurs positions
- Les tunnels connectant les pièces

Un script Perl `laby_gen.pl` est fourni pour générer des configurations de labyrinthe. Exemple d'utilisation :

```bash
./laby_gen.pl 8 15 34 > input && cat input
```

## Format de Sortie

Après le traitement de la configuration du labyrinthe, le programme affiche :
- Le nombre de robots
- Les descriptions des pièces
- Les connexions des tunnels
- Les mouvements nécessaires pour que chaque robot atteigne la sortie

## Utilisation

Pour exécuter le programme avec un fichier de configuration de labyrinthe (`labyrinth` dans cet exemple) :

```bash
./amazed < labyrinth
```

## Exemples

### Exemple 1 : Configuration de Labyrinthe Simple

Considérez la configuration de labyrinthe suivante :

```
3
##start
0 1 0
##end
1 13 0 #chambre
2 5 0
3 9 0
0-2
2-3
3-1
```

Exécution du programme :

```bash
./amazed < labyrinth
```

Sortie :

```
#number_of_robots
3
#rooms
##start
0 1 0
##end
1 13 0
2 5 0
3 9 0
#tunnels
0-2
2-3
3-1
P1-2 
P1-3 P2-2 
P1-1 P2-3 P3-2 
P2-1 P3-3 
P3-1 
```

## Contributeurs

- Labadie Florian ([GitHub](https://github.com/florian-labadie))
- Axel Lavrador ([GitHub](https://github.com/Oursegamin))
- Baptiste Blambert ([GitHub](https://github.com/baptistebd))

---
