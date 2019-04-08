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


using namespace std;

/****************************************************************************
 * Fonction: GestionnairePlats::GestionnairePlats(const string& nomFichier,TypeMenu type)
 * Description: Créer un GestionnairePlats à partir d’un nom de fichier le type de menu qui sera contenu
 * Paramètres: (string&) nomFichier et (TypeMenu) type
 * Retour: rien
 ****************************************************************************/
GestionnairePlats::GestionnairePlats(const string& nomFichier, TypeMenu type)
	: type_(type) { //TODO fait
	lirePlats(nomFichier, type);
}

/****************************************************************************
 * Fonction: GestionnairePlats::GestionnairePlats(GestionnairePlats* gestionnaire)
 * Description: Contructeurpar copie
 * Paramètres: (GestionnairePlats*) gestionnaire
 * Retour: rien
 ****************************************************************************/
GestionnairePlats::GestionnairePlats(GestionnairePlats* gestionnaire) { // TODO fait
	type_ = gestionnaire->type_;
	conteneur_ = gestionnaire->conteneur_;
}

/****************************************************************************
 * Fonction: GestionnairePlats::~GestionnairePlats()
 * Description: destructeur copie
 * Paramètres: rien
 * Retour: rien
 ****************************************************************************/
GestionnairePlats::~GestionnairePlats() { // TODO fait
}

/****************************************************************************
 * Fonction: GestionnairePlats::getType()
 * Description: retourne le type de plat
 * Paramètres: rien
 * Retour: TypeMenu
 ****************************************************************************/
TypeMenu GestionnairePlats::getType() const { // TODO fait
	return type_;
}

/****************************************************************************
 * Fonction: GestionnairePlats::allouerPlat(Plat* plat)
 * Description:: crée un plat à partir d’un autr
 * Paramètres: (Plat*) plat
 * Retour: Plat*
 ****************************************************************************/
Plat* GestionnairePlats::allouerPlat(Plat* plat) { // TODO fait
	return new Plat(*plat);
}

/****************************************************************************
 * Fonction: GestionnairePlats:::trouverPlatMoinsCher()
 * Description::  retourne le plat le moins cher du conteneu
 * Paramètres: rien
 * Retour: Plat*
 ****************************************************************************/
Plat* GestionnairePlats::trouverPlatMoinsCher() const { // TODO fait utiliser les min/max
	Plat* platMoinsCher = (*(min_element(conteneur_.begin(),conteneur_.end(),FoncteurPlatMoinsCher()))).second;
	return platMoinsCher;
}

/****************************************************************************
 * Fonction: GestionnairePlats:::trouverPlatCher()
 * Description::  retourne le plat le plus cher du conteneu
 * Paramètres: rien
 * Retour: Plat*
 ****************************************************************************/
Plat* GestionnairePlats::trouverPlatPlusCher() const { // TODO fait
	auto comparaison = [](const pair<string, Plat*> paire1, const pair<string, Plat*> paire2) -> bool {return paire1.second->getPrix() < paire2.second->getPrix(); };
	return max_element(conteneur_.begin(), conteneur_.end(), comparaison)->second;
}

/****************************************************************************
 * Fonction: GestionnairePlats:::trouverPlat(const string& nom)
 * Description::  Retourne le plat duconteneur qui porte le nom spécifie
 * Paramètres: (string&) nom
 * Retour: Plat*
 ****************************************************************************/
Plat* GestionnairePlats::trouverPlat(const string& nom) const { // TODO fait
	pair<string, Plat*> paireTrouvee;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		paireTrouvee = *it;
		if (paireTrouvee.second->getNom() == nom) {
			return paireTrouvee.second;
		}
	}
	return nullptr;
}

/****************************************************************************
 * Fonction: GestionnairePlats:::getPlatsEntre(double borneInf, double borneSup)
 * Description::   retourne les plats dont les prix sont compris entre la borneInf et la borneSup
 * Paramètres: (double) borneInf (double) borneSup
 * Retour: vector<pair<string, Plat*>>
 ****************************************************************************/
vector<pair<string, Plat*>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup) { // TODO fait
	vector<pair<string, Plat*>> listePlats;
	pair<string, Plat*> platTrouvee;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		platTrouvee = *it;
		if ((platTrouvee.second->getPrix() > borneInf) && (platTrouvee.second->getPrix() < borneSup)) {
			listePlats.push_back(platTrouvee);
		}
	}
	return listePlats;
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

/****************************************************************************
 * Fonction: GestionnairePlats:::afficherPlats(ostreams& os)
 * Description::  affiche les plats
 * Paramètres: (ostream&) os
 * Retour:rien
 ****************************************************************************/
void GestionnairePlats::afficherPlats(ostream& os) { 
	auto it = conteneur_.begin();
	for (it; it != conteneur_.end(); it++) {
		(*it).second->afficherPlat(os);
	}
}