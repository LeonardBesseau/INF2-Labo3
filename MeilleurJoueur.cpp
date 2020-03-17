//
// Created by leonard on 3/11/20.
//

#include "MeilleurJoueur.h"

Carte MeilleurJoueur::choseCard() const {
    unsigned index = 0;
    unsigned family = 0;
    unsigned max = 0;
    unsigned familyMax = 1;

    while (index < deck.size()) {
        unsigned count = numberOfMember(family);
        if (count > max) {
            familyMax = family;
            max = count;
        }
        index += count;
        ++family;
    }

    return findMissingMember(familyMax);
}
