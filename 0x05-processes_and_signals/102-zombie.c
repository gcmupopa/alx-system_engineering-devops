#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * infinite_while()- loop that runs indefinite
 * Return: a value
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main()- creates zombie processes
 * Return: a value
 */

int main(void)
{
	int counter;
	pid_t kidpid;

	for (counter = 0; counter < 5; counter++)
	{
		kidpid = fork();
		if (kidpid > 0)
		{
			printf("Zombie process created, PID: %d\n", kidpid);
		}
		else if (kidpid == 0)
		{
			exit(0);
		}
		else
		{
			perror("fork");
			exit(1);
		}
	}
	infinite_while();
	return (0);
}
