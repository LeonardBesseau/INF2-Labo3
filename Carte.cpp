//
// Created by leonard on 3/6/20.
//

#include "Carte.h"



Carte::Carte(unsigned short familly, unsigned short member) :familly(familly), member(member){}

unsigned short Carte::getFamilly() const {
    return familly;
}

unsigned short Carte::getMember() const {
    return member;
}

std::string Carte::toString() const {
    return std::to_string(familly)+getMemberName();
}

std::string Carte::getMemberName() const{
    return std::__cxx11::string();
}

std::ostream &operator<<(std::ostream &lhs, const Carte &rhs) {
    return lhs<<rhs.toString();
}