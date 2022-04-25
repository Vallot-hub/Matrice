#include "CFichier.h"
#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;

void CFichier::CLireFichier(char* pcNomFichier)
{
    char * pcLigneFichier = (char*)malloc(sizeof(char)*50);
    ifstream fichier(pcNomFichier, ios::in);
    fichier.getline(pcLigneFichier, 49);
    cout << pcLigneFichier << endl;
}