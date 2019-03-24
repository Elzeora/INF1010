#ifndef PLAT_BIOVEGE_H
#define PLAT_BIOVEGE_H

#include "PlatBio.h"
#include "Vege.h"
#include "def.h"
class PlatBioVege :
	public PlatBio, public Vege
{
public:
		PlatBioVege(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0,
					double vitamines = 0, double proteines = 0, double mineraux = 0); // TODO fait
        ~PlatBioVege();
        Plat * clone() const; // TODO fait
        void afficherPlat(ostream & os) const; // TODO fait
        double calculerApportNutritif() const; // TODO fait

};
#endif
