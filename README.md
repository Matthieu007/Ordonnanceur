# Ordonnanceur
Intitulé : Ordonnancement de processus
(Projet de Programmation Procédurale ING 1 GI GM 2022-2023)  
__Groupe : BOURGOGNE Matthieu et BRIGITTE Maëva__

## Objectif

L'objectif est d'implémenter en C un algorithme qui permet d'optimiser l'utilisation du processeur en répartissant mieux le temps de calul entre tout les processus.

Ainsi, la création de la structure ordonnanceur et de file d'ordonnanceur qui vont nous permettre de traiter les processus. On a alors creer des fonctions permettant de manipuler les files. 

Ensuite, nous avons permis l'ajout d'une activité à la file de processus de l'ordonnanceur ainsi qu'un trie de la file afin qu'elle soit adaptée au mieux pour l'ordonnancement. 

Enfin, on effectue step, qui depile les éléments de la file et les renvoies tout en attendant le temps qui correspond à la durée du processus jusqu'a que la file soit vide.

## Compilation
Une fois dans le dossier du projet, le terminal vous permet d'exécuter les commandes suivantes :  
* make ordonnanceur : compile le projet une première fois et l'exécute
* make run : exécute le projet
* make clean : nettoie le projet
