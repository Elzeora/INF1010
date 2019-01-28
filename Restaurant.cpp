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

}

