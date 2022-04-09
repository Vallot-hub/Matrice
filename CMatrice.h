#ifndef CMATRICE_H
#define CMATRICE_H
#include <stdio.h>

using namespace std;

template <typename Type> class CMatrice
{
private:
	int iNombreColonne;
	int iNombreLigne;
	Type** pTElement;

public:
	CMatrice();
	~CMatrice();
	void SetNombreColonne(int iColonne) { iNombreColonne = iColonne; }
	void SetNombreLigne(int iLigne) { iNombreLigne = iLigne; }
	int iGetNombreColonne() { return iNombreColonne; };
	int iGetNombreLigne() { return iNombreLigne; };
	void ModifierElement(int iLigne, int iColonne, Type TElement);

};

template<typename Type> CMatrice<Type>::CMatrice()
{

}

template<typename Type> CMatrice<Type>::~CMatrice()
{

}

#include "CMatrice.tpp"  //suite des definitions des methodes

#endif