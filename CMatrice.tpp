template<typename Type> void CMatrice<Type>::MATModifierElement(int iLigne, int iColonne, Type TElement)
{
    pTMATElement[iLigne][iColonne] = TElement;
}

template<typename Type> CMatrice<Type>::CMatrice(int iNbLigne, int iNbColonne)
{
    iMATNombreColonne = iNbColonne;
    iMATNombreLigne = iNbLigne;

    pTMATElement = new Type*[iNbLigne];
    for (int iBoucle = 0; iBoucle < iNbLigne; iBoucle++)
    {
        pTMATElement[iBoucle] = new Type[iNbColonne];
    }
}

template<typename T> void CMatrice<T>::MATAfficherMatrice() 
{
	int iBoucle1 = 0;
	int iBoucle2 = 0;

	for (iBoucle1 = 0; iBoucle1 < iMATNombreLigne; iBoucle1++) 
    {
		for (iBoucle2 = 0; iBoucle2 < iMATNombreColonne; iBoucle2++) 
        {
			MATAfficherElement(iBoucle1, iBoucle2);
			cout << "\t";
		}
		cout << endl;
	}
}


template<typename T> void CMatrice<T>::MATAfficherElement(int iLigne, int iColonne) 
{
	cout << pTMATElement[iLigne][iColonne];
}