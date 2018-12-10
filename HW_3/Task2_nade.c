/* Operating Systems, Sheet 3, Task 2, Nadya Marinova*/

#include <unistd.h>   // define pid_t
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>  // define pid_t
#include <sys/wait.h>

int main (void){  //int main(int argc, char **argv)
	
	int n = 16;	
	for (int i = 0; i < n; i++){
				
		pid_t pid = fork();
       
		if ((int)pid > 0){		 //parent
			//to do???
		}
		else if ((int)pid == 0){		  //child
			
			fprintf(stdout, "Child Process %d: %d\n", i + 1, (int) getpid());
			exit(0);
		}
		else{   			 // proccess was not successfully created
			fprintf (stderr, "Error");
      		exit (1);
		}
	}
	
	fprintf(stdout, "16 child processes have been created\n");
}
/*	int fprintf(FILE *stream, const char *format, ...) sends formatted output to a stream.
	fork() - It takes no arguments and returns a process ID
Child process receives from the parent: copie of the memory, file handlers of open files, 
	After a new child process is created, both processes will execute the next
 instruction following the fork() system call. To distinguish them use the return value of fork()
	Unix will make an exact copy of the parent's address space and give it to the child.
Therefore, the parent and child processes have separate address spaces.
	Write / printf? It is because printf() is "buffered," While buffering the output for 
the parent process, the child may also use printf to print out some information, which will also
be buffered. As a result, since the output will not be send to screen immediately, you may not 
get the right order of the expected result. The output may be mixed in strange ways. To overcome this
 problem, you may consider to use the "unbuffered" write.
	Also, due to the fact that these processes are run concurrently, their output lines are 
intermixed in a rather unpredictable way. Moreover, the order of these lines are determined by 
the CPU scheduler. Hence, if you run this program again, you may get a totally different result.
	Due to the fact that the CPU scheduler will assign a time quantum to each process, the parent 
or the child process will run for some time before the control is switched to the other and the 
running process will print some lines before you can see any line printed by the other process.

	POSIX defines a function: wait(NULL)；. It's the shorthand for waitpid(-1, NULL, 0);,
which will suspends the execution of the calling process until any one child process exits.
Here, 1st argument of waitpid indicates wait for any child process to end.
 */