#include <iostream>
#include <pthread.h>
#include <stdint.h>
#include <cstdlib>
#include "MutexExperiment.h"

int main(int argc, char *argv[])
{   
    std::cout  << "Running mutex experiment" << std::endl;
    MutexExperiment();
    return 0;
}
