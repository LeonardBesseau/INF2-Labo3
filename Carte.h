/* ---------------------------
Laboratoire : 02
Fichier : Carte.h
Auteur(s) : Besseau
Date : 06-03-2020

But :

Remarque(s) :

Compilateur : gcc version 7.4.0

--------------------------- */
#ifndef LABO3_CARTE_H
#define LABO3_CARTE_H

#include <string>
#include <iostream>

class Carte {
    friend std::ostream &operator<<(std::ostream &lhs, const Carte &rhs);
public:
    Carte(unsigned short familly, unsigned short member);

    unsigned short getFamily() const;

    unsigned short getMember() const;

    std::string toString() const;

private:
    std::string getMemberName() const;
    unsigned short family;
    unsigned short member;
};


#endif //LABO3_CARTE_H
