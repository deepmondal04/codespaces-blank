//deep mondal-1186
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> // Required for fork()
int main() {
int x = 10; // initial value of x
printf("Initial value of x: %d\n", x);
pid_t pid = fork(); //for child process
if (pid < 0) { // for fork failed
fprintf(stderr, "Fork failed\n");
return 1;
} else if (pid == 0) { // for child process
printf("Child process: PID = %d\n", getpid());
x = 20; // gives a new constant value to x in the child process
printf("Child process: Updated value of x = %d\n", x);
} else {// for parent process
printf("Parent process: PID = %d\n", getpid());
// Wait for child process to complete
wait(NULL); 
printf("Parent process: Value of x after child process = %d\n", x);
}
return 0;
}