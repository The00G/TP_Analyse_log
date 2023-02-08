/*************************************************************************
        FluxLog  -  lecture d'un fichier de log Apache
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <FluxLog> (fichier FluxLog.h) ----------
#if ! defined ( FLUXLOG_H )
#define FLUXLOG_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Statistiques.h"
#include "Connexion.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FluxLog>
//
//
//------------------------------------------------------------------------

class FluxLog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void LireLog ( ifstream & stream, Statistiques & stat, string prefixeAEnlever = "" ) const;
    // Mode d'emploi :
    // 
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    FluxLog ( );
    // Mode d'emploi :
    // 
    // Contrat :
    //

    ~FluxLog ( );
    // Mode d'emploi :
    // 
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//----------------------------- Autres définitions dépendantes de <FluxLog>

#endif // FLUXLOG_H
