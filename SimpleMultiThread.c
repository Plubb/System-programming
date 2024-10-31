#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void *print_word(void *arg) {
    char **args = (char **)arg; // Convert to char pointer array
    char *word = args[0];       // First argument: the word
    int count = atoi(args[1]);   // Second argument: the count (converted to int)
    
    for (int i = 0; i < count; i++) {
        printf("%s\n", word);
        sleep(1); // Pause to see output clearly
    }
    return NULL;
}

int main() {
    // Define words and counts for each thread
    char *args1[] = {"Hello", "3"};
    char *args2[] = {"World", "5"};
    char *args3[] = {"Threading", "4"};

    // Thread variables
    pthread_t thread1, thread2, thread3;

    // Create threads with different arguments
    pthread_create(&thread1, NULL, print_word, args1);
    pthread_create(&thread2, NULL, print_word, args2);
    pthread_create(&thread3, NULL, print_word, args3);

    // Wait for all threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("All threads finished.\n");
    return 0;
}
