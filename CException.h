#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#define Fichier_introuvable 100
#define valeur_deja_presente 200

class CException
{
private:
    /* data */
    int iEXCValeur;
public:
    //CException();
    CException(int iError) { iEXCValeur = iError; };
    //~CException();
    int iEXCGet() { return iEXCValeur; }
    void EXCSet ( int iparam ) { iEXCValeur = iparam; }
};


/*CException::CException()
{

}

CException::~CException()
{

}*/



#endif