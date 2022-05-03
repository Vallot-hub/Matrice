#include <fstream>
#include <stdio.h>
#include <iostream>
#include "CFichier.h"
#include "CException.h"

#define FichierTypeInvalide 101


char CFichier::FICMinuscule(char cElement)
{
    if (cElement >= 'A' && cElement <= 'Z')
    {
        cElement = (char)(cElement - 'A' + 'a');
    }
    return cElement;
}

char* CFichier::FICSuivant(char* str, char separator)
{
    while (*str != '\0' && *str != separator)
    {
        str++;
    }
    return ++str;
}

char* CFichier::FICArretA(char* str, char separator)
{
    unsigned int uiboucle = 0;
    while (str[uiboucle] != '\0' && str[uiboucle] != separator)
    {
        uiboucle++;
    }
    str[uiboucle + 1] = '\0';
    return str;
}



void CFichier::FICLireFichier(char* pcNomFichier)
{
    //cout << *pcNomFichier;
    char* pcLigneFichier = (char*)malloc(sizeof(char) * 50);
    ifstream fichier(pcNomFichier, ios::in);
    fichier.getline(pcLigneFichier, 49);
    char* pcReel = (char*)malloc(sizeof(char) * 50);    //!!!! A free;
    pcReel = FICSupprimerEspace(pcLigneFichier);
    cout << pcReel << endl;
    cout << FICStrCompare(pcReel, (char*)"typematrice=double\0");
    if (FICStrCompare(pcReel, (char*)"typematrice=double\0") != 0)
    {
        CException EXCError(FichierTypeInvalide);
        throw EXCError;
    }

    /** Lecture du Nombre de ligne **/
    fichier.getline(pcLigneFichier, 49);
    char* pcNumeroLigne = (char*)malloc(sizeof(char) * 50);
    pcReel = FICSupprimerEspace(pcLigneFichier);
    if (FICStrCompare(pcReel, (char*)"nombrelignes=") != 0)
    {
        CException EXCError(FichierTypeInvalide);
        throw EXCError;
    }
    pcNumeroLigne = FICSuivant(pcLigneFichier, '=');
    unsigned int uiNombreLigne = atoi(pcNumeroLigne);
    cout << pcReel << endl;

    /** Lecture du Nombre de Colonne **/
    fichier.getline(pcLigneFichier, 49);
    char* pcNumeroColonne = (char*)malloc(sizeof(char) * 50);
    pcReel = FICSupprimerEspace(pcLigneFichier);
    pcNumeroColonne = FICSuivant(pcLigneFichier, '=');
    unsigned int uiNombreColonne = atoi(pcNumeroColonne);
    cout << pcReel << endl;

    //cout << pcLigneFichier << endl;
    fichier.getline(pcLigneFichier, 49);
    cout << pcLigneFichier << endl;
    cout << "Nombre de ligne : " << uiNombreLigne << endl;
    cout << "Nombre de colonne : " << uiNombreColonne << endl;
}

char* CFichier::FICSupprimerEspace(char* pcstr)
{
    unsigned int uiTailleSansEspace = 0;
    unsigned int uiboucle = 0;
    while (pcstr[uiboucle] != '\0')
    {
        if (pcstr[uiboucle] != ' ')
        {
            uiTailleSansEspace++;
        }
        uiboucle++;
    }
    char* pcChaineSansEspace = (char*)malloc(sizeof(char) * uiTailleSansEspace);

    unsigned int uiChaineBase = 0;
    unsigned int uiNouvelleChaine = 0;
    while (pcstr[uiChaineBase] != '\0')
    {
        if (pcstr[uiChaineBase] != ' ')
        {
            pcChaineSansEspace[uiNouvelleChaine] = FICMinuscule(pcstr[uiChaineBase]);
            uiChaineBase++;
            uiNouvelleChaine++;
        }
        else
        {
            uiChaineBase++;
        }
    }
    pcChaineSansEspace[uiNouvelleChaine] = '\0';
    return pcChaineSansEspace;
}

int CFichier::FICStrCompare(char* str1, char* str2)
{
    while (*str1 == *str2 && *str1 != '\0')
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
