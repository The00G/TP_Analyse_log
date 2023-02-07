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
#include <fstream>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "Statistiques.h"

//------------------------------------------------------------- Constantes
const string EXTENSION_SPECIALES [] = {".png", ".bmp",".jpg",".jpeg",".css",".js"};
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Statistiques::Ajouter ( Connexion c )
// Algorithme :
//
{
    if(exclureFichierSpec && find(begin(EXTENSION_SPECIALES),end(EXTENSION_SPECIALES),c.extension) != end(EXTENSION_SPECIALES)) {
        return;
    }
    if(this->heure!=-1 && c.heure!=this->heure) {
        return;
    }
    
    this->pages[c.cibleURL]++;
    this->pages[c.refererURL];
    
    if(graphe) {
        string redirection = c.refererURL + "\n" + c.cibleURL;
        this->connexions[redirection]++;
    }

} //----- Fin de Ajouter

void Statistiques::ExporterGraphe ( string nomFichier )
// Algorithme :
//
{
    ofstream flux;
    flux.open( nomFichier );


    flux << "digraph {" << endl;
    for(unordered_map <string, int>::iterator it = this->pages.begin(); it != this->pages.end(); ++it)
    {
        flux << "\"" << it->first << "\"" << endl;
    }
    for(unordered_map <string, int>::iterator it = this->connexions.begin(); it != this->connexions.end(); ++it)
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
    this->topDix.clear();
    unordered_map <string, int>::iterator itPages = this->pages.begin();
    while(itPages != this->pages.end() && this->pages[itPages->first]==0) ++itPages;
    this->topDix.push_front(itPages->first);
    ++itPages;
    while( itPages != this->pages.end() && this->topDix.size() < 10)
    {
        int nbRedirections = this->pages[itPages->first];
        if(nbRedirections > 0) {
            list<string>::iterator itTop = this->topDix.begin();
            while( itTop != this->topDix.end() && this->pages[*itTop] < nbRedirections) ++itTop;
            this->topDix.insert(itTop,itPages->first);
        }
        ++itPages;
    }
    while (itPages != this->pages.end())
    {
        int nbRedirections = this->pages[itPages->first];
        list<string>::iterator itTop = this->topDix.begin();
        if(nbRedirections > this->pages[*itTop])
        {
            do {++itTop;} while(itTop != this->topDix.end() && this->pages[*itTop] < nbRedirections);
            this->topDix.insert(itTop,itPages->first);
            this->topDix.pop_front();
        }
        ++itPages;
    }
    for(list<string>::reverse_iterator rit = this->topDix.rbegin(); rit != this->topDix.rend(); ++rit) {
        cout << *rit << " (" << this->pages[*rit] << " hits)" << endl;
    }
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

