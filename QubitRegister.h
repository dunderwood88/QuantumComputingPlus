//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUANTUMREGISTER_H
#define QUANTUMCOMPUTING_QUANTUMREGISTER_H

#include <vector>
#include <complex>

class QuantumRegister {

private:
    int _numStates;
    std::vector<std::complex<double>> _qubits;

public:
    QuantumRegister(int numQubits);
    //~QuantumRegister();

    void PrintStates();
};


#endif //QUANTUMCOMPUTING_QUANTUMREGISTER_H
