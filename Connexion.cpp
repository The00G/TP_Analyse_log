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

//------------------------------------------------------ Include personnel
#include "Connexion.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Connexion::Afficher ( bool fullInfo ) const
// Algorithme :
//
{
    if(fullInfo)
    {
        cout << "Informations exhaustives de la connexion :" << endl;
        cout << ip << " ";
        cout << userLogname << " ";
        cout << authenticatedUser << " ";
        cout << date << " ";
        cout << heure << " ";
        cout << typeAction << " ";
        cout << cibleURL << " ";
        cout << extension << " ";
        cout << httpVersion << " ";
        cout << status << " ";
        cout << quantiteDonnees << " ";
        cout << refererURL << " "; 
        cout << navigateurInfo;
        cout << endl << endl;
    }
    else
    {
        cout << "Informations basiques de la connexion :" << endl;
        cout << "heure : " << heure << endl;
        cout << "cibleURL : " << cibleURL << endl;
        cout << "refererURL : " << refererURL << endl;
        cout << endl;
    }


} //----- Fin de Afficher

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
