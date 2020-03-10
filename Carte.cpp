//
// Created by leonard on 3/6/20.
//

#include "Carte.h"
#include <algorithm>


Carte::Carte(unsigned short familly, unsigned short member) : family(familly), member(member) {}

unsigned short Carte::getFamily() const {
    return family;
}

unsigned short Carte::getMember() const {
    return member;
}

std::string Carte::toString() const {
    return std::to_string(family) + getMemberName();
}

std::string Carte::getMemberName() const {
    std::string output;
    unsigned short number = member;
    while (number > 0) {
        char digit = --number % 26;
        char b = (char) ('A' + digit);
        output += b;
        number = (number - digit)/26;
    }

    std::reverse(output.begin(), output.end());
    return output;
}

std::ostream &operator<<(std::ostream &lhs, const Carte &rhs) {
    return lhs << rhs.toString();
}