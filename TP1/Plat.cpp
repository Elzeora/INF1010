/****************************************************************************
 * Fichier: Plat.cpp
 * Auteur: Louis Roberge
 * Date: 29 Janvier 2019
 * Description: Impl�mentation de la classe Plat
 ****************************************************************************/
#include "Plat.h"
#include <iostream>
#include <string>
using namespace std;

/****************************************************************************
 * Fonction: Plat :: Plat
 * Description: Constructeur par d�faut
 * Param�tres: aucun
 * Retour: aucun
 ****************************************************************************/
Plat::Plat() {
	nom_ = "inconnu";
	prix_ = 0.0;
	cout_ = 0.0;
}
/****************************************************************************
 * Fonction: Plat :: Plat
 * Description: Constructeur par parametres
 * Param�tres:  - string nom : valeur de nom_ (IN)
 *				- double prix : valeur de prix_ (IN)
 *	            - double cout : valeur de cout_ (IN)
 * Retour: aucun
 ****************************************************************************/
Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}
/****************************************************************************
 * Fonction: Plat::getNom
 * Description: Retourne nom_
 * Param�tres: aucun
 * Retour: (string) le string de nom_
 ****************************************************************************/
string Plat::getNom() const {
	return nom_;
}
/****************************************************************************
 * Fonction: Plat::getPrix
 * Description: Retourne prix_
 * Param�tres: aucun
 * Retour: (double) la valeur de prix_
 ****************************************************************************/
double Plat::getPrix() const {
	return prix_;
}
/****************************************************************************
 * Fonction: Plat::getCout
 * Description: Retourne cout_
 * Param�tres: aucun
 * Retour: (double) la valeur de cout_
 ****************************************************************************/
double Plat::getCout() const {
	return cout_;
}
/****************************************************************************
 * Fonction: Plat::setNom
 * Description: permet d'attribuer un nouveau nom au plat
 * Param�tres: - string nom : valeur de nom_ (IN)
 * Retour: rien
 ****************************************************************************/
void Plat::setNom(string nom) {
	nom_ = nom;
}
/****************************************************************************
 * Fonction: Plat::setPrix
 * Description: permet d'attribuer un nouveau prix au plat
 * Param�tres: 	- double prix : valeur de prix_ (IN)
 * Retour: rien
 ****************************************************************************/
void Plat::setPrix(double prix) {
	prix_ = prix;
}
/****************************************************************************
 * Fonction: Plat::afficher
 * Description: permet d'afficher le plat
 * Param�tres: aucun
 * Retour: rien
 ****************************************************************************/
void Plat::afficher() const {
	cout << "        " << nom_ << " - " << prix_ << " $ " << "(" << cout_ << "$" << " pour le restaurant)" << endl;
}





