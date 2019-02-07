/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Restaurant.h"

using namespace std;

//constructeurs
Restaurant::Restaurant() {
	nom_ = new string("Inconnu");

	chiffreAffaire_ = 0;

	momentJournee_ = Matin;

	menuMatin_ = new Menu("menu.txt", Matin);
	menuMidi_ = new Menu("menu.txt", Midi);
	menuSoir_ = new Menu("menu.txt",  Soir);

	nbTables_ = 0;
}

Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom);

	chiffreAffaire_ = 0;

	momentJournee_ = moment;

	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);


	nbTables_ = 0;

	lireTable(fichier);
}
/****************************************************************************
 * Fonction: Restaurant::Restaurant
 * Description: constructeur par copie
 * Paramètres: (IN) restaurantCopie le restaurant que l'on souhaite copier
 * Retour: rien
 ****************************************************************************/
Restaurant::Restaurant(const Restaurant& restaurantCopie) 
	:nom_(restaurantCopie.nom_), chiffreAffaire_(restaurantCopie.chiffreAffaire_),
	momentJournee_(restaurantCopie.momentJournee_), menuMatin_(restaurantCopie.menuMatin_),
	menuMidi_(restaurantCopie.menuMidi_), menuSoir_(restaurantCopie.menuSoir_),
	tables_(restaurantCopie.tables_), nbTables_(restaurantCopie.nbTables_)
{
}
//destructeur
Restaurant::~Restaurant() {
	delete nom_;
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;
	for (int i = 0; i < nbTables_;i++) {
		delete tables_[i];
	}
}
//setter
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}
void Restaurant::setNom(string nom) {
	*nom_ = nom;
}
//getters
string Restaurant::getNom() const {
	return *nom_;
}
TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

//autres methodes
void Restaurant::libererTable(int id) {
	for (int i = 0; i < nbTables_; i++) {
		if (id == tables_[i]->getId()) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->libererTable();
		}
	}
}
ostream& operator<<(ostream& os, const Restaurant& restaurant) {
	os << "Le restaurant " << *restaurant.nom_;
	if (restaurant.chiffreAffaire_ != 0)
		os << " a fait un chiffre d'affaire de : " << restaurant.chiffreAffaire_ << "$" << endl;
	else
		os << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	os << "-Voici les tables : " << endl;
	for (int i = 0; i < restaurant.nbTables_; i++) {
		os << "\t";
		os << restaurant.tables_[i];
		os << endl;
	}
	os << endl;


	os << "-Voici son menu : " << endl;
	os << "Matin : " << endl << restaurant.menuMatin_;
	os << "Midi : " << endl << restaurant.menuMidi_;
	os << "Soir : " << endl << restaurant.menuSoir_;
	return os;
}

void Restaurant::commanderPlat(const string& nom, int idTable) {
	Plat* plat = nullptr;
	int index;
	for (int i = 0; i < nbTables_; i++) {
		if (idTable == tables_[i]->getId()) {
			index = i;
			switch (momentJournee_) {
			case Matin :
				plat = menuMatin_->trouverPlat(nom);
				break;
			case Midi :
				plat = menuMidi_->trouverPlat(nom);
				break;
			case Soir :
				plat = menuSoir_->trouverPlat(nom);
				break;
			}
		}
	}
	if (plat != nullptr && tables_[index]->estOccupee()) {
		tables_[index]->commander(plat);
	}
	else cout << "Erreur : table non occupee ou plat introuvable" << endl;
}

void Restaurant::lireTable(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (file) {
		string ligne;

		string idString;
		int id;

		string nbPersonnesString;
		int nbPersonnes;

		int curseur;
		while (!file.eof()) {
			getline(file, ligne);
			if (ligne == "-TABLES") {
				while (!file.eof()) {
					getline(file, ligne);
					for (int i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						idString += ligne[i];
					}

					id = stoi(idString);

					nbPersonnesString = ligne.substr(curseur + 1);
					nbPersonnes = stoi(nbPersonnesString);

					ajouterTable(id, nbPersonnes);
					nbPersonnesString = "";
					idString = "";
				}
			}
		}
		file.close();
	}
}
/****************************************************************************
 * Fonction: Restaurant::ajouterTable
 * Description: ajoute une table au restaurant
 * Paramètres: (IN) id le id d'une table
 *             (IN) nbPlaces le nbPlaces d'une table
 * Retour: rien
 ****************************************************************************/
void Restaurant::ajouterTable(int id, int nbPlaces) {
	tables_.push_back(new Table(id, nbPlaces));
	nbTables_++;
}

void Restaurant::placerClients(int nbClients) {
	int indexTable = -1;
	int minimum = 100;


	for (int i = 0; i < nbTables_; i++) {
		if (tables_[i]->getNbPlaces() >= nbClients && !tables_[i]->estOccupee() && tables_[i]->getNbPlaces() < minimum) {
			indexTable = i;
			minimum = tables_[i]->getNbPlaces();
		}
	}
	if (indexTable == -1) {
		cout << "Erreur : il n'y a plus/pas de table disponible pour le client. " << endl;
	}else
	tables_[indexTable]->placerClient(nbClients);
}
/****************************************************************************
 * Fonction: Restaurant::operator+=
 * Description: renant en paramètre unpointeur à unetable,
 *              permettant d’ajouter unetableau restaurant
 * Paramètres: (IN) table le pointeur d'une table
 * Retour: (Restaurant) le restaurant avec la nouvelle table
 ****************************************************************************/
Restaurant& Restaurant::operator+=(Table* table) {
	this->ajouterTable(table->getId(),table->getNbPlaces());
	return *this;
}
/****************************************************************************
 * Fonction: Restaurant::operator=
 * Description: écrase les attributs du restaurant par les attributs du restaurant
 *       passé en parametre et qui renvoie ensuite une référence au restaurant
 * Paramètres: (IN) restaurant l'adresse du restaurant
 * Retour: (Restaurant) le restaurant ecrase
 ****************************************************************************/
Restaurant& Restaurant::operator=(Restaurant& restaurant) {
	if (this != &restaurant) {
		nom_ = restaurant.nom_;
		chiffreAffaire_ = restaurant.chiffreAffaire_;
		momentJournee_ = restaurant.momentJournee_;
		menuMatin_ = restaurant.menuMatin_;
		menuMidi_ = restaurant.menuMidi_;
		menuSoir_ = restaurant.menuSoir_;
		tables_ = restaurant.tables_;
		nbTables_ = restaurant.nbTables_;
	}
	return *this;
}
/****************************************************************************
 * Fonction: Restaurant::operator<
 * Description: Retourne true ou false selon si le chiffre d'affaire est
 *	plus grand ou plus petit comparer à un autre restaurant
 * Paramètres: (IN) restaurant l'adresse du restaurant 
 * Retour: (bool) le resultat de la comparaison
 ****************************************************************************/
bool Restaurant::operator<(const Restaurant& restaurant) const {
	if (chiffreAffaire_ < restaurant.chiffreAffaire_) {
		return true;
	}else{
		return false;
	}
}