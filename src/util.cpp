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
/**
 * Discrete Fourier Transform: takes a vector of complex numbers and
 * returns the discrete fourier transform of that vector
 *
 * @return DFT of input vector
 */
std::vector<std::complex<double>> util::discreteFourierTrans(std::vector<std::complex<double>>& inputVector) {

    unsigned long n = inputVector.size();
    std::vector<std::complex<double>> outputVector;

    // for each element in the transformed vector
    for (unsigned long i = 0; i < n; i++) {

        std::complex<double> transform;

        // for each element in the input vector
        for (unsigned long j = 0; j < n; j++) {

            double angle = (2.0 * M_PI * i * j)/n;

            //std::complex<double> complexExponent(cos(angle), -sin(angle));
            //transform += inputVector.at(j) * complexExponent;

            transform += inputVector.at(j) * std::polar(1.0, -angle);

        }

        outputVector.push_back(transform);

    }

    return outputVector;
}
