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
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Connexion>
// Stocke un log au format Apache afin de pouvoir le manipuler plus
// facilement
//------------------------------------------------------------------------

class Connexion
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
    string extension;
    string httpVersion;
    int status;
    int quantiteDonnees;
    string refererURL;
    string navigateurInfo;

//----------------------------------------------------- Méthodes publiques
    void Afficher ( bool fullInfo = false ) const;
    // Mode d'emploi :
    // Permet d afficher les informations d un log pour faciliter le
    // débugage
    // L option fullInfo permet de choisir entre tout afficher et afficher
    // seulement les infos principales
    // Contrat :
    //

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
