#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/wait.h>

#include <errno.h>

#define COUNT 20

int main()
{
	int pipe_fds[2];

	if(pipe(pipe_fds) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < COUNT; i++)
	{
		pid_t result = fork();

		if(result == -1)
		{
			perror("Error");
			exit(1);
		}
		else if(result == 0)
		{
			close(pipe_fds[0]);

			if(dup2(pipe_fds[1], 1) == -1)
			{
				perror("Error");
				exit(1);
			}

			sleep(3 + i);
			printf("I am child process #%d\n\n", i);
			close(pipe_fds[1]);
			exit(0);
		}
	}

	close(pipe_fds[1]);

	int status;

	while(wait(&status) != -1)
	{
		if(WIFEXITED(status) && WEXITSTATUS(status) != EXIT_SUCCESS)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	printf("I am the parent, and all child processes have been collected\n\n");

	int read_status = 1;
	int write_status = 1;

	char buffer[100];

	while(read_status > 0)
	{
		read_status = read(pipe_fds[0], buffer, 100);

		if(read_status == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		write_status = write(1, buffer, read_status);

		if(write_status == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	close(pipe_fds[0]);
	return 0;
}
