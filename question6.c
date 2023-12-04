#include "fonctions.h"

int main(void){
	char commande[MAX_SIZE] = {0};
	char display[MAX_SIZE] = {0};
	int commande_size;
	int pid;
	int status;
	int test;
	struct timespec timestart;
	struct timespec timestop;
	
	
	//Welcome message
	write(STDOUT_FILENO, WELCOME, strlen(WELCOME));
	write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));
	
	while(1){

		//Command prompt reading
		commande_size = read(STDOUT_FILENO, commande, MAX_SIZE);
		
		//Earse the last element
		commande[commande_size-1] = '\0';
		
		//Exit the process on the 'exit' command or ctrl+d
		test = strcmp(EXIT, commande);
		if(test==0 || commande_size==0){
			write(STDOUT_FILENO, GOODBYE, strlen(GOODBYE));
			kill(getpid(),SIGINT);
		}
		
		clock_gettime(CLOCK_REALTIME, &timestart);

		//Forking a child process
		pid = fork();
		if(pid==0){

			//Execution of the child
			//Using execlp is complicated in this context because it would require counting the number of arguments to know which one is being passed. Instead, we use execvp with an array.
			char * argv[MAX_ARG]={NULL};
			int i = 0;
			
			//call of strtok to get argv[], here the separator is a blanck space
			argv[0] = strtok(commande, " ");
			
			while (argv[i] != NULL){
				i++;
				argv[i] = strtok(NULL, " ");
			}
			execvp(argv[0], argv);
		} 
        
        else {
			//Execution of the father
			wait(&status);
			clock_gettime(CLOCK_REALTIME, &timestop);
			int time = (timestop.tv_nsec - timestart.tv_nsec)/1000000;
			if(WIFSIGNALED(status)){
				sprintf(display, "%s%d%s%d%s%s", SIGNALED_PROMPT, WSTOPSIG(status), "|", time, "ms", END_PROMPT);
				write(STDOUT_FILENO, display, strlen(display));
			} else {
				if(WIFEXITED(status)){
					sprintf(display, "%s%d%s%d%s%s", EXITED_PROMPT, WSTOPSIG(status), "|", time, "ms", END_PROMPT);
					write(STDOUT_FILENO, display, strlen(display));
				}
			}
		}
	}	
}
