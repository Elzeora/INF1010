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
  ****************************************************************************/
ClientRegulier::ClientRegulier() :Client(), nbPoints_(0) {
	statut_ = Fidele;
}

/****************************************************************************
 * Fonction: ClientRegulier::ClientRegulier
 * Description: Constructeur par parametre
 * Paramètres:	- string nom
 *				- string prenom
 *				- int tailleGroupe
 *				- int nbPoints
 ****************************************************************************/
ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints)
	: Client(nom, prenom, tailleGroupe), nbPoints_(nbPoints) {
	statut_ = Fidele;
}


/****************************************************************************
 * Fonction: getNbPoints
 * Description: accesseur du nombre de points du client
 * Paramètres: aucun
 * Retour: nbPoints_
 ****************************************************************************/
int ClientRegulier::getNbPoints() const {
	return nbPoints_;
}

/****************************************************************************
 * Fonction: augmenterNbPoints
 * Description: augmenter le nombre de points du client
 * Paramètres: int bonus
 * Retour: aucun
 ****************************************************************************/
void ClientRegulier::augmenterNbPoints(int bonus) {
	nbPoints_ += bonus;
}

/****************************************************************************
 * Fonction: operateur<<
 * Description: surcharge de l'opérateur << pour afficher un client regulier
 * Paramètres:	- ostream& os
 *				- ClientRegulier& client
 * Retour: os
 ****************************************************************************/
ostream& operator<<(ostream & os, const ClientRegulier& client) {
	os << static_cast<Client>(client) << " Possede " << client.getNbPoints() << " Points." << endl;
	return os;
}