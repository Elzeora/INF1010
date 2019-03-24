#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe): Plat(nom, prix, cout), ecoTaxe_(ecotaxe){
}

PlatBio::~ PlatBio(){}

double PlatBio::getEcoTaxe() const
{	return ecoTaxe_;}

void PlatBio::setEcoTaxe(double ecoTaxe)
{	ecoTaxe_ = ecoTaxe;}

Plat * PlatBio:: clone () const {
	PlatBio* copiePlat = new PlatBio(nom_, prix_, cout_, ecoTaxe_);
	return copiePlat;
}
double PlatBio:: getPrixDeRevient()
{ 	return prix_ - cout_ + ecoTaxe_;}

void PlatBio::afficherPlat(ostream& os) const {
	static_cast<Plat>(*this).afficherPlat(os);
    os << "BIO comprend une Taxe ecologique de : " << this->getEcoTaxe() << "$\n";
}


