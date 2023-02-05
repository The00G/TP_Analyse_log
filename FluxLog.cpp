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
#include "Connexion.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void FluxLog::LireLog ( Statistiques * stat, string prefixeAEnlever ) const
// Algorithme :
//
{
    ifstream stream;
    stream.open(this->nomFichier);

    int taillePrefixe = prefixeAEnlever.length();

    if(!stream.fail())
    {
        string tmp;
        
        string ip;
        string userLogname;
        string authenticatedUser;
        string date;
        string heureStr;
        int heure;
        string typeAction;
        string cibleURL;
        string extension;
        string httpVersion;
        string statusStr;
        int status;
        string quantiteDonneesStr;
        int quantiteDonnees;
        string refererURL;
        string navigateurInfo;

        while(!stream.eof())
        {
            std::getline(stream,ip,' ');
            std::getline(stream,userLogname,' ');
            std::getline(stream,authenticatedUser,' ');

            std::getline(stream,tmp,'[');

            std::getline(stream,date,':');
            std::getline(stream,heureStr,':');
            // Conversion du string en int
            heure = stoi(heureStr);

            std::getline(stream,tmp,'"');

            std::getline(stream,typeAction,' ');
            std::getline(stream,cibleURL,' ');
            // Isolation de l'extension
            string extension = std::string(cibleURL.begin() + cibleURL.find('.'), 
                                           cibleURL.end());
            std::getline(stream,httpVersion,'"');

            std::getline(stream,tmp,' ');

            std::getline(stream,statusStr,' ');
            status = stoi(statusStr);
            std::getline(stream,quantiteDonneesStr,' ');
            if(quantiteDonneesStr == "-")
            {
                // Données anonymisées
                quantiteDonnees = -1;
            }
            else
            {
                // Conversion des données en int
                quantiteDonnees = stoi(quantiteDonneesStr);
            }

            std::getline(stream,tmp,'"');

            std::getline(stream,refererURL,'"');
            // Retire le début de l'url spécifié lors de l'appel de la fonction
            if(refererURL.find(prefixeAEnlever) != string::npos)
            {
                refererURL.erase(0, taillePrefixe);
            }
            // Retire ce qu'il y a derrière les '?' et ';' si il y en a
            long unsigned int ptInterro = refererURL.find("?");
            long unsigned int ptVirgule = refererURL.find(";");
            if(ptInterro != string::npos)
            {
                refererURL.erase(ptInterro, string::npos);
            }
            else if(ptVirgule != string::npos)
            {
                refererURL.erase(ptVirgule, string::npos);
            }

            std::getline(stream,tmp,'"');

            std::getline(stream,navigateurInfo,'"');

            std::getline(stream,tmp);

            Connexion transfert;

            transfert.ip = ip;
            transfert.userLogname = userLogname;
            transfert.authenticatedUser = authenticatedUser;
            transfert.date = date;
            transfert.heure = heure;
            transfert.typeAction = typeAction;
            transfert.cibleURL = cibleURL;
            transfert.extension = extension;
            transfert.httpVersion = httpVersion;
            transfert.status = status;
            transfert.quantiteDonnees = quantiteDonnees;
            transfert.refererURL = refererURL;
            transfert.navigateurInfo = navigateurInfo;
            
            transfert.Afficher();
            stat->Ajouter(transfert);
        }

    }
    else
    {
        cout << "Le fichier ne peut pas être ouvert !" << endl;
    }
} //----- Fin de Méthode

void FluxLog::SetFichier ( const char * const newNomFichier )
// Algorithme :
//
{
    int length = strlen(newNomFichier);
    delete(this->nomFichier);
    this->nomFichier = new char[length+1];

    strcpy(this->nomFichier, newNomFichier);
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
