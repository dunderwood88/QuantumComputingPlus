//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUBIT_H
#define QUANTUMCOMPUTING_QUBIT_H

#include <complex>
#include <vector>
#include <functional>

class Qubit {

private:
    std::complex<double> _alpha;
    std::complex<double> _beta;


public:
    Qubit();
    ~Qubit(){}

    void initialise(std::complex<double> alpha, std::complex<double> beta);
    void manipulate(std::function<std::vector<std::complex<double>> (std::complex<double>&, std::complex<double>&)> manipulation);
    void collapse();
};


#endif //QUANTUMCOMPUTING_QUBIT_H
