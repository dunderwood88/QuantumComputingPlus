//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUANTUMMANIPULATORS_H
#define QUANTUMCOMPUTING_QUANTUMMANIPULATORS_H

#include <vector>
#include "Qubit.h"
#include "QubitRegister.h"

namespace qubitManipulators {

    // MEASUREMENT
    //void measure(Qubit& qubit);


    // QUANTUM GATES

    //Hadamard
    void hadamardGate(Qubit& qubit);
    void hadamardGate(std::vector<Qubit>& qubits);
    void hadamardGate(QubitRegister& qubits);

    //Pauli
    void pauliX(Qubit& qubit);
    void pauliY(Qubit& qubit);
    void pauliZ(Qubit& qubit);

    //CNOT
    void cNot(Qubit& control, Qubit& target);


}

#endif //QUANTUMCOMPUTING_QUANTUMMANIPULATORS_H
