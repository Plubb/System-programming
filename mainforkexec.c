// main.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) { // Child process
        execl("./print_program", "print_program", "Child", "321", (char *)NULL);
        perror("Exec failed");
        exit(1);
    }
    else { // Parent process
        execl("./print_program", "print_program", "Parent", "123", (char *)NULL);
        perror("Exec failed");
        exit(1);
    }

    return 0;
}
