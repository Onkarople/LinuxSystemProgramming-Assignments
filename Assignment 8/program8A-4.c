#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid, pid1;

	pid = fork();

	if (pid == 0) {
		printf("process1 --> pid = %d and ppid = %d\n",
			getpid(), getppid());
	}

	else {
		pid1 = fork();
		if (pid1 == 0) {
			sleep(1);
			printf("process2 --> pid = %d and ppid = %d\n",
				getpid(), getppid());
		}
		else 
        {
			sleep(3);
			printf("parent --> pid = %d\n", getpid());
		}
	}


	return 0;
}
