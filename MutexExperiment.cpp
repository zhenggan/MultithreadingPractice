#include <iostream>
#include <pthread.h>
#include <stdint.h>
#include <cstdlib>
#include <unistd.h> 
#include "MutexExperiment.h"

//Global mutex
pthread_mutex_t mutex;

//Locks and increments the value of the pointer passed into it, then unlocks and sleeps
void *incrementCounter(void *arg)
{
    int *counter = (int *)arg;

    while ((*counter) < 20)
    {
        pthread_mutex_lock(&mutex);
        (*counter)++;
        std::cout  <<"Thread: " << pthread_self() << " " << "Counter: " << *counter << std::endl;
        pthread_mutex_unlock(&mutex);

        //Sleep this thread to allow the other thread to do some work.
        //Very bad use case of multithreading since it is making the program actually slower, but just trying to practice :)
        usleep(200000);
    }

}

//Function to run the experiment
void MutexExperiment()
{
    int counter = 0;
    pthread_t thread1, thread2;
    int checkThreadCreation = 1;
    checkThreadCreation = pthread_create(&thread1, NULL, &incrementCounter, &counter);
    if (checkThreadCreation)
    {
        std::cout<< "Failed to allocate thread 1" << std::endl;
        exit(EXIT_FAILURE);
    }

    checkThreadCreation = 0;
    checkThreadCreation = pthread_create(&thread2, NULL, &incrementCounter, &counter);
    if (checkThreadCreation)
    {
        std::cout  << "Failed to allocate thread 1" << std::endl;
        exit(EXIT_FAILURE);
    }

    //Wait for the 2 threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

}

