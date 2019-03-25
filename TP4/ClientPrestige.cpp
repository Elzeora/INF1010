/*
* Titre : clientPrestige.cpp - Travail Pratique #4
* Date :  mars 2019
* Auteur : Louis Roberge  && Jean-Sébastien Patenaude
*/
#include "ClientPrestige.h"
#include "Restaurant.h"

ClientPrestige::ClientPrestige(){
	adresse_ = ZoneHabitation::Zone3;
}

ClientPrestige::ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, int nbPoints, ZoneHabitation adresse) 
	: ClientRegulier(nom, prenom, tailleGroupe, nbPoints), adresse_(adresse){
}

ZoneHabitation ClientPrestige::getAdresseCode() const
{	return adresse_;}

double ClientPrestige::getReduction(const Restaurant & res, double montant, bool estLivraison) {
	double reduction = 0.0;
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION) {
		reduction = (-montant) * TAUX_REDUC_PRESTIGE;
	}
	if (nbPoints_ < SEUIL_LIVRAISON_GRATUITE && estLivraison) {
		reduction += res.getFraisLivraison(adresse_);
	}
	return reduction;
}


void ClientPrestige::afficherClient(ostream & os) const
{	static_cast<Client>(*this).afficherClient(os);}

string ClientPrestige::getAdressCodeString() const{
	string zone;
	switch (adresse_)
	{
	case ZoneHabitation::Zone1:
		zone = "Zone 1";
		break;
	case  ZoneHabitation::Zone2:
		zone = " Zone 2";
		break;
	case  ZoneHabitation::Zone3:
		zone = "Zone 3";
		break;

	default:
		zone = "erreur zone";
		break;
	}
	return zone;
}

