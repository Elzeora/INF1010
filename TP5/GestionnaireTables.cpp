/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"
#include <iostream>

/****************************************************************************
 * Fonction: GestionnairePlats::~GestionnaireTables()
 * Description: destructeur
 * Paramètres: rien
 * Retour: rien
 ****************************************************************************/
GestionnaireTables::~GestionnaireTables(){
	for (Table* table : conteneur_)
		delete table;
}

/****************************************************************************
 * Fonction: GestionnairePlats::getTable(int id)
 * Description: retourne la table dans le conteneur qui porte le id spécifié
 * Paramètres: (int) id
 * Retour: Table*
 ****************************************************************************/
Table* GestionnaireTables::getTable(int id) const { //TODO fait
	for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if ((*it)->getId() == id)
			return *it;
	}
	return nullptr;
}

/****************************************************************************
 * Fonction: GestionnairePlats::getMeilleureTable(int tailleGroupe)
 * Description: retourne  la  plus  petite  table pouvant contenir le groupe
 * Paramètres: (int) tailleGroupe
 * Retour: Table*
 ****************************************************************************/
Table* GestionnaireTables::getMeilleureTable(int tailleGroupe) const { //TODO fait
	Table* meilleureTable = new Table(-1, 9999);
	bool meilleurTableTrouvee = false;
	for (Table* table : conteneur_) {
		if ((!table->estOccupee()) && (table->getId() != ID_TABLE_LIVRAISON)) {
			if ((table->getNbPlaces() >= tailleGroupe) && (table->getNbPlaces() < meilleureTable->getNbPlaces())) {
				meilleureTable = table;
				meilleurTableTrouvee = true;
			}
		}
	}
	if (meilleurTableTrouvee)
		return meilleureTable;
	else
		return nullptr;
}
 

void GestionnaireTables::lireTables(const string& nomFichier) {
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		ajouter(new Table(id, nbPlaces));
	}
}

/****************************************************************************
 * Fonction: GestionnairePlats::afficherTables(ostream& os) const
 * Description: t:affiche  les  tables  en  utilisant  des itérateurs.
 * Paramètres: (ostream) os
 * Retour: rien
 ****************************************************************************/
void GestionnaireTables::afficherTables(ostream& os) const { //TODO fait
	for (set<Table*>::iterator it = getConteneur().begin(); it != getConteneur().end(); it++) {
		os << *it;
	}
}
