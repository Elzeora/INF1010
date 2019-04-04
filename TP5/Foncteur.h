/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher { // TODO fait
public:
	FoncteurPlatMoinsCher(Plat plat1, Plat plat2)
		: plat1_(plat1), plat2_(plat2) {};
	bool operator()(Plat plat1, Plat plat2) {
		return plat1.getPrix() < plat2.getPrix();
	}

private:
	Plat plat1_;
	Plat plat2_;
};

class FoncteurIntervalle { // TODO fait
public:
	FoncteurIntervalle(double min, double max)
		: min_(min), max_(max) {};
	// Plat* car c'est ce que contient la map de plats
	bool operator()(Plat* plat) {
		//copy_if p39////////////////////////////////////////////////////////////////////////////////////
		return plat->getPrix() >= min_ && plat->getPrix() >= max_;
	}

private:
	double min_;
	double max_;
};

/*
class FoncteurMeilleureTable {
public:
	FoncteurMeilleureTable(...)
	int operator()(Table* table, int tailleGroupe) {
		return table->getNbPlaces() - tailleGroupe;
	}
private:


};
*/
