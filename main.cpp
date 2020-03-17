/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : Léonard Besseau, Alexandra Cerottini, Nicolas Viotti
 Date        : 24.02.2020

 But         : Construire un système pouvant jouer au jeu des 7 familles

 Remarque(s) :

 Compilateur : gcc version 7.4.0
 -----------------------------------------------------------------------------------
*/

#include <iostream>
#include "Partie.h"

int main() {
    const int nbPlays = 100;
    std::cout << "Debut de la partie de 7 familles" << std::endl;
    std::vector<std::string> name{"Alice", "Bobby", "Carol", "Danny"};
    MeilleurJoueur p1(name.at(0));
    Joueur p2(name.at(1));
    Joueur p3(name.at(2));
    Joueur p4(name.at(3));
    std::vector<Joueur *> list{&p1, &p2, &p3, &p4};

    for (int i = 0; i < nbPlays; ++i) {
        Partie a(list, 8, 4, 5);
        a.play(i);
    }
    for (int k = 0; k < name.size(); ++k) {
        std::cout << list.at(k)->getScore() << std::endl;
    }
    return 0;
}
