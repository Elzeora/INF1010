/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"
#include <string>

using namespace std;

GestionnairePlats::GestionnairePlats(const string& nomFichier, TypeMenu type)
	: type_(type) { //TODO fait
	lirePlats(nomFichier, type);
}


GestionnairePlats::GestionnairePlats(GestionnairePlats* gestionnaire) { // TODO fait
	type_ = gestionnaire->type_;
	for (map<string, Plat*>::iterator it = gestionnaire->conteneur_.begin(); it != gestionnaire->conteneur_.end(); it++) {
		ajouter(*it);
	}
}


GestionnairePlats::~GestionnairePlats() { // TODO fait
	for (map<string, Plat*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		delete it->second;
	}
}


TypeMenu GestionnairePlats::getType() const { // TODO fait
	return type_;
}


Plat* GestionnairePlats::allouerPlat(Plat* plat) { // TODO fait
	Plat* ptrPlat = new Plat(*plat);
	return ptrPlat;
}


Plat* GestionnairePlats::trouverPlatMoinsCher() const { // TODO fait utiliser les min/max
	map<string, Plat*>::iterator plat;
	plat = min_element(getConteneur().begin(), getConteneur().end(), FoncteurPlatMoinsCher());
	return plat->second;
}


Plat* GestionnairePlats::trouverPlatPlusCher() const { // TODO fait
	map<string, Plat*>::iterator plat;
	// avec une fonction lambda en 3e parametre: [capture] (param) -> retour {body}
	plat = max_element(getConteneur().begin(), getConteneur().end(),
		[](const pair<string, Plat*>& plat1, const pair<string, Plat*>& plat2) -> bool {
			return plat1.second->getPrix() < plat2.second->getPrix(); });
	return plat->second;
}


Plat* GestionnairePlats::trouverPlat(const string& nom) const { // TODO fait
	for (map<string, Plat*>::iterator it = getConteneur().begin(); it != getConteneur().end(); it++) {
		if (it->second->getNom() == nom)
			return it->second;
	}
	return nullptr;
}


vector<pair<string, Plat*>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup) { // TODO fait
	vector<pair<string, Plat*>> vecteurPlat;
	copy_if(getConteneur().begin(), getConteneur().end(), vecteurPlat.begin(), FoncteurIntervalle(borneInf, borneSup));
	return vecteurPlat;
}


void GestionnairePlats::lirePlats(const string& nomFichier, TypeMenu type)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}

pair<string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier)
{
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	string nom, typeStr;
	TypePlat type;
	double prix, coutDeRevient;
	lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
	type = TypePlat(stoi(typeStr));
	double ecotaxe, vitamines, proteines, mineraux;
	switch (type) {
	case TypePlat::Bio:
		lectureLigne >> ecotaxe;
		plat = new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
		break;
	case TypePlat::BioVege:
		lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
		plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
		break;
	case TypePlat::Vege:
		lectureLigne >> vitamines >> proteines >> mineraux;
		plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
		break;
	default:
		plat = new Plat{ nom, prix, coutDeRevient };
	}
	return pair<string, Plat*>(plat->getNom(), plat);
}


void GestionnairePlats::afficherPlats(ostream& os) { //TODO fait
	for (map<string, Plat*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++) {
		it->second->afficherPlat(os);
	}
}