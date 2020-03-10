//
// Created by leonard on 3/6/20.
//

#include "Partie.h"
#include <iostream>
#include <algorithm>

Partie::Partie(const std::vector<std::string> &playerName, unsigned nbFamilly, unsigned cardsPerFamily,
               unsigned cardsPerPlayer)
        : cardPerFamily(cardsPerFamily), turns(0) {

    std::vector<Carte> cards;
    cards.reserve(nbFamilly * cardsPerFamily);
    for (unsigned family = 1; family <= nbFamilly; ++family) {
        for (unsigned member = 1; member < cardsPerFamily; ++member) {
            cards.emplace_back(family, member);
        }
    }
    std::random_shuffle(cards.begin(), cards.end());
    for (int i = 0; i < playerName.size(); ++i) {
        player.emplace_back(playerName.at(i), std::vector<Carte>(cards.begin() + i * cardsPerPlayer,
                                                                 cards.begin() + i * cardsPerPlayer + cardsPerPlayer));
    }
    stack.assign(cards.begin() + playerName.size() * cardsPerPlayer, cards.end());
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

unsigned int Partie::getCardPerFamily() const {
    return cardPerFamily;
}

std::vector<unsigned> Partie::play() {
    std::vector<unsigned int> score(player.size());
    bool isPlaying = true;
    unsigned turn = 1;
    while (isPlaying){
        std::cout << "*** Tour "<< turn++ << " ***"<<std::endl;
        for (Joueur j : player){
            //j.play();
            if(!stack.empty()){
                //j.ajouteCarte(stack.back());
                stack.pop_back();
            }
            isPlaying = !(stack.empty()  && j.mainVide());
        }
    }
    for (int i = 0; i < player.size(); ++i) {
      //  score.at(i) =
    }
    return score;
}




