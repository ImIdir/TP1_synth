#include "fonctions.h"

int main(void) {
    char commande[MAX_SIZE];
    int commande_size;
    int pid;
    int status;
	
    // Welcome message
    write(STDOUT_FILENO, WELCOME, strlen(WELCOME));

    while (1) {
        write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));

        // Command prompt reading
        commande_size = read(STDIN_FILENO, commande, MAX_SIZE);

        // Check for end of file (Ctrl+D)
        if (commande_size == 0) {
            write(STDOUT_FILENO, GOODBYE, strlen(GOODBYE));
            exit(0);
        }

        // Erase the last newline character
        if (commande_size > 0 && commande[commande_size - 1] == '\n') {
            commande[commande_size - 1] = '\0';
            commande_size--;
        }

        // Handle the "exit" command
        if (strcasecmp(EXIT, commande) == 0) {
            write(STDOUT_FILENO, GOODBYE, strlen(GOODBYE));
            exit(0);
        }

        // Forking a child process
        pid = fork();
        if (pid == 0) {
            // Execution of the child
            execlp(commande, commande, NULL);
            
        } 
        
        else {
            // Execution of the father
            wait(&status);
            // Print "Bye bye..." if the child process exits with "exit" command
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                write(STDOUT_FILENO, GOODBYE, strlen(GOODBYE));
                exit(0);
            }
        }
    }
    return 0;
}
