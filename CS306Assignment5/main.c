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
//    int fd, n;
//    char buf[1024];
//
//    fd = open(arg, O_RDONLY);
//    if (fd < 0) {
//        printf("Error opening the file.");
//        return (void *) 1;
//    }
//
//    n = read(fd, buf, sizeof(buf));
//    close(fd);
    printf("filename: %s\n", ((struct args*)input)->filename);
    printf("index of file in array: %d\n", ((struct args*)input)->index);

//    pthread_mutex_lock(&mutex);
//
//    pthread_mutex_unlock(&mutex);
    return NULL;
}
int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Invalid number of arguments. Use at least two args.\n");
        return 1;
    }
    else {
        // array of character pointers to hold filenames
        const char *filenames[argc-1];
        for (int i=0; i<argc-1; i++) {
            filenames[i] = argv[i+1];
        }

        // dynamically allocated array of unsigned longs to hold bytes of each file
        unsigned long *numberOfBytes = (unsigned long*) malloc((argc-1)*sizeof(unsigned long));

        // create a thread for each file
        for (int j=1; j<argc; j++) {
            struct args *file = (struct args *)malloc(sizeof(struct args));
//            char allen[] = "Allen";
            file->filename = argv[j];
            file->index = j-1;
            pthread_t tid;
            pthread_create(&tid,NULL,threadhandler,(void *)file);
            pthread_join(tid, NULL);
        }

        exit(EXIT_SUCCESS);

        // print the number of bytes for each file
        for (int i=0; i<argc-1; i++) {
            printf("%s\n", filenames[i]);
        }
    }
    return 0;
}
