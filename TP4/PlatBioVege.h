
/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
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
                double vitamines = 0, double proteines = 0, double mineraux = 0); // TODO
	// pas certain pour constrcteur par parametre (Bio et Vege) ////////////////////////////////////////////////////////
        ~PlatBioVege();
        Plat * clone() const override; // TODO
		// question: est ce que ca doit etre vraiment Plat* ou bien PlatBioVege*/////////////////
        void afficherPlat(ostream & os) const override;// TODO fait
        double calculerApportNutritif() const override; // TODO fait

};
#endif