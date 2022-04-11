#include <iostream>
#include "CMatrice.h"

using namespace std;

int main()
{
    //std::cout << "Hello World!\n";
    int nbLigne = 2;
    int nbColonne = 2;
    double E = 5.56;
    CMatrice<double> Md(2,2);
    cout << Md.iMATGetNombreColonne() << endl;
    //Md.ModifierElement(1,1,E);
    for (int i = 0; i < nbLigne; i++)
    {
        for (int j = 0; j < nbColonne; j++)
        {
            Md.MATModifierElement(i,j,E);
        }
    }
    Md.MATAfficherMatrice();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
