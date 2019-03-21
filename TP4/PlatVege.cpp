/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"



PlatVege::PlatVege(string nom, double prix, double cout, double vitamines, double proteines, double mineraux)
	: Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux){
}

PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const {
	PlatVege* copiePlat = new PlatVege(Plat::nom_, prix_, cout_, vitamines_, proteines_, mineraux_);
	return copiePlat;
}


void PlatVege::afficherPlat(ostream & os) const {
	Plat::afficherPlat(os);
	Vege::afficherVege(os);
}

double PlatVege::calculerApportNutritif() const {
	return (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF;
}

void PlatVege::setTaxe() { taxe_ = 0.07; }
double PlatVege::getTaxe() const { return taxe_; }