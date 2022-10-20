#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/mman.h>

int main() {
    int SIZE = 4096;
    int *shared_memory = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,
                                   MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    const int arraySize = 10;
    int myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    *shared_memory = myArray;

    pid_t pid;
    /* fork another process to get block size*/
    pid = fork();

    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        exit(-1);
    } else if (pid == 0) { /* child process to get the size of the file in blocks*/
        printf("In Child Process...\n");
        for (int i = 0; i < arraySize; i++) {
            printf("%d\n", myArray[i]);
        }
        for (int i = 0; i < arraySize; i++) {
            *(shared_memory + i) = myArray[i] * myArray[i];
        }
        printf("Values are squared.\n");
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);
        printf("Child Complete\n");
        printf("In Parent Process..\n");
        for (int i = 0; i < arraySize; i++) {
            printf("%d\n", *(shared_memory + i));
        }
        return 0;
    }
}