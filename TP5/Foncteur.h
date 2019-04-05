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
	FoncteurPlatMoinsCher(pair<string, Plat*> plat)
		: plat_(plat) {}
	bool operator()(pair<string, Plat*> plat) {
		return plat_.second->getPrix() < plat.second->getPrix();
	}

private:
	pair<string, Plat*> plat_;
};

class FoncteurIntervalle { // TODO fait
public:
	FoncteurIntervalle(double min, double max)
		: min_(min), max_(max) {}
	bool operator()(Plat* plat) {
		return plat->getPrix() >= min_ && plat->getPrix() >= max_;
	}

private:
	double min_;
	double max_;
};
