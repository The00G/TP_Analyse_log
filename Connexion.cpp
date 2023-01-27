/*************************************************************************
        Connexion  -  conteneur de log au format utilise par Apache
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//-------- Réalisation de la classe <Connexion> (fichier Connexion.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Connexion.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Connexion::Connexion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Connexion>" << endl;
#endif
} //----- Fin de Connexion


Connexion::~Connexion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Connexion>" << endl;
#endif
} //----- Fin de ~Connexion


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
