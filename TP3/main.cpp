/*
* Titre : main.cpp - Travail Pratique #3
* Date : 11 F�vrier 2019
* Auteur : Fatou S. Mounzeo
*/

/*
Questions:
1.Pourquoi � t�on besoin de l�attribut type_ dans la classe Plat? Que ce serait-il
pass� s�il n�existait ?
	L'attribut type_ nous permet de d�terminer de quel type de plat il est question.
	Puisque seulement certains types de plat ont acc�s � certaines m�thodes et
	fonctionnalit�s, il faut avoir un attribut pour d�terminer le type de plat. Ainsi,
	on peut utiliser pleinment l'h�ritage, car les classes d�riv�es ont des m�thodes
	non accessibles par la classe m�re Plat. S'il n'y avait pas cet attribut, cel aurait
	�t� beaucoup plus difficile de diff�rencier les types de plats pour faire cetaines
	actions.

2.Quelle est l�importance du static_cast dans la classe Client et ses classes d�riv�es?
	Le static_cast nous permet de pouvoir utiliser les m�thodes et attributs sp�cifiques
	d'une classe d�riv�e de Client dans un vecteur contenant seulement des pointeurs de
	Client. Ainsi, par exemple, en appelant static_cast, on permet au programme d'avoir
	acc�s aux attributs d'un PlatBio m�me si le vector qui contient le pointeur � ce plat
	est form� de pointeurs de Plat.

3.(bonus)Pourquoi est-il int�ressant de d�river ClientPrestige de ClientR�gulier?
	C'est interessant, car ClientPrestige contient les m�mes attributs et m�thodes
	que ClientR�gulier, en plus de d'autres. On peut donc voir ClientPrestige comme
	une sorte de ClientR�gulier, mais plus "sp�cialis�". Ainsi, en faisant d�river
	la classe ClientPrestige de ClientR�gulier, on �vite de se r�p�ter.
*/






#include "Restaurant.h"
#include "ClientPrestige.h"


using namespace std;

int main() {



	//creation du restaurant 
	Restaurant poly("polyFood.txt", "PolyFood", Soir);

	///creer plusieurs clients  


	Client * cl1 = new Client("Martin", "b", 1);

	vector<string> commandeMartin;
	commandeMartin.push_back("Muffin");
	commandeMartin.push_back("Poisson");
	Client * cl2 = new Client("Amy", "wh", 15);
	Client * cl3 = new ClientRegulier("Jonh", "sm", 5, 25);
	Client * cl4 = new ClientRegulier("Moussa", "T", 3, 45);
	Client * cl5 = new ClientPrestige("Andree", "F", 2, 150, Zone2);
	Client * cl6 = new ClientPrestige("Marie", "C", 1, 125, Zone1);
	vector<string> commandeMarie;
	commandeMarie.push_back("Quesadillas");
	commandeMarie.push_back("Ratatouille");
	commandeMarie.push_back("Pancake");
	commandeMarie.push_back("Pizza");

	cout << "\t\t\t\t\tLIVRAISONS" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;

	//Livrer les clients Marie et Martins

	poly.livrerClient(cl6, commandeMarie);
	poly.livrerClient(cl1, commandeMartin);

	cout << "\t\t\t\t\tPLACEMENT DES CLIENT" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;

	//placer les clients 
	poly.placerClients(cl1);
	poly.placerClients(cl2);
	poly.placerClients(cl3);
	poly.placerClients(cl4);
	poly.placerClients(cl5);

	// commander des plats 

	poly.commanderPlat("Poisson", 1, Custom, 3);
	poly.commanderPlat("Pizza", 2, Custom, 4);
	poly.commanderPlat("Poulet", 2);
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

	delete cl1;
	delete cl2;
	delete cl3;
	delete cl4;
	delete cl5;
	delete cl6;

}