#include "./CException.h"

#include <stdio.h>
#include <iostream>

using namespace std;

void CException::EXCAffiche()
{
    switch (iEXCValeur)
    {
    case 1:
        cout << "Erreur division par 0 " << endl;
        break;
    case 2:
        cout << "Erreur dimention incoherente" << endl;
        break;
    case 100:
        cout << "Erreur fichier introuvable" << endl;
        break;
    case 101:
        cout << "Erreur fichier type different de \"TypeMatrice=double\"" << endl;
        break;
    case 102:
        cout << "Erreur fichier prefix nombre de ligne invalide" << endl;
        break;
    case 103:
        cout << "Erreur fichier nombre de colonne invalide" << endl;
        break;
    case 104:
        cout << "Erreur lecture de la matrice invalide au niveau de la ligne \"Matrice=[\"" << endl;
        break;
    case 105:
        cout << "Erreur nombre de colonne different de ce qu'il a ete indiquee" << endl;  
        break;
    case 106:
        cout << "Erreur la fin de fichier inatendu: peut-etre nombre de ligne incoherent par rapport au nombre de ligne indiquee" << endl;
        break;
    case 201:
        cout << "Erreur division par 0" << endl;
        break;
    case 202:
        cout << "Erreur dimention incoherente pour la creation de la matrice" << endl;
        break;
    case 203:
        cout << "Erreur dimention incoherente lors de la modification des elements de la matrice" << endl;
        break;
    case 204:
        cout << "Erreur dimention incoherente lors de la lecture des elements de la matrice" << endl;
        break;
    case 205:
        cout << "Erreur dimention incoherente lors de la somme des matrices" << endl;
        break;
    case 206:
        cout << "Erreur dimention incoherente lors de la difference des matrices" << endl;
        break;
    case 207:
        cout << "Erreur dimention incoherente lors du produit des matrices" << endl;
        break;
    default:
        cout << "erreur inconnue code: " << iEXCGet() << endl;
        break;
    }
}