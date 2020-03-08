//
// Created by leonard on 3/6/20.
//

#include "Partie.h"
#include <iostream>
#include <algorithm>

Partie::Partie(unsigned nbPlayer, unsigned nbFamilly, unsigned cardsPerFamily, unsigned cardsPerPlayer)
        : cardPerFamilly(cardsPerFamily), turns(0) {
    std::vector<Carte> cards(nbFamilly * cardsPerFamily);
    for (unsigned family = 1; family <= nbFamilly; ++family) {
        for (unsigned member = 1; member < cardsPerFamily; ++member) {
            cards.emplace_back(family, member);
        }
    }
    std::random_shuffle(cards.begin(), cards.end());
    player = std::vector<Joueur>(nbPlayer);
    for (int player = 0; player < nbPlayer; ++player) {
        //addDeck
        // cards.begin()+player*cardsPerPlayer, cards.begin()+player*cardsPerPlayer+cardsPerPlayer
    }
    stack.assign(cards.begin() + nbPlayer * cardsPerPlayer, cards.end());
}

unsigned int Partie::getTurns() const {
    return turns;
}

const std::vector<Carte> &Partie::getStack() const {
    return stack;
}

const std::vector<Joueur> &Partie::getPlayerList() const {
    return player;
}

void Partie::displayStack() {
    std::cout << "Pioche: ";
    for (Carte card: stack) {
        std::cout << card << " ";
    }
    std::cout << std::endl;
}




