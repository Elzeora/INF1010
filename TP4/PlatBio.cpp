
/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe)
	: Plat(nom, prix, cout), ecoTaxe_(ecotaxe)
{
}

PlatBio::~ PlatBio(){}

double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe)
{
	ecoTaxe_ = ecoTaxe;
}

//TODO
Plat * PlatBio:: clone () const
{
	Plat* copiePlat = new Plat(nom_, prix_, cout_);
	return copiePlat;

	//return Plat::clone();
}
double PlatBio:: getPrixDeRevient()
{ //TODO fait
	return prix_ - cout_ + ecoTaxe_;
}

void PlatBio::afficherPlat(ostream& os) const
{ //TODO fait
	os << "PLAT BIO   comprend une Taxe ecologique de: " << ecoTaxe_ << "$" << endl;
	Plat::afficherPlat(os);
}
