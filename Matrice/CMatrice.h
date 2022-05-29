#ifndef CMATRICE_H
#define CMATRICE_H
#include <stdio.h>
#include <iostream>
#include "CException.h"

#define DivisionParZero 201
#define DimentionIncoherenteCreation 202
#define DimentionIncoherenteModifierElement 203
#define DimentionIncoherenteLireElement 204
#define DimentionIncoherenteSommmeMatrice 205
#define DimentionIncoherenteDifferenceMatrice 206
#define DimentionIncoherenteProduitMatrice 207

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
	CMatrice(const CMatrice <Type> &MATMatrice);
	~CMatrice();
	
	/** Acceseur **/
	Type TMATLireElement(unsigned int uiLigne, unsigned int uiColonne)const;
	unsigned int uiMATGetNombreColonne()const { return uiMATNombreColonne; };
	unsigned int uiMATGetNombreLigne()const { return uiMATNombreLigne; };
	void MATModifierElement(unsigned int iLigne, unsigned int iColonne, Type TElement);
	CMatrice<Type> MATPermutation(Type *pTTab, unsigned int Taille);
	CMatrice<Type> MATPermutationVecteur(unsigned int uiTab[uiMATGetNombreLigne()]);

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
	CMatrice<Type> operator=(CMatrice <Type> MAT2);
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

/***
** Constructeur de confort
** Entrée: uiNbLigne, nombre de lignes de la matrice || uiNbColonne, le nombre de colonnes de la matrice
** PreCondition: rien
** Sortie: rien
** PostCondition: l'objet est initialiser à partir d'un autre CMatrice<T>
***/
template<typename Type> CMatrice<Type>::CMatrice(unsigned int uiNbLigne, unsigned int uiNbColonne)
{
	if (uiNbColonne < 0 || uiNbLigne < 0)
	{
		CException EXCError(DimentionIncoherenteCreation);
		throw EXCError;
	}
	
	uiMATNombreColonne = uiNbColonne;
	uiMATNombreLigne = uiNbLigne;

	ppTMATElement = new Type * [uiNbLigne];
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbLigne; uiBoucle++)
	{
		ppTMATElement[uiBoucle] = new Type[uiNbColonne];
	}
}

/***
** Constructeur de recopie
** Entrée: CMatrice
** PreCondition: un objet initialisé
** Sortie: Rien
** PostCondition: l'objet crée est une copie de l'objet d'entrée
***/
template<typename Type> CMatrice<Type>::CMatrice(const CMatrice <Type> &MATMatrice) 
{
		/*Nouvelle affectation de valeur*/
	uiMATNombreLigne = MATMatrice.uiMATGetNombreLigne();
	uiMATNombreColonne = MATMatrice.uiMATGetNombreColonne();

		/*Nouvelle allocation de la mémoire*/
	ppTMATElement = new Type*[uiMATNombreLigne];
	for (unsigned int uiBoucleAlloc = 0; uiBoucleAlloc < uiMATNombreLigne; uiBoucleAlloc++) 
	{
		ppTMATElement[uiBoucleAlloc] = new Type[uiMATNombreColonne];
	}

		/*Affectation des valeurs dans la matrice*/
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATModifierElement(uiBoucle1, uiBoucle2, MATMatrice.TMATLireElement(uiBoucle1, uiBoucle2));
		}
	}
}

template<typename Type> inline Type CMatrice<Type>::TMATLireElement(unsigned int uiLigne, unsigned int uiColonne)const
{ 
	if (uiLigne > uiMATNombreColonne || uiColonne > uiMATNombreColonne)
	{
		CException EXCError(DimentionIncoherenteLireElement);
		throw EXCError;
	}
	return ppTMATElement[uiLigne][uiColonne]; 
}
/*** recopie par operateur
** Entrée: CMatrice
** PreCondition: un objet initialisé
** Sortie: Rien
** PostCondition: l'objet crée est une copie de l'objet d'entrée
***/
template<typename Type> CMatrice<Type> CMatrice<Type>::operator=(CMatrice <Type> MATMatrice2) 
{
	
	/*Si les deux matrices sont de taille différente*/
	if ((uiMATGetNombreLigne() != MATMatrice2.uiMATGetNombreLigne()) || (uiMATGetNombreColonne() != MATMatrice2.uiMATGetNombreColonne()))
	{
		/*Libération mémoire*/
		for (unsigned int uiBoucleAlloc = 0; uiBoucleAlloc < uiMATNombreLigne; uiBoucleAlloc++) 
		{
			delete[] ppTMATElement[uiBoucleAlloc];
		}
		delete[] ppTMATElement;

		/*Nouvelle affectation de valeur*/
		uiMATNombreLigne = MATMatrice2.uiMATGetNombreLigne();
		uiMATNombreColonne = MATMatrice2.uiMATGetNombreColonne();

		/*Nouvelle allocation de la mémoire*/
		ppTMATElement = new Type*[uiMATNombreLigne];
		for (unsigned int uiBoucleAlloc = 0; uiBoucleAlloc < uiMATNombreLigne; uiBoucleAlloc++) 
		{
			ppTMATElement[uiBoucleAlloc] = new Type[uiMATNombreColonne];
		}
	}

	/*Affectation des valeurs dans la matrice*/
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATModifierElement(uiBoucle1, uiBoucle2, MATMatrice2.TMATLireElement(uiBoucle1, uiBoucle2));
		}
	}
	return *this;
}

/***
** Permet de modifier un élément d'un CMatrice
** Entrée: uiLigne, numéro de la lignes || uiColonne, numéro de la colonnes || TElement, l'élément à modifier
** PreCondition: uiLigne < uiMATNombreLigne et uiColonne < uiMATNombreColonne
** Sortie: rien
** PostCondition: modification de l'élément à la position uiNbLigne, uiNbColonne
***/
template<typename Type> void CMatrice<Type>::MATModifierElement(unsigned int uiLigne, unsigned int uiColonne, Type TElement)
{
    if ( uiColonne > uiMATNombreColonne || uiColonne > uiMATNombreLigne )
	{
		CException EXCError(DimentionIncoherenteModifierElement);
		throw EXCError;
	}
	ppTMATElement[uiLigne][uiColonne] = TElement;
}

/***
** Affiche la matrice dans un terminal
** Entrée: rien
** PreCondition: Matrice initialisé
** Sortie: rien
** PostCondition: rien
***/
template<typename Type> void CMatrice<Type>::MATAfficherMatrice() 
{
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
    {
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
        {
			cout << ppTMATElement[uiBoucle1][uiBoucle2];
			cout << "\t";
		}
		cout << endl;
	}
}


/***
** Produit des elements de la matrice par une constante
** PreCondition: TCte: la constante
** Necessite: le type "Type" doit être de type élémentaire
** Sortie: CMatrice<T>
** PostCondition: retourne le produit par une constante
***/
template<typename Type> CMatrice<Type> CMatrice<Type>::operator*(Type TCte)
{
	CMatrice<Type> MATResultat = CMatrice(uiMATNombreLigne, uiMATNombreColonne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
    {
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
        {
			MATResultat.MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2) * TCte);
		}
	}
	return MATResultat;
}

/***
** Division des élements de la matrice par une constante
** Entrée: TCte: la constante
** PreCondition: le type "Type" doit être de type élémentaire de la matrice || doit être != 0
** Sortie: CMatrice<T>
** PostCondition: retourne le produit par une constante
***/
template<typename Type> CMatrice<Type> CMatrice<Type>::operator/(Type TCte)
{
	if (TCte == 0)
	{
		CException EXCError(DivisionParZero);
		throw EXCError;
	}
		
	CMatrice<Type> MATResultat = CMatrice(uiMATNombreLigne, uiMATNombreColonne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
    {
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
        {
			MATResultat.MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2) / TCte);
		}
	}
	return MATResultat;
}

/***
** Permet de retourner la transposée de la matrice
** Entrée: rien
** PreCondition: rien
** Sortie: CMatrice<T>
** PostCondition: renvoie la transposée de la matrice
***/
template<typename Type> CMatrice<Type> CMatrice<Type>::MATTranspose()
{
	CMatrice<Type> MATResultat = CMatrice( uiMATNombreColonne, uiMATNombreLigne);    // création de la matrice à transposée
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATResultat.MATModifierElement(uiBoucle2, uiBoucle1, TMATLireElement(uiBoucle1, uiBoucle2));
		}
	}
	return MATResultat;
}


/***
** Permet de retourner la somme des matrices
** Entrée: CMatrice Mat2
** PreCondition: Matrice de même taille
** Sortie: CMatrice<T>
** PostCondition: renvoie l'addition des deux matrices
***/
template<typename Type> CMatrice<Type> CMatrice<Type>::operator+(CMatrice <Type> &MAT2) 
{
	if ( uiMATNombreColonne != MAT2.uiMATGetNombreColonne() || uiMATNombreLigne != MAT2.uiMATGetNombreLigne() )
	{
		CException EXCError(DimentionIncoherenteSommmeMatrice);
		throw EXCError;
	}
	CMatrice<Type> MATResultat = CMatrice( uiMATNombreLigne, uiMATNombreColonne ); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATResultat.MATModifierElement(uiBoucle1, uiBoucle2, (Type)(TMATLireElement(uiBoucle1, uiBoucle2) + MAT2.TMATLireElement(uiBoucle1, uiBoucle2)));
			//cout << "i = " << uiBoucle1 << endl;
			//cout << "j = " << uiBoucle2 << endl;
		}
	}
	return MATResultat;
}


/***
** Permet de retourner la difference des matrices
** Entrée: CMatrice Mat2
** PreCondition: Matrice de même taille
** Sortie: CMatrice<T>
** PostCondition: renvoie l'addition des deux matrices
***/
template<typename Type> CMatrice<Type> CMatrice<Type>::operator-(CMatrice <Type> &MAT2) 
{
	if (uiMATNombreColonne != MAT2.uiMATGetNombreColonne() || uiMATNombreLigne != MAT2.uiMATGetNombreLigne())
	{
		CException EXCError(DimentionIncoherenteDifferenceMatrice);
		throw EXCError;
	}
	CMatrice<Type> MATResultat = CMatrice( uiMATNombreColonne, uiMATNombreLigne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATResultat.MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2) - MAT2.TMATLireElement(uiBoucle1, uiBoucle2));
		}
	}
	return MATResultat;
}

/***
** Permet de retourner le produit des matrices
** Entrée: CMatrice Mat2
** PreCondition: M1[n,m] et M2[m,n]
** Sortie: CMatrice<T>
** PostCondition: renvoie l'addition des deux matrices
***/
template<typename Type> CMatrice<Type> CMatrice<Type>::operator*(CMatrice <Type> &MAT2) 
{
	if ( uiMATGetNombreColonne() != MAT2.uiMATGetNombreColonne() || uiMATGetNombreLigne() != MAT2.uiMATGetNombreLigne() )
	{
		CException EXCError(DimentionIncoherenteProduitMatrice);
		throw EXCError;
	}
	CMatrice<Type> MATResultat = CMatrice(uiMATGetNombreColonne(), uiMATGetNombreLigne()); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATGetNombreLigne(); uiBoucle1++)
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATGetNombreColonne(); uiBoucle2++)
		{
			Type Tres = 0;
			for (unsigned int uiBoucle3 = 0; uiBoucle3 < uiMATGetNombreColonne(); uiBoucle3++)
			{
				Tres += TMATLireElement(uiBoucle1, uiBoucle3) * MAT2.TMATLireElement(uiBoucle3, uiBoucle2);
			}
			MATResultat.MATModifierElement(uiBoucle1, uiBoucle2, Tres);
		}
	}
	return MATResultat;
}

template<typename Type> CMatrice<Type> CMatrice<Type>::MATPermutation(Type *puiTab, unsigned int Taille)
{
	CMatrice<Type> MATResultat = CMatrice(Taille, Taille); 
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < Taille; uiBoucle1++)
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < Taille; uiBoucle2++)
		{
			Type ValeurAjoute;
			if((int)(uiBoucle2 - uiBoucle1) >= 0)
			{
				ValeurAjoute = puiTab[uiBoucle2 - uiBoucle1];
			}
			else
			{
				ValeurAjoute = puiTab[uiBoucle2 - uiBoucle1 + Taille];
			}
			MATResultat.MATModifierElement(uiBoucle1, uiBoucle2, ValeurAjoute);
		}
	}
	return MATResultat;
}

template<typename Type> CMatrice<Type> CMatrice<Type>::MATPermutationVecteur(unsigned int uiTab[uiMATGetNombreLigne()])
{
	CMatrice<Type> MATResultat = CMatrice(uiMATGetNombreLigne(), uiMATGetNombreColonne()); 
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATGetNombreLigne(); uiBoucle1++)
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATGetNombreColonne(); uiBoucle2++)
		{
			Type ValeurAjoute;
			if((int)(uiBoucle2 - uiTab[uiBoucle1]) >= 0)
			{
				ValeurAjoute = TMATLireElement(uiBoucle1, uiBoucle2 - uiTab[uiBoucle1]);
			}
			else
			{
				ValeurAjoute = TMATLireElement(uiBoucle1, (uiBoucle2 - uiTab[uiBoucle1]) % uiMATGetNombreColonne());
			}
			MATResultat.MATModifierElement(uiBoucle1, uiBoucle2, ValeurAjoute);
		}
	}
	return MATResultat;
}


#endif