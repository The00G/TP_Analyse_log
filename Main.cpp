using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
#include <fstream>
#include "FluxLog.h"
#include "Connexion.h"
#include "Statistiques.h"

int main( int argc, char * argv[] ) {
    int i;

    string prefixe = "http://intranet-if.insa-lyon.fr";

    char * fichierLog;
    bool exporterGraph = false;
    string fichierGraph;
    bool exclusionImages = false;
    int heure = -1;

    if(argc<2)
    {
        cerr << "No log file has been specified !" << endl;
        return 0;
    }
    else
    {
        fichierLog = argv[argc-1];
    }

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
            try
            {
                heure = stoi(argv[i+1]);
            }
            catch(exception &err)
            {
                cerr << "The specified hour is not valid !" << endl;
                return 0;
            }
            
            if(!(0<=heure && heure<=23))
            {
                cerr << "The specified hour is not valid !" << endl;
                return 0;
            }
            ++i;
        }
        else
        {
            cerr << "One of the commands is not valid !" << endl;
            return 0;
        }
    }

    FluxLog flux;
    Statistiques stats(exporterGraph, exclusionImages, heure);

    ifstream stream;
    stream.open(fichierLog);

    if(!stream.fail())
    {
        flux.LireLog(stream, stats, prefixe);

        if(exporterGraph)
        {
            ofstream streamGraph;
            streamGraph.open( fichierGraph );
            if(!streamGraph.fail())
            {
                stats.ExporterGraphe(streamGraph);
                cout << "Dot-file " << fichierGraph << " generated" << endl;
            }
            else
            {
                cerr << "Dot-file could not be generated" << endl;
            }
        }

        if(heure != -1)
        {
            cout << "Warning : only hits between " << heure << "h and ";
            cout << heure+1 << "h have been taken into account" << endl;
        }

        stats.AfficherTop( cout );
    }
    else
    {
        cerr << "The file can not be opened !" << endl;
    }

    return 0;
}