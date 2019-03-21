/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"


// TODO fait
PlatVege::PlatVege(string nom, double prix, double cout, double vitamines, double proteines, double mineraux)
	: Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux)
{
}

PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const
{ // TODO fait
	PlatVege* copiePlat = new PlatVege(Plat::nom_, prix_, cout_, vitamines_, proteines_, mineraux_);
	return copiePlat;
}


void PlatVege::afficherPlat(ostream & os) const
{   //TODO fait
	Plat::afficherPlat(os);
	Vege::afficherVege(os);
}

double PlatVege::calculerApportNutritif() const
{ // TODO fait
	return (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF;
}