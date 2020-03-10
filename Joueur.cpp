//
// Created by leonard on 3/6/20.
//

#include "Joueur.h"
#include "Carte.h"
#include <algorithm>


void Joueur::detecterFamille(unsigned cardsPerFamily) {
    std::sort(cartesEnMains.begin(), cartesEnMains.end());
    size_t index = 0;
    unsigned nbFamily = 1;
    while (index < cartesEnMains.size()) {
        int number = std::count_if(cartesEnMains.begin() + index, cartesEnMains.end(),
                                   [nbFamily](const Carte &c) {
                                       return c.getFamily() == nbFamily;
                                   });
        ++nbFamily;
        if (number == cardsPerFamily) {
            ajoutSurTable(index, cardsPerFamily);
            cartesEnMains.erase(cartesEnMains.begin() + index, cartesEnMains.begin() + index + cardsPerFamily);
        } else {
            index += number;
        }

    }
    /*   size_t count = 0;
       for (size_t i = 0; i < this->cartesEnMains.size() - 1; i++) {
           if (cartesEnMains.at(i).getFamily() == cartesEnMains.at(i + 1).getFamily()) {
               count++;
               if (count == cartesEnMains.size() - 1) {
                   ajoutSurTable();
               }
           }
       }

       */

}

void Joueur::ajoutSurTable(unsigned index, unsigned cardsPerFamily) {
    familleSurTable.insert(familleSurTable.end(), familleSurTable.begin() + index,
                           cartesEnMains.begin() + index + cardsPerFamily);
    /*
    for (Carte c : this->cartesEnMains) {
        this->familleSurTable.push_back(c);
    }
     */
}

std::vector<Carte> Joueur::cartesEnMain() const {
    return this->cartesEnMains;
}

void Joueur::demanderCarte(Joueur &joueur, const unsigned short &famille, const unsigned short member) {
    for (Carte c : joueur.cartesEnMain()) {
        if (c.getFamily() == famille && c.getMember() == member) {
            joueur.supprimerCarte(c);
            this->ajoutCarte(c);
        }
    }
}

void Joueur::ajoutCarte(Carte &carte) {
    this->cartesEnMains.push_back(carte);
}

void Joueur::supprimerCarte(Carte &carte) {
    auto pos = find(this->cartesEnMains.begin(), this->cartesEnMains.end(), carte);
    this->cartesEnMains.erase(pos);
}

bool Joueur::mainVide() {
    return cartesEnMains.empty();
}

unsigned Joueur::nbCarteStack() {
    return familleSurTable.size();
}

void Joueur::play(Joueur &target, unsigned cardsPerFamily) {
    while (true) {
        if (cartesEnMains.empty()) {
            return;
        }
        Carte ask = choseCard();
        if (target.giveCard(ask)) {
            cartesEnMains.push_back(ask);
            detecterFamille(cardsPerFamily);
        } else {
            return;
        }
    }
}

Carte Joueur::choseCard() const {
    return cartesEnMains.front();
}

bool Joueur::giveCard(const Carte &c) {
    auto pos = std::find(cartesEnMains.begin(), cartesEnMains.end(), c);
    if (pos != cartesEnMain().end()) {
        cartesEnMains.erase(pos);
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &lhs, const Joueur &rhs) {
    lhs << rhs.nomJoueur << " : ";
    for (const Carte &c : rhs.cartesEnMains) {
        lhs << c << " ";
    }
    lhs << "[";
    for (const Carte &c : rhs.cartesEnMains) {
        lhs << c << ".";
    }
    lhs << "]";
    return lhs;
}
