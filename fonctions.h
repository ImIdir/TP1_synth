#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

#define WELCOME "Bienvenue dans le Shell ENSEA. \n Pour quitter, tapez 'exit'. \n"
#define GOODBYE "Bye bye... \n"
#define EXIT "exit"

#define REGULAR_PROMPT "enseash %  "
#define EXITED_PROMPT "enseash [exit : "
#define SIGNALED_PROMPT "enseash [sign : "
#define END_PROMPT "] % "

#define MAX_SIZE 128
#define MAX_ARG 8