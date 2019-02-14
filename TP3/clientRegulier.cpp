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
  * Retour: aucun
  ****************************************************************************/
ClientRegulier::ClientRegulier() :Client()
{
	nbPoints_ = 0;
}

/****************************************************************************
 * Fonction: ClientRegulier::ClientRegulier
 * Description: Constructeur par parametre
 * Param�tres: aucun
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

//Autres M�thodes
void ClientRegulier::augmenterNbPoints(int bonus) {
	nbPoints_ += bonus;
}

ostream& operator<<(ostream & os, const ClientRegulier& client) {
	os << client << " Possede " << client.nbPoints_ << " Points." << endl;
}