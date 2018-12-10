/* Operating Systems, Sheet 3, Task 4, Nadya Marinova*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void signal_handler(int signal){
	if (signal == SIGCHLD){
		exit(0);   // change here make sure it print something
	}
	else{
		pause();
	}
}

int main(void){
	
	//From the manpage: The termination signal of the child is always SIGCHLD
	//int pid = fork();
	pid_t pid = fork();
	
	if ((int) pid == 0){
		fprintf(stdout, "%d\n", (int)getpid());
		exit(0);
	}
	else if ((int)pid > 0){
		signal(SIGCHLD, signal_handler);
		pause();  //why this pause for?
	}
	else{
		fprintf (stderr, "Error");
      	exit (1);
	}
	
	return EXIT_SUCCESS;
}

/* struct sigaction action_sigchild;
 	action_sigchild.sa_handler = handler;		pointer to the handler
	sigemptyset(&action_sigchild.sa_mask);		sa_mask is a sigset_t
	action_sigchild.sa_flags = 0;

  * in main:

	sigaction(SIGCHILD, &action_sigchild, NULL);	//NULL for the default handler??

*/