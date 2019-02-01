/****************************************************************************
 * Fichier: Menu.cpp
 * Auteur: Jean-Sébastien Patenaude
 * Date: 31 Janvier 2019
 * Description: Implémentation de la classe Menu
 ****************************************************************************/

#include "Menu.h"
#include "polyFood.txt"
#include <fstream>

using namespace std;

/****************************************************************************
 * Fonction: Menu::menu
 * Description: Constructeur par défaut
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Menu::Menu() {
	capacite_ = MAXPLAT;
	listePlats_ = new Plat*[capacite_];
	nbPlats_ = 0;
	type_ = Matin;
}

/****************************************************************************
 * Fonction: Menu::Menu
 * Description: Constructeur par paramètres
 * Paramètres: - string fichier : le fichier a ouvrir (IN)
 *			   - TypeMenu type : le moment de la journee (IN)
 * Retour: aucun
 ****************************************************************************/
Menu::Menu(string fichier, TypeMenu type) {
type_ = type;
capacite_ = MAXPLAT;
lireMenu(fichier);
listePlats_ = new Plat*[capacite_];
}


/****************************************************************************
 * Fonction: ~Menu::Menu
 * Description: Destructeur de Menu
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Menu::~Menu() {
	for (int i = 0; i < nbPlats_; i++) {
		delete listePlats_[i];
	}
	delete[] listePlats_;
	listePlats_ = nullptr;
}


/****************************************************************************
 * Fonction: Menu::getNbPlats
 * Description: retourne nbPlats_
 * Paramètres: aucun
 * Retour: (int) la valeur de nbPlats
 ****************************************************************************/
int Menu::getNbPlats() {
	return nbPlats_;
}


/****************************************************************************
 * Fonction: Menu::trouverPlat
 * Description: retourne un pointeur vers un plat dans listePlats_
 * Paramètres: - string nom : le fichier a ouvrir (IN)
 * Retour: (Plat*) un pointeur vers un plat
 ****************************************************************************/
Plat* Menu::trouverPlat(string& nom) {
	for (int i = 0; i < getNbPlats(); i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr;
}


/****************************************************************************
 * Fonction: Menu::ajouterPlat
 * Description: ajoute un plat dans listePlats_ avec un plat en parametre
 * Paramètres: - Plat plat : le plat a ajouter (IN)
 * Retour: aucun
 ****************************************************************************/
void Menu::ajouterPlat(Plat& plat) {
	/*if (unsigned(getNbPlats()) >= capacite_) {
		capacite_ *= 2;
		Plat **platsTemp = new Plat*[capacite_];
	}*/
	listePlats_[getNbPlats() - 1] = &plat;
	nbPlats_++;
}


/****************************************************************************
 * Fonction: Menu::ajouterPlat
 * Description: ajoute un plat avec le nom, le montant et le cout en parametres
 * Paramètres: - string nom : le nom du plat (IN)
 *             - double montant : le montant du plat (IN)
 *			   - double cout : le cout du plat (IN)
 * Retour: aucun
 ****************************************************************************/
void Menu::ajouterPlat(string& nom, double montant, double cout) {
	ajouterPlat(nom, montant, cout);
}


/****************************************************************************
 * Fonction: Menu::lireMenu
 * Description: lit le menu selon le moment de la journee
 * Paramètres: - string fichier : le fichier a ouvrir (IN)
 * Retour: un booleen
 ****************************************************************************/
bool Menu::lireMenu(string& fichier) {
	//ifstream fichierLire(fichier);
	bool aEteLu = false;
	while (!(aEteLu)) {
		switch (type_) {
		case Matin: lireBonMenu("-MATIN", fichier);
			break;
		case Midi: lireBonMenu("MIDI", fichier);
			break;
		case Soir: lireBonMenu("-SOIR", fichier);
			break;
		}
	}






	return 0;
}


/****************************************************************************
 * Fonction: Menu::affiche
 * Description: afficher le menu selon le moment de la journee
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
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















/*
bool Menu::lireMenu(string& fichier) {
	ifstream fichierLire(fichier);
	for (int i = 0; i < type_ + 1; i++) {
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
	return 0;
}*/


void Menu::lireBonMenu(string motCherche, string& fichier) {
	ifstream fichierLire(fichier);
	while (!ws(fichierLire).eof()) {
		string nom;
		fichierLire >> nom;
		if (nom == motCherche) {
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
		}
	}
}