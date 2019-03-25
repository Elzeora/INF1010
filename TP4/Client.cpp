/*
* Titre : client.cpp - Travail Pratique #4
* Date :  mars 2019
* Auteur : Louis Roberge  && Jean-Sébastien Patenaude
*/
#include "Client.h"

Client::Client()
{ tableOccupee_ = nullptr;}

Client::Client(string_view nom, string_view prenom, int tailleGroupe) : nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe)
{    tableOccupee_ = nullptr; }

int Client::getTailleGroupe() const
{	return tailleGroupe_;}

string Client::getNom() const
{	return nom_;}

string Client::getPrenom() const
{	return prenom_;}

Table * Client::getTable() const
{	return tableOccupee_;}

int Client::getNbPoints() const
{	return 0;}

double Client::getReduction(const Restaurant & res, double montant, bool estLivraison) const
{	return 0;}

void Client:: setTable(Table * ta)
{ tableOccupee_ = ta;}


void Client::afficherClient(ostream & os) const { 
	if (this->getTable() != nullptr)
		os << this->getPrenom() << " " << this->getNom() << " a une place au resto.\n";
	else
		os << this->getPrenom() << " " << this->getNom() << " n'a pas une place au resto.\n";
}

