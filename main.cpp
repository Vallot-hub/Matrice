#include <iostream>
#include "CMatrice.h"
//#include "CFichier.h"
using namespace std;

int main()
{
    int nbLigne = 2;
    int nbColonne = 3;
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
    try
    {
        CMatrice Md1 = Md * -5.2;
        CMatrice Md2 = Md.MATTranspose();
        CMatrice Md3 = Md + Md;
        Md.MATAfficherMatrice();
        cout << endl;
        Md2.MATAfficherMatrice();
        cout << endl;
        cout << (Md + Md1).uiMATGetNombreColonne() << endl;
        Md3.MATAfficherMatrice();
    }
    catch (CException e)
    {
        cout << e.iEXCGet();
    }
    
    
    //CFichier F;
    //F.CLireFichier('./CMatrice.h');
}