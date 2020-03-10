//
// Created by leonard on 3/6/20.
//

#include "Partie.h"
#include <iostream>
#include <algorithm>
#include <random>

unsigned generateRandomNumber(unsigned maxRange, unsigned forbidden);

unsigned generateRandomNumber(unsigned maxRange, unsigned forbidden) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, maxRange);
    unsigned output = distr(eng);
    while (output == forbidden) {
        output = distr(eng);
    }
    return output;
}


Partie::Partie(const std::vector<std::string> &playerName, unsigned nbFamily, unsigned cardsPerFamily,
               unsigned cardsPerPlayer)
        : cardPerFamily(cardsPerFamily), turns(0) {

    std::vector<Carte> cards;
    cards.reserve(nbFamily * cardsPerFamily);
    for (unsigned family = 1; family <= nbFamily; ++family) {
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

std::vector<unsigned> Partie::play(unsigned startPerson) {
    std::vector<unsigned int> score(player.size());
    bool isPlaying = true;
    unsigned turn = 1;
    while (isPlaying) {
        std::cout << "*** Tour " << turn++ << " ***" << std::endl;
        for (int i = 0; i < player.size(); ++i) {
            Joueur *current = &player.at((startPerson + i) % player.size());
            Joueur &target = player.at(generateRandomNumber(player.size() - 1, startPerson + i) % player.size());
            current->play(target, cardPerFamily);
            if (!stack.empty()) {
                current->ajoutCarte(stack.back());
                stack.pop_back();
            }
            isPlaying = !(stack.empty() && current->mainVide());
        }
    }
    for (int i = 0; i < player.size(); ++i) {
        score.at(i) = player.at(i).nbCarteStack() / cardPerFamily;
    }
    return score;
}




