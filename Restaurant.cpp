/*
* Titre : Restaurant.cpp - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/
#include "Restaurant.h"

using namespace std;

//constructeur par defaut
Restaurant::Restaurant() {
	*nom_ = "inconnu";
	momentJournee_ = Matin;
	chiffreAffaire_ = 0.0;
}

//constructeur par paramtere
Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment) {
	lireTable(fichier);
}

//setters
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

//getters
string Restaurant::getNom() {
	return *nom_;
}

TypeMenu Restaurant::getMoment() {
	return momentJournee_;
}

//methodes
void lireTable(string& fichier) {
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

void ajouterTable(int id, int nbPlaces) {

}

void libererTable(int id) {

}

void commanderPlat(string& nom, int idTable) {

}

void placerClients(int nbClients) {
	
}

void afficher() {
	if (chiffreAffaire_ = 0) {
		cout << "Le restaurant " << nom_ << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	}else {
		cout << "Le restaurant " << nom_ << " a fait un chiffre d'affaire de : " << chiffreAffaire_ << "$" << endl;
	}
	"-Voici les tables : " << endl;
	for (int i = 0; i < nbTable_; i++) {
		tables_[i].afficher();
	}
	menuMatin_.afficher();
	menuMidi_.afficher();
	menuSoir_.afficher();
}

