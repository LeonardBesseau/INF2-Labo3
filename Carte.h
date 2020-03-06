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

class Carte {
public:
    Carte(unsigned short familly, unsigned short member);

    unsigned short getFamilly() const;

    unsigned short getMember() const;

    std::string toString() const;

private:
    std::string getMemberName() const;
    unsigned short familly;
    unsigned short member;
};


#endif //LABO3_CARTE_H
