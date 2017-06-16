//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUANTUMREGISTER_H
#define QUANTUMCOMPUTING_QUANTUMREGISTER_H

#include "Qubit.h"
#include <vector>

class QuantumRegister : public std::vector<Qubit> {

private:
    int _numStates;

public:
    QuantumRegister(int numQubits);

};


#endif //QUANTUMCOMPUTING_QUANTUMREGISTER_H
