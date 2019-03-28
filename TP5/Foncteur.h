/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher { // TODO
	bool operator()(Plat plat1, Plat plat2) {
		return plat1.getPrix() < plat2.getPrix();
	}
};

class FoncteurIntervalle { // TODO
	bool operator()(Plat plat) {
		//copy_if p39////////////////////////////////////////////////////////////////////////////////////
		return plat.getPrix() > borneInferieure_ && plat.getPrix() < borneSuperieure_;
	}

private:
	int borneInferieure_;
	int borneSuperieure_;
};

class FoncteurMeilleureTable {
	int operator()(Table* table, int tailleGroupe) {
		return table->getNbPlaces() - tailleGroupe;
	}


};

