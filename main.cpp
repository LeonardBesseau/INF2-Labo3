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
    std::vector<std::string> name{"Alice", "Bobby", "Carol", "Danny"};
    std::vector<unsigned> score(4);
    MeilleurJoueur p1;
    Joueur p2;
    Joueur p3;
    Joueur p4;
    std::vector<Joueur *> list{&p1, &p2, &p3, &p4};
    Partie a(name, list, 8, 4, 5);
    std::vector<unsigned> playScore = a.play(0);
    /*  for (int i = 0; i < nbPlays; ++i) {
          Partie a(name,list, 8, 4, 5);
          std::vector<unsigned> playScore = a.play(i%name.size());
          for (int j = 0; j < name.size(); ++j) {
              score.at(j) += playScore.at(j);
          }
      }
      for (int k = 0; k < name.size(); ++k) {
          std::cout<<name.at(k)<<" : "<<score.at(k)/100 << std::endl;
      }
      */



    return 0;
}
