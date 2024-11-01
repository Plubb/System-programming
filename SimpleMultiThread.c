#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Structure to hold the character and count
typedef struct {
    char character;
    int count;
} thread_data_t;

// Thread function
void* print_character(void* arg) {
    thread_data_t* data = (thread_data_t*)arg; // Cast the argument to thread_data_t
    for (int i = 0; i < data->count; i++) {
        printf("%c", data->character); // Print the character
    }
    return NULL; // Exit the thread
}

int main() {
    pthread_t threads[3]; // Array to hold thread identifiers
    thread_data_t thread_data[3]; // Array to hold thread data

    // Initialize data for each thread
    thread_data[0].character = 'a';
    thread_data[0].count = 999;

    thread_data[1].character = 'b';
    thread_data[1].count = 888;

    thread_data[2].character = 'c';
    thread_data[2].count = 777;

    // Create threads
    pthread_create(&threads[0], NULL, print_character, (void*)&thread_data[0]);
    pthread_create(&threads[1], NULL, print_character, (void*)&thread_data[1]);
    pthread_create(&threads[2], NULL, print_character, (void*)&thread_data[2]);

    // Wait for each thread to finish without using a loop
    pthread_join(threads[0], NULL); // Wait for thread 1
    pthread_join(threads[1], NULL); // Wait for thread 2
    pthread_join(threads[2], NULL); // Wait for thread 3

    printf("\n"); // Print newline after all characters are printed
    return 0; // Exit program
}
