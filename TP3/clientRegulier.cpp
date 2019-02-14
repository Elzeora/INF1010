/****************************************************************************
 * Fichier: clientRegulier.cpp
 * Auteur: Jean-Sébastien Patenaude
 * Date: 14 février 2019
 * Description: Implémentation de la classe ClientRegulier
 ****************************************************************************/

#include "ClientRegulier.h"

 /****************************************************************************
  * Fonction: ClientRegulier::ClientRegulier
  * Description: Constructeur par défaut
  * Paramètres: aucun
  * Retour: aucun
  ****************************************************************************/
ClientRegulier::ClientRegulier() :Client()
{
	nbPoints_ = 0;
}

/****************************************************************************
 * Fonction: ClientRegulier::ClientRegulier
 * Description: Constructeur par parametre
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints)
	: Client(nom,prenom,tailleGroupe)
{
	statut_ = Fidele;
	nbPoints_ = nbPoints;
}


//Accesseurs
int ClientRegulier::getNbPoints() {
	return nbPoints_;
}

//Autres Méthodes
void ClientRegulier::augmenterNbPoints(int bonus) {
	nbPoints_ += bonus;
}

ostream& operator<<(ostream & os, const ClientRegulier& client) {
	os << client << " Possede " << client.nbPoints_ << " Points." << endl;
}