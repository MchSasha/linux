#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


pid_t fork(void);
int kill(pid_t pid, int sig);
void exit(int status);

int main (void){//+
//
pid_t PAR = getppid();
printf("Program started.\nIts PID =  %d \t PPID = %d\n", getpid(), getppid());
//pr 1
pid_t a1  = fork();
printf("PID1 =  %d\t PPID =  %d\n ", getpid(), getppid());
//d 

kill(PAR, 2);
renice 
if (a1 == -1)
	printf("warning");
else if (!a1)
	{//+
	//pr2
	pid_t a2 = fork();
	printf("PID2 =  %d\t PPID =  %d\n ", getpid(), getppid());
	//d
	if (a2 == -1)
        	printf("warning");
	else if (!a2)
		{//+
		//pr3
		pid_t a3 = fork();
		printf("PID3 =  %d\t PPID =  %d\n ", getpid(), getppid());
		kill(a1, 2);
	//	kill(a3, 2);
		//d
		if (a2 == -1)
        		printf("warning");
		else if (!a2)
			{//pr4    // +
			pid_t a4 = fork();
			printf("PID4 =  %d\t PPID =  %d\n ", getpid(), getppid());
			kill(a3, 2);
			kill(a2, 2);
			//d
			if (a4 == -1)
				printf("warning");
			else if(!a4)
			{
				//pr5
				pid_t a5 = fork();
		                printf("PID5 =  %d\t PPID =  %d\n ", getpid(), getppid());
				kill(a5, 2);
				//pr6
                                pid_t a6 = fork();
                                printf("PID6 =  %d\t PPID =  %d\n ", getpid(), getppid());
				system("ls");
                                kill(a6, 2);
				//pr7
                                pid_t a7 = fork();
                                printf("PID7 =  %d\t PPID =  %d\n ", getpid(), getppid());
                                kill(a7, 2);
			}
			else {//+
                        exit(1);
                        }//+
		}//+
		else {//+
		exit(1);
		}//+

	}//+
	else {//+
	exit(1);
	}//+
}//+
else {//+
exit(1);
}//+
}//+
