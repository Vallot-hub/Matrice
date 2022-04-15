#define DivisionParZero 100

/** recopie **/
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
		for (unsigned int uiBoucleAlloc = 0; uiBoucleAlloc < uiMATNombreLigne; uiBoucleAlloc++) {
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

template<typename Type> void CMatrice<Type>::MATModifierElement(int iLigne, int iColonne, Type TElement)
{
    ppTMATElement[iLigne][iColonne] = TElement;
}

template<typename Type> CMatrice<Type>::CMatrice(int iNbLigne, int iNbColonne)
{
    uiMATNombreColonne = iNbColonne;
    uiMATNombreLigne = iNbLigne;

    ppTMATElement = new Type*[iNbLigne];
    for (int iBoucle = 0; iBoucle < iNbLigne; iBoucle++)
    {
        ppTMATElement[iBoucle] = new Type[iNbColonne];
    }
}

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

/** Division par une Cte**/
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