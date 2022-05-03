#ifndef CFICHIER
#define CFICHIER

using namespace std;

class CFichier
{
public:
	/*CFichier();
	~CFichier();*/
	void FICLireFichier(char* pcNomFichier);

private:
    int FICStrCompare(char* str1, char* str2);
    char* FICSupprimerEspace(char* str);
    char* FICSuivant(char* str, char separator);
    char* FICArretA(char* str, char separator);
    char FICMinuscule(char cElement);
};

#endif