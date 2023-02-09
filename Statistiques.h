/*************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Statistiques> (fichier Statistiques.h) ----------------
#if ! defined ( STATISTIQUES_H )
#define STATISTIQUES_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <list>
#include "Connexion.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistiques>
//
//
//------------------------------------------------------------------------

class Statistiques
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
     void Ajouter ( Connexion c ) ;
    // Mode d'emploi :
    // Ajoute une instance de Connexion aux statistiques si elle respecte 
    // les critères de l'instance de Statistique
    // Contrat :
    // 

    void ExporterGraphe ( ostream & flux ) ;
    // Mode d'emploi :
    // exporte le graphe au format digraph dans un flux donné
    // Contrat :
    // le flux est valide

    void AfficherTop ( ostream & flux, long unsigned int n = 10) ;
    // Mode d'emploi :
    // affiche dans un flux donné les n pages les plus accédées dans l'ordre
    // ainsi que leur nombre d'accès respectifs
    // si il y a moins de n pages les affiche toutes dans l'ordre
    // Contrat :
    // le flux est valide

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    explicit Statistiques ( const Statistiques & s );
    // Mode d'emploi (constructeur de copie) :
    // construit une copie de l'entièreté instance de Statistique
    // Contrat :
    //

    Statistiques ( bool graphe = false, bool exclureFichierSpec = false, int heure = -1);
    // Mode d'emploi :
    // creer une instance de Statistique avec des critères de sélection donnés
    // Contrat :
    // l'heure est comprise entre -1 et 23

    virtual ~Statistiques ( );
    // Mode d'emploi :
    // détruit l'instance de Statistique
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
unordered_map <string, int> pages;
unordered_map <string, int> connexions;
list <string> top;
bool graphe;
bool exclureFichierSpec;
int heure;

};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // STATISTIQUES_H

