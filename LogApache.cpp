/*************************************************************************
        LogApache  -  conteneur de log au format utilise par Apache
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//-------- Réalisation de la classe <LogApache> (fichier LogApache.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "LogApache.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
LogApache::LogApache ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogApache>" << endl;
#endif
} //----- Fin de LogApache


LogApache::~LogApache ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogApache>" << endl;
#endif
} //----- Fin de ~LogApache


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
