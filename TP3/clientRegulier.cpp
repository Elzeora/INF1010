/****************************************************************************
 * Fichier: clientRegulier.cpp
 * Auteur: Jean-S�bastien Patenaude
 * Date: 14 f�vrier 2019
 * Description: Impl�mentation de la classe ClientRegulier
 ****************************************************************************/

#include "ClientRegulier.h"

 /****************************************************************************
  * Fonction: ClientRegulier::ClientRegulier
  * Description: Constructeur par d�faut
  * Param�tres: aucun
  ****************************************************************************/
ClientRegulier::ClientRegulier() :Client(), nbPoints_(0) {
	statut_ = Fidele;
}

/****************************************************************************
 * Fonction: ClientRegulier::ClientRegulier
 * Description: Constructeur par parametre
 * Param�tres:	- string nom
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
 * Param�tres: aucun
 * Retour: nbPoints_
 ****************************************************************************/
int ClientRegulier::getNbPoints() const {
	return nbPoints_;
}

/****************************************************************************
 * Fonction: augmenterNbPoints
 * Description: augmenter le nombre de points du client
 * Param�tres: int bonus
 * Retour: aucun
 ****************************************************************************/
void ClientRegulier::augmenterNbPoints(int bonus) {
	nbPoints_ += bonus;
}

/****************************************************************************
 * Fonction: operateur<<
 * Description: surcharge de l'op�rateur << pour afficher un client regulier
 * Param�tres:	- ostream& os
 *				- ClientRegulier& client
 * Retour: os
 ****************************************************************************/
ostream& operator<<(ostream & os, const ClientRegulier& client) {
	os << static_cast<Client>(client) << " Possede " << client.getNbPoints() << " Points." << endl;
	return os;
}