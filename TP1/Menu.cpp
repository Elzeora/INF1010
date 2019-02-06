#include "Menu.h"
#include <iostream>
#include <string>
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
	nbPlats_ = 0;
	listePlats_ = new Plat*[capacite_];
	lireMenu(fichier);
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
 * Paramètres: - string nom : le fichier a ouvrir (IN)
 * Retour: (Plat*) un pointeur vers un plat
 ****************************************************************************/
Plat* Menu::trouverPlat(string& nom) {
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
void Menu::ajouterPlat(Plat& plat) {
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
void Menu::ajouterPlat(string& nom, double montant, double cout) {
	ajouterPlat(nom, montant, cout);
}
/****************************************************************************
 * Fonction: Menu::lireMenu
 * Description: lit le menu selon le moment de la journee
 * Paramètres: - string fichier : le fichier a ouvrir (IN)
 * Retour: un booleen
 ****************************************************************************/
bool Menu::lireMenu(string& nomFichier) {
	ifstream fichier(nomFichier);
	string temps, tempsSuivant;
	switch (type_)
	{
	case Matin:
		temps = "-MATIN";
		tempsSuivant = "-MIDI";
		break;
	case Midi:
		temps = "-MIDI";
		tempsSuivant = "-SOIR";
		break;
	case Soir:
		temps = "-SOIR";
		tempsSuivant = "-TABLES";
		break;
	}
	if (fichier.is_open()) {
		bool fini = 1;
		while (!ws(fichier).eof() && fini) {
			string chaine;
			getline(fichier, chaine);
			string nom;
			double prix, cout1;
			if (!chaine.compare(temps)) {
				while (fini) {
					fichier >> nom >> cout1 >> prix;
					if (nom.compare(tempsSuivant)) {
						Plat plat(nom, cout1, prix);
						ajouterPlat(plat);
					}
					else {
						fini = 0;
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
		for (int i = 0; i < getNbPlats(); i++) {
			listePlats_[i]->afficher();
		}
		break;
	case Midi: cout << "Midi :\n";
		for (int i = 0; i < getNbPlats(); i++) {
			listePlats_[i]->afficher();
		}
		break;
	case Soir: cout << "Soir :\n";
		for (int i = 0; i < getNbPlats(); i++) {
			listePlats_[i]->afficher();
		}
		break;
	}
	
}




