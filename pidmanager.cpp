#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int MAXPID=1000
int MINPID=100
int PID_RANGE=5000;
int pid_map[5000]
int allocate_map()
{
	for(int i=0;i<MAXPID; i++)
	{
		pid_map[i]=0;
	}
	return 1;
	
}
int allocate_pid()
{
	for(int i=0; i<MAXPID; i++)
	{
		if(pid_map[i]==0)
		{
			pid_map[i]=1;
			return i+MINPID;
		}
	}
	return 1;
}
void release_pid(int pid)
{
	pid_map[MINPID+pid]=0;
}
