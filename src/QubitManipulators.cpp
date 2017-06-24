//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include <random>
#include "../include/QubitManipulators.h"

namespace qubitManipulators {


    // QUANTUM GATES

    /**
     * Accepts a qubit register object reference and performs a Hadamard
     * transform on the qubit in the position specified
     *
     * @param qubits the qubit vector
     * @param qubitPosition the register position of the qubit to be transformed
     */
    void hadamardGate(QubitRegister &qubits, int qubitPosition) {

        qubits.manipulate(
                [](std::vector<std::complex<double>> &amplitudes) {

                    std::vector<std::complex<double>> newAmplitudes;



                    return newAmplitudes;

                }

        );
    }

    /**
     * Accepts a qubit object reference and performs a Hadamard
     * transform on it
     *
     * @param qubits the qubit reference
     */
    void hadamardGate(Qubit &qubit) {

        hadamardGate(qubit, 1);
    }

}