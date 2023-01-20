/*************************************************************************
        FluxLog  -  lecture d'un fichier de log Apache
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//-------- Réalisation de la classe <FluxLog> (fichier FluxLog.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

//------------------------------------------------------ Include personnel
#include "FluxLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void FluxLog::LireLog ( )
// Algorithme :
//
{
    ifstream stream;
    stream.open(this->nomFichier);

    if(!stream.fail())
    {
        char tmp = new char[2000];
        
        string ip[20];
        char userLogname[50];
        char authenticatedUser[50];
        char dateEtHeure[30];
        int date;
        int heure;
        char typeAction[20];
        char cibleURL[500];
        char httpVersion[20];
        char statusChar[10];
        int status;
        char quantiteDonneesChar[20];
        int quantiteDonnees;
        char refererURL[500];
        char navigateurInfo[500];

        while(!stream.eof())
        {
            std::getline(stream,ip,' ');

            stream.getline(authenticatedUser,);











        }

        delete(tmp);

        delete(ip);
        delete(userLogname);
        delete(authenticatedUser);
        delete(dateEtHeure);
        delete(typeAction);
        delete(cibleURL);
        delete(httpVersion);
        delete(statusChar);
        delete(quantiteDonneesChar);
        delete(refererURL);
        delete(navigateurInfo);
    }
    else
    {
        cout << "Le fichier ne peut pas être ouvert !" << endl;
    }
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
FluxLog::FluxLog ( const char * const nomFichier)
// Algorithme :
// Copie le nom du fichier dans l'attribut nomFichier
{
#ifdef MAP
    cout << "Appel au constructeur de <FluxLog>" << endl;
#endif

    int length = strlen(nomFichier);
    this->nomFichier = new char[length+1];

    strcpy(this->nomFichier, nomFichier);

} //----- Fin de FluxLog


FluxLog::~FluxLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FluxLog>" << endl;
#endif

    delete(this->nomFichier);

} //----- Fin de ~FluxLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
