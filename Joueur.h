/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Joueur.h
 Auteur(s)   : Léonard Besseau, Alexandra Cerottini, Nicolas Viotti
 Date        : 24.02.2020

 But         : Contient les fonctions liées à la classe Joueur

 Remarque(s) :

 Compilateur : gcc version 7.4.0
 -----------------------------------------------------------------------------------
*/

#ifndef LABO3_JOUEUR_H
#define LABO3_JOUEUR_H

#include <vector>
#include "Carte.h"
#include <string>
#include <iostream>


class Joueur {
    friend std::ostream &operator<<(std::ostream &lhs, const Joueur &rhs);

public:
    /**
     * Construct a player
     * @param name a string with the name of the player
     */
    Joueur(const std::string &name);


    /**
   * Asign a deck to the player
   * @param carte a vector of cartes the new deck of the player
   * @param cardsPerFamily the number of card per family
   */
    void assign(const std::vector<Carte> &cartes, unsigned cardsPerFamily);

    /**
     * Indicates if the player has no more card in its deck
     * @return true if deck is empty, false otherwise
     */
    bool mainVide() const;

    /**
     * Get the number of cards on the table
     * @return an unsigned with the number of cards
     */
    unsigned nbCarteStack() const;


    /**
     * Clear the completed famiiies deck
     */
    void clearPlayer();


    /**
     * Add a Carte to the player deck
     * @param carte the carte to add
     * @param cardsPerFamily the number of card per family
     */
    void ajoutCarte(Carte &carte, unsigned cardsPerFamily);


    /**
     * Player game loop
     * @param target a player to ask a card to
     * @param cardsPerFamily the number of cards per family
     */
    void play(Joueur &target, unsigned cardsPerFamily);


    /**
     * Get the player name
     * @return a string with the player name
     */
    const std::string &getNomJoueur() const;

    /**
     * Get the score of the player
     * @return an unsigned with the score of the player
     */
    unsigned int getScore() const;

    /**
     * Add points to the score player
     * @param score an unsigned the points to add
     */
    void addScore(unsigned score);

protected:
    /**
     * Chose which card to ask
     * @return a Carte, the one to ask from the other player
     */
    virtual Carte choseCard() const;

    /**
     * Find a missing member of a family based on the player deck
     * @param family the family to look for
     * @return a Card missing in the player deck
     */
    Carte findMissingMember(unsigned family) const;

    /**
     * Get the number of member of a given family in the player deck
     * @param family the family to look for
     * @param index a position  of where to start the search if the list is sorted
     * @return an unsigned, the number of mumber of the family
     */
    unsigned numberOfMember(unsigned family, unsigned index = 0) const;

    std::vector<Carte> deck;

private:
    /**
     * Check if a family is completed and if it is, put the family on the table
     * @param cardsPerFamily an unsigned with the number of cards per family
     */
    void detecterFamille(unsigned cardsPerFamily);


    /**
     * Add the carte on the table when a family is completed
     * @param index the starting position of the family
     * @param cardsPerFamily the number of cards per family
     * @attention assume the deck is sorted
     */
    void ajoutSurTable(unsigned index, unsigned cardsPerFamily);

    /**
     * Indicates if the demanded card is in the player game and can be exchanged
     * @param c the card to exchange
     * @return true if the card can be exchanged, false otherwise
     * @attention if the card can be exchanged, the card will be remove from the player deck
     */
    bool giveCard(const Carte &c);

    std::string name;
    std::vector<Carte> completedFamillies;
    unsigned score;

};


#endif //LABO3_JOUEUR_H
