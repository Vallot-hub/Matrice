#include <iostream>
#include "CMatrice.h"

using namespace std;

int main()
{
    //std::cout << "Hello World!\n";
    int nbLigne = 2;
    int nbColonne = 2;
    double E = 48.6;
    CMatrice<double> Md(nbLigne, nbColonne);
    
    for (int i = 0; i < nbLigne; i++)
    {
        for (int j = 0; j < nbColonne; j++)
        {
            Md.MATModifierElement(i,j,E);
            E++;
        }
    }
    CMatrice Md1 = Md.MATProduitCte(-2.12);
    CMatrice Md2 = Md.MATTranspose();
    CMatrice Md3 = Md * Md2;
    
    Md.MATAfficherMatrice();
    Md1.MATAfficherMatrice();
    Md3.MATAfficherMatrice();
}