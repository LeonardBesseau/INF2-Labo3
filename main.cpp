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
#include <algorithm>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<std::string> name{"Alice", "Bobby", "Carol", "Danny"};
    Partie a(name, 8, 4, 5);
    std::vector<unsigned> score = a.play(1);

    return 0;
}
