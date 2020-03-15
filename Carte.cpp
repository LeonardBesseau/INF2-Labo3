/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Carte.cpp
 Auteur(s)   : Léonard Besseau, Alexandra Cerottini, Nicolas Viotti
 Date        : 24.02.2020

 But         : Contient les fonctions liées à la classe Carte

 Remarque(s) :

 Compilateur : gcc version 7.4.0
 -----------------------------------------------------------------------------------
*/

#include "Carte.h"
#include <algorithm>


Carte::Carte(unsigned short familly, unsigned short member) : family(familly), member(member) {}

unsigned short Carte::getFamily() const {
    return family;
}

std::string Carte::getMemberName() const {
    std::string output;
    unsigned short number = member;
    while (number > 0) {
        char digit = --number % 26;
        char b = (char) ('A' + digit);
        output += b;
        number = (number - digit) / 26;
    }

    std::reverse(output.begin(), output.end());
    return output;
}

std::ostream &operator<<(std::ostream &lhs, const Carte &rhs) {
    return lhs << std::to_string(rhs.family) + rhs.getMemberName();
}

bool Carte::operator<(const Carte &rhs) const {
    if (family < rhs.family) {
        return true;
    }
    if (family > rhs.family) {
        return false;
    }
    return member < rhs.member;
}

bool Carte::operator>(const Carte &rhs) const {
    return rhs < *this;
}

bool Carte::operator<=(const Carte &rhs) const {
    return !(rhs < *this);
}

bool Carte::operator>=(const Carte &rhs) const {
    return !(*this < rhs);
}

bool Carte::operator==(const Carte &rhs) const {
    return family == rhs.family &&
           member == rhs.member;
}

bool Carte::operator!=(const Carte &rhs) const {
    return !(rhs == *this);
}
