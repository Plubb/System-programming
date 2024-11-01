#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid > 0) { // Parent process
        printf("Parent process (PID: %d) is waiting...\n", getpid());
        sleep(5); // Wait for 5 seconds to observe the zombie state
        printf("Parent process exiting...\n");
    } else if (child_pid == 0) { // Child process
        printf("Child process (PID: %d) exiting...\n", getpid());
        exit(0); // Child exits
    } else {
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }

    return 0;
}
