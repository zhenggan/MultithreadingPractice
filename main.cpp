#include <iostream>
#include <pthread.h>
#include <stdint.h>
#include <cstdlib>
#include "MutexExperiment.h"

int main(int argc, char *argv[])
{   
    if (argc != 2)
    {
        std::cout  << "Invalid number of arguments, Please enter 0 for mutex experiment and 1 for dining philosopher" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if (atoi(argv[1]) == 0)
    {
        std::cout  << "Running mutex experiment" << std::endl;
        MutexExperiment();
    }
    else if (atoi(argv[1]) == 1)
    {
        //TODO:Implement a case of dining philosopher
        std::cout  << "Dining philosopher not yet implemented. This feature will be added at a later patch :)" << std::endl;
    }
    return 0;
}
