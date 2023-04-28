#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>


struct args {
    char* filename;
    int index;
};

// where the thread will read in some part of the file
void *threadhandler(void *input) {
    int n;
    char c;
    const char *filename = (((struct args *) input)->filename);
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("File does not exist\n");
        return (void *) 1;
    } else {
        printf("File was opened successfully\n");
        unsigned long count = 0;

        while ((n = read(fd, &c, 1)) > 0) {
            if (c != EOF) {
                count += n;
            }
        }
        // update the pointer of the file to the correct number of bytes
        printf("%s has %lu bytes\n", ((struct args *) input)->filename, count);

        return NULL;
    }
}
    int main(int argc, char *argv[]) {
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

            // dynamically allocated array of unsigned longs to hold bytes of each file
            unsigned long *numberOfBytes = (unsigned long *) malloc((argc - 1) * sizeof(unsigned long));

            // create a thread for each file
            for (int j = 1; j < argc; j++) {
                struct args *file = (struct args *) malloc(sizeof(struct args));
//            char allen[] = "Allen";
                file->filename = argv[j];
                file->index = j - 1;
                pthread_t tid;
                pthread_create(&tid, NULL, threadhandler, (void *) file);
                pthread_join(tid, NULL);
            }
            exit(EXIT_SUCCESS);

            // print the number of bytes for each file
            for (int i = 0; i < argc - 1; i++) {
                printf("%s\n", filenames[i]);
            }
        }
        return 0;
    }