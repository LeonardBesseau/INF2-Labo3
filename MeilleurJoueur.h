//
// Created by leonard on 3/11/20.
//

#ifndef LABO3_MEILLEURJOUEUR_H
#define LABO3_MEILLEURJOUEUR_H

#include "Joueur.h"

class MeilleurJoueur : public Joueur {
public:
    MeilleurJoueur() = default;
protected:
    Carte choseCard() const override;
};


#endif //LABO3_MEILLEURJOUEUR_H
