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
 *				- double ecoTaxe
 ****************************************************************************/
PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients) : Plat(nom, prix, cout) {
	nbIngredients_ = nbIngredients;
	supplement_ = calculerSupplement(); 
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
 * Fonction: PlatCustom::setSupplement
 * description: setter de supplement
 * Param�tres:	ecoTaxe
 * retour: supplement_
 ****************************************************************************/
double PlatCustom::getSupplement()const {
	return supplement_;
}
/****************************************************************************
 * Fonction: PlatCustom::setNbIngredients
 * description: setter de NbIngredients
 * Param�tres:	nbIngredients
 ****************************************************************************/
void PlatCustom::setNbIngredients(int nbIngredients) {
	nbIngredients_ = nbIngredients;
}
/****************************************************************************
 * Fonction: PlatCustom::calculerSupplement
 * description: permet de calculer le supplement
 * Param�tres:	rien
 * retour le resultat en double du supplement
 ****************************************************************************/
double PlatCustom::calculerSupplement() const {
	return nbIngredients_*FRAIS_CUSTOMISATION;
}
ostream& operator<<(ostream& os, const PlatCustom& plat) {
	os << plat.nom_ << " - " << plat.prix_ << " $ (" << (plat.cout_+plat.getSupplement()) << "$ pour le restaurant)" << endl;
	return os;
}