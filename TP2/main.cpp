/*
* Titre : main.cpp - Travail Pratique #1
* Date : 18 Janvier 2019 
* Auteur : Allan BEDDOUK
*/

/*
Questions:
	1. L'op�rateur = permet d'attribuer les attributs d'un objet pass�
		en parametres � l'objet courant et le constructeur par copie permet
		de creer un objet avec un objet pass� en parametre. Cela permet de
		faire une deep copy ou lieu d'une shallow copy, ce qui �vite qu'il y
		ait deux pointeurs qui pointent la meme chose.

	2. La diff�rence est que l'op�rateur = donne les attributs de l'objet en parametre
		lors de l'ex�cution du programme, tandis que le constructeur par copie cr�e
		un nouvel objet avec les memes attributs que l'objet en parametre avant
		l'ex�cution du programme.
*/



#include "Restaurant.h"
#include <vector>

using namespace std; 

int main() {

	//creation du restaurant 
	Restaurant poly("polyFood.txt", "PolyFood", Soir); 

	///creer plusieurs clients 
	int nbclient1 = 1; 
	int nbclient2 = 5; 
	int nbclient3 = 15; 
	int nbclient4 = 3; 
	int nbclient5 = 2; 


	//placer les clients 
	poly.placerClients(nbclient1);
	poly.placerClients(nbclient2);
	poly.placerClients(nbclient3); 
	poly.placerClients(nbclient4); 
	poly.placerClients(nbclient5); 

	// commander des plats 
	poly.commanderPlat("Poisson", 1);
	poly.commanderPlat("Poulet", 2);
	poly.commanderPlat("Pizza", 2); 
	poly.commanderPlat("Poulet", 4); 
	poly.commanderPlat("Muffin", 4); 
	poly.commanderPlat("Oeuf", 4); 


	//Creation d'une copie du poly restaurant 
	Restaurant poly2(poly);
	poly2.setNom("PolyFood2");


	//Affichage du restaurant poly 
	cout << poly;

	cout << "--------------------------------------------------------------------------------------------------" << endl; 


	//liberer les tables et calcule du chiffre d'affaire
	poly.libererTable(1);
	poly.libererTable(2);
	poly.libererTable(3);
	poly.libererTable(4);

	cout << poly;

	cout << "====================================================================================================" << endl;

	// Le restaurant Poly2 ne doit pas encore avoir liberer ses tables
	cout << poly2;

	poly2 = poly;
	

	cout << "--------------------------------------------------------------------------------------------------" << endl;
	// Le restaurant Poly2 doit maintenant avoir toutes ses tables lib�r�es
	cout << poly2;
}