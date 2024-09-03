//deep mondal-1186
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>
int main() {
int num;
printf("Enter a number: "); //input
scanf("%d", &num);
pid_t pid = fork(); // creation of child process
if (pid < 0) {
fprintf(stderr, "Fork failed\n"); // for fork failed
return 1;
} 
else if (pid == 0) { // even number given by child process
if (num % 2 == 0) {
printf("Child process (PID: %d): Next even number is %d\n", getpid(), num + 2);
} else {
printf("Child process (PID: %d): Next even number is %d\n", getpid(), num + 1);
}
} else { 
if (num % 2 == 0) { // odd number given by parent process
printf("Parent process (PID: %d): Next odd number is %d\n", getpid(), num + 1);
} else {
printf("Parent process (PID: %d): Next odd number is %d\n", getpid(), num + 2);
 } 
} return 0;}