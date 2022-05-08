#include <fstream>
#include <stdio.h>
#include <iostream>
#include "CFichier.h"
#include "CException.h"
#include "CMatrice.h"

#define FichierIntrouvable 100
#define FichierTypeInvalide 101
#define FichierNombreligneInvalide 102
#define FichierNombreColonneInvalide 103
#define FichierLectureMatriceInvalide 104
#define FichierNombreColonneIncoherent 105
#define FichierFinInvalide 106


/***
** convertie un caractere en minuscule
** Entrée: caractere
** PreCondition: rien
** Sortie: caractere
** PostCondition: caractere en minuscule
***/
char CFichier::FICMinuscule(char cElement)
{
    if (cElement >= 'A' && cElement <= 'Z')
    {
        cElement = (char)(cElement - 'A' + 'a');
    }
    return cElement;
}

/***
** recupere le suffix
** Entrée: chaine de caracter, caractere separateur
** PreCondition: fin de caractere: '\0'
** Sortie: pointeur de caractere
** PostCondition: pointeur vers le caractere aprés la premiere occurence de separator
***/
char* CFichier::FICSuivant(char* str, char separator)
{
    while (*str != '\0' && *str != separator)
    {
        str++;
    }
    return ++str;
}

/***
** recupere le prefix avant separator
** Entrée: chaine de caracter, caractere separateur
** PreCondition: fin de caractere: '\0'
** Sortie: nouvelle chaine de caractere allouer sur le tas
** PostCondition: chaine retourné ne contient que le prefix
***/
char* CFichier::FICArretA(char* pcStr, char separator)
{
    unsigned int uiboucle = 0;
    while (pcStr[uiboucle] != '\0' && pcStr[uiboucle] != separator)
    {
        uiboucle++;
    }
    char* pcNewStr = (char*)malloc(sizeof(char)*(uiboucle + 2));
    uiboucle = 0;
    
    while (pcStr[uiboucle] != '\0' && pcStr[uiboucle] != separator)
    {
        pcNewStr[uiboucle] = pcStr[uiboucle];
        uiboucle++;   
    } 
    pcNewStr[uiboucle] = pcStr[uiboucle];
    pcNewStr[uiboucle + 1] = '\0';
    return pcNewStr;
}

/***
** Compare deux chaine de caractere
** Entrée: deux chaine de caractere
** PreCondition: fin de caractere: '\0' 
** Sortie: entier
** PostCondition: 0 si chaine sont egale autre entier si chaine differente
***/
int CFichier::FICStrCompare(char* pcStr1, char* pcStr2)
{
    while (*pcStr1 == *pcStr2 && *pcStr1 != '\0')
    {
        pcStr1++;
        pcStr2++;   
    }
    return *pcStr1 - *pcStr2;
}

/***
** Lit un fichier et si possible initialise une matrice
** Entrée: nom du fichier
** PreCondition: fin de caractere: '\0'
** Sortie: matrice 
** PostCondition: 
***/
CMatrice<double> CFichier::FICLireFichier(char* pcNomFichier)
{
    //cout << *pcNomFichier;
    char* pcLigneFichier = (char*)malloc(sizeof(char) * 50);
    ifstream fichier(pcNomFichier, ios::in);
    if (!fichier)
    {
        CException EXCError(FichierIntrouvable);
        throw EXCError;
    }
    fichier.getline(pcLigneFichier, 49);
    char* pcReel;    //!!!! A free;
    pcReel = FICSupprimerEspace(pcLigneFichier);
    //cout << pcReel << endl;
    if (FICStrCompare(pcReel, (char*)"typematrice=double") != 0)
    {
        CException EXCError(FichierTypeInvalide);
        throw EXCError;
    }
    free(pcLigneFichier);
    free(pcReel);

    /** Lecture du Nombre de ligne **/
    pcLigneFichier = (char*)malloc(sizeof(char) * 50);
    fichier.getline(pcLigneFichier, 49);
    pcReel = FICSupprimerEspace(pcLigneFichier);
    char* pcPrefix = FICArretA(pcReel, '=');
    if (FICStrCompare(pcPrefix, (char*)"nombrelignes=") != 0)
    {
        CException EXCError(FichierNombreligneInvalide);
        throw EXCError;
    }
    char* pcNumeroLigne;
    pcNumeroLigne = FICSuivant(pcReel, '=');
    unsigned int uiNombreLigne = atoi(pcNumeroLigne);
    //cout << pcReel << endl;
    free(pcLigneFichier);
    free(pcReel);
    free(pcPrefix);



    /** Lecture du Nombre de Colonne **/
    pcLigneFichier = (char*)malloc(sizeof(char) * 50);
    fichier.getline(pcLigneFichier, 49);
    pcReel = FICSupprimerEspace(pcLigneFichier);
    pcPrefix = FICArretA(pcReel, '=');
    //cout << pcPrefix << endl;
    if (FICStrCompare(pcPrefix, (char*)"nombrecolonnes=") != 0)
    {
        CException EXCError(FichierNombreColonneInvalide);
        throw EXCError;
    }
    char* pcNumeroColonne;
    pcNumeroColonne = FICSuivant(pcLigneFichier, '=');
    unsigned int uiNombreColonne = atoi(pcNumeroColonne);
    //cout << pcReel << endl;
    free(pcReel);
    free(pcPrefix);
    free(pcLigneFichier);

    /** Lecture de la ligne suivante: Matrice=[ **/
    pcLigneFichier = (char*)malloc(sizeof(char) * 50);
    fichier.getline(pcLigneFichier, 49);
    pcReel = FICSupprimerEspace(pcLigneFichier);
    //cout << pcReel << endl;
    if (FICStrCompare(pcReel, (char*)"matrice=[") != 0)
    {
        CException EXCError(FichierLectureMatriceInvalide);
        throw EXCError;
    }
    free(pcLigneFichier);
    free(pcReel);
    

    CMatrice<double> MATResultat = CMatrice<double>(uiNombreLigne, uiNombreColonne);
    unsigned int uiBoucle1 = 0;
    char pcValeur[21];
    while (uiBoucle1 < uiNombreLigne)
    {
        pcLigneFichier = (char*)malloc(sizeof(char) * 50);
        fichier.getline(pcLigneFichier, 49);
        char* pcReel;
        if (pcLigneFichier[0] == ' ')
        {
            pcReel = FICSuivant(pcLigneFichier, ' ');
        }
        else
        {
            pcReel = pcLigneFichier;
        }
        unsigned int uiBoucle2 = 0;
        unsigned int uiNombreCarctere = 0;
        unsigned int uiPosition_y = 0;

        while (pcReel[uiBoucle2] != '\0')
        {
            if (pcReel[uiBoucle2] != ' ')
            {
                pcValeur[uiNombreCarctere] = pcReel[uiBoucle2];
                if (pcReel[uiBoucle2 + 1] == '\0')
                {
                    pcValeur[uiNombreCarctere + 1] = '\0';
                    //cout << uiBoucle1 << " " << uiPosition_y << " " << pcValeur << endl; 
                    if (uiPosition_y < uiNombreColonne)
                    {
                        MATResultat.MATModifierElement(uiBoucle1, uiPosition_y, atof(pcValeur));
                    }
                    else
                    {
                        CException EXCError(FichierNombreColonneIncoherent);
                        throw EXCError;
                    }
                    uiPosition_y++;
                }
                uiNombreCarctere++;
            }
            else
            {
                pcValeur[uiNombreCarctere] = '\0';
                uiNombreCarctere = 0;
                //cout << uiBoucle1 << " " << uiPosition_y << " " << pcValeur << endl;
                if (uiPosition_y < uiNombreColonne)
                {
                    MATResultat.MATModifierElement(uiBoucle1, uiPosition_y, atof(pcValeur));
                }
                else
                {
                    CException EXCError(FichierNombreColonneIncoherent);
                    throw EXCError;
                }
                
                uiPosition_y++;
            }
            uiBoucle2++;
            //cout << uiBoucle1 << " " << uiBoucle2 << " " << pcValeur << endl;
        }
        uiBoucle1++;
        free(pcLigneFichier);
    }
    

    pcLigneFichier = (char*)malloc(sizeof(char) * 50);
    fichier.getline(pcLigneFichier, 49);
    pcReel = FICSupprimerEspace(pcLigneFichier);
    //cout << pcReel << endl;
    if (FICStrCompare(pcReel, (char*)"]") != 0)
    {
        CException EXCError(FichierFinInvalide);
        throw EXCError;
    }
    free(pcLigneFichier);
    free(pcReel);
    return MATResultat;
}

/***
** Supprime les espaces d'une chaine de caracters
** Entrée: chaine de caractere
** PreCondition: fin de caractere: '\0'
** Sortie: chaine caractere allouee sur le tas
** PostCondition: La chaine de sortie est sans espace
***/
char* CFichier::FICSupprimerEspace(char* pcStr)
{
    unsigned int uiTailleSansEspace = 0;
    unsigned int uiboucle = 0;
    while (pcStr[uiboucle] != '\0')
    {
        if (pcStr[uiboucle] != ' ')
        {
            uiTailleSansEspace++;
        }
        uiboucle++;
    }
    //cout << uiTailleSansEspace << endl;
    //cout << uiboucle << endl;
    char* pcChaineSansEspace = (char*)malloc(sizeof(char) * (uiTailleSansEspace + 1));

    unsigned int uiChaineBase = 0;
    unsigned int uiNouvelleChaine = 0;
    while (pcStr[uiChaineBase] != '\0')
    {
        if (pcStr[uiChaineBase] != ' ')
        {
            pcChaineSansEspace[uiNouvelleChaine] = FICMinuscule(pcStr[uiChaineBase]);
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