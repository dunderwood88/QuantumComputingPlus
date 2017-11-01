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
    void hadamardGate(Qubit &qubit);
    void hadamardGate(QubitRegister &qubits);
    void hadamardGate(QubitRegister &qubits, unsigned int qubitPosition);

    //Pauli
    void pauliX(Qubit &qubit);
    void pauliX(QubitRegister &qubits, unsigned int qubitPosition);
    void pauliY(Qubit &qubit);
    void pauliY(QubitRegister &qubits, unsigned int qubitPosition);
    void pauliZ(Qubit &qubit);
    void pauliZ(QubitRegister &qubits, unsigned int qubitPosition);

    //CNOT
    //void cNot(Qubit& control, Qubit& target);
    void cNot(QubitRegister &qubits);


}

#endif //QUANTUMCOMPUTING_QUANTUMMANIPULATORS_H
