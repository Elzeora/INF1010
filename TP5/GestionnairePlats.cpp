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



GestionnairePlats(const std::string& nomFichier, TypeMenu type); //TODO
GestionnairePlats(GestionnairePlats* gestionnaire); // TODO

~GestionnairePlats(); // TODO

TypeMenu getType() const; // TODO

Plat* allouerPlat(Plat*); // TODO

Plat* trouverPlatMoinsCher() const; // TODO utiliser les min/max
Plat* trouverPlatPlusCher() const; // TODO

Plat* trouverPlat(const std::string& nom) const; // TODO
vector<pair<std::string, Plat*>> getPlatsEntre(double borneInf, double borneSup); // TODO



void GestionnairePlats::lirePlats(const std::string& nomFichier, TypeMenu type)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}

pair<std::string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier)
{
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	std::string nom, typeStr;
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
	return pair<std::string, Plat*>(plat->getNom(), plat);
}



void afficherPlats(ostream& os) { //TODO
	map<std::string, Plat*>::iterator end = conteneur_.end();
	copy(conteneur_.begin(), end, ostream_iterator<std::string, Plat*>(os, "\n"));



}