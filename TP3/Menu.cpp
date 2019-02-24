/*
* Titre : Menu.cpp - Travail Pratique #3
* Date : 11 Février 2019
* Auteur : Fatou S Mounzeo
*/

#include "Menu.h"

//constructeurs 

Menu::Menu() {
	type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type) {
	type_ = type;

	//lecture du fichier -- creation du menu
	lireMenu(fichier);
}

/****************************************************************************
 * Fonction: Menu::Menu
 * Description: Constructeur par copie de Menu
 * Paramètres: - Menu& menu
 ****************************************************************************/
Menu::Menu(const Menu & menu) : type_(menu.type_) {
	for (unsigned i = 0; i < menu.listePlats_.size(); ++i){
		switch (menu.listePlats_[i]->getType()) {
		case Bio:
			listePlats_.push_back(static_cast<PlatBio*>(menu.listePlats_[i]));
			break;
		case Regulier:
			listePlats_.push_back(new Plat(*menu.listePlats_[i]));
			break;
		}
	}
}

/****************************************************************************
 * Fonction: ~Menu
 * Description: Destructeur de Menu
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Menu::~Menu() {
	for (unsigned i = 0; i < listePlats_.size(); i++)
		delete listePlats_[i];
}


//getters

vector<Plat*> Menu::getListePlats() const {
	return listePlats_;
}

//autres methodes 

/****************************************************************************
 * Fonction: operateur<<
 * Description: surcharge de l'opérateur << pour afficher un menu
 * Paramètres:	- ostream& os
 *				- Menu& menu
 * Retour: os
 ****************************************************************************/
ostream& operator<<(ostream& os, const Menu& menu) {
	for (unsigned i = 0; i < menu.listePlats_.size(); ++i) {
		if (menu.listePlats_[i]->getType() == Regulier)
			os << "\t" << *menu.listePlats_[i] << endl;
		if (menu.listePlats_[i]->getType() == Bio) {
			os << "comprend une taxe ecologique de : " << static_cast<PlatBio*>(menu.listePlats_[i])->getEcoTaxe()
			   << '$' << endl;
		}
	}
	return os;
}


Menu& Menu::operator+=(const Plat& plat) {
	listePlats_.push_back(new Plat(plat));
	return *this;
}

/****************************************************************************
 * Fonction: operateur+=
 * Description: surcharge de l'opérateur += pour ajouter un PlatBio
 * Paramètres:	- PlatBio& plat
 * Retour: Menu&
 ****************************************************************************/
Menu& Menu::operator+=(const PlatBio& plat) {
	PlatBio* platB = new PlatBio(plat);
	listePlats_.push_back(static_cast<Plat*>(platB));
	return *this;
}

/****************************************************************************
 * Fonction: operateur=
 * Description: surcharge de l'opérateur = pour assigner les attributs du menu
				en parametre au menu courant
 * Paramètres:	- Menu& menu
 * Retour: Menu&
 ****************************************************************************/
Menu & Menu::operator=(const Menu & menu) {
	if (this != &menu) {
		this->type_ = menu.type_;
		listePlats_.clear();
		for (unsigned i = 0; i < menu.listePlats_.size(); ++i) {
			if (menu.listePlats_[i]->getType() == Regulier)
				listePlats_.push_back(new Plat(*menu.listePlats_[i]));
			if (menu.listePlats_[i]->getType() == Bio) {
				listePlats_.push_back(static_cast<PlatBio*>(menu.listePlats_[i]));
			}
		}
	}
	return *this;
}



void Menu::lireMenu(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (!file) {
		cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl;
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
		double cout;

		string typeString;
		int typePlat;

		string ecotaxeString;
		double ecoTaxe;


		// lecture
		while (!file.eof()) {
			std::getline(file, ligne);
			//trouver le bon type de menu (section)
			if (ligne == type) {
				//commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu 
				std::getline(file, ligne);
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

					//trouver le type 
					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						typeString += ligne[i];

					}

					typePlat = stoi(typeString);

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
						if (ligne[i] == ' ') {
							if (typePlat == Bio)
								curseur = i;
							break;

						}

						coutString += ligne[i];
					}

					cout = stod(coutString.c_str());

					//lire le taux si plat bio

					if (typePlat == TypePlat::Bio) {

						for (int i = curseur + 1; i < int(ligne.size()); i++) {
							if (ligne[i] == ' ')
								break;
							ecotaxeString += ligne[i];
						}
						ecoTaxe = stod(ecotaxeString);
						*this += PlatBio(nom, prix, cout, ecoTaxe);
					}
					else {
						*this += Plat(nom, prix, cout);
					}

					nom = "";
					prixString = "";
					coutString = "";
					typeString = "";
					ecotaxeString = "";

					std::getline(file, ligne);
				}
			}
		}

		file.close();
	}
}

Plat * Menu::trouverPlatMoinsCher() const {
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
	for (int i = 0; i < listePlats_.size(); ++i) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr;
}