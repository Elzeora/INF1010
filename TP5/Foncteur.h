/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;

/****************************************************************************
 * Class: FoncteurPlatMoinsCher
 * Description: Un foncteur prédicat binaire permet  de  comparer  les plats deux à deuxdu conteneur ma
 ****************************************************************************/
class FoncteurPlatMoinsCher { // TODO fait
public:
	FoncteurPlatMoinsCher() {}
	bool operator()(const pair<string, Plat*>& plat1, const pair<string, Plat*>& plat2) {
		return plat1.second->getPrix() < plat2.second->getPrix();
	}
};

/****************************************************************************
 * Class: FoncteurPlatMoinsCher
 * Description:   Un  foncteurprédicatunaireayantla  borne  inférieure  et  la borne supérieure comme attributs.
 *    Ce foncteurprend en entrée un plat uniquedu conteneur mapet vérifiesison prix est compris entre les bornes
 ****************************************************************************/
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
