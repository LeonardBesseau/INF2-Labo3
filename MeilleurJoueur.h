//
// Created by leonard on 3/11/20.
//

#ifndef LABO3_MEILLEURJOUEUR_H
#define LABO3_MEILLEURJOUEUR_H

#include "Joueur.h"

class MeilleurJoueur : public Joueur {
public:
    MeilleurJoueur(const std::string &name, const std::vector<Carte> &cartes) : Joueur(name, cartes) {};

    MeilleurJoueur() : Joueur() {};
protected:
    Carte choseCard() const override;

private:
};


#endif //LABO3_MEILLEURJOUEUR_H
