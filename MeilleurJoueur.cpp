//
// Created by leonard on 3/11/20.
//

#include "MeilleurJoueur.h"
#include <algorithm>

Carte MeilleurJoueur::choseCard() const {
    unsigned nbTotal = 0;
    unsigned nbFamily = 0;
    unsigned max = 0;
    unsigned familyMax = 1;
    while (nbTotal < cartesEnMains.size()) {
        unsigned count = std::count_if(cartesEnMains.begin(), cartesEnMains.end(), [nbFamily](const Carte &c) {
            return c.getFamily() == nbFamily;
        });
        if (count > max) {
            familyMax = nbFamily;
            max = count;
        }
        nbTotal += count;
        ++nbFamily;
    }
    unsigned member = 1;
    Carte search = Carte(familyMax, member);
    auto pos = std::find(cartesEnMains.begin(), cartesEnMains.end(), search);
    while (pos != cartesEnMains.end()) {
        ++member;
        search = Carte(familyMax, member);
        pos = std::find(cartesEnMains.begin(), cartesEnMains.end(), search);
    }
    return search;
}
