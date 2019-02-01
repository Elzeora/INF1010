/*
* Titre : main.cpp - Travail Pratique #1
* Date : 09 Janvier 2019 
* Auteur : David Dratwa
*/

#include "Restaurant.h"
using namespace std; 

int main() {

	//creation du restaurant - avec le fichier donne - le nom : PolyFood - moment de la journee : soir. 
	string fichier = "polyFood.txt";
	string nom = "polyFood";

	Restaurant poly(fichier, nom, Soir);

	//creer plusieurs clients -- des entiers 

	int client1 = 1; 
	int client2 = 5; 
	int client3 = 15; 
	int client4 = 3; 
	int client5 = 2; 

	//placer les clients
	poly.placerClients(client1);
	poly.placerClients(client2);
	poly.placerClients(client3);
	poly.placerClients(client4);
	poly.placerClients(client5);

	// commander des plats
	//Poisson - Table 1 
	string plat1 = "Poisson";
	poly.commanderPlat(plat1, 1);
	//Poulet - Table 2 
	string plat2 = "Poulet";
	poly.commanderPlat(plat2, 2);
	//Pizza - Table 2 
	string plat3 = "Pizza";
	poly.commanderPlat(plat3, 2);
	//Poulet - Table 4
	string plat4 = "Poulet";
	poly.commanderPlat(plat4, 4);
	//Muffin - Table 4 
	string plat5 = "Muffin";
	poly.commanderPlat(plat5, 4);
	//Oeud - Table 4
	string plat6 = "Pizza";
	poly.commanderPlat(plat6, 4);

	//afficher le restaurant
	poly.afficher(); 

	cout << "-------------------------------------------------" << endl; 

	//liberer les tables 

	//afficher le restaurant 
	poly.afficher(); 
	return 0;

}