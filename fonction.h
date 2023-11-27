#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>

#define WELCOME  "Bienvenue dans le Shell ENSEA. \nPour quitter, tapez 'exit'. \n"


#define REGULAR_PROMPT "enseash %  "