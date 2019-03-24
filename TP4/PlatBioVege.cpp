#include "PlatBioVege.h"

PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux) 
	: PlatBio(nom, prix, cout, ecotaxe), Vege(nom, vitamines, proteines, mineraux){
}

PlatBioVege:: ~PlatBioVege(){}


void PlatBioVege::afficherPlat(ostream & os) const{   
	static_cast<PlatBio>(*this).afficherPlat(os);
	os << "ET ";
	static_cast<Vege>(*this).afficherVege(os);
	os << "(Apport nutritif " << this->calculerApportNutritif() << "mg)\n";
}

Plat * PlatBioVege::clone() const{ 
	PlatBioVege* copiePlat = new PlatBioVege(PlatBio::nom_, prix_, cout_, ecoTaxe_, vitamines_, proteines_, mineraux_);
	return copiePlat;
}

double PlatBioVege::calculerApportNutritif() const{
	return (this->getVitamines() * this->getProteines() * RAPPORT_NUTRITIF_BIO * AVANTAGE_SANS_PESTICIDE) / this->getMineraux();
}
