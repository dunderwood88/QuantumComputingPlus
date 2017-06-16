//
// Created by Dan Underwood on 16/06/2017.
//

#include <time.h>
#include <random>
#include "../include/util.h"

// Merseene's twister with time seed for random number generation
static std::mt19937 gen((unsigned)time(0));

/**
 * Random number generator using Merseene's twister and system time seed
 *
 * @return random number between 0 and 1
 */
double ::util::random() {

    // random number between 0 and 1
    std::uniform_real_distribution<> dis(0,1);
    return dis(gen);
}
