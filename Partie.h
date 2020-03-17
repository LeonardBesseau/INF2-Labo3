/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Léonard Besseau, Alexandra Cerottini, Nicolas Viotti
 Date        : 24.02.2020

 But         : Contient les fonctions liées à la classe Partie

 Remarque(s) :

 Compilateur : gcc version 7.4.0
 -----------------------------------------------------------------------------------
*/

#ifndef LABO3_PARTIE_H
#define LABO3_PARTIE_H

#include "Carte.h"
#include "Joueur.h"
#include "MeilleurJoueur.h"
#include <vector>
#include <array>

class Partie {
public:
    /**
     * Construct a Partie with the given parameters
     * @param nbFamily an unsigned, the number of family in the game
     * @param cardsPerFamily an unsigned, the number of cards per family
     * @param cardsPerPlayer the number of cards per player at the start of the game
     */
    Partie(std::vector<Joueur *>, unsigned nbFamily,
           unsigned cardsPerFamily,
           unsigned cardsPerPlayer);

    /**
     * Play the game
     * @param startPerson an unsigned the index of the starting position
     */
    void play(unsigned startPerson);

private:
    unsigned cardPerFamily;
    std::vector<Carte> stack;
    std::vector<Joueur *> player;

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
