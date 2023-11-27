#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <string.h>
#include <sys/wait.h>

#define WELCOME "Bienvenue dans le Shell ENSEA. \n Pour quitter, tapez 'exit'. \n"
#define GOODBYE "Bye bye... \n"
#define EXIT "exit"

#define REGULAR_PROMPT "enseash %  "

#define MAX_SIZE 128