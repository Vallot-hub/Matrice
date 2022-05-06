#include "./CException.h"

#include <stdio.h>
#include <iostream>

using namespace std;

void CException::EXCAffiche()
{
    switch (iEXCValeur)
    {
    case 1:
        cout << " erreur division par 0 " << endl;
        break;
    case 2:
        cout << " erreur dimention incoherente" << endl;
        break;
    case 102:
        cout << "erreur fichier prefix nombre de ligne invalide" << endl;
        break;
    case 103:
        cout << "erreur fichier nombre de colonne invalide" << endl;
        break;
    case 104:
        cout << "Lecture de la matrice invalide au niveau de la ligne \"Matrice=[\""
            << endl;
        break;
    case 105:
        cout << "erreur la fin de fichier inatendu: peut-etre problème trop de ligne par rapport au nombre de ligne indiquée";
        break;
    default:
        cout << "erreur inconnue " << iEXCGet() << endl;
        break;
    }
}