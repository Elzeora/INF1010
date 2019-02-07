/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Plat.h"

using namespace std;

//constructeurs
Plat::Plat() {
	nom_ = "Inconnu";
	prix_ = 0;
	cout_ = 0;
}

Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}
//getters

string Plat::getNom() const {
	return nom_;
}

double Plat::getPrix() const {
	return prix_;
}

double Plat::getCout() const {
	return cout_;
}
//setters
void Plat::setNom(string nom) {
	nom_ = nom;
}

void Plat::setPrix(double prix) {
	prix_ = prix;
}


/****************************************************************************
 * Fonction: operateur<<
 * Description: surcharge de l'opérateur << pour afficher un plat
 * Paramètres:	- ostream& os
				- Plat& plat
 * Retour: os
 ****************************************************************************/
ostream& operator<<(ostream& os, const Plat& plat) {
	os << plat.getNom() << " - " << plat.getPrix() << " $ (" << plat.getCout() << "$ pour le restaurant)" << endl;
	return os;
}

/****************************************************************************
 * Fonction: operateur<
 * Description: surcharge de l'opérateur < pour retourner vrai si le prix du
				plat courant est plus petit que le plat en parametre
 * Paramètres:	- Plat& plat
 * Retour: true ou false
 ****************************************************************************/
bool Plat::operator<(const Plat& plat) const {
	if (prix_ < plat.getPrix())
		return true;
	else
		return false;
}