//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUBITREGISTER_H
#define QUANTUMCOMPUTING_QUBITREGISTER_H

#include "Qubit.h"
#include <vector>

class QuantumRegister : public std::vector<Qubit> {

public:
    QuantumRegister(int numQubits);
};


#endif //QUANTUMCOMPUTING_QUBITREGISTER_H
