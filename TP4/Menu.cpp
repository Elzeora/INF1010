/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#include "Menu.h"
#include "LectureFichierEnSections.h"
#include <cassert>  //? Contient "assert" qui permet de s'assurer qu'une expression est vraie, et terminer le programme avec un message d'erreur en cas contraire.
using namespace std;

// Constructeurs.

Menu::Menu() : type_{TypeMenu::Matin}{
}

Menu::Menu(string fichier, TypeMenu type) :	type_{type} {
	lireMenu(fichier); 
}

Menu::~Menu(){
	//à vérifier//////////////////////////////////////////////////////////////
	for (int i = 0; i < listePlats_.size(); i++) {
		delete listePlats_[i];
	}
	for (int i = 0; i < listePlatsVege_.size(); i++) {
		delete listePlatsVege_[i];
	}
}

Plat* Menu::allouerPlat(Plat* plat) {
    return plat->clone();
}


Menu::Menu(const Menu & menu) : type_(menu.type_) {
	for (int i = 0; i < menu.listePlats_.size(); i++) {
		listePlats_.push_back( new Plat (*(menu.listePlats_[i])));
    }
	for (int i = 0; i < menu.listePlatsVege_.size(); i++) {
		listePlatsVege_.push_back( new PlatVege(dynamic_cast<PlatVege*>(menu.listePlatsVege_[i])));
	}
}

Menu & Menu::operator=(const Menu & menu) {
	if (&menu != this) {
		type_ = menu.type_;
		for (int i = 0; i < listePlats_.size(); i++) {
			listePlats_.push_back(allouerPlat(menu.listePlats_[i]));
		}
		for (int i = 0; i < listePlatsVege_.size(); i++) {
			listePlatsVege_.push_back(allouerPlat(menu.listePlatsVege_[i]));
		}
	}
}

// Getters.

vector<Plat*> Menu::getListePlats() const {
	return listePlats_;
}

// Autres methodes.

Menu& Menu::operator+=(owner<Plat*> plat) {
        //TODO
}

void Menu::lireMenu(const string& nomFichier) {
	LectureFichierEnSections fichier{nomFichier};
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type_)]);
	while (!fichier.estFinSection())
		*this += lirePlatDe(fichier);
}

Plat* Menu::trouverPlatMoinsCher() const{
	assert(!listePlats_.empty() && "La liste de plats de doit pas etre vide pour trouver le plat le moins cher.");
	Plat* minimum = listePlats_[0];
	for (Plat* plat : listePlats_)
		if (*plat < *minimum)
			minimum = plat;

	return minimum;
}

Plat* Menu::trouverPlat(string_view nom) const {
	for (Plat* plat : listePlats_)
		if (plat->getNom() == nom)
			return plat; 

	return nullptr; 
}
Plat* Menu::lirePlatDe(LectureFichierEnSections& fichier) {
    auto lectureLigne = fichier.lecteurDeLigne();
    
    string nom, typeStr;
    TypePlat type;
    double prix, coutDeRevient;
    lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
    type = TypePlat(stoi(typeStr));
    double ecotaxe, vitamines, proteines, mineraux;
    switch (type) {
        case TypePlat::Bio :
            lectureLigne >> ecotaxe;
            return new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
        case TypePlat::BioVege:
            lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
            return new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
        case TypePlat::Vege:
            lectureLigne >> vitamines >> proteines >> mineraux;
            return new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
        default:
            return new Plat{nom, prix, coutDeRevient};
    }
    
}

// Fonctions globales.

ostream& operator<<(ostream& os, const Menu& menu){   
        //TODO
	for (int i = 0; i < menu.listePlats_.size(); i++) {
		menu.listePlats_[i]->afficherPlat(os);
	}
	os << "MENU ENTIERREMENT VEGETARIEN" << endl;
	for (int i = 0; i < menu.listePlatsVege_.size(); i++) {
		menu.listePlatsVege_[i]->afficherVege(os);
	}
}
/////////////////verif avec static_cast ou dynamic_cast