/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Table.h"

using namespace std;

//constructeurs
Table::Table() {
	//capacite_ = MAXCAP;
	//commande_ = new Plat*[MAXCAP];
	nbPlats_ = 0;
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces) {
	//capacite_ = MAXCAP;
	//commande_ = new Plat*[capacite_];
	nbPlats_ = 0;
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}

//getters
int Table::getId() const {
	return id_;
}

int Table::getNbPlaces() const {
	return nbPlaces_;
}

int Table::getnbClientATable() const
{
	return nbClientsATable_;
}

bool Table::estPleine() const {
	return nbPlaces_==0;
}

bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

//setters
void Table::setId(int id) {
	id_ = id;
}

void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	//A MODIFIER
	for (int i = 0; i < nbPlats_; i++) {
		commande_.pop_back();
	}
	nbPlats_ = 0;
}

void Table::placerClient(int nbClients) {
	nbClientsATable_ = nbClients;
	nbPlaces_ -= nbClients;
}

//autres methodes
void Table::commander(Plat* plat) {
	// A MODIFIER
	/*if (nbPlats_ == capacite_) {
		capacite_ *= 2;
		Plat** temp = new Plat*[capacite_];
		for (int i = 0; i < nbPlats_; i++) {
			temp[i] = commande_[i];
		}

		delete[] commande_;
		commande_ = temp;
	}*/
	commande_.push_back(plat);
	nbPlats_++;
}

double Table::getChiffreAffaire() const {
	double chiffre = 0;
	for (int i = 0; i < nbPlats_; i++) {
		chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffre;
}

/****************************************************************************
 * Fonction: operateur<<
 * Description: surcharge de l'op�rateur << pour afficher une table
 * Param�tres:	- ostream& os
				- Table& table
 * Retour: os
 ****************************************************************************/
ostream& operator<<(ostream& os, const Table& table) {
	os << "La table numero " << table.getId();
	if (table.estOccupee()) {
		os << " est occupee. ";
		if (table.nbPlats_ != 0) {
			os << "Voici la commande passee par les clients : " << endl;
			for (int i = 0; i < table.commande_.size(); i++) {
				cout << "\t";
				os << table.commande_[i];
			}
		}
		else
			os << "Mais ils n'ont rien conmmande pour l'instant. " << endl;
	}
	else {
		os << " est libre. " << endl;
	}
	return os;
}

/*
void Table::afficher() const {
	cout << "La table numero " << id_;
	if (estOccupee()) {
		cout << " est occupee. ";
		if (nbPlats_ != 0) {
			cout << "Voici la commande passee par les clients : " << endl;
			for (int i = 0; i < nbPlats_; i++) {
				cout << "\t";
				commande_[i]->afficher();
			}
		}
		else
			cout << "Mais ils n'ont rien conmmande pour l'instant. " << endl;
	}
	else {
		cout << " est libre. " << endl;
	}
}*/
