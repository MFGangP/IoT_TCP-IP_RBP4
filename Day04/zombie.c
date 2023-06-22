#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();

	if(pid==0) // if child process
	{
		puts("Hi, I am a child process");
	}
	else
	{
		printf("Child Process Id: %d \n", pid);
		sleep(30); 
	}

	if(pid==0)
		puts("End child Process");
	else
		puts("End parent Process");
	return 0;
}
