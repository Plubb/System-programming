#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) { // Parent process
        sleep(3); // Parent sleeps for 3 seconds
        printf("Parent process exiting...\n");
        exit(0); // Parent exits, making the child an orphan
    } else if (pid == 0) { // Child process
        sleep(6); // Child sleeps for 6 seconds before printing
        while (1) {
            printf("This is Child\n");
            sleep(1); // Child continues to run indefinitely
        }
    } else {
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }

    return 0;
}
