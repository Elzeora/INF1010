/****************************************************************************
 * Fichier: Restaurant.cpp
 * Auteur: Louis Roberge et Jean-Sébastien Patenaude
 * Date: 31 Janvier 2019
 * Description: Implémentation de la classe Restaurant
 ****************************************************************************/
#include "Restaurant.h"

using namespace std;

/****************************************************************************
 * Fonction: Restaurant::Restaurant
 * Description: Constructeur par défaut
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Restaurant::Restaurant() {
	*nom_ = "inconnu";
	momentJournee_ = Matin;
	chiffreAffaire_ = 0.0;
	nbTables_ = 0;
	capaciteTables_ = INTTABLES;
}

/****************************************************************************
 * Fonction: Restaurant::Restaurant
 * Description: Constructeur par paramètres
 * Paramètres: - string fichier : le fichier a ouvrir (IN)
 *             - string nom : le nom du restaurant (IN)
 *			   - TypeMenu moment : le moment de la journee (IN)
 * Retour: aucun
 ****************************************************************************/
Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment) {
	nom_ = &nom;
	momentJournee_ = moment;
	chiffreAffaire_ = 0.0;
	menuMatin_ = &Menu(fichier, Matin);
	menuMidi_ = &Menu(fichier, Midi);
	menuSoir_ = &Menu(fichier, Soir);
	nbTables_ = 0;
	lireTable(fichier);
	capaciteTables_ = INTTABLES;
}


/****************************************************************************
 * Fonction: ~Restaurant::Restaurant
 * Description: Destructeur de Restaurant
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Restaurant::~Restaurant() {
	for (unsigned int i = 0; i < nbTables_; i++) {
		delete tables_[i];
	}
	delete[] tables_;
	tables_ = nullptr;
	delete menuMatin_;
	menuMatin_ = nullptr;
	delete menuMidi_;
	menuMidi_ = nullptr;
	delete menuSoir_;
	menuSoir_ = nullptr;
	delete nom_;
	nom_ = nullptr;
}


/****************************************************************************
 * Fonction: Restaurant::setMoment
 * Description: set momentJournee_
 * Paramètres: TypeMenu moment : le moment de la journee (IN)
 * Retour: aucun
 ****************************************************************************/
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

/****************************************************************************
 * Fonction: Restaurant::getNom
 * Description: retourne nom_ du restaurant
 * Paramètres: aucun
 * Retour: (string) le nom du restaurant
 ****************************************************************************/
string Restaurant::getNom() {
	return *nom_;
}


/****************************************************************************
 * Fonction: Restaurant::getMoment
 * Description: retourne momentJournee_
 * Paramètres: aucun
 * Retour: (TypeMenu) la valeur de momentJournee_
 ****************************************************************************/
TypeMenu Restaurant::getMoment() {
	return momentJournee_;
}

/****************************************************************************
 * Fonction: Restaurant::
 * Description: set le moment de la journee
 * Paramètres: string fichier : le fichier a ouvrir (IN)
 * Retour: aucun
 ****************************************************************************/
void Restaurant::lireTable(string& fichier) {
	ifstream fichierLire(fichier);
	const int sectionTable = 4;
	for (int i = 0; i < sectionTable; i++) {
		fichierLire.ignore(INT_MAX, '-');
	}
	fichierLire.ignore(INT_MAX, '\n');
	while (!ws(fichierLire).eof()) {
		int id;
		int nbPlaces;
		fichierLire >> id >> nbPlaces;
		ajouterTable(id, nbPlaces);
	}
}


/****************************************************************************
 * Fonction: Restaurant::ajouterTable
 * Description: ajouter une table a la liste de tables
 * Paramètres: - int id : id de la table (IN)
 *			   - int nbPlaces : nombre de places de la table (IN)
 * Retour: aucun
 ****************************************************************************/
void Restaurant::ajouterTable(int id, int nbPlaces) {
	Table table(id, nbPlaces);
	if (nbTables_ >= capaciteTables_) {
		capaciteTables_ *= 2;
		Table** tablesTemp = new Table*[capaciteTables_];
		for (unsigned int i = 0; i < nbTables_; i++) {
			tablesTemp[i] = tables_[i];
		}
		for (unsigned int i = 0; i < nbTables_; i++) {
			delete tablesTemp[i];
		}
		delete[] tables_;
		tables_ = tablesTemp;
	}
	tables_[nbTables_] = &table;
	nbTables_++;
}


/****************************************************************************
 * Fonction: Restaurant::libererTable
 * Description: liberer une table
 * Paramètres: - int id : id de la table (IN)
 * Retour: aucun
 ****************************************************************************/
void Restaurant::libererTable(int id) {
	for (unsigned int i = 0; i < nbTables_; i++) {
		if (tables_[i]->getId() == id) {
			tables_[i]->libererTable();
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
		}
	}
}


/****************************************************************************
 * Fonction: Restaurant::commanderPlat
 * Description: commander un plat selon le menu
 * Paramètres: - string nom : nom du plat (IN)
 *			   - int idTable : id de la table (IN)
 * Retour: aucun
 ****************************************************************************/
void Restaurant::commanderPlat(string& nom, int idTable) {
	TypeMenu typeMenu = getMoment();
	switch (typeMenu) {
	case Matin: tables_[idTable - 1]->commander(menuMatin_->trouverPlat(nom));
		break;
	case Midi: tables_[idTable - 1]->commander(menuMidi_->trouverPlat(nom));
		break;
	case Soir: tables_[idTable - 1]->commander(menuSoir_->trouverPlat(nom));
		break;
	}
}


/****************************************************************************
 * Fonction: Restaurant::placerClients
 * Description: placer les clients aux bonnes tables
 * Paramètres: - int nbClients : nombre de clients (IN)
 * Retour: aucun
 ****************************************************************************/
void Restaurant::placerClients(int nbClients) {
	string erreur = "Il n'y a plus/pas de tables disponibles pour le client.";
	if (nbTables_ > 0) {
		int difference = 0;
		int petiteDifference = INT_MAX;
		int tablesOccupees = 0;
		int indice = -1;
		for (unsigned int i = 0; i < nbTables_; i++) {
			difference = tables_[i]->getNbPlaces() - nbClients;
			if (difference >= 0) {
				if (difference <= petiteDifference && !(tables_[i]->estOccupee())) {
					petiteDifference = difference;
					indice = i;
				}
			}
		}
		if (indice != -1) {
			tables_[indice]->placerClient();
		}
		else
			cout << erreur << endl;
	}
	else
		cout << erreur << endl;
	
}


/****************************************************************************
 * Fonction: Restaurant::afficher
 * Description: afficher le restaurant
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
void Restaurant::afficher() {
	if (chiffreAffaire_ = 0) {
		cout << "Le restaurant " << nom_ << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	}
	else {
		cout << "Le restaurant " << nom_ << " a fait un chiffre d'affaire de : " << chiffreAffaire_ << "$" << endl;
	}
	cout  << "-Voici les tables : " << endl;
	for (unsigned int i = 0; i < nbTables_; i++) {
		tables_[i]->afficher();
	}
	menuMatin_->afficher();
	menuMidi_->afficher();
	menuSoir_->afficher();


}



