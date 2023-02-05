using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>
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

    FluxLog * flux = new FluxLog(fichierLog);
    Statistiques * stats = new Statistiques();

    flux->LireLog(stats);
    stats->ExporterGraphe(fichierGraph);

    delete(flux);
    delete(stats);

    return 0;
}