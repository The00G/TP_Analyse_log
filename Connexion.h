/*************************************************************************
        Connexion  -  conteneur de log au format utilise par Apache
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Connexion> (fichier Connexion.h) ----------
#if ! defined ( CONNEXION_H )
#define CONNEXION_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Connexion>
//
//
//------------------------------------------------------------------------

class Connexion
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
    Connexion ( );
    // Mode d'emploi :
    // 
    // Contrat :
    //

    ~Connexion ( );
    // Mode d'emploi :
    // 
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    
};

//----------------------------- Autres définitions dépendantes de <Connexion>

#endif // CONNEXION_H
