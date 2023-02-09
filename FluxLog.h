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
// La classe FluxLog sert à lire un flux de fichier de logs
// Dans le cas où de nouveaux types de logs voudraient être lus, il suffit
// de créer une nouvelle méthode calquée sur LireLog
//------------------------------------------------------------------------

class FluxLog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void LireLog ( ifstream & stream, Statistiques & stat, string prefixeAEnlever = "" ) const;
    // Mode d'emploi :
    // Traite des logs Apache depuis un flux passé en paramètre
    // Les logs traités sont envoyés à l'objet Statistiques passé en
    // paramètre
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
