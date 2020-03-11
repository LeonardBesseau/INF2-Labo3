//
// Created by leonard n 3/6/20.
//

#ifndef LABO3_JOUEUR_H
#define LABO3_JOUEUR_H
#include <vector>
#include "Carte.h"
#include <string>
#include <iostream>


class Joueur {
    friend std::ostream &operator<<(std::ostream &lhs, const Joueur &rhs);
public:
    Joueur(const std::string &name, const std::vector<Carte> &cartes) : nomJoueur(name), cartesEnMains(cartes) {}

    Joueur() = default;

    void detecterFamille(unsigned cardsPerFamily);

    bool mainVide() const;

    std::vector<Carte> cartesEnMain() const;

    //   void demanderCarte(Joueur &joueur, const unsigned short &famille, unsigned short member);

    void ajoutCarte(Carte &carte, unsigned cardsPerFamily);

    void supprimerCarte(Carte &carte);

    void ajoutSurTable(unsigned index, unsigned cardsPerFamily);

    unsigned nbCarteStack();

    Carte choseCard() const;

    void play(Joueur &target, unsigned cardsPerFamily);

    bool giveCard(const Carte &c);

    const std::string &getNomJoueur() const;


    //unsigned short compteCarte(){};
private:
    std::string nomJoueur;
    std::vector<Carte> cartesEnMains;
    std::vector<Carte> familleSurTable;
};


#endif //LABO3_JOUEUR_H
