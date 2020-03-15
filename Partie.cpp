//
// Created by leonard on 3/6/20.
//

#include "Partie.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

/**
 * Generate a random number between 0 and maxRange excluding the forbidden number
 * @param maxRange an unsigned the maximum number in the range (included)
 * @param forbidden an unsigned a number that cannot be returned by the generator
 * @return an unsigned in the range [0, maxRange]-forbidden
 */
unsigned generateRandomNumber(unsigned maxRange, unsigned forbidden);

unsigned generateRandomNumber(unsigned maxRange, unsigned forbidden) {
    std::mt19937 eng(std::chrono::high_resolution_clock::now().time_since_epoch().count()); // seed the generator
    std::uniform_int_distribution<> distr(0, maxRange);
    unsigned output = distr(eng);
    while (output == forbidden) {
        output = distr(eng);
    }
    return output;
}


Partie::Partie(const std::vector<std::string> &playerName, std::vector<Joueur *> list, unsigned nbFamily,
               unsigned cardsPerFamily,
               unsigned cardsPerPlayer)
        : cardPerFamily(cardsPerFamily) {

    std::vector<Carte> cards;
    cards.reserve(nbFamily * cardsPerFamily);

    for (unsigned family = 1; family <= nbFamily; ++family) {
        for (unsigned member = 1; member <= cardsPerFamily; ++member) {
            cards.emplace_back(family, member);
        }
    }


    std::shuffle(cards.begin(), cards.end(),
                 std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count()));

    for (int i = 0; i < playerName.size(); ++i) {
        list.at(i)->clearPlayer();
        list.at(i)->assign(playerName.at(i), std::vector<Carte>(cards.begin() + i * cardsPerPlayer,
                                                                cards.begin() + i * cardsPerPlayer + cardsPerPlayer));

        player.push_back(list.at(i));
    }

    stack.assign(cards.begin() + playerName.size() * cardsPerPlayer, cards.end());
}

std::vector<unsigned> Partie::play(unsigned startPerson) {
    std::vector<unsigned int> score(player.size());
    bool isPlaying = true;
    unsigned turn = 1;

    while (isPlaying) {
        std::cout << "*** Tour " << turn++ << " ***" << std::endl;
        displayPlayer();
        displayStack();

        for (int i = 0; i < player.size(); ++i) {
            size_t indexCurrent = (startPerson + i) % player.size();
            Joueur *current = player.at(indexCurrent);
            Joueur *target = player.at(generateRandomNumber(player.size() - 1, indexCurrent));

            current->play(*target, cardPerFamily);

            if (!stack.empty()) {
                Carte c = stack.back();
                current->ajoutCarte(c, cardPerFamily);
                stack.pop_back();
                std::cout << current->getNomJoueur() << " prend une carte dans la pioche (" << c << ")" << std::endl;
            }
        }

        isPlaying = false;
        for (const auto &j : player) {
            if (!j->mainVide()) {
                isPlaying = true;
                break;
            }
        }

    }

    displayPlayer();
    displayStack();
    std::cout << "La partie est finie !" << std::endl << "Nombre de tours : " << turn << std::endl;

    for (int i = 0; i < player.size(); ++i) {
        score.at(i) = player.at(i)->nbCarteStack() / cardPerFamily;
    }
    return score;
}

void Partie::displayStack() {
    std::cout << "Pioche: ";
    for (Carte card: stack) {
        std::cout << card << " ";
    }
    std::cout << std::endl;
}

void Partie::displayPlayer() {
    for (const auto &j : player) {
        std::cout << *j << std::endl;
    }
}




