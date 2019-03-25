/*
* Titre : Vege.h - Travail Pratique #4
* Date :  mars 2019
* Auteur : Louis Roberge  && Jean-Sébastien Patenaude
*/
#ifndef VEGE_H
#define VEGE_H
#include <iostream>
#include <string_view>
#include <string>
#include"Taxable.h"
using namespace std;
class Vege
{
public:
	Vege(string nom, double vitamines, double proteines, double mineraux);
	double getVitamines() const;
	double getProteines() const;
	double getMineraux() const;
	void setVitamines(double vitamines);
	void setProteines(double proteines);
	void setMineraux(double mineraux);
	void afficherVege(ostream & os)const;  // TODO fait
	virtual double calculerApportNutritif() const; // TODO fait

protected: 
	double vitamines_;
	double proteines_;
	double mineraux_;
    
    string nom_;
};
#endif
