/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include "Plat.h"
#include "Vege.h"
#include "gestionnaireGenerique.h"
#include "Foncteur.h"

#include <utility>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

class GestionnairePlats : public GestionnaireGenerique< pair<std::string, Plat*>, map<std::string, Plat*>>
{
public:
	GestionnairePlats(const std::string& nomFichier, TypeMenu type); //TODO
	GestionnairePlats(GestionnairePlats* gestionnaire); // TODO

	~GestionnairePlats(); // TODO

	TypeMenu getType() const; // TODO

	Plat* allouerPlat(Plat*); // TODO

	Plat* trouverPlatMoinsCher() const; // TODO utiliser les min/max
	Plat* trouverPlatPlusCher() const; // TODO

	Plat* trouverPlat(const std::string& nom) const; // TODO
	vector<pair<std::string, Plat*>> getPlatsEntre(double borneInf, double borneSup); // TODO
	void lirePlats(const std::string& nomFichier, TypeMenu type);
	pair<std::string, Plat*> lirePlatDe(LectureFichierEnSections& fichier);

	void afficherPlats(ostream& os);

private:
	TypeMenu type_;
};