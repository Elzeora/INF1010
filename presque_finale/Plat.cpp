/*
* Titre : main.cpp - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#include "Plat.h"

using namespace std;

//constructeur par defaut
Plat::Plat() {
	nom_ = "inconnu";
	prix_ = 0.0;
	cout_ = 0.0;
}

//constructeur par parametre
Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

//methodes
string Plat::getNom() const {
	return nom_;
}
double Plat::getPrix() const {
	return prix_;
}
double Plat::getCout() const {
	return cout_;
}
void Plat::setNom(string nom) {
	nom_ = nom;
}
void Plat::setPrix(double prix) {
	prix_ = prix;
}
void Plat::afficher() const{
	cout << nom_ << " - " << prix_ << "$" << " (" << cout_ << "$ pour le restaurant)" << endl;
}
