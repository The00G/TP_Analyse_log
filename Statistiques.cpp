/*************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Statistiques> (fichier Statistiques.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <unordered_map>
#include <string>

//------------------------------------------------------ Include personnel
#include "LogApache.h"
#include "Statistiques.h"

//------------------------------------------------------------- Constantes
const string EXTENSION_SPECIALES [] = {"png", "bmp","jpg","jpeg","css","js"};
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Statistiques::Ajouter ( LogApache acces )
// Algorithme :
//
{
    if(exclureFichierSpec) {
        //TODO
    }
    pages[acces.cibleURL]++;
    if(graphe) {
        string redirection = acces.refererURL + "\n" + acces.cibleURL;
        redirections[redirection]++;
    }

} //----- Fin de Ajouter


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
/*Statistiques::Statistiques ( const Statistiques & unStatistiques )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques (constructeur de copie)*/


Statistiques::Statistiques ( bool graphe, bool exclureFichierSpec, int heure )
        : graphe(graphe), exclureFichierSpec(exclureFichierSpec), heure(heure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques


Statistiques::~Statistiques ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistiques>" << endl;
#endif
} //----- Fin de ~Statistiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

