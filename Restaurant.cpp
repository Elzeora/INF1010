#include "Restaurant.h"
#include <iostream>
#include <string>
#include <fstream>
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
Restaurant::Restaurant(string & fichier, string & nom, TypeMenu moment){
	nom_ = &nom;
	momentJournee_ = moment;
	chiffreAffaire_ = 0;
	nbTables_ = 0;
	capaciteTables_ = INTTABLES;
	tables_ = new Table*[INTTABLES];
	lireTable(fichier);
	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_  = new Menu(fichier, Midi);
	menuSoir_  = new Menu(fichier, Soir);
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
void Restaurant::lireTable(string & nomFichier)
{
	ifstream fichier(nomFichier);
	int i = 0;
	while (!ws(fichier).eof()) {
		string chaine;
		getline(fichier, chaine);
		if (chaine.compare("-TABLES") == 0) {
			while (!ws(fichier).eof()) {

				int id, nbPlaces;
				fichier >> id >> nbPlaces;
				ajouterTable(id, nbPlaces);
			}
		}
	}
}
/****************************************************************************
 * Fonction: Restaurant::ajouterTable
 * Description: ajouter une table a la liste de tables
 * Paramètres: - int id : id de la table (IN)
 *			   - int nbPlaces : nombre de places de la table (IN)
 * Retour: aucun
 ****************************************************************************/
void Restaurant::ajouterTable(int id, int nbPlaces)
{
	if (capaciteTables_ > nbTables_) {
		tables_[nbTables_] = new Table(id,nbPlaces);
		nbTables_++;
	}
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
void Restaurant::commanderPlat(string& nomPlat, int idTable) {
	Menu* menuTemp = new Menu();
	switch (momentJournee_) {
	case Matin : 
		menuTemp = menuMatin_;
		break;
	case Midi:
		menuTemp = menuMidi_;
		break;
	case Soir:
		menuTemp = menuSoir_;
		break;
	}
	Plat* platTemp = menuTemp->trouverPlat(nomPlat);
	if (platTemp) {
		for (int i = 0; i < nbTables_; i++) {
			if (tables_[i]->getId() == idTable) {
				tables_[i]->commander(platTemp);
			}
		}
	}
	
}
/****************************************************************************
 * Fonction: Restaurant::placerClients
 * Description: placer les clients aux bonnes tables
 * Paramètres: - int nbClients : nombre de clients (IN)
 * Retour: aucun
 ****************************************************************************/
void Restaurant::placerClients(int nbClients) {
	string erreur = "ERREUR : Il n'y a plus/pas de tables disponibles pour le client.";
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
	if (chiffreAffaire_ == 0) {
		cout << "Le restaurant " << *nom_ << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	}
	else {
		cout << "Le restaurant " << *nom_ << " a fait un chiffre d'affaire de : " << chiffreAffaire_ << "$" << endl;
	}
	cout << "-Voici les tables : " << endl;
	for (unsigned int i = 0; i < nbTables_; i++) {
		tables_[i]->afficher();
	}
	cout << "-Voici son menu : " << endl;
	menuMatin_->afficher();
	menuMidi_->afficher();
	menuSoir_->afficher();


}




