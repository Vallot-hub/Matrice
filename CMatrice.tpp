#define DivisionParZero 100

/***
** Constructeur de recopie
** Entrée: CMatrice
** PreCondition: un objet initialisé
** Sortie: Rien
** PostCondition: l'objet crée est une copie de l'objet d'entrée
***/
template<typename Type> CMatrice<Type>::CMatrice(CMatrice <Type> &MATMatrice) 
{
		/*Nouvelle affectation de valeur*/
	uiMATNombreLigne = MATMatrice.iMATGetNombreLigne();
	uiMATNombreColonne = MATMatrice.iMATGetNombreColonne();

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

/*** recopie par operateur
** Entrée: CMatrice
** PreCondition: un objet initialisé
** Sortie: Rien
** PostCondition: l'objet crée est une copie de l'objet d'entrée
***/
template<typename Type> CMatrice<Type>& CMatrice<Type>::operator=(CMatrice <Type> &MATMatrice2) {

	/*Si les deux matrices sont de taille différente*/
	if ((uiMATNombreLigne != MATMatrice2.uiMATLireNbLigne()) || (uiMATNombreLigne != MATMatrice2.uiMATLireNbColonne())) 
	{
		/*Libération mémoire*/
		for (unsigned int uiBoucleAlloc = 0; uiBoucleAlloc < uiMATNombreLigne; uiBoucleAlloc++) 
		{
			delete[] ppTMATElement[uiBoucleAlloc];
		}
		delete[] ppTMATElement;

		/*Nouvelle affectation de valeur*/
		uiMATNombreLigne = MATMatrice2.uiMATLireNbLigne();
		uiMATNombreColonne = MATMatrice2.uiMATLireNbColonne();

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
			MATModifierElement(uiBoucle1, uiBoucle2, MATMatrice2.MATLireElement(uiBoucle1, uiBoucle2));
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
    ppTMATElement[uiLigne][uiColonne] = TElement;
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
    uiMATNombreColonne = uiNbColonne;
    uiMATNombreLigne = uiNbLigne;

    ppTMATElement = new Type*[uiNbLigne];
    for (unsigned int uiBoucle = 0; uiBoucle < uiNbLigne; uiBoucle++)
    {
        ppTMATElement[uiBoucle] = new Type[uiNbColonne];
    }
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
	for (int iBoucle1 = 0; iBoucle1 < uiMATNombreLigne; iBoucle1++) 
    {
		for (int iBoucle2 = 0; iBoucle2 < uiMATNombreColonne; iBoucle2++) 
        {
			MATAfficherElement(iBoucle1, iBoucle2);
			cout << "\t";
		}
		cout << endl;
	}
}

template<typename Type> void CMatrice<Type>::MATAfficherElement(int iLigne, int iColonne) 
{
	cout << ppTMATElement[iLigne][iColonne];
}


template<typename Type> void CMatrice<Type>::MATSommeCte(Type TCte) 
{
	for (int iBoucle1 = 0; iBoucle1 < uiMATNombreLigne; iBoucle1++) 
    {
		for (int iBoucle2 = 0; iBoucle2 < uiMATNombreColonne; iBoucle2++) 
        {
			ppTMATElement[iBoucle1][iBoucle2] += TCte;
		}
	}
}

/***
** Produit des elements de la matrice par une constante
** Entrée: TCte: la constante
** PreCondition: le type "Type" doit être de type élémentaire
** Sortie: CMatrice<T>
** PostCondition: retourne le produit par une constante
***/
template<typename Type> CMatrice<Type>& CMatrice<Type>::MATProduitCte(Type TCte) 
{
	CMatrice<Type> * MATResultat = new CMatrice(uiMATNombreLigne, uiMATNombreColonne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
    {
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
        {
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2) * TCte);
		}
	}
	return * MATResultat;
}

/***
** surcharge d'operateur idem MATProduitCte
** PreCondition: TCte: la constante
** Necessite: le type "Type" doit être de type élémentaire
** Sortie: CMatrice<T>
** PostCondition: retourne le produit par une constante
***/
template<typename Type> CMatrice<Type> &CMatrice<Type>::operator*(Type TCte)
{
	CMatrice<Type> * MATResultat = new CMatrice(uiMATNombreLigne, uiMATNombreColonne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
    {
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
        {
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2) * TCte);
		}
	}
	return * MATResultat;
}

/***
** Division des élements de la matrice par une constante
** Entrée: TCte: la constante
** PreCondition: le type "Type" doit être de type élémentaire de la matrice || doit être != 0
** Sortie: CMatrice<T>
** PostCondition: retourne la division par une constante
***/
template<typename Type> CMatrice<Type>& CMatrice<Type>::MATDivisionCte(Type TCte) 
{
	if (TCte == 0)
	{
		CException EXCError(DivisionParZero);
		throw EXCError;
	}
		
	CMatrice<Type> * MATResultat = new CMatrice(uiMATNombreLigne, uiMATNombreColonne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
    {
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
        {
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2) / TCte);
		}
	}
	return * MATResultat;
}

/***
** surcharge d'operateur idem MATDivisionCte
** Entrée: TCte: la constante
** PreCondition: le type "Type" doit être de type élémentaire de la matrice || doit être != 0
** Sortie: CMatrice<T>
** PostCondition: retourne le produit par une constante
***/
template<typename Type> CMatrice<Type> &CMatrice<Type>::operator/(Type TCte)
{
	if (TCte == 0)
	{
		CException EXCError(DivisionParZero);
		throw EXCError;
	}
		
	CMatrice<Type> * MATResultat = new CMatrice(uiMATNombreLigne, uiMATNombreColonne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
    {
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
        {
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2) / TCte);
		}
	}
	return * MATResultat;
}

/***
** Permet de retourner la transposée de la matrice
** Entrée: rien
** PreCondition: rien
** Sortie: CMatrice<T>
** PostCondition: renvoie la transposée de la matrice
***/
template<typename Type> CMatrice<Type>& CMatrice<Type>::MATTranspose()
{
	CMatrice<Type> * MATResultat = new CMatrice( uiMATNombreColonne, uiMATNombreLigne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle2, uiBoucle1));
		}
	}
	return *MATResultat;
}

/***
** Permet de retourner la somme des matrices
** Entrée: CMatrice Mat2
** PreCondition: Matrice de même taille
** Sortie: CMatrice<T>
** PostCondition: renvoie l'addition des deux matrices
***/
template <typename Type> CMatrice<Type> & CMatrice<Type>::MATSomme(CMatrice MAT2)
{
	CMatrice<Type> * MATResultat = new CMatrice( uiMATNombreColonne, uiMATNombreLigne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2)+MAT2.TMATLireElement(uiBoucle1, uiBoucle2));
		}
	}
	return *MATResultat;
}

/***
** surcharge d'operateur idem MATSomme
** Entrée: CMatrice Mat2
** PreCondition: Matrice de même taille
** Sortie: CMatrice<T>
** PostCondition: renvoie l'addition des deux matrices
***/
template<typename Type> CMatrice<Type>& CMatrice<Type>::operator+(CMatrice <Type> &MATMatrice2) 
{
	CMatrice<Type> * MATResultat = new CMatrice( uiMATNombreColonne, uiMATNombreLigne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2) + MATMatrice2.TMATLireElement(uiBoucle1, uiBoucle2));
		}
	}
	return *MATResultat;
}

/***
** Permet de retourner la difference des matrices
** Entrée: CMatrice Mat2
** PreCondition: Matrice de même taille
** Sortie: CMatrice<T>
** PostCondition: renvoie l'addition des deux matrices
***/
template <typename Type> CMatrice<Type> & CMatrice<Type>::MATDifference(CMatrice MAT2)
{
	CMatrice<Type> * MATResultat = new CMatrice( uiMATNombreColonne, uiMATNombreLigne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2)-MAT2.TMATLireElement(uiBoucle1, uiBoucle2));
		}
	}
	return *MATResultat;
}

/***
** surcharge d'operateur idem MATDifference
** Entrée: CMatrice Mat2
** PreCondition: Matrice de même taille
** Sortie: CMatrice<T>
** PostCondition: renvoie l'addition des deux matrices
***/
template<typename Type> CMatrice<Type>& CMatrice<Type>::operator-(CMatrice <Type> &MATMatrice2) 
{
	CMatrice<Type> * MATResultat = new CMatrice( uiMATNombreColonne, uiMATNombreLigne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, TMATLireElement(uiBoucle1, uiBoucle2) - MATMatrice2.TMATLireElement(uiBoucle1, uiBoucle2));
		}
	}
	return *MATResultat;
}

/***
** Permet de retourner le produit des matrices
** Entrée: CMatrice Mat2
** PreCondition: M1[n,m] et M2[m,n]
** Sortie: CMatrice<T>
** PostCondition: renvoie l'addition des deux matrices
***/
template <typename Type> CMatrice<Type> & CMatrice<Type>::MATProduitMatrice(CMatrice MAT2)
{
	CMatrice<Type> * MATResultat = new CMatrice( uiMATNombreColonne, uiMATNombreLigne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			Type Tres = 0;
			for (unsigned int uiBoucle3 = 0; uiBoucle3 < uiMATNombreColonne; uiBoucle3++)
			{
				Tres += TMATLireElement(uiBoucle1, uiBoucle3) * MAT2.TMATLireElement(uiBoucle3, uiBoucle2);
			}
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, Tres);
		}
	}
	return *MATResultat;
}

/***
** surcharge d'operateur idem MATProduitMatrice
** Entrée: CMatrice Mat2
** PreCondition: M1[n,m] et M2[m,n]
** Sortie: CMatrice<T>
** PostCondition: renvoie l'addition des deux matrices
***/
template<typename Type> CMatrice<Type>& CMatrice<Type>::operator*(CMatrice <Type> &MATMatrice2) 
{
	CMatrice<Type> * MATResultat = new CMatrice( uiMATNombreColonne, uiMATNombreLigne); // création de la matrice à retourner
	for (unsigned int uiBoucle1 = 0; uiBoucle1 < uiMATNombreLigne; uiBoucle1++) 
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiMATNombreColonne; uiBoucle2++) 
		{
			Type Tres = 0;
			for (unsigned int uiBoucle3 = 0; uiBoucle3 < uiMATNombreColonne; uiBoucle3++)
			{
				Tres += TMATLireElement(uiBoucle1, uiBoucle3) * MATMatrice2.TMATLireElement(uiBoucle3, uiBoucle2);
			}
			MATResultat->MATModifierElement(uiBoucle1, uiBoucle2, Tres);
		}
	}
	return *MATResultat;
}