#include "fonctions.h"

 

int main(void){

    char commande[MAX_SIZE];
    int commande_size;

    write(STDOUT_FILENO, WELCOME, strlen(WELCOME));
    write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));

    commande_size = read(STDOUT_FILENO, commande, MAX_SIZE);

    write(STDOUT_FILENO, commande, commande_size);

}