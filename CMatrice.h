#ifndef CMATRICE_H
#define CMATRICE_H
#include <stdio.h>
#include "CException.h"

using namespace std;

template <typename Type> class CMatrice
{
private:
	unsigned int uiMATNombreColonne;
	unsigned int uiMATNombreLigne;
	Type** ppTMATElement;

public:
	CMatrice();
	CMatrice(unsigned int uiNbLigne, unsigned int uiNbColonne);
	CMatrice(CMatrice <Type> &MATMatrice);
	~CMatrice();
	
	/** Acceseur **/
	Type TMATLireElement(unsigned int uiLigne,unsigned int uiColonne) { return ppTMATElement[uiLigne][uiColonne]; }
	unsigned int uiMATGetNombreColonne() { return uiMATNombreColonne; };
	unsigned int uiMATGetNombreLigne() { return uiMATNombreLigne; };
	void MATModifierElement(unsigned int iLigne, unsigned int iColonne, Type TElement);
	
	/** Operation basic **/
	void MATAfficherMatrice();
	CMatrice<Type> operator/(Type TCte);
	CMatrice<Type> operator*(Type TCte);

	/** Operation "Avancer" **/
	CMatrice MATTranspose();
	CMatrice<Type> operator+(CMatrice <Type> &MAT2);
	CMatrice<Type> operator-(CMatrice <Type> &MAT2);
	CMatrice<Type> operator*(CMatrice <Type> &MAT2);
	
	/** Surcharge Operateur **/
	CMatrice<Type> operator=(CMatrice <Type> &MAT2);
};

/***
** Constructeur par defaut
** Entrée: CMatrice <Type>
** PreCondition: rien
** Sortie: rien
** PostCondition: l'objet est initialiser
***/
template<typename Type> CMatrice<Type>::CMatrice()
{
	uiMATNombreLigne = 0;
	uiMATNombreColonne = 0;

	ppTMATElement = nullptr;
}

/***
** Destructeur
** Entrée: CMatrice <Type>
** PreCondition: rien
** Sortie: rien
** PostCondition: l'objet est detruit
***/
template<typename Type> CMatrice<Type>::~CMatrice()
{
	/*Désallocation mémoire*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNombreLigne; uiBoucle++) 
	{
		delete[] ppTMATElement[uiBoucle];
	}
	delete[] ppTMATElement;
}

#include "CMatrice.tpp"  //suite des definitions des methodes de la template

#endif