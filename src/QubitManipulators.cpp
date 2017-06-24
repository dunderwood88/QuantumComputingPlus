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

        if (qubitPosition > qubits.size()) {

            std::cout << "Invalid register position" << std::endl;
            return;
        }

        qubits.manipulate(
                [&qubitPosition](std::vector<std::complex<double>> &amplitudes) {

                    std::vector<std::complex<double>> newAmplitudes;
                    bool minus = false;

                    for (int i = 0; i < amplitudes.size(); i++) {

                        std::complex<double> amp;

                        if (i != 0 && (i % qubitPosition == 0))
                            minus = !minus;

                        if (!minus) {

                            amp = (amplitudes[i] + amplitudes[i + qubitPosition])/sqrt(2);

                        } else {

                            amp = (amplitudes[i - qubitPosition] - amplitudes[i])/sqrt(2);
                        }

                        newAmplitudes.push_back(amp);

                        std::cout << minus << std::endl;
                        std::cout << amp << std::endl;
                    }

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