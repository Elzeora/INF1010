/****************************************************************************
 * Fichier: client.cpp
 * Auteur: Jean-S�bastien Patenaude
 * Date: 14 f�vrier 2019
 * Description: Impl�mentation de la classe Client
 ****************************************************************************/

#include "Client.h"

 /****************************************************************************
  * Fonction: Client::Client
  * Description: Constructeur par d�faut
  * Param�tres: aucun
  ****************************************************************************/
Client::Client() {
	nom_ = "inconnu";
	prenom_ = "inconnu";
	tailleGroupe_ = 0;
	statut_ = Occasionnel;
}

/****************************************************************************
 * Fonction: Client::Client
 * Description: Constructeur par parametre
 * Param�tres: - string nom
 *			   - string prenom
 *			   - int tailleGroupe
 ****************************************************************************/
Client::Client(string nom, string prenom, int tailleGroupe) {
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
	statut_ = Occasionnel;
}

/****************************************************************************
 * Fonction: ~Client
 * Description: Destructeur de Client
 * Param�tres: aucun
 * Retour: aucun
 ****************************************************************************/
Client::~Client() {
	//aucun pointeur donc destructeur vide
}

/****************************************************************************
 * Fonction: getStatus
 * Description: accesseur du statut du client
 * Param�tres: aucun
 * Retour: statut_
 ****************************************************************************/
StatutClient Client::getStatut() const {
	return statut_;
}

/****************************************************************************
 * Fonction: getTailleGroupe
 * Description: accesseur de la taille du groupe
 * Param�tres: aucun
 * Retour: tailleGroupe_
 ****************************************************************************/
int Client::getTailleGroupe() const {
	return tailleGroupe_;
}

/****************************************************************************
 * Fonction: getNom
 * Description: accesseur du nom du client
 * Param�tres: aucun
 * Retour: nom_
 ****************************************************************************/
string Client::getNom() const {
	return nom_;
}

/****************************************************************************
 * Fonction: getPrenom
 * Description: accesseur du prenom du client
 * Param�tres: aucun
 * Retour: prenom_
 ****************************************************************************/
string Client::getPrenom() const {
	return prenom_;
}

/****************************************************************************
 * Fonction: operateur<<
 * Description: surcharge de l'op�rateur << pour afficher un client
 * Param�tres:	- ostream& os
 *				- Client& client
 * Retour: os
 ****************************************************************************/
ostream& operator<<(ostream& os, const Client& client) {
	os << "Le client principal est: " << endl;
	os << "\t -" << client.nom_ << " " << client.prenom_ << " statut: " 
		<< client.convertirStatutString;
}

/****************************************************************************
 * Fonction: convertirStatutString
 * Description: convertir le statut en string
 * Param�tres:	aucun
 * Retour: statut du client (en string)
 ****************************************************************************/
string Client::convertirStatutString() const {
	switch (statut_) {
	case Occasionnel:
		return "Occasionnel";
	case Fidele:
		return "Regulier";
	case Prestige:
		return "Prestige";
	}
}