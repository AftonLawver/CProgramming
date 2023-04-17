#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char **argv) {
    if (argc <= 1 || argc >= 6) {
        fprintf(stderr, "Incorrect usage. Use between 1 and four filenames.\nusage: %s <filename1> <filename2> <filename3> <filename4>\n", argv[0]);
        exit(-1);
    }
    int numOfFiles = argc - 1;
    pid_t pids[numOfFiles];

    int pipes[4][2];
    // populate the pipes array and create the pipes
    for (int i = 0; i < numOfFiles; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("Pipe failed.");
            exit(-1);
        }
    }
    for (int i = 0; i < numOfFiles; i++) {
        pids[i] = fork();
        if (pids[i] == -1) {
            fprintf(stderr, "The fork() call has failed!\n\n");
        }
        //Child
        else if (pids[i] == 0) {
            close(pipes[i][0]); // close read end of pipe for child
            // close every other pipe other than the ith childs
            switch(i) {
                case 0:
                    close(pipes[1][0]);
                    close(pipes[1][1]);
                    close(pipes[2][0]);
                    close(pipes[2][1]);
                    close(pipes[3][0]);
                    close(pipes[3][1]);
                    break;
                case 1:
                    close(pipes[0][0]);
                    close(pipes[0][1]);
                    close(pipes[2][0]);
                    close(pipes[2][1]);
                    close(pipes[3][0]);
                    close(pipes[3][1]);
                    break;
                case 2:
                    close(pipes[0][0]);
                    close(pipes[0][1]);
                    close(pipes[1][0]);
                    close(pipes[1][1]);
                    close(pipes[3][0]);
                    close(pipes[3][1]);
                    break;
                case 3:
                    close(pipes[0][0]);
                    close(pipes[0][1]);
                    close(pipes[1][0]);
                    close(pipes[1][1]);
                    close(pipes[2][0]);
                    close(pipes[2][1]);
                    break;
            }
            dup2(pipes[i][1],1);
            execl("/bin/ls", "ls", "-l", argv[i], NULL); //sends the output to the childs write end
        }
        //Parent
        else {
            // close the writing end of all pipes since parent will only read
            for (int i = 0; i < numOfFiles; i++) {
                close(pipes[i][1]);
            }
            // Wait for all children to complete
            printf("Parent process (PID: %d) waiting for child processes to complete.\n", getpid());
            int status;
            for (int i = 0; i < numOfFiles; i++) {
                waitpid(pids[i], &status, 0);
                if (WIFEXITED(status)) {
                    printf("Child process %d (PID: %d) completed with exit status: %d\n", i + 1, pids[i], WEXITSTATUS(status));
                    char data[] = "";
                    read(pipes[i][0], data, 100);
                    printf("Data from child %d: %s", i + 1, data);
                } else {
                    printf("Child process %d (PID: %d) terminated abnormally\n", i + 1, pids[i]);
                }
            }
            printf("All child processes completed.\n");
            // when all done, close the reading end
            close(pipes[i][0]);
            exit(EXIT_SUCCESS);
        }
    }

    // Prints fds for each pipe read and write end
//    for (int i = 0; i < numOfFiles; i++) {
//        for (int j = 0; j < 2; j++) {
//            printf("%d ", pipes[i][j]);
//        }
//        printf("\n");
//    }
    return 0;
}



