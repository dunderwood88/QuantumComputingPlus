//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
#include "../include/QubitManipulators.h"

namespace qubitManipulators {

    // Merseene's twister with time seed
    static std::mt19937 gen((unsigned)time(0));

    // MEASUREMENT
    void measure(Qubit& qubit) {

        std::cout << "Performing measurement in computational basis." << std::endl;

        qubit.manipulate(
                [](std::complex<double>& alpha, std::complex<double>& beta) {

                    std::vector<std::complex<double>> newAmplitudes;

                    // random number between 0 and 1
                    std::uniform_real_distribution<> dis(0,1);
                    double rand = dis(gen);


                    double alphaProb = pow(abs(alpha),2);

                    if (rand < alphaProb) {
                        alpha = 1;
                        beta = 0;
                        std::cout << "Qubit system collapsed to |0>" << std::endl;
                    }
                    else {
                        alpha = 0;
                        beta = 1;
                        std::cout << "Qubit system collapsed to |1>" << std::endl;
                    }

                    newAmplitudes.push_back(alpha);
                    newAmplitudes.push_back(beta);

                    return newAmplitudes;
                }
        );

    }

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