#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MINPID 100
#define MAXPID 1000

int value = 0;
pthread_mutex_t mutex;

struct pid
{
    int pid1;
    bool bitmap;
}obj[1000];

int allocate_map(void)    //function to initialise data structure for representing pids              
{
    int i,j;
    for(i = MINPID, j =0; i <= MAXPID; i++, j++)
    {
        obj[j].pid1 = i;
        obj[j].bitmap = 0;
    }
    if(i == MAXPID && j == 1000)
    return 1;
    else
    return -1;
}

int allocate_pid(void) //function to allocate pid
{
    for(int i = MINPID, j =0; i <= MAXPID; i++, j++)
    {
        if(obj[j].bitmap == 0)
        {
            obj[j].pid1 = i;
            obj[j].bitmap = 1;
            return i;
            break;
        }
    }

    return -1;
}

