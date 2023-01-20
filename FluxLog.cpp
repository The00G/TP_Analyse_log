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
        char * tmp = new char[2000];
        
        char * ip = new char[20];
        char * userLogname = new char[50];
        char * authenticatedUser = new char[50];
        char * dateEtHeure = new char[30];
        int date;
        int heure;
        char * typeAction = new char[20];
        char * cibleURL = new char[500];
        char * httpVersion = new char[20];
        char * statusChar = new char[10];
        int status;
        char * quantiteDonneesChar = new char[20];
        int quantiteDonnees;
        char * refererURL = new char[500];
        char * navigateurInfo = new char[500];

        while(!stream.eof())
        {
            stream.getline(tmp,2000);
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
