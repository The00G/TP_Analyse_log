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
    string ip;
    string userLogname;
    string authenticatedUser;
    string date;
    int heure;
    string typeAction;
    string cibleURL;
    string httpVersion;
    int status;
    int quantiteDonnees; // -1 si anonymisé
    string refererURL;
    string navigateurInfo;
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
