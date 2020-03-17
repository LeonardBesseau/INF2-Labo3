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


Joueur::Joueur(const std::string &name) : name(name), score(0) {}


void Joueur::detecterFamille(unsigned cardsPerFamily) {
    std::sort(deck.begin(), deck.end());
    size_t index = 0;
    unsigned family = 1;
    size_t limit = deck.size();

    while (index < limit) {
        unsigned number = numberOfMember(family, index);
        ++family;

        if (number == cardsPerFamily) {
            ajoutSurTable(index, cardsPerFamily);
            deck.erase(deck.begin() + index, deck.begin() + index + cardsPerFamily);
            limit = deck.size();
        } else {
            index += number;
        }

    }
}

void Joueur::ajoutSurTable(unsigned index, unsigned cardsPerFamily) {
    completedFamillies.insert(completedFamillies.end(), deck.begin() + index,
                              deck.begin() + index + cardsPerFamily);
}

void Joueur::ajoutCarte(Carte &carte, unsigned cardsPerFamily) {
    this->deck.push_back(carte);
    detecterFamille(cardsPerFamily);
}

bool Joueur::mainVide() const {
    return deck.empty();
}

unsigned Joueur::nbCarteStack() const {
    return completedFamillies.size();
}

void Joueur::play(Joueur &target, unsigned cardsPerFamily) {
    while (true) {
        if (deck.empty()) {
            return;
        }
        Carte ask = choseCard();

        std::cout << name << " demande a " << target.name << " la carte " << ask << " " << std::endl;

        if (target.giveCard(ask)) {
            std::cout << "  et " << target.name << " donne la carte a " << name << std::endl;
            ajoutCarte(ask, cardsPerFamily);
        } else {
            std::cout << "  mais " << target.name << " ne l'a pas" << std::endl;
            return;
        }
    }
}

Carte Joueur::choseCard() const {
    return findMissingMember(deck.front().getFamily());
}

bool Joueur::giveCard(const Carte &c) {
    auto pos = std::find(deck.begin(), deck.end(), c);
    if (pos != deck.end()) {
        deck.erase(pos);
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &lhs, const Joueur &rhs) {
    lhs << rhs.name << " : ";
    for (const Carte &c : rhs.deck) {
        lhs << c << " ";
    }
    lhs << "[";
    for (const Carte &c : rhs.completedFamillies) {
        lhs << c << ".";
    }
    lhs << "]";
    return lhs;
}

const std::string &Joueur::getNomJoueur() const {
    return name;
}

void Joueur::assign(const std::vector<Carte> &cartes, unsigned cardsPerFamily) {
    deck = cartes;
    detecterFamille(cardsPerFamily);
}

void Joueur::clearPlayer() {
    completedFamillies.clear();
}

Carte Joueur::findMissingMember(unsigned family) const {
    unsigned member = 1;
    Carte search = Carte(family, member);
    auto pos = std::find(deck.begin(), deck.end(), search);
    while (pos != deck.end()) {
        search = Carte(family, ++member);
        pos = std::find(deck.begin(), deck.end(), search);
    }
    return search;
}

unsigned Joueur::numberOfMember(unsigned family, unsigned index) const {
    return std::count_if(deck.begin() + index, deck.end(),
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

