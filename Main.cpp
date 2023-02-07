using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
#include "FluxLog.h"
#include "Connexion.h"
#include "Statistiques.h"

int main( int argc, char * argv[] ) {
    int i;

    string prefixe = "http://intranet-if.insa-lyon.fr";

    char * fichierLog = argv[argc-1];
    bool exporterGraph = false;
    string fichierGraph;
    bool exclusionImages = false;
    int heure = -1;

    // Test de la validité des commandes
    // ./analog [options] nomfichier.log
    // -g nomfichier.dot / -e / -t heure
    for(i=1; i<argc-1; ++i)
    {
        if(strcmp(argv[i], "-g") == 0)
        {
            exporterGraph = true;
            fichierGraph = argv[i+1];
            ++i;
        }
        else if(strcmp(argv[i], "-e") == 0)
        {
            exclusionImages = true;
        }
        else if(strcmp(argv[i], "-t") == 0)
        {
            heure = stoi(argv[i+1]);
            if(!(0<=heure && heure<=23))
            {
                cout << "L'heure n'est pas valide !" << endl;
                return 0;
            }
            ++i;
        }
        else
        {
            cout << "Une des commandes n'est pas valide !" << endl;
            cout << "Les commandes valides sont:" << endl;

            cout << "-g nomfichier.dot  Pour indiquer l'export ";
            cout << "d'un graphe" << endl;

            cout << "-e                 Pour exclure les documents qui ont une ";
            cout << "extension de type image, css ou javascript" << endl;

            cout << "-t heure           Pour ne prendre en compte que les ";
            cout << "hits qui ont eu lieu lors d'une heure spécifique" << endl;
            
            return 0;
        }
    }

    FluxLog * flux = new FluxLog(fichierLog);
    Statistiques * stats = new Statistiques(exporterGraph, exclusionImages, heure);


    flux->LireLog(stats, prefixe);

    if(exporterGraph)
    {
        stats->ExporterGraphe(fichierGraph);
    }

    stats->AfficherTopDix();


    delete(flux);
    delete(stats);

    return 0;
}