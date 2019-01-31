/*
* Titre : Menu.cpp - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#include "Menu.h"
#include "polyFood.txt"
#include <fstream>

using namespace std;

//constructeur par defaut
Menu::Menu() {
	capacite_ = MAXPLAT;
	listePlats_ = new Plat*[capacite_];
	nbPlats_ = 0;
	type_ = Matin;
}

//constructeur par parametre
Menu::Menu(string fichier, TypeMenu type) {
	type_ = type;
	capacite_ = MAXPLAT;
	lireMenu(fichier);
	listePlats_ = new Plat*[capacite_];
}




//implementation des methodes
int Menu::getNbPlats() {
	return nbPlats_;
}

Plat* Menu::trouverPlat(string& nom) {
	for (int i = 0; i < getNbPlats(); i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
		////////////////////////////////////////check cest weird que ca marche
	}
	return nullptr;
}
void Menu::ajouterPlat(Plat& plat) {
	if (unsigned(getNbPlats()) >= capacite_) {
		capacite_ *= 2;
	}
	listePlats_[getNbPlats() - 1] = &plat;
	nbPlats_++;
}

void Menu::ajouterPlat(string& nom, double montant, double cout) {
	ajouterPlat(nom, montant, cout);
}
bool Menu::lireMenu(string& fichier) {
	ifstream fichierLire(fichier);
	for (int i = 0; i < type_+1; i++) {
		fichierLire.ignore(INT_MAX, '-');
	}
	fichierLire.ignore(INT_MAX, '\n');
	bool menuVoulu = true;
	while (menuVoulu) {
		string nom;
		double prix;
		double cout;
		fichierLire >> nom >> prix >> cout;
		if (nom.front() == '-')
			menuVoulu = false;
		ajouterPlat(nom, prix, cout);
	}
	return 0;//////////////////////////////////////check cque tu dois retourner comme bool
}
void Menu::afficher() {
	switch (type_) {
	case Matin: cout << "Matin :\n";
	case Midi: cout << "Midi :\n";
	case Soir: cout << "Soir :\n";
	}
	for (int i = 0; i < getNbPlats(); i++) {
		listePlats_[i]->afficher();
	}
}


