//
// Created by leonard on 3/6/20.
//

#include "Joueur.h"
#include "Carte.h"
#include <algorithm>


Joueur::Joueur(const std::string &name, const std::vector<Carte> &cartes) : nomJoueur(name), cartesEnMains(cartes) {}


void Joueur::detecterFamille(unsigned cardsPerFamily) {
    std::sort(cartesEnMains.begin(), cartesEnMains.end());
    size_t index = 0;
    unsigned nbFamily = 1;
    size_t limit = cartesEnMains.size();
    while (index < limit) {
        int number = std::count_if(cartesEnMains.begin() + index, cartesEnMains.end(),
                                   [nbFamily](const Carte &c) {
                                       return c.getFamily() == nbFamily;
                                   });
        ++nbFamily;
        if (number == cardsPerFamily) {
            ajoutSurTable(index, cardsPerFamily);
            cartesEnMains.erase(cartesEnMains.begin() + index, cartesEnMains.begin() + index + cardsPerFamily);
            limit = cartesEnMains.size();
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
    familleSurTable.insert(familleSurTable.end(), cartesEnMains.begin() + index,
                           cartesEnMains.begin() + index + cardsPerFamily);
    /*
    for (Carte c : this->cartesEnMains) {
        this->familleSurTable.push_back(c);
    }
     */
}

/*
void Joueur::demanderCarte(Joueur &joueur, const unsigned short &famille, const unsigned short member) {
    for (Carte c : joueur.cartesEnMain()) {
        if (c.getFamily() == famille && c.getMember() == member) {
            joueur.supprimerCarte(c);
            this->ajoutCarte(c,);
        }
    }
}*/

void Joueur::ajoutCarte(Carte &carte, unsigned cardsPerFamily) {
    this->cartesEnMains.push_back(carte);
    detecterFamille(cardsPerFamily);
}

bool Joueur::mainVide() const {
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
        std::cout << nomJoueur << " demande à " << target.nomJoueur << " la carte " << ask << " ";
        if (target.giveCard(ask)) {
            ajoutCarte(ask, cardsPerFamily);
            std::cout << target.nomJoueur << " donne la carte à " << nomJoueur << std::endl;
        } else {
            std::cout << "mais " << target.nomJoueur << " ne l'a pas" << std::endl;
            return;
        }
    }
}

Carte Joueur::choseCard() const {
    unsigned family = cartesEnMains.front().getFamily();
    unsigned member = 1;
    Carte search = Carte(family, member);
    auto pos = std::find(cartesEnMains.begin(), cartesEnMains.end(), search);
    while (pos != cartesEnMains.end()) {
        ++member;
        search = Carte(family, member);
        pos = std::find(cartesEnMains.begin(), cartesEnMains.end(), search);
    }
    return search;
}

bool Joueur::giveCard(const Carte &c) {
    auto pos = std::find(cartesEnMains.begin(), cartesEnMains.end(), c);
    if (pos != cartesEnMains.end()) {
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
    for (const Carte &c : rhs.familleSurTable) {
        lhs << c << ".";
    }
    lhs << "]";
    return lhs;
}

const std::string &Joueur::getNomJoueur() const {
    return nomJoueur;
}

void Joueur::assign(const std::string &name, const std::vector<Carte> &cartes) {
    nomJoueur = name;
    cartesEnMains = cartes;
}

