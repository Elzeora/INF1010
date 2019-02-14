/****************************************************************************
 * Fichier: clientPrestige.cpp
 * Auteur: Jean-S�bastien Patenaude
 * Date: 14 f�vrier 2019
 * Description: Impl�mentation de la classe ClientPrestige
 ****************************************************************************/

#include "ClientPrestige.h"

 /****************************************************************************
  * Fonction: ClientPrestige::ClientPrestige
  * Description: Constructeur par d�faut
  * Param�tres: aucun
  * Retour: aucun
  ****************************************************************************/
ClientPrestige::ClientPrestige() :ClientRegulier()
{
	addresse_ = Zone3;
}

ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AddressCode addresse) 
	: ClientRegulier(nom, prenom, tailleGroupe, nbPoints)
{
	addresse_ = addresse;
}

//Accesseur 
AddressCode ClientPrestige::getAddresseCode() {
	return addresse_;
}

//Autres Fonctions??
ostream & operator<<(ostream & os, ClientPrestige client) {
	os << client << "Habite dans la " << client.getAddressCodeString << endl;
}

string ClientPrestige::getAddressCodeString() {
	switch (addresse_) {
	case Zone1:
		return "Zone1";
	case Zone2:
		return "Zone2";
	case Zone3:
		return "Zone3";
	}
}