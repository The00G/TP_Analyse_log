/*************************************************************************
        LogApache  -  conteneur de log au format utilise par Apache
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LogApache> (fichier LogApache.h) ----------
#if ! defined ( LOGAPACHE_H )
#define LOGAPACHE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogApache>
//
//
//------------------------------------------------------------------------

class LogApache
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Attributs publiques
    std::string ip;
    std::string userLogname;
    std::string authenticatedUser;
    std::string date;
    int heure;
    std::string typeAction;
    std::string cibleURL;
    std::string httpVersion;
    int status;
    int quantiteDonnees;
    std::string refererURL;
    std::string navigateurInfo;
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    LogApache ( );
    // Mode d'emploi :
    // 
    // Contrat :
    //

    ~LogApache ( );
    // Mode d'emploi :
    // 
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    
};

//----------------------------- Autres définitions dépendantes de <LogApache>

#endif // LOGAPACHE_H
