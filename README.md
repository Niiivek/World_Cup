# World_Cup game

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SDL2](https://img.shields.io/badge/Biblioth%C3%A9que-SDL2-blue)
[![Rapport](https://img.shields.io/badge/Rapport-overleaf.com%2Fproject%2F6399d50c1b6cb4c2b234ed82-blue)](https://fr.overleaf.com/project/63c29d1ba3bcd03b9fa08cea)


Ce Projet a pour but de présenter nos acquis en programmation C++ et orientée objet du semestre 1 de 2022-2023. 

Le thème du projet est *"Coupe du monde"*


## Présentation du sujet

Notre projet se présente sous forme d'un jeu amusant et simple à jouer et qui a donc comme thème la coupe du monde de football. Ce jeu peut se jouer à 2 et consiste donc à répondre aux questions sur le football. Ces questions sont propres à chacun des pays ayant participant à la récente coupe du monde au Qatar.

Pour remporter la partie, il faut que un des deux joueurs aient 10 points en répondant au différentes questions, certains pays rapportent 5 et d'autres 2 en fonction de la performance qu'ils ont fait lors des précédentes coupes du monde, si on répond à une question on perd des points, il y a aussi dans chaque partie une case qui te donne bonus permettant de changer le cours de la partie de manière significative.

## Installation

La partie graphique du projet repose sur la bibliothèque graphique SDL2.
Pour télécharger la librairie SDL2 sous Ubuntu:

sudo apt install libsdl2-dev libsdl2-ttf-dev  libsdl2-mixer-dev

Pour télécharger la librairie SDL2 sous macOS M1/M2: 

brew install SDL2 SDL2_image SDL2_ttf SDL2_mixer

Selon la machine utilisé le makefile est à modifier 
## Utilisation

Pour compiler le programme :

make dans le fichier principale

Pour lancer une partie:

./jeu

Pour les tests unitaires:
make dans le fichier principale puis cd tests puis make puis ./testcase






## Images
![jeu_foot](https://user-images.githubusercontent.com/92987250/214931389-09de4ecc-d1b9-46d6-9b0c-1f4ae59004d8.png)


