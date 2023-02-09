Programme pour analyser des logs Apache

Pour lancer l application, utilisez cette syntaxe:
$./analog [options] nomfichier.log

Les options sont:
-g nomfichier.dot   Pour créer un fichier au format GraphViz afin d afficher un graphe par la suite
-e                  Pour exclure les documents qui ont une extension de type image, css ou javascript
-t heure            Pour ne prendre en compte que les connexions ayant eu lieu entre heure et heure+1 (entre 0 et 23h)