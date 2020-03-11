//
// Created by leonard on 3/6/20.
//

#ifndef LABO3_PARTIE_H
#define LABO3_PARTIE_H

#include "Carte.h"
#include "Joueur.h"
#include <vector>
#include <array>

class Partie {
public:
    /**
     * Construct a Partie with the given parameters
     * @param playerName a vector of string containing the name of the player.
     * The number of name is the number of player
     * @param nbFamily an unsigned, the number of family in the game
     * @param cardsPerFamily an unsigned, the number of cards per family
     * @param cardsPerPlayer the number of cards per player at the start of the game
     */
    Partie(const std::vector<std::string> &playerName, unsigned nbFamily, unsigned cardsPerFamily,
           unsigned cardsPerPlayer);

    /**
     * Play the game
     * @param startPerson an unsigned the index of the starting position
     * @return a vector of unsigned containing the score of each player
     */
    std::vector<unsigned> play(unsigned startPerson);

private:
    unsigned cardPerFamily;
    std::vector<Carte> stack;
    std::vector<Joueur> player;

    /**
     * Display the stack on the standard output
     */
    void displayStack();

    /**
     * Display the information of all the players on the standard output
     */
    void displayPlayer();
};


#endif //LABO3_PARTIE_H
