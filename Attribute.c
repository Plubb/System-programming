// To specify customized thread attributes, you must follow these steps:
// 1. Create a pthread_attr_t object. The easiest way is simply to declare an automatic
// variable of this type.
// 2. Call pthread_attr_init, passing a pointer to this object. This initializes the attributes
// to their default values.
// 3. Modify the attribute object to contain the desired attribute values.
// 4. Pass a pointer to the attribute object when calling pthread_create.
// 5. Call pthread_attr_destroy to release the attribute object. The pthread_attr_t variable
// itself is not deallocated; it may be reinitialized with pthread_attr_init.

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
