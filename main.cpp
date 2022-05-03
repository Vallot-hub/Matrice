#include <iostream>
#include "CMatrice.h"
#include "CFichier.h"

using namespace std;

int main()
{
    int nbLigne = 2;
    int nbColonne = 3;
    double E = 48.6;
    CMatrice<double> Md(nbLigne, nbColonne);
    CMatrice<double> Md1(nbLigne, nbColonne);
    for (int i = 0; i < nbLigne; i++)
    {
        for (int j = 0; j < nbColonne; j++)
        {
            Md.MATModifierElement(i,j,E);
            Md1.MATModifierElement(i, j, E + 5);
            E++;
        }
    }
    try
    {
        Md * -5.2;

        CMatrice<double> Md2 = Md.MATTranspose();
        CMatrice<double> Md3 = Md1;
        Md.MATAfficherMatrice();
        cout << endl;
        Md2.MATAfficherMatrice();
        cout << endl;
        Md3.MATAfficherMatrice();
    }
    catch (CException e)
    {
        cout << e.iEXCGet();
    }
    
    
    CFichier F;
    //char* NomFile = (char*)malloc(85*sizeof(char));

    F.FICLireFichier((char*)"./M1.txt");
}