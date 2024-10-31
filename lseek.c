#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("myfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    // Use lseek to move to the end of the file
    int n = lseek(fd, 0, SEEK_END);
    if (n == -1) {
        perror("Failed to determine file size");
        close(fd);
        return 1;
    }

    printf("File size: %d bytes\n", n);

    close(fd);
    return 0;
}
// lseek changes the file pointer (the current read/write position in the file) to a specific location.
// By calling lseek(fd, 0, SEEK_END);, you move the file pointer to the end of the file.
// lseek returns the position in bytes from the start of the file to the end, which is effectively the file size.

// Summary
// Setting n = lseek(fd, 0, SEEK_END); provides a quick way to determine file size.
