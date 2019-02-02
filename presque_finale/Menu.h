/*
* Titre : Menu.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#ifndef MENU_H
#define MENU_H 

#include "Plat.h"
#include <fstream>

enum TypeMenu{Matin, Midi, Soir};
const int MAXPLAT = 5;
class Menu {
public: 
	// constructeurs
	Menu(); 
	Menu(string& fichier, const TypeMenu& type); 

	//destructeur
	~Menu();

	//getters
	int getNbPlats() const; 
	
	//affichage 
	void afficher()const; 

	//methodes en plus
	Plat* trouverPlat(const string& nom)const; 
	void ajouterPlat(Plat & plat); 
	void ajouterPlat(const string& nom, const double& montant, const double& cout); 
	bool lireMenu(string& fichier);
	void lireBonMenu(string motCherche, string& fichier);//////ajout
	
private : 
	unsigned int capacite_;
	Plat** listePlats_;  
	unsigned int nbPlats_; 
	TypeMenu type_; 

};

#endif // !MENU_H
