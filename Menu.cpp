/****************************************************************************
 * Fichier: Menu.cpp
 * Auteur: Jean-Sébastien Patenaude
 * Date: 31 Janvier 2019
 * Description: Implémentation de la classe Menu
 ****************************************************************************/
#include "Menu.h"
#include <iostream>
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
 * Paramètres: - string fichier : le fichier a ouvrir (OUT)
 *			   - TypeMenu type : le moment de la journee (IN)
 * Retour: aucun
 ****************************************************************************/
Menu::Menu(string& fichier, const TypeMenu& type) {
	type_ = type;
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	listePlats_ = new Plat*[capacite_];
	lireMenu(fichier);
}

/****************************************************************************
 * Fonction: ~Menu::Menu
 * Description: Destructeur de Menu
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Menu::~Menu() {
	for (unsigned int i = 0; i < nbPlats_; i++) {
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
int Menu::getNbPlats() const {
	return nbPlats_;
}

/****************************************************************************
 * Fonction: Menu::trouverPlat
 * Description: retourne un pointeur vers un plat dans listePlats_
 * Paramètres: - string nom : le nom du plat (IN)
 * Retour: (Plat*) un pointeur vers un plat
 ****************************************************************************/
Plat* Menu::trouverPlat(const string& nom) {
	for (int i = 0; i < getNbPlats(); i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	cout << "ERREUR : table non occuppe ou plat introuvable" << endl;
	return nullptr;
}

/****************************************************************************
 * Fonction: Menu::ajouterPlat
 * Description: ajoute un plat dans listePlats_ avec un plat en parametre
 * Paramètres: - Plat plat : le plat a ajouter (IN)
 * Retour: aucun
 ****************************************************************************/
void Menu::ajouterPlat(const Plat& plat) {
	if (capacite_ > nbPlats_) {
		listePlats_[nbPlats_] = new Plat(plat);
		nbPlats_++;
	}
}

/****************************************************************************
 * Fonction: Menu::ajouterPlat
 * Description: ajoute un plat avec le nom, le montant et le cout en parametres
 * Paramètres: - string nom : le nom du plat (IN)
 *             - double montant : le montant du plat (IN)
 *			   - double cout : le cout du plat (IN)
 * Retour: aucun
 ****************************************************************************/
void Menu::ajouterPlat(const string& nom, const double& montant, const double& cout) {
	ajouterPlat(nom, montant, cout);
}

/****************************************************************************
 * Fonction: Menu::lireMenu
 * Description: lit le menu selon le moment de la journee
 * Paramètres: - string fichier : le fichier a ouvrir (IN)
 * Retour: (bool) vrai si le fichier a pu etre ouvert, faux sinon
 ****************************************************************************/
bool Menu::lireMenu(string& nomFichier) {
	ifstream fichierLire(nomFichier);
	string motVoulu;
	switch (type_) {
		case Matin:
			motVoulu = "-MATIN";
			break;
		case Midi:
			motVoulu= "-MIDI";
			break;
		case Soir:
			motVoulu = "-SOIR";
			break;
	}
	if (fichierLire.is_open()) {
		bool menuVoulu = true;
		while (!ws(fichierLire).eof() && menuVoulu) {
			string ligne;
			getline(fichierLire, ligne);
			string nom;
			double prix;
			double cout;
			if (ligne == motVoulu) {
				while (menuVoulu) {
					fichierLire >> nom >> prix >> cout;
					if (nom.front() != '-') {
						Plat platTemp(nom, prix, cout);
						ajouterPlat(platTemp);
					}
					else {
						menuVoulu = false;
					}
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}

/****************************************************************************
 * Fonction: Menu::affiche
 * Description: afficher le menu selon le moment de la journee
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
void Menu::afficher() const {
	switch (type_) {
		case Matin: cout << "Matin :\n";
			break;
		case Midi: cout << "Midi :\n";
			break;
		case Soir: cout << "Soir :\n";
			break;
	}
	for (int i = 0; i < getNbPlats(); i++) {
		listePlats_[i]->afficher();
	}
}


