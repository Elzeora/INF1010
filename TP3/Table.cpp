/*
* Titre : Table.cpp - Travail Pratique #3
* Date : 11 F�vrier 2019
* Auteur :Fatou S. MOUNZEO
*/

#include "Table.h"

//constructeurs
Table::Table() {
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
	clientPrincipal_ = nullptr;
}

Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
	clientPrincipal_ = nullptr;
}

//getters
int Table::getId() const {
	return id_;
}

int Table::getNbPlaces() const {
	return nbPlaces_;
}

bool Table::estOccupee() const {
	return nbClientsATable_ != 0;
}

bool Table::estPleine() const {
	return nbPlaces_ == 0;
}

int Table::getNbClientsATable() const {
	return nbClientsATable_;
}
vector<Plat*> Table::getCommande() const {
	return commande_;
}

/****************************************************************************
 * Fonction: getClientPrincipal
 * Description: get le client principal
 * Param�tres:	rien
 * Retour: Client* clientPrincipal_
 ****************************************************************************/
Client* Table::getCliengtPrincipal() const {
	return  clientPrincipal_;
}

/****************************************************************************
 * Fonction: getChiffreAffaire
 * Description: get le chiffre d'affaire
 * Param�tres:	rien
 * Retour: double chiffre
 ****************************************************************************/
double Table::getChiffreAffaire() const {
	double chiffre = 0.0;
	for (unsigned i = 0; i < commande_.size(); ++i) {

		if (commande_[i]->getType() == Bio) {
			chiffre += (commande_[i]->getPrix() + static_cast<PlatBio*>(commande_[i])->getEcoTaxe() - commande_[i]->getCout());
		}
		if (commande_[i]->getType() == Custom) {
			chiffre += (commande_[i]->getPrix() + static_cast<PlatCustom*>(commande_[i])->getSupplement() - commande_[i]->getCout());
		}
		else
			chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffre;
}

//setters
void Table::setId(int id) {
	id_ = id;
}

/****************************************************************************
 * Fonction: setClientPrincipal
 * Description: set le client principal
 * Param�tres:	- Client* clientPrincipal
 * Retour: rien
 ****************************************************************************/
void Table::setClientPrincipal(Client* clientPrincipal) {
	Client* ptrClient = new Client(*clientPrincipal);
	delete clientPrincipal_;
	clientPrincipal_ = ptrClient;
}

void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	commande_.clear();
}

void Table::placerClients(int nbClient) {
	nbPlaces_ -= nbClient;
	nbClientsATable_ = nbClient;
}

//autres methodes
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
}



//affichage

/****************************************************************************
 * Fonction: operateur<<
 * Description: surcharge de l'op�rateur << pour afficher une table
 * Param�tres:	- ostream& os
 *				- Table& table
 * Retour: os
 ****************************************************************************/
ostream& operator<<(ostream& os, const Table& table)
{
	os << "La table numero " << table.id_;
	if (table.estOccupee())
	{
		os << " est occupee. ";
		os << "Le client principal est: \n" << *table.getCliengtPrincipal() << endl;
		if (!table.commande_.empty())
		{
			os << "Voici la commande passee par les clients : " << endl;
			for (unsigned i = 0; i < table.commande_.size(); ++i)
			{
				os << "\t" << *table.commande_[i];
			}
		}
		else
			os << "Mais ils n'ont rien commande pour l'instant. " << endl;
	}
	else
		os << " est vide. " << endl;

	return os;
}