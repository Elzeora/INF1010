/*
* Titre : PlatBio.cpp - Travail Pratique #3
* Date :  Février 2019
* Auteur : Louis Roberge
*/

#include "PlatBio.h"

/****************************************************************************
 * Fonction: PlatBio::PlatBio
 * description: constructeur par paramètres
 * Paramètres:	- string nom
 *				- double prix
 *				- double cout
 *				- double ecoTaxe 
 ****************************************************************************/
PlatBio::PlatBio(string nom, double prix, double cout, double ecoTaxe) : Plat(nom,prix,cout){
	ecoTaxe_ = ecoTaxe;
}

/****************************************************************************
 * Fonction: PlatBio::getEcoTaxe()
 * description: accesseur ecoTaxe
 * Paramètres:	aucun
 * retour  ecoTaxe_
 ****************************************************************************/
double PlatBio::getEcoTaxe() const{
	return ecoTaxe_;
}

/****************************************************************************
 * Fonction: PlatBio::setEcoTaxe
 * description: setter ecoTaxe
 * Paramètres:	ecoTaxe
 ****************************************************************************/
void PlatBio::setEcoTaxe(double ecoTaxe) {
	ecoTaxe_ = ecoTaxe;
}
/****************************************************************************
 * Fonction: operator<<
 * description: surcharge de l'operateur <<
 * Paramètres:	- ostream& os
 *				- PlatBio& plat
 * retour os
 ****************************************************************************/
ostream& operator<<(ostream& os, const PlatBio& plat) {
	os << plat << endl;
	os << "      comprend une Taxe ecologique de : " << plat.ecoTaxe_ << "$" <<endl;
	return os;
}