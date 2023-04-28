#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

struct args {
    char* filename;
    int index;
};

unsigned long numberOfBytes[5];
pthread_mutex_t mutex;

void* threadHandler(void *input) {
    int n;
    char c;
    const char *filename = (((struct args *) input)->filename);
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("File does not exist\n");
        return (void *) 1;
    }
    else {
        unsigned long count = 0;
        while ((n = read(fd, &c, 1)) > 0) {
            if (c != EOF) {
                count += n;
            }
        }
        pthread_mutex_lock(&mutex);
        // update the pointer of the file to the correct number of bytes
        numberOfBytes[((struct args *) input)->index] = count;
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
}
    int main(int argc, char **argv) {
        if (argc < 3) {
            printf("Invalid number of arguments. Use at least two args.\n");
            return 1;
        }
        else {
            // array of character pointers to hold filenames
            const char *filenames[argc - 1];
            for (int i = 0; i < argc - 1; i++) {
                filenames[i] = argv[i + 1];
            }

            // create a thread for each file
            pthread_t tid[argc - 1];
            pthread_mutex_init(&mutex, NULL);
            for (int i = 0; i < argc-1; i++) {
                struct args *file = (struct args *) malloc(sizeof(struct args));
                file->filename = argv[i+1];
                file->index = i;
                if (pthread_create(&tid[i], NULL, &threadHandler, (void *) file) != 0) {
                    perror("thread creation failed");
                }
            }
            for (int j = 0; j < argc-1; j++) {
                if (pthread_join(tid[j], NULL) != 0) {
                    perror("thread join failed");
                }
            }
            pthread_mutex_destroy(&mutex);
            unsigned long maxBytes = 0;
            int index = 0;
            // print the number of bytes for each file
            for (int i = 0; i < argc - 1; i++) {
                printf("%s has %lu bytes.\n", filenames[i], numberOfBytes[i]);
                if (numberOfBytes[i] > maxBytes) {
                    index = i;
                }
            }
            printf("%s is the largest of the submitted files.\n", filenames[index]);
        }
        return 0;
    }