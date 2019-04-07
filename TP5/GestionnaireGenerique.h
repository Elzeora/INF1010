/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Foncteur.h"
#include "debogageMemoire.hpp"

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 
template<typename T, typename C>
class GestionnaireGenerique
{
public:

	C getConteneur() const; //TODO fait

	void ajouter(T t); //TODO fait

	int getNombreElements() const; //TODO fait


protected:
	C conteneur_;
};


/********************************************************/
/*              implementation                          */
/********************************************************/
template<typename T, typename C>
C GestionnaireGenerique<T, C>::getConteneur() const
{
	return conteneur_;
}

template<typename T, typename C>
void GestionnaireGenerique<T, C>::ajouter(T t) {
	conteneur_.insert(t);
}

template<typename T, typename C>
int GestionnaireGenerique<T, C>::getNombreElements() const
{
	return conteneur_.size();
}