/*************************************************************************
        Statistiques  -  des statistique sur l'accès a des pages web
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//- Réalisation de la classe <Statistiques> (fichier Statistiques.cpp) -//

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Statistiques.h"

//------------------------------------------------------------- Constantes
const string EXTENSION_SPECIALES [] = {".png", ".bmp",".jpg",".jpeg",".css",".js",".gif",".ico"};
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

void Statistiques::ExporterGraphe ( ostream & flux )
// Algorithme :
//
{
    


    flux << "digraph {" << endl;
    for(unordered_map <string, int>::const_iterator it = this->pages.begin(); it != this->pages.end(); ++it)
    {
        flux << "\"" << it->first << "\"" << endl;
    }

    for(unordered_map <string, int>::const_iterator it = this->connexions.begin(); it != this->connexions.end(); ++it)
    {
        flux << "\"" << it->first.substr(0,it->first.find("\n")) 
             << "\" -> \"" << it->first.substr(it->first.find("\n")+1,it->first.length()) 
             << "\" [label=\"" << it->second << "\"];" << endl;
    }
    flux << "}";

} //----- Fin de ExporterGraphe

void Statistiques::AfficherTop ( ostream & flux , long unsigned int n)
// Algorithme :
// Parcourt l'ensemble des pages enregistrées et stocke les n plus accédés 
// dans la liste top de la moins accédée à la plus accédée
// puis affiche les pages de la liste en la parcourant en ses inverse
{
    this->top.clear();

    if(this->pages.size()==0)
    {
        return;
    }

    unordered_map <string, int>::const_iterator itPages = this->pages.begin();

    while( itPages != this->pages.end() && this->top.size() < n)
    {
        int nbRedirections = this->pages[itPages->first];
        if(nbRedirections != 0) {
            list<string>::iterator itTop = this->top.begin();
            while( itTop != this->top.end() && this->pages[*itTop] < nbRedirections) 
            {
                ++itTop;
            }
            this->top.insert(itTop,itPages->first);
        }
        ++itPages;
    }

    while (itPages != this->pages.end())
    {
        int nbRedirections = this->pages[itPages->first];
        list<string>::iterator itTop = this->top.begin();
        if(nbRedirections > this->pages[*itTop])
        {
            do 
            {
                ++itTop;
            } 
            while(itTop != this->top.end() && this->pages[*itTop] < nbRedirections);

            this->top.insert(itTop,itPages->first);
            this->top.pop_front();
        }
        ++itPages;
    }

    for(list<string>::const_reverse_iterator rit = this->top.rbegin(); rit != this->top.rend(); ++rit) {
        flux << *rit << " (" << this->pages[*rit] << " hits)" << endl;
    }
} //----- Fin de AfficherTop

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Statistiques::Statistiques ( const Statistiques & s )
        : pages(s.pages), connexions(s.connexions), graphe(s.graphe), 
          exclureFichierSpec(s.exclureFichierSpec), heure(s.heure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques (constructeur de copie)

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

