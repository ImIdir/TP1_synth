#include "fonctions.h"

int main(void){
	char commande[MAX_SIZE];
	int commande_size;
	int pid;
	int status;
	int test;
	
	//Welcome message
	write(STDOUT_FILENO, WELCOME, strlen(WELCOME));
	
	while(1){
		write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));
		
		//Command prompt reading
		commande_size = read(STDOUT_FILENO, commande, MAX_SIZE);
		
		//Earse the last element
		commande[commande_size-1] = '\0';
		
		test = strcmp(EXIT, commande);
		if(test==0){
			write(STDOUT_FILENO, GOODBYE, strlen(GOODBYE));
			kill(getpid(),SIGINT);
		}
		
		pid = fork();
		if(pid==0){
			//Execution of the child
			execlp(commande, commande, NULL);
		} else {
			//Execution of the father
			wait(&status);
		}
	}	
}