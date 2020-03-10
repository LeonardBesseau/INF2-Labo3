//
// Created by leonard on 3/6/20.
//

#include "Joueur.h"
#include "Carte.h"
#include <algorithm>



void Joueur::detecterFamille()
{
    size_t count=0;
    for (size_t i = 0; i<this->cartesEnMains.size()-1;i++)
    {
        if(cartesEnMains.at(i).getFamily() == cartesEnMains.at(i+1).getFamily()) {
            count++;
            if (count == cartesEnMains.size()-1) {
                ajoutSurTable();
            }
        }
    }

}

void Joueur::ajoutSurTable()
{
        for(Carte c : this->cartesEnMains)
        {
            this->familleSurTable.push_back(c);
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
            joueur.supprimerCarte(carte);
            this->ajoutCarte(c);
        }
    }
}
void Joueur::ajoutCarte(Carte& carte)
{
    this->cartesEnMains.push_back(carte);
}

void Joueur::supprimerCarte(Carte& carte){
    auto pos = find(this->cartesEnMains.begin(), this->cartesEnMains.end(),carte);
    this->cartesEnMains.erase(pos);
}

bool Joueur::mainVide(){
    return cartesEnMains.empty();
}
