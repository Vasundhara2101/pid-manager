#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <pthread.h>
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

void release_pid(int pid1)  //function to release pid
{
    for(int i = 0; i <= 100; i++)
    {
        if(obj[i].pid1 == pid1)
        {
            obj[i].bitmap = 0;
        }
    }
}

void * callthread(void* )                         
{
    int x = allocate_pid();       
    while (value < 100)
    {
        pthread_mutex_lock(&mutex);     
        if (value >= 100)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        value++;                    
        Sleep(100);
        printf("\n Process %d pid: %d",value);
        printf("\n ",obj[value].pid1);
        pthread_mutex_unlock(&mutex); 
    }
    Sleep(500);
    release_pid(x); //pid released
}

int main()
{
    int i =0;

    pthread_t thread[100];
    printf("\n 100 threads created.");
    Sleep(100);        

    for(i = 0; i < 100; i++)
    {
        pthread_mutex_init(&mutex, NULL);
        pthread_create(&thread[i], NULL,callthread, NULL);
        callthread(NULL);
    }

    for(i = 0; i < 100; i++)
    {
        pthread_join(thread[i], NULL);
        pthread_mutex_destroy(&mutex);
    }

    return 0;
}
