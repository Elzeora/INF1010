/*
* Titre : clientOccasionnel.cpp - Travail Pratique #4
* Date :  mars 2019
* Auteur : Louis Roberge  && Jean-Sébastien Patenaude
*/
#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe)
	: Client(nom, prenom, tailleGroupe){ 
}

ClientOccasionnel::~ClientOccasionnel(){}

int ClientOccasionnel::getNbPoints() const
{	return 0;}

double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison)
{	return 0;}

void ClientOccasionnel::afficherClient(ostream & os) const
{	static_cast<Client>(*this).afficherClient(os);}

