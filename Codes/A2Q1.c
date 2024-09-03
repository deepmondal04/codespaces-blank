//deep mondal-1186
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> // Required for fork() and getpid()
int main() { // Print before the first fork
printf("Before first fork: Hello guys! PID = %d\n", getpid());
pid_t pid1 = fork(); // First fork call
printf("Between forks: Hello guys! PID = %d\n", getpid()); // Print between the two fork calls
pid_t pid2 = fork(); // Second fork call
printf("After second fork: Hello guys! PID = %d\n", getpid()); // Print after the second fork
return 0;
}