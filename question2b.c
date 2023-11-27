#include "fonctions.h"

int main(void){
	char commande[MAX_SIZE];
	int commande_size;
	
	//Welcome message
	write(STDOUT_FILENO, WELCOME, strlen(WELCOME));
	write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));
	
	//Command prompt reading
	commande_size = read(STDOUT_FILENO, commande, MAX_SIZE);
	
	//Earse the last element
	commande[commande_size-1] = '\0';
	
	//Editing the command prompt content
	write(STDOUT_FILENO, commande, commande_size);
	
	execlp(commande, commande, NULL);
}