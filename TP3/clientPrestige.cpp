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
  ****************************************************************************/
ClientPrestige::ClientPrestige() : ClientRegulier()
{
	addresse_ = Zone3;
	statut_ = Prestige;
}

/****************************************************************************
 * Fonction: ClientPrestige::ClientPrestige
 * Description: Constructeur par parametre
 * Param�tres: - string nom
 *				- string prenom
 *				- int tailleGroupe
 *				- int nbPoints
 *				- AdressCode adresse
 ****************************************************************************/
ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AddressCode addresse) 
	: ClientRegulier(nom, prenom, tailleGroupe, nbPoints)
{
	addresse_ = addresse;
	statut_ = Prestige;
}

/****************************************************************************
 * Fonction: getAdresseCode
 * Description: accesseur de l'adresse du client
 * Param�tres: aucun
 * Retour: adresse_
 ****************************************************************************/
AddressCode ClientPrestige::getAddresseCode() const{
	return addresse_;
}

/****************************************************************************
 * Fonction: operateur<<
 * Description: surcharge de l'op�rateur << pour afficher un client prestige
 * Param�tres:	- ostream& os
 *				- ClientPrestige& client
 * Retour: os
 ****************************************************************************/
ostream & operator<<(ostream & os, ClientPrestige client) {
	os << client << "Habite dans la " << client.getAddressCodeString() << endl;
	return os;
}

/****************************************************************************
 * Fonction: getAdresseCodeString
 * Description: convertir la zone d'adresse en string
 * Param�tres: aucun
 * Retour: zone d'adresse
 ****************************************************************************/
string ClientPrestige::getAddressCodeString() const{
	switch (addresse_) {
	case Zone1:
		return "Zone1";
	case Zone2:
		return "Zone2";
	case Zone3:
		return "Zone3";
	}
	return "";
}