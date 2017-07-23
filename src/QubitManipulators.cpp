//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include <random>
#include "../include/QubitManipulators.h"

namespace qubitManipulators {


    /** QUANTUM GATES
     * Manipulations accept a qubit system (single or register) object and pass into it a lambda
     * function that performs an internal manipulation, which avoids exposing the internal
     * information of the qubit
     */

    /**
     * Accepts a qubit register object reference and performs a Hadamard
     * transform on the qubit in the position specified
     *
     * @param qubits the qubit vector
     * @param qubitPosition the register position of the qubit to be transformed
     */
    void hadamardGate(QubitRegister &qubits, unsigned int qubitPosition) {

        if (qubitPosition < 1 || qubitPosition > qubits.size()) {

            std::cout << "Invalid position (" << qubitPosition
                      << ") for register of size " << qubits.size() << std::endl;
            return;
        }

        qubits.manipulate(
                [&qubitPosition](std::vector<std::complex<double>> &amplitudes) {

                    std::vector<std::complex<double>> newAmplitudes;
                    bool minus = false;
                    unsigned int count = 0;
                    unsigned int diffCoeff;

                    std::cout << "Applying Hadamard transformation on qubit "
                              << qubitPosition << std::endl;

                    for (unsigned int i = 0; i < amplitudes.size(); i++) {

                        std::complex<double> amp;

                        diffCoeff = (unsigned int)pow(2,qubitPosition)/2;

                        if (count == diffCoeff) {
                            minus = !minus;
                            count = 0;
                        }

                        if (!minus) {

                            amp = (amplitudes.at(i) + amplitudes.at(i + diffCoeff))/sqrt(2);

                        } else {

                            amp = (amplitudes.at(i - diffCoeff) - amplitudes.at(i))/sqrt(2);
                        }

                        newAmplitudes.push_back(amp);
                        count++;
                    }

                    return newAmplitudes;
                }

        );
    }

    /**
     * Accepts a qubit register object reference and performs a Hadamard
     * transform on all qubits
     *
     * @param qubits
     */
    void hadamardGate(QubitRegister &qubits) {

        for (unsigned int i = 1; i <= qubits.size(); i++) {
            hadamardGate(qubits, i);
        }

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



    void cNot(QubitRegister &qubits) {

        /*qubits.manipulate(
                [](std::vector<std::complex<double>> &amplitudes) {

                    std::vector<std::complex<double>> newAmplitudes;

                    std::cout << "Applying CNOT transformation" << std::endl;

                    for (unsigned int i = 0; i < amplitudes.size(); i++) {

                        if (i == amplitudes.size() - 2) {

                            newAmplitudes.push_back(amplitudes.at(i + 1));

                        } else if (i == amplitudes.size() - 1) {

                            newAmplitudes.push_back(amplitudes.at(i - 1));

                        } else {
                            newAmplitudes.push_back(amplitudes.at(i));
                        }

                    }

                    return newAmplitudes;
                }

        );*/

    }


}