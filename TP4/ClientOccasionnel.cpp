/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe)
	: Client(nom, prenom, tailleGroupe)
{ // TODO fait
}

ClientOccasionnel::~ClientOccasionnel(){}

int ClientOccasionnel::getNbPoints() const
{ // TODO fait
	return 0;
}

void ClientOccasionnel::afficherClient(ostream & os) const
{ // TODO fait
	Client::afficherClient(os);
}

double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison)
{ // TODO fait
	return 0.0;
}