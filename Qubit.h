//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUBIT_H
#define QUANTUMCOMPUTING_QUBIT_H

#include <complex>

class Qubit {

private:
    std::complex<double> _alpha;
    std::complex<double> _beta;


public:
    Qubit();
    ~Qubit(){}

    void initialise(std::complex<double> alpha, std::complex<double> beta);
    void collapse();
};


#endif //QUANTUMCOMPUTING_QUBIT_H
