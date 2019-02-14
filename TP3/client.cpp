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
  * Retour: aucun
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
 * Param�tres: aucun
 * Retour: aucun
 ****************************************************************************/
Client::Client(string nom, string prenom, int tailleGroupe) {
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
	statut_ = Occasionnel;
}

Client::~Client() {
	//aucun pointeur donc destructeur vide
}

// Accesseurs
StatutClient Client::getStatut() {
	return statut_;
}

int Client::getTailleGroupe() {
	return tailleGroupe_;
}

string Client::getNom() {
	return nom_;
}

string Client::getPrenom() {
	return prenom_;
}

//Autes m�thodes

ostream& operator<<(ostream& os, const Client& client) {
	os << "Le client principal est: " << endl;
	os << "\t -" << client.nom_ << " " << client.prenom_ << " statut: " 
		<< client.convertirStatutString;
}

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