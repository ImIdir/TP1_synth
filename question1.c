#include "fonction.h"


int main(void){
	write(STDOUT_FILENO, WELCOME, strlen(WELCOME));
	write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));
}
