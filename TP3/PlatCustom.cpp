/*
* Titre : PlatCustom.cpp - Travail Pratique #3
* Date :  F�vrier 2019
* Auteur : Louis Roberge
*/

#include "PlatCustom.h"

/****************************************************************************
 * Fonction: PlatCustom::PlatCustom
 * description: constructeur par param�tres
 * Param�tres:	- string nom
 *				- double prix
 *				- double cout
 *				- int nbIngredients
 ****************************************************************************/
PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients) : Plat(nom, prix, cout), nbIngredients_(nbIngredients) {
	supplement_ = calculerSupplement();
	type_ = Custom;
}

/****************************************************************************
 * Fonction: PlatCustom::getNbIngredients
 * description: accesseur de nbIntegredients
 * Param�tres:	aucun
 * retour nbIgredients
 ****************************************************************************/
int PlatCustom::getNbIngredients() const {
	return nbIngredients_;
}

/****************************************************************************
 * Fonction: PlatCustom::getSupplement
 * description: getter de supplement
 * Param�tres:	aucun
 * retour: supplement_
 ****************************************************************************/
double PlatCustom::getSupplement()const {
	return supplement_;
}

/****************************************************************************
 * Fonction: PlatCustom::setNbIngredients
 * description: setter de NbIngredients
 * Param�tres:	nbIngredients
 * retour: aucun
 ****************************************************************************/
void PlatCustom::setNbIngredients(int nbIngredients) {
	nbIngredients_ = nbIngredients;
}

/****************************************************************************
 * Fonction: PlatCustom::calculerSupplement
 * description: permet de calculer le supplement
 * Param�tres:	rien
 * retour: le resultat en double du supplement
 ****************************************************************************/
double PlatCustom::calculerSupplement() const {
	return nbIngredients_ * FRAIS_CUSTOMISATION;
}

/****************************************************************************
 * Fonction: operator<<
 * description: afficher le PlatCustom
 * Param�tres:	- os
 *				- plat
 ****************************************************************************/
ostream& operator<<(ostream& os, const PlatCustom& plat) {
	os << "contient " << plat.nbIngredients_ 
	   << " element(s) en plus pour un supplement total de : "
	   << plat.supplement_ << endl;
	return os;
}