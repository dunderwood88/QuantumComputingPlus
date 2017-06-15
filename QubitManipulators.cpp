//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include "QubitManipulators.h"

namespace qubitManipulators {

    // QUANTUM GATES

    void hadamardGate(Qubit& qubit) {

        std::cout << "Applying Hadamard gate." << std::endl;

        qubit.manipulate(
                [](std::complex<double>& alpha, std::complex<double>& beta) {

                    std::vector<std::complex<double>> newAmplitudes;

                    newAmplitudes.push_back((alpha + beta)/sqrt(2));
                    newAmplitudes.push_back((alpha - beta)/sqrt(2));

                    return newAmplitudes;
                }
        );

    }

    void hadamardGate(std::vector<Qubit>& qubits) {

        for(Qubit& q: qubits){
            hadamardGate(q);
        }
    }
}