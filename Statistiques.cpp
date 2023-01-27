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
#include <ostream>

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
    if(exclureFichierSpec) {
        //TODO
    }
    unordered_map<string, StatsPage>::iterator it = pages.find(c.cibleURL);
    if( it == pages.end()) {
        
        pages[c.cibleURL].index = nbConnexions++;
        pages[c.cibleURL].nbAcces = 1;
    } else {
        it->second.nbAcces++;
    }

    if(graphe) {
        string redirection = c.refererURL + "\n" + c.cibleURL;
        connexions[redirection]++;
    }

} //----- Fin de Ajouter

void Statistiques::ExporterGraphe ( string nomFichier )// Algorithme :
//
{
    //ofstream flux;
    // TODO

    cout << "digraph {" << endl;
    for(unordered_map <string, StatsPage>::iterator it = pages.begin(); it != pages.end(); ++it){
        cout << "node" << it->second.index << " [label=\"" << it->first << "l\"];" << endl;
    }
    for(unordered_map <string, int>::iterator it = connexions.begin(); it != connexions.end(); ++it){
        cout << "node" << pages[it->first.substr(0,it->first.find("\n"))].index 
                << " -> node" << pages[it->first.substr(it->first.find("\n")+1,it->first.length())].index 
                << " [label=\"" << it->second << "\"];" << endl;
    }
    cout << "}";
} //----- Fin de ExporterGraphe


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

