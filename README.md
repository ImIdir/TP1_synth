# TP1_synth
TP 1 de synthèse Shell Ensea

# Question 1 
Objectif :

Afficher un message de bienvenue suivi d'une invitation à saisir une entrée utilisateur.

Solution :

Utilisation de la fonction write de la bibliothèque standard pour écrire le message d'accueil et le prompt sur la sortie standard.

# Question 2
Objectif :

Créer une boucle de lecture, exécution de commandes simples et retour au prompt pour permettre une interaction continue avec l'utilisateur (REPL).

Solution:

Utilisation de la fonction read pour obtenir la commande saisie, forkant un processus enfant pour exécuter cette commande, puis attendant la fin de l'exécution avant de retourner au prompt.

# Question 3 

Objectif :

Permettre à l'utilisateur de quitter le shell en utilisant la commande "exit" ou en entrant <Ctrl>+D pour indiquer la fin du fichier d'entrée standard.

Solution :

Ajout d'une vérification pour détecter la commande "exit" ou la fin du fichier d'entrée standard (Ctrl+D), permettant ainsi au shell de se fermer de manière contrôlée.

# Question 4 

Objectif :

Afficher le code de retour ou le signal de la commande précédente dans le prompt du shell.

Solution :

Ce code affiche le code de retour ou le signal de la commande précédente dans le prompt du shell après son exécution.
Il utilise les fonctions fournies par la bibliothèque <sys/wait.h> pour déterminer si la commande s'est terminée normalement ou à cause d'un signal, puis affiche le résultat correspondant dans le prompt.

# Question 5

Objectif :

Calculer et afficher le temps d'exécution de chaque commande en utilisant la fonction clock_gettime.

Solution :

Ce code mesure le temps d'exécution de chaque commande en utilisant clock_gettime avant et après l'exécution de la commande.
Il calcule la différence de temps pour obtenir le temps d'exécution en millisecondes et l'affiche dans le prompt du shell après l'exécution de la commande.

# Question 6 

Objectif : 

Permettre l'exécution de commandes complexes avec des arguments à l'intérieur du shell.

Solution : 

La solution implémente l'utilisation de execvp pour gérer les commandes avec arguments. 
Plutôt que d'utiliser execlp qui nécessiterait de compter le nombre d'arguments, execvp est utilisé avec un tableau d'arguments pour faciliter l'exécution de commandes complexes.

#Question 7 :

Objectif :

Permettre les redirections des entrées et sorties standard du shell en utilisant les opérateurs ‘<’ et ‘>’ pour lire depuis et écrire vers des fichiers.

Solution :

Le code implémente la détection des opérateurs ‘<’ et ‘>’ dans la commande saisie. S'il détecte ces opérateurs, il redirige l'entrée ou la sortie standard vers les fichiers correspondants en utilisant dup2 et open pour gérer les redirections.
En cas de détection, il ouvre les fichiers correspondants et redirige les flux d'entrée ou de sortie du processus enfant vers ces fichiers pour effectuer les redirections.
