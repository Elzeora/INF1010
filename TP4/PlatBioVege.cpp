
/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBioVege.h"

PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux)
	: PlatBio(nom, prix, cout, ecotaxe), Vege(nom, vitamines, proteines, mineraux) 
{ // TODO
}

PlatBioVege:: ~PlatBioVege(){}

//TODO fait
void PlatBioVege::afficherPlat(ostream & os) const
{   //TODO fait
	PlatBio::afficherPlat(os);
	os << "ET ";
	Vege::afficherVege(os);
}

Plat * PlatBioVege::clone() const
{ //TODO

	Plat* copiePlat = new Plat(Plat::nom_, prix_, cout_);
	return copiePlat;

	//return Plat::clone();
}

double PlatBioVege::calculerApportNutritif() const
{
   //TODO fait
	return (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF*AVANTAGE_SANS_PESTICIDE;
}