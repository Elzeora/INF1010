/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe)
{ // TODO
}
ClientOccasionnel::~ClientOccasionnel(){}

int ClientOccasionnel::getNbPoints() const
{ // TODO fait
	return 0;
}

void ClientOccasionnel::afficherClient(ostream & os) const
{ // TODO
	Client::afficherClient(os);
}
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison)
{ // TODO
	return 0.0;
}