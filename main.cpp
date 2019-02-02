/*
* Titre : main.cpp - Travail Pratique #1
* Date : 09 Janvier 2019 
* Auteur : David Dratwa
*/

#include "Restaurant.h"
#include <string>
#include <fstream>
using namespace std; 

int main() {
	//creation du restaurant - avec le fichier donne - le nom : PolyFood - moment de la journee : soir. 
	string fichier = "polyFood.txt";
	ifstream file(fichier);
	string nom = "PolyFood";
	Restaurant poly = Restaurant(fichier, nom, Soir);
	poly.lireTable(fichier);
	int client1 = 15; 
	int client2 = 6;
	int client3 = 5; 
	int client4 = 1; 
	int client5 = 2; 

	//placer les clients 
	poly.placerClients(client1);
	poly.placerClients(client2);
	poly.placerClients(client3);
	poly.placerClients(client4);
	poly.placerClients(client5);
	// commander des plats
	//Poisson - Table 1 
	string plat = "Poisson";
	poly.commanderPlat(plat, 1);
	//Poulet - Table 2 
	plat = "Poulet";
	poly.commanderPlat(plat, 2);
	//Pizza - Table 2 
	plat = "Pizza";
	poly.commanderPlat(plat, 2);
	//Poulet - Table 4
	plat = "Poulet";
	poly.commanderPlat(plat, 4);
	//Muffin - Table 4 
	plat = "Muffin";
	poly.commanderPlat(plat, 4);
	//Oeud - Table 4 
	plat = "oeuf";
	poly.commanderPlat(plat, 4);
	

	//afficher le restaurant
	poly.afficher(); 

	cout << "-------------------------------------------------" << endl; 

	//liberer les tables 
	for (int i = 0; i < 10; i++){
		poly.libererTable(i);
	}
	//afficher le restaurant 
	poly.afficher(); 
	return 0;

}