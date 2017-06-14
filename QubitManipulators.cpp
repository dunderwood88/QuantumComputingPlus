//
// Created by Dan Underwood on 06/06/2017.
//

#include "QubitManipulators.h"

namespace qubitManipulators {

    // QUANTUM GATES

    void hadamardGate(Qubit& qubit) {


    }

    void hadamardGate(std::vector<Qubit>& qubits) {

        for(Qubit& q: qubits){
            hadamardGate(q);
        }
    }
}