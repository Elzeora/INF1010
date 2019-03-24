#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"
class PlatVege :
	public Vege, public Plat, public Taxable
{
public:
	PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0, double proteines = 0, double mineraux = 0); //TODO
    ~ PlatVege();
    Plat * clone()const;  // TODO fait
    void afficherPlat(ostream & os) const; // TODO fait
    double calculerApportNutritif() const;  // TODO fait
	void setTaxe();
	double getTaxe() const;
protected:
	double taxe_;
};
#endif
