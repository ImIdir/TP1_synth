#include "fonctions.h"

int main(void){
	char commande[MAX_SIZE] = {0};
	char display[MAX_SIZE] = {0};
	int commande_size;
	int pid;
	int status;
	int test;
	
	//Welcome message
	write(STDOUT_FILENO, WELCOME, strlen(WELCOME));
	write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));
	
	while(1){
		//Command prompt reading
		commande_size = read(STDOUT_FILENO, commande, MAX_SIZE);
		
		//Earse the last element
		commande[commande_size-1] = '\0';
		
		//exit the process on the 'exit' command or ctrl+d
		test = strcmp(EXIT, commande);
		if(test==0 || commande_size==0){
			write(STDOUT_FILENO, GOODBYE, strlen(GOODBYE));
			kill(getpid(),SIGINT);
		}
		
        // Forking a child process
		pid = fork();
		if(pid==0){
			//Execution of the child
			execlp(commande, commande, NULL);
		} 
		
		else {
			//Execution of the father
			wait(&status);
			if(WIFSIGNALED(status)){ //WIFSIGNALED(status)==true if the child terminated because of an unsignal

				sprintf(display, "%s%d%s", SIGNALED_PROMPT, WTERMSIG(status), END_PROMPT); //WTERMSIG return the value of the signal that killed the child
				write(STDOUT_FILENO, display, strlen(display));
			} 
            else {
                if(WIFEXITED(status)){ //WIFEXITED(status)==true if the child terminated normally

					sprintf(display, "%s%d%s", EXITED_PROMPT, WEXITSTATUS(status), END_PROMPT); //WEXITSTATUS return the exit value of the child
					write(STDOUT_FILENO, display, strlen(display));
				}
			}
		}
	}	
}
