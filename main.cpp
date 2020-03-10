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
#include "Carte.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Carte a(1, 1024);
    std::cout << a;

    return 0;
}
