/*
* Titre : Vege.cpp - Travail Pratique #4
* Date :  mars 2019
* Auteur : Louis Roberge  && Jean-Sébastien Patenaude
*/
#include "Vege.h"

Vege::Vege(string nom, double vitamines, double proteines, double mineraux)
	: nom_(nom),vitamines_(vitamines), proteines_(proteines), mineraux_(mineraux){
}

double Vege::getVitamines() const
{	return vitamines_;}

double Vege::getProteines() const
{	return proteines_;}

double Vege::getMineraux() const
{	return mineraux_;}

void Vege::setVitamines(double vitamines)
{	vitamines_ = vitamines;}

void Vege::setProteines(double proteines)
{	proteines_ = proteines;}

void Vege::setMineraux(double mineraux)
{	mineraux_ = mineraux;}

void Vege::afficherVege(ostream & os) const{   
	os << "VEGE - " << nom_ << "  Vitamines : " << getVitamines() << "  Proteines : " << getProteines()
	<< "  Mineraux : " << getMineraux() << endl;
}

double Vege::calculerApportNutritif() const
{	return 0;}

