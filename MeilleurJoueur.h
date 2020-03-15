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
    MeilleurJoueur() = default;
protected:
    Carte choseCard() const override;
};


#endif //LABO3_MEILLEURJOUEUR_H
