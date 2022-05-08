#include <iostream>
#include "CMatrice.h"
#include "CFichier.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "debut du programme" << endl;
    if (argc > 1)
    {
        CMatrice<double>* MATtabMatrice = new CMatrice<double>[argc - 1];
        CFichier FICFichier;
        for (int iBoucle = 1; iBoucle < argc; iBoucle++)
        {
            try
            {
                MATtabMatrice[iBoucle - 1] = FICFichier.FICLireFichier(argv[iBoucle]);
            }
            catch (CException EXCe)
            {
                EXCe.EXCAffiche();
            }
        }
        //MATtabMatrice[0].MATAfficherMatrice();
        int iC = 0;
        cout << "Merci d'entrez un entier ";
        while (!(cin >> iC))
        {
            cout << "Merci d'entrez un entier ";
        }
        CMatrice<double> MATresultat;
        cout << endl << "Multiplication par : " << iC << endl << endl;
        for (int iBoucle = 1; iBoucle < argc; iBoucle++)
        {
            try
            {
                cout << argv[iBoucle] << endl;
                MATresultat = MATtabMatrice[iBoucle - 1] * iC;
                MATresultat.MATAfficherMatrice();
                cout << endl;
            }
            catch (CException EXCe)
            {
                EXCe.EXCAffiche();
            }
        }
        cout << endl << "Division par : " << iC << endl << endl;
        for (int iBoucle = 1; iBoucle < argc; iBoucle++)
        {
            try
            {
                cout << argv[iBoucle] << endl;
                MATresultat = MATtabMatrice[iBoucle - 1] / iC;
                MATresultat.MATAfficherMatrice();
                cout << endl;
            }
            catch (CException EXCe)
            {
                EXCe.EXCAffiche();
            }
        }
        cout << endl << "Somme des matrices" << endl << endl;
        MATresultat = MATtabMatrice[0];
        for (int iBoucle = 1; iBoucle < argc - 1; iBoucle++)
        {
            try
            {
                MATresultat = MATresultat + MATtabMatrice[iBoucle];
            }
            catch (CException EXCe)
            {
                EXCe.EXCAffiche();
            }
        }
        MATresultat.MATAfficherMatrice();
        cout << endl << "Operation - + - + -" << endl << endl;
        MATresultat = MATtabMatrice[0];
        for (int iBoucle = 1; iBoucle < argc - 1; iBoucle++)
        {
            try
            {
                if (iBoucle % 2 == 0)
                {
                    MATresultat = MATresultat + MATtabMatrice[iBoucle];
                }
                else
                {
                    MATresultat = MATresultat - MATtabMatrice[iBoucle];
                }
            }
            catch (CException EXCe)
            {
                EXCe.EXCAffiche();
            }
        }
        MATresultat.MATAfficherMatrice();
        cout << endl << "Produit des matrices" << endl << endl;
        MATresultat = MATtabMatrice[0];
        for (int iBoucle = 1; iBoucle < argc - 1; iBoucle++)
        {
            try
            {
                MATresultat = MATresultat * MATtabMatrice[iBoucle];
            }
            catch (CException EXCe)
            {
                EXCe.EXCAffiche();
            }
        }
        MATresultat.MATAfficherMatrice();
    }
}

void test(){
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
    cout << endl;

    CFichier F;
    //char* NomFile = (char*)malloc(85*sizeof(char));
    try
    {
        CMatrice<double> Md4 = F.FICLireFichier((char*)"./M2.txt");
        Md4.MATAfficherMatrice();
    }
    catch (CException e)
    {
        e.EXCAffiche();
    }
}