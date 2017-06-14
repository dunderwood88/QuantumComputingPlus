//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUANTUMGATES_H
#define QUANTUMCOMPUTING_QUANTUMGATES_H

#include <vector>
#include "Qubit.h"

namespace qubitManipulators {

    // MEASUREMENT
    void measure();


    // QUANTUM GATES
    void hadamardGate(Qubit& qubit);
    void hadamardGate(std::vector<Qubit>& qubits);

}

#endif //QUANTUMCOMPUTING_QUANTUMGATES_H
