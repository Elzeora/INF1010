/*
* Titre : Menu.h - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include <fstream>
#include <vector>

enum TypeMenu{Matin, Midi, Soir};
const int MAXPLAT = 5;
class Menu {
public:
	// constructeurs
	Menu();
	Menu(string fichier, TypeMenu type);
	Menu(const Menu& menu);

	//destructeur
	~Menu();

	//getters
	int getNbPlats() const;

	//nouvel attribut
	vector<Plat*> getListePlats() const;

	//methodes en plus
	Plat* trouverPlat(const string& nom) const; // A MODIFIER
	Plat * trouverPlatMoinsCher() const; // Utilise les vecteurs (NE PAS MODIFIER)
	bool lireMenu(const string& fichier);

	//void afficher() const; //A MODIFIER
	friend ostream& operator<<(ostream& os, Menu& menu);

	//operateur=
	Menu& operator=(const Menu& menu);

	//operateur+=
	Menu& operator+=(const Plat& plat);

private :
	vector<Plat*> listePlats_;
	TypeMenu type_;
};

#endif // !MENU_H
