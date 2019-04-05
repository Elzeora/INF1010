/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include "Foncteur.h"

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 
template<typename T, typename C>
class GestionnaireGenerique
{
public:
	C getConteneur() const { //TODO fait
		C conteneurCopy;
		copy(conteneur_.begin(), conteneur_.end(), conteneurCopy.begin());
		return conteneurCopy;
	}

	void ajouter(T t) {//TODO fait
		conteneur_.insert(t);
	}

	int getNombreElements() const {//TODO fait
		return conteneur_.size();
	}

protected:
	C conteneur_;
};

