README du bootstrap initial, à adapter si besoin.

# Architecture du répertoire

## Répertoires : 

  * include : les fichiers .h
  * src : les fichiers .c du projet (sauf ceux avec un main)
  * programs : les fichiers .c contenant les programmes principaux (main) des livrables
  * test : les fichiers .c contenant les programmes principaux (main) de test
  * graphes : les fichiers contenant des graphes. Ne pas envoyer sur le serveur git de gros fichiers graphe (> quelques Mo) !
  * rapport : pour le rapport final et le fichier de suivi
  * ressources : tous autres fichier dont on pourrait avoir besoin
  
## Autres : 
  * Makefile : pour compiler / exécuter les tests automatiques / lancer le debugger. Voir ci dessous. **Il ne devrait aucunement être utile de modifier ce Makefile**
  * Makefile.inc : options de compilation 
  * Makefile.inst : pour configurer Visual Studio Code. Voir ci dessous.
  * répertoire .vs_code et test/env.gdb : fichiers utiles à Visual Studio Code. Ne pas modifier !
  
  
# Programmes principaux
  * programs/acm.c : embryon de programme principal pour le calcul de l'acm
  * programs/gen_graph_file.c : programme principal fourni fonctionnel permettant de générer des fichiers graphes aléatoires. 

# Configuration de Visual Studio Code

L’utilisation de gdb depuis VSCode par simple clic suppose suppose que vous ayez installé l'extension dashboard, donc faites d'abord :

* Sur la machine virtuelle :

`$ make -f Makefile.inst my-box-stylish`

* Sur votre compte école :

`$ make -f Makefile.inst my-env-stylish`

Ne PAS modifier le Makefile.inst, ni le répertoire .vscode, ni le répertoire test/env.gdb !

# Compiler

`make`permet de compiler tous les fichiers .c du répertoire `src` et tous les programmes exécutables des répertoires `programs` et `test`

Les exécutetables de test (du répertoire `test`) seront compilé en "mode debug" : ils pourront être exécutés confortablement dans un debugger.

Les exécutetables "livrables" (du répertoire `programs`) seront compilé sans "mode debug" et avec les options d'optimisation du compilateur : ils pourront être utilisés pour tester les performances de votre code.

**attention : tous les fichiers .c des répertoires `src`, `programs` et `test` seront compilés atomatiquement. Si un de vos fichiers est en cours de développement et empèche la compilation, renommez-le temporairement en .ctmp ou déplacez le ailleurs, par exemple dans ressources/**
 
# Lancer automatiquement les tests dans le Terminal

Les tests (fournis) sont dans le répertoire test. 


La commande :

`$ make tests@check`

exécute tous les tests, jusqu'au premier test qui est en échec.

Les tests sont exécutés dans l'ordre alphabétique des noms des fichiers .c de test.


Pour exécuter un test en particulier, par exemple test/01_edge :

`$ make test/01_edge@check`

Ou plus simplement encore : 
  
`$ test/01_edge`

# Utiliser le debugger dans le Terminal

Votre debugger (gdb ou lldb suivant votre configuration) peut s'utiliser comme d'habitude.

Le Makefile permet toutefois d'améliorer les affichages du debugger.

Pour lancer tous les tests dans le debugger depuis le terminal (sinon, suffit de cliquer dans VScode !), c'est :

`$ make tests@debug`


Pour lancer un test choisi dans le debugger gdb depuis le terminal (sinon, suffit de cliquer dans VScode !), c'est :

`$ make test/01_edge@debug`


# Utiliser valgrind

Pour tester, par exemple, les erreurs d'accès mémoire et fuite mémoire du test  `test/01_edge`, exécuter : 

`$ valgrind test/01_edge`

