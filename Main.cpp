using namespace std;

#include <iostream>
#include <unordered_map>
#include "FluxLog.h"
#include "Connexion.h"
#include "Statistiques.h"

int main( int argc, char * argv[] ) {
    cout << "Lancement main.cpp" << endl;
    cout << "Nombre d'arguments: " << argc << endl << endl;

    int i;
    for(i=0; i<argc; ++i)
    {
        cout << "argument " << i << ": ";
        cout << argv[i] << endl;
    }
    cout << endl;

    char * fichierLog = "test_log.txt";
    char * fichierGraph = "test_export.txt";

    string prefixe = "http://intranet-if.insa-lyon.fr";

    FluxLog * flux = new FluxLog(fichierLog);
    Statistiques * stats = new Statistiques(true, false, -1);

    flux->LireLog(stats, prefixe);
    stats->ExporterGraphe(fichierGraph);
    stats->AfficherTopDix();

    delete(flux);
    delete(stats);

    return 0;
}