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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct StatsPage {
    int index;
    int nbAcces;
};

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
     void Ajouter ( Connexion );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ExporterGraphe ( string nomFichier );

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    explicit Statistiques ( const Statistiques & unStatistiques );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Statistiques ( bool graphe = false, bool exclureFichierSpec = false, int heure = -1);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Statistiques ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
unordered_map <string, StatsPage> pages;
unordered_map <string, int> connexions;
bool graphe;
bool exclureFichierSpec;
int heure;
int nbConnexions;

};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // STATISTIQUES_H

