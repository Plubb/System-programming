// 1)Create pthread_attr_t object: We declare pthread_attr_t attr;, creating an automatic variable to hold thread attributes.
// 2)Initialize the attribute object: pthread_attr_init(&attr); initializes attr to default values (joinable by default).
// 3)Modify the attribute values: We change attr to make the thread detached by calling pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);.
// 4)Create the thread using the attribute object: We pass &attr to pthread_create so that the thread is created with the specified attributes.
// 5)Destroy the attribute object: pthread_attr_destroy(&attr); releases resources held by the attribute object. The pthread_attr_t variable attr can still be reused if reinitialized with pthread_attr_init.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void *thread_function(void *arg) {
    printf("Hello from the thread!\n");
    sleep(1);  // Simulate some work
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;  // Step 1: Create a pthread_attr_t object

    // Step 2: Initialize the attribute object
    pthread_attr_init(&attr);

    // Step 3: Modify the attribute (e.g., set the thread to detached)
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    // Step 4: Pass the attribute object to pthread_create
    pthread_create(&thread, &attr, thread_function, NULL);

    // Step 5: Destroy the attribute object
    pthread_attr_destroy(&attr);

    printf("Main thread finished. Detached thread will finish on its own.\n");

    // Sleep to let detached thread finish (for demo purposes only)
    sleep(2);

    return 0;
}
