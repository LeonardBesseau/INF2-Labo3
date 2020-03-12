/* ---------------------------
Laboratoire :
Fichier : main.cpp
Auteur(s) : Besseau
Date : 24-02-2020

But :

Remarque(s) :

Compilateur : gcc version 7.4.0

--------------------------- */
#include <iostream>
#include "Partie.h"

int main() {
    const int nbPlays = 100;
    std::cout << "Hello, World!" << std::endl;
    std::vector<std::string> name{"Adolf", "Benito", "Joseph", "Miguel"};
    std::vector<unsigned> score(4);
    MeilleurJoueur p1;
    Joueur p2;
    Joueur p3;
    Joueur p4;
    std::vector<Joueur *> list{&p1, &p2, &p3, &p4};

    for (int i = 0; i < nbPlays; ++i) {
        Partie a(name, list, 4, 27, 5);
        std::vector<unsigned> playScore = a.play(i);
        for (int j = 0; j < name.size(); ++j) {
            score.at(j) += playScore.at(j);
        }
    }
    for (int k = 0; k < name.size(); ++k) {
        std::cout << name.at(k) << " : " << score.at(k) << std::endl;
    }




    return 0;
}
