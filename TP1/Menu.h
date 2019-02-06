<<<<<<< HEAD:TP1/Menu.h
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
	Menu(string fichier, TypeMenu type); 


	//getters
	int getNbPlats() const; 
	
	//affichage 
	void afficher()const; 

	//methodes en plus
	Plat* trouverPlat(string& nom); 
	void ajouterPlat(Plat & plat); 
	void ajouterPlat(string& nom, double montant, double cout); 
	bool lireMenu(string& fichier);

	
private : 
	 int capacite_;
	Plat** listePlats_;  
	int nbPlats_; 
	TypeMenu type_; 

};

#endif // !MENU_H
=======
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
	Plat* trouverPlat(const string& nom); 
	void ajouterPlat(const Plat & plat); 
	void ajouterPlat(const string& nom, const double& montant, const double& cout); 
	bool lireMenu(string& fichier);

	
private : 
	 int capacite_;
	Plat** listePlats_;  
	int nbPlats_; 
	TypeMenu type_; 

};

#endif // !MENU_H
>>>>>>> f87bb5eabb6459f767b47a21351bdb93ae8310b0:Menu.h
