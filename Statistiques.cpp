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
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Connexion.h"
#include "Statistiques.h"

//------------------------------------------------------------- Constantes
const string EXTENSION_SPECIALES [] = {"png", "bmp","jpg","jpeg","css","js"};
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Statistiques::Ajouter ( Connexion c )
// Algorithme :
//
{
    /*if(exclureFichierSpec && EXTENSION_SPECIALES.find(c.extension) != EXTENSION_SPECIALES.end()) {
        return;
    }*/
    if(heure!=-1 && c.heure!=heure) {
        return;
    }  
    pages[c.cibleURL]++;
    pages[c.refererURL];
    
    if(graphe) {
        string redirection = c.refererURL + "\n" + c.cibleURL;
        connexions[redirection]++;
    }

} //----- Fin de Ajouter

void Statistiques::ExporterGraphe ( string nomFichier )// Algorithme :
//
{
    ofstream flux;
    flux.open( nomFichier );


    flux << "digraph {" << endl;
    for(unordered_map <string, int>::iterator it = pages.begin(); it != pages.end(); ++it)
    {
        flux << "\"" << it->first << "\"" << endl;
    }
    for(unordered_map <string, int>::iterator it = connexions.begin(); it != connexions.end(); ++it)
    {
        flux << "\"" << it->first.substr(0,it->first.find("\n")) 
             << "\" -> \"" << it->first.substr(it->first.find("\n")+1,it->first.length()) 
             << "\" [label=\"" << it->second << "\"];" << endl;
    }
    flux << "}";
} //----- Fin de ExporterGraphe

void Statistiques::AfficherTopDix ( )// Algorithme :
//
{
    
    /*for(unordered_map <string, int>::iterator it = pages.begin(); it != pages.end(); ++it)
    {
        flux << "node" << it->second.index << " [label=\"" << it->first << "l\"];" << endl;
    }*/
    
} //----- Fin de AfficherTopDix


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
        : graphe(graphe), exclureFichierSpec(exclureFichierSpec), heure(heure), nbConnexions(0)
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

