//
// Created by Dan Underwood on 16/06/2017.
//

#ifndef QUANTUMCOMPUTING_UTIL_H
#define QUANTUMCOMPUTING_UTIL_H


#include <complex.h>

namespace util {

    // random number generator
    double random();

    // discrete Fourier transform
    std::vector<std::complex<double>> discreteFourierTrans(std::vector<std::complex<double>>& inputVector);


};


#endif //QUANTUMCOMPUTING_UTIL_H
