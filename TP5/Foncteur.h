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
	FoncteurPlatMoinsCher() {}
	bool operator()(const pair<string, Plat*>& plat1, const pair<string, Plat*>& plat2) {
		return plat1.second->getPrix() < plat2.second->getPrix();
	}
};

class FoncteurIntervalle { // TODO fait
public:
	FoncteurIntervalle(double min, double max)
		: min_(min), max_(max) {}
	bool operator()(const pair<string, Plat*>& plat) {
		return (plat.second->getPrix() < max_) && (plat.second->getPrix() > min_);
	}

private:
	double min_;
	double max_;
};
