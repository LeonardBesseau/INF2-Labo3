//
// Created by leonard on 3/6/20.
//

#include "Joueur.h"
#include "Carte.h"



void Joueur::detecterFamille() const
{
    for (size_t i = 0; i<this->cartesEnMains.size();i++)
    {
        if(!(this->mainVide()))
        {

        }
    }
}
std::vector<Carte> Joueur::cartesEnMain() const {
    return this->cartesEnMains;
}
void Joueur::demanderCarte(Joueur& joueur, const unsigned short& famille,const unsigned short member){
    for (Carte c : joueur.cartesEnMain())
    {
        if(c.getFamily() == famille && c.getMember() == member)
        {
            Carte carte(c.getFamily(),c.getMember());
            auto pos = find(joueur.cartesEnMains.begin(), joueur.cartesEnMains.end(),carte);
            joueur.cartesEnMains.erase(pos);
            this->ajoutCarte(c);
        }
    }
}
void Joueur::ajoutCarte(Carte& carte)
{
    this->cartesEnMains.push_back(carte);
}

void Joueur::supprimerCarte(){
}

void Joueur::mainVide()
{};
