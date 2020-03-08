//
// Created by leonard on 3/6/20.
//

#include "Partie.h"

Partie::Partie(unsigned nbPlayer, unsigned nbFamilly, unsigned cardsPerFamily, unsigned cardsPerPlayer): cardPerFamilly(cardsPerFamily) {
    std::vector<Carte> cards(nbFamilly*cardsPerFamily);
    for (int i = 1; i <= nbFamilly; ++i) {

    }
    player = std::vector<Joueur>(nbPlayer);
}

unsigned int Partie::getTurns() const {
    return Turns;
}

const std::vector<Carte> &Partie::getStack() const {
    return Stack;
}

const std::vector<Joueur> &Partie::getPlayerList() const {
    return player;
}

void Partie::displayStack() {

}




