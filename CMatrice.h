#ifndef CMATRICE_H
#define CMATRICE_H
#include <stdio.h>

using namespace std;

template <typename Type> class CMatrice
{
private:
	int iMATNombreColonne;
	int iMATNombreLigne;
	Type** pTMATElement;

public:
	CMatrice();
	CMatrice(int iNbLigne, int iNbColonne);
	~CMatrice();
	
	int iMATGetNombreColonne() { return iMATNombreColonne; };
	int iMATGetNombreLigne() { return iMATNombreLigne; };
	void MATModifierElement(int iLigne, int iColonne, Type TElement);
	void MATAfficherMatrice();
	void MATAfficherElement(int iLigne, int iColonne);
};

template<typename Type> CMatrice<Type>::CMatrice()
{

}

template<typename Type> CMatrice<Type>::~CMatrice()
{

}

#include "CMatrice.tpp"  //suite des definitions des methodes de la template

#endif