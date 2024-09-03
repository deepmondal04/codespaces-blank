//deep mondal-1186
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> // Required for pid_t
#include <unistd.h> // Required for fork(), getpid(), and getppid()
int main() {
int n;
printf("Enter the number of iterations: "); // input for iter
scanf("%d", &n);
for (int i = 0; i < n; i++) {
pid_t pid = fork(); // Create child process
if (pid < 0) {
// Fork failed
fprintf(stderr, "Fork failed\n");
return 1;
} else if (pid == 0) {
// Child process
printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
break; // Prevent child process from continuing the loop
} else {
// Parent process
printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
}
return 0;
 } }