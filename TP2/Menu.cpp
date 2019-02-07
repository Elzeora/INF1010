/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Menu.h"

using namespace std;

//constructeurs

Menu::Menu() {
	//capacite_ = MAXPLAT;
	//listePlats_ = new Plat*[capacite_];
	nbPlats_ = 0;
	type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type) {
	//capacite_ = MAXPLAT;
	//listePlats_ = new Plat*[capacite_];
	nbPlats_ = 0;
	type_ = type;

	//lecture du fichier -- creation du menu
	lireMenu(fichier);
}

//destructeur
Menu::~Menu() {
	// A MODIFIER
	for (int i = 0; i < listePlats_.size(); i++) {
		delete listePlats_[i];
		listePlats_[i] = nullptr;
	}
}

//getters

int Menu::getNbPlats() const {
	return nbPlats_;
}

//autres methodes

bool Menu::lireMenu(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (!file) {
		//cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl;
		return false;
	}
	else {
		string type;
		switch (type_) {
		case Matin :
			type = "-MATIN";
			break;
		case Midi :
			type = "-MIDI";
			break;
		case Soir :
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
			if (ligne == type){
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

					cout =int( stof(coutString.c_str()));
					
					Plat* platTemp = new Plat(nom, prix, cout);
					*this += platTemp;
					delete platTemp;



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
	for (int i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr;
}


//afficher
ostream& operator<<(ostream& os, const Menu& menu) {
	for (int i = 0; i < menu.listePlats_.size(); i++) {
		os << "\t";
		//listePlats_[i]->afficher();
		os << menu.listePlats_[i];
	}
}

//operateur=
Menu& Menu::operator=(Menu& menu) {
	if (this != &menu) {
		listePlats_ = menu.listePlats_;
		nbPlats_ = menu.nbPlats_;
		type_ = menu.type_;
	}
	return *this;
}

//operateur+=
Menu& Menu::operator+=(Plat* plat) {
	if (this->listePlats_[0] != plat) {
		listePlats_.push_back(plat);
		nbPlats_++;
	}
	return *this;
}

//constructeur par copie
Menu::Menu(const Menu& menu)
	: listePlats_(menu.listePlats_), nbPlats_(menu.nbPlats_), type_(menu.type_)
{
}

//acces au nouvel attribut
vector<Plat*> Menu::getListePlats() const {
	return listePlats_;
}

