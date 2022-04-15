#include <iostream>
#include "CMatrice.h"

using namespace std;

int main()
{
    //std::cout << "Hello World!\n";
    int nbLigne = 2;
    int nbColonne = 2;
    double E = 1;
    CMatrice<double> Md(nbLigne, nbColonne);
    //cout << Md.iMATGetNombreColonne() << endl;
    //Md.ModifierElement(1,1,E);
    for (int i = 0; i < nbLigne; i++)
    {
        for (int j = 0; j < nbColonne; j++)
        {
            Md.MATModifierElement(i,j,E);
            E++;
        }
    }
    Md.MATSommeCte(-2.5);  //Avoir pour la soustraction ## unsigned int ?????
    CMatrice Md1 = Md.MATProduitCte(-2.12);
    CMatrice Md2 = Md.MATTranspose();
    CMatrice Md3 = Md.MATProduitMatrice(Md2);
    Md.MATAfficherMatrice();
    //Md1.MATAfficherMatrice();
    Md3.MATAfficherMatrice();
}