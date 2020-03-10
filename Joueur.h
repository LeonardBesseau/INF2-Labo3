//
// Created by leonard n 3/6/20.
//

#ifndef LABO3_JOUEUR_H
#define LABO3_JOUEUR_H
#include <vector>
#include "Carte.h"
#include <string>
#include <algorithm>


class Joueur {
public:
    Joueur(const std::string& name, const std::vector<Carte> cartes): nomJoueur(name),cartesEnMains(cartes) {}
    Joueur() = default;
    bool detecterFamille() const;
    void mainVide();
    std::vector<Carte> cartesEnMain() const;
    void demanderCarte(Joueur& joueur, const unsigned short& famille, const unsigned short member);
    void ajoutCarte(Carte& carte);
    void supprimerCarte(Carte& carte);
    void ajoutSurTable(bool familleComplete);



    //unsigned short compteCarte(){};
private:
    std::string nomJoueur;
    std::vector<Carte> cartesEnMains;
    std::vector<Carte> familleSurTable;
};


#endif //LABO3_JOUEUR_H
