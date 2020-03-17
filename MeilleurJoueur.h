/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : MeilleurJoueur.h
 Auteur(s)   : Léonard Besseau, Alexandra Cerottini, Nicolas Viotti
 Date        : 24.02.2020

 But         : Contient les fonctions liées à la classe MeilleurJoueur

 Remarque(s) :

 Compilateur : gcc version 7.4.0
 -----------------------------------------------------------------------------------
*/

#ifndef LABO3_MEILLEURJOUEUR_H
#define LABO3_MEILLEURJOUEUR_H

#include "Joueur.h"

class MeilleurJoueur : public Joueur {
public:
    MeilleurJoueur(const std::string &name) : Joueur(name) {};
protected:
    /**
     * Chose which card to ask
     * @return a Carte, the one to ask from the other player
     * @details choose a card from the most populated family in the deck
     */
    Carte choseCard() const override;
};


#endif //LABO3_MEILLEURJOUEUR_H
