/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Joueur.cpp
 Auteur(s)   : Léonard Besseau, Alexandra Cerottini, Nicolas Viotti
 Date        : 24.02.2020

 But         : Contient les fonctions liées à la classe Joueur

 Remarque(s) :

 Compilateur : gcc version 7.4.0
 -----------------------------------------------------------------------------------
*/

#include "Joueur.h"
#include "Carte.h"
#include <algorithm>


Joueur::Joueur(const std::string &name) : nomJoueur(name), score(0) {}


void Joueur::detecterFamille(unsigned cardsPerFamily) {
    std::sort(cartesEnMains.begin(), cartesEnMains.end());
    size_t index = 0;
    unsigned family = 1;
    size_t limit = cartesEnMains.size();

    while (index < limit) {
        unsigned number = numberOfMember(family, index);
        ++family;

        if (number == cardsPerFamily) {
            ajoutSurTable(index, cardsPerFamily);
            cartesEnMains.erase(cartesEnMains.begin() + index, cartesEnMains.begin() + index + cardsPerFamily);
            limit = cartesEnMains.size();
        } else {
            index += number;
        }

    }
}

void Joueur::ajoutSurTable(unsigned index, unsigned cardsPerFamily) {
    familleSurTable.insert(familleSurTable.end(), cartesEnMains.begin() + index,
                           cartesEnMains.begin() + index + cardsPerFamily);
}

void Joueur::ajoutCarte(Carte &carte, unsigned cardsPerFamily) {
    this->cartesEnMains.push_back(carte);
    detecterFamille(cardsPerFamily);
}

bool Joueur::mainVide() const {
    return cartesEnMains.empty();
}

unsigned Joueur::nbCarteStack() const {
    return familleSurTable.size();
}

void Joueur::play(Joueur &target, unsigned cardsPerFamily) {
    while (true) {
        if (cartesEnMains.empty()) {
            return;
        }
        Carte ask = choseCard();

        std::cout << nomJoueur << " demande a " << target.nomJoueur << " la carte " << ask << " " << std::endl;

        if (target.giveCard(ask)) {
            std::cout << "  et " << target.nomJoueur << " donne la carte a " << nomJoueur << std::endl;
            ajoutCarte(ask, cardsPerFamily);
        } else {
            std::cout << "  mais " << target.nomJoueur << " ne l'a pas" << std::endl;
            return;
        }
    }
}

Carte Joueur::choseCard() const {
    return findMissingMember(cartesEnMains.front().getFamily());
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

void Joueur::assign(const std::vector<Carte> &cartes, unsigned cardsPerFamily) {
    cartesEnMains = cartes;
    detecterFamille(cardsPerFamily);
}

void Joueur::clearPlayer() {
    familleSurTable.clear();
}

Carte Joueur::findMissingMember(unsigned family) const {
    unsigned member = 1;
    Carte search = Carte(family, member);
    auto pos = std::find(cartesEnMains.begin(), cartesEnMains.end(), search);
    while (pos != cartesEnMains.end()) {
        search = Carte(family, ++member);
        pos = std::find(cartesEnMains.begin(), cartesEnMains.end(), search);
    }
    return search;
}

unsigned Joueur::numberOfMember(unsigned family, unsigned index) const {
    return std::count_if(cartesEnMains.begin() + index, cartesEnMains.end(),
                         [family](const Carte &c) {
                             return c.getFamily() == family;
                         });
}

unsigned int Joueur::getScore() const {
    return score;
}

void Joueur::addScore(unsigned score) {
    this->score += score;

}

