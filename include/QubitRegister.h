//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUBITREGISTER_H
#define QUANTUMCOMPUTING_QUBITREGISTER_H

#include "Qubit.h"
#include <vector>

class QubitRegister {

private:
    std::vector<Qubit> _qubits;

public:
    QubitRegister(int numQubits);

    std::string measure();
    std::vector<Qubit>& list();

};


#endif //QUANTUMCOMPUTING_QUBITREGISTER_H
