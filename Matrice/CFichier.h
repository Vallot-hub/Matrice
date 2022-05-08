#ifndef CFICHIER
#define CFICHIER
#include "CMatrice.h"

#define FichierIntrouvable 100
#define FichierTypeInvalide 101
#define FichierNombreligneInvalide 102
#define FichierNombreColonneInvalide 103
#define FichierLectureMatriceInvalide 104
#define FichierNombreColonneIncoherent 105
#define FichierFinInvalide 106

using namespace std;


class CFichier
{
public:
	/*CFichier();
	~CFichier();*/
	CMatrice<double> FICLireFichier(char* pcNomFichier);

private:
    int FICStrCompare(char* str1, char* str2);
    char* FICSupprimerEspace(char* str);
    char* FICSuivant(char* str, char separator);
    char* FICArretA(char* str, char separator);
    char FICMinuscule(char cElement);
};

#endif