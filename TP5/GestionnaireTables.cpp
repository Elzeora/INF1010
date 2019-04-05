/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"


Table* GestionnaireTables::getTable(int id) const { //TODO fait
	return *find(conteneur_.begin(), conteneur_.end(), id);
}

Table* GestionnaireTables::getMeilleureTable(int tailleGroupe) const { //TODO fait
	Table* meilleureTable = nullptr;
	// si marche pas --> STL p15
	for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		Table* table = *it;
		if (!(table->estOccupee()) && table->getId() != ID_TABLE_LIVRAISON) {
			int placesACetteTable = table->getNbPlaces();
			if (placesACetteTable >= tailleGroupe && (!meilleureTable || placesACetteTable < meilleureTable->getNbPlaces()))
				meilleureTable = table;
		}
	}
	return meilleureTable;
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





void GestionnaireTables::afficherTables(ostream& os) const { //TODO fait
	set<Table*>::iterator end = conteneur_.end();
	copy(conteneur_.begin(), end, ostream_iterator<Table*>(os, "\n"));
	// ou si ca donne pas le bon affichage faire ca:
	/*
	for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		os << *it;
	}
	*/
}
