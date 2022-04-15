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
	CMatrice(int iNbLigne, int iNbColonne);
	~CMatrice();
	
	/** Acceseur **/
	Type TMATLireElement(int iLigne, int iColonne) { return ppTMATElement[iLigne][iColonne]; }
	int iMATGetNombreColonne() { return uiMATNombreColonne; };
	int iMATGetNombreLigne() { return uiMATNombreLigne; };
	void MATModifierElement(int iLigne, int iColonne, Type TElement);
	void MATAfficherElement(int iLigne, int iColonne);
	
	/** Operation basic **/
	void MATSommeCte(Type TCte);
	void MATAfficherMatrice();
	CMatrice & MATProduitCte(Type TCte);
	CMatrice & MATDivisionCte(Type TCte);

	/** Operation "Avancer" **/
	CMatrice & MATTranspose();
	CMatrice & MATSomme(CMatrice MAT2);
	CMatrice & MATDifference(CMatrice MAT2);
	CMatrice & MATProduitMatrice(CMatrice MAT2);
	
	/** Surcharge Operateur **/
	CMatrice<Type> & operator=(CMatrice <Type> &MATMatrice2);
	CMatrice<Type> & operator+(CMatrice <Type> &MATMatrice2);
	CMatrice<Type> & operator-(CMatrice <Type> &MATMatrice2);
	CMatrice<Type> & operator/(Type TCte);
	CMatrice<Type> & operator*(Type TCte);
	CMatrice<Type> & operator*(CMatrice <Type> &MATMatrice2);
};

template<typename Type> CMatrice<Type>::CMatrice()
{
	uiMATNombreLigne = 0;
	uiMATNombreColonne = 0;

	ppTMATElement = nullptr;
}

template<typename Type> CMatrice<Type>::~CMatrice()
{
	/*Désallocation mémoire*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNombreLigne; uiBoucle++) {
		delete[] ppTMATElement[uiBoucle];
	}
	delete[] ppTMATElement;
}

#include "CMatrice.tpp"  //suite des definitions des methodes de la template

#endif