/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Menu.h"

using namespace std;

//constructeurs

Menu::Menu() {
	type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type) {
	type_ = type;
	//lecture du fichier -- creation du menu
	lireMenu(fichier);
}

//constructeur par copie
Menu::Menu(const Menu& menu) : type_(menu.type_) {
	for (int i = 0; i < menu.listePlats_.size(); i++)
		listePlats_.push_back(new Plat(*menu.listePlats_[i]));
}

/*Menu::Menu(const Menu& menu)
	: listePlats_(menu.listePlats_), nbPlats_(menu.nbPlats_), type_(menu.type_)
{
}*/

//destructeur
Menu::~Menu() {
	for (int i = 0; i < listePlats_.size(); i++) {
		delete listePlats_[i];
	}
}

//getters

//getters
int Menu::getNbPlats() const {
	return listePlats_.size();
}

/****************************************************************************
 * Fonction: Menu::getListePlatss
 * Description: retourne listePlats_
 * Paramètres: aucun
 * Retour: vector<Plat*> listePlats_
 ****************************************************************************/
vector<Plat*> Menu::getListePlats() const {
	return listePlats_;
}

//autres methodes
bool Menu::lireMenu(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (file.fail()) {
		cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl;
		return false;
	}
	else {
		string type;
		switch (type_) {
		case Matin:
			type = "-MATIN";
			break;
		case Midi:
			type = "-MIDI";
			break;
		case Soir:
			type = "-SOIR";
			break;
		}
		string ligne;

		string nom;

		string prixString;
		double prix;

		string coutString;
		int cout;


		// lecture
		while (!file.eof()) {
			getline(file, ligne);
			//trouver le bon type de menu (section)
			if (ligne == type) {
				//commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu
				getline(file, ligne);
				int curseur;
				while (ligne[0] != '-' && !file.eof()) {
					//trouver le nom
					for (int i = 0; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						nom += ligne[i];
					}
					//trouver le prix

					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						prixString += ligne[i];

					}
					//passer le prixString en double --- indice dans l'enonce
					prix = stof(prixString.c_str());

					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ')
							break;
						coutString += ligne[i];
					}

					cout = int(stof(coutString.c_str()));


					*this += (Plat(nom, prix, cout));


					nom = "";
					prixString = "";
					coutString = "";

					getline(file, ligne);
				}
			}
		}

		file.close();
		return true;
	}
}

Plat * Menu::trouverPlatMoinsCher() const
{
	Plat minimum(*listePlats_[0]);
	int found = -1;

	for (unsigned i = 0; i < listePlats_.size(); ++i)
	{
		if (*listePlats_[i] < minimum)
		{
			minimum = *listePlats_[i];
			found = i;
		}
	}

	return listePlats_[found];

}

Plat* Menu::trouverPlat(const string& nom) const {
	for (int i = 0; i < listePlats_.size(); i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr;
}


/****************************************************************************
 * Fonction: operateur<<
 * Description: surcharge de l'opérateur << pour afficher un menu
 * Paramètres:	- ostream& os
				- Menu& menu
 * Retour: os
 ****************************************************************************/
ostream& operator<<(ostream& os, Menu& menu) {
	for (int i = 0; i < menu.listePlats_.size(); i++) {
		os << "\t";
		os << *menu.listePlats_[i];
	}
	return os;
}

/****************************************************************************
 * Fonction: operateur=
 * Description: surcharge de l'opérateur = pour affecter un les attributs
				du menu en parametre au menu courant
 * Paramètres:	- Menu& menu
 * Retour: le nouveau menu courant
 ****************************************************************************/
Menu& Menu::operator=(const Menu& menu) {
	if (this != &menu) {
		for (int i = 0; i < menu.listePlats_.size(); i++) {
			listePlats_.push_back(new Plat(*menu.listePlats_[i]));
		}
		type_ = menu.type_;
	}
	return *this;
}

/****************************************************************************
 * Fonction: operateur+=
 * Description: surcharge de l'opérateur += pour ajouter une plat au menu
 * Paramètres:	- Plat* plat
 * Retour: le nouveau menu courant
 ****************************************************************************/
Menu& Menu::operator+=(const Plat& plat) {
	listePlats_.push_back(new Plat(plat));
	return *this;
}