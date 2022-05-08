#ifndef CEXCEPTION_H
#define CEXCEPTION_H

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
    void EXCAffiche();
};



/*CException::CException()
{

}

CException::~CException()
{

}*/



#endif