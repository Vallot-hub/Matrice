#include <iostream>
#include "CMatrice.h"
#include "CFichier.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "debut du programme" << endl;
    int tab[4] = {1,2,3,4};

    CMatrice<int> Mat;
    CMatrice<int> Mat2(3,4);

    Mat2.MATModifierElement(0,0,2);
    Mat2.MATModifierElement(0,1,4);
    Mat2.MATModifierElement(0,2,3);
    Mat2.MATModifierElement(0,3,1);

    Mat2.MATModifierElement(1,0,1);
    Mat2.MATModifierElement(1,1,5);
    Mat2.MATModifierElement(1,2,2);
    Mat2.MATModifierElement(1,3,3);

    Mat2.MATModifierElement(2,0,2);
    Mat2.MATModifierElement(2,1,3);
    Mat2.MATModifierElement(2,2,7);
    Mat2.MATModifierElement(2,3,1);
    
    unsigned int Tab1[3]={0,1,3};



    Mat = Mat.MATPermutation(tab, 4);
    Mat.MATAfficherMatrice();
    cout << "" << endl;
    Mat = Mat2.MATPermutationVecteur(Tab1);
    Mat.MATAfficherMatrice();

    /*if (argc > 1)
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

    }*/
    cout << "fin du programme" << endl;
}

