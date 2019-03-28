/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"


Table* GestionnaireTables::getTable(int id) const {
	return *find(conteneur_.begin(), conteneur_.end(), id);
}

Table* GestionnaireTables::getMeilleureTable(int tailleGroupe) const {
	FoncteurMeilleureTable meilleureTable;

	// si marche pas --> STL p15
	for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		FoncteurMeilleureTable foncteurMeilleureTable;
		int meilleurePlace = foncteurMeilleureTable(it, tailleGroupe);
		if(meilleurePlace > 0 && )
	}


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

void GestionnaireTables::afficherTables(ostream& os) const {



}
