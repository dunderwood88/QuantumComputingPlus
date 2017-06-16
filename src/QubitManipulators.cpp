//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
#include "../include/QubitManipulators.h"
#include "../include/QubitRegister.h"

namespace qubitManipulators {

    // MEASUREMENT

    /**
     * Accepts a qubit object reference and performs a measurement in the computational basis
     *
     * @param qubit the qubit to be measured
     */
    /*void measure(Qubit& qubit) {

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

    }*/


    // QUANTUM GATES

    /**
     * Accepts a qubit object reference and performs a Hadamard transform
     *
     * @param qubit the qubit to be transformed
     */
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


    /**
     * Accepts a qubit vector object reference and performs a Hadamard
     * transform on each qubit element
     *
     * @param qubits the qubit vector to be transformed
     */
    void hadamardGate(std::vector<Qubit>& qubits) {

        for (Qubit& q: qubits) {
            hadamardGate(q);
        }
    }


    /**
     * Accepts a qubit register object reference and performs a Hadamard
     * transform on each qubit element
     *
     * @param qubits the qubit vector to be transformed
     */
    void hadamardGate(QubitRegister& qubits) {

        for (Qubit& q: qubits.list()) {
            hadamardGate(q);
        }
    }


    /**
     * Accepts a qubit object reference and performs a pauli-X transform
     *
     * @param qubit the qubit to be transformed
     */
    void pauliX(Qubit& qubit) {

        std::cout << "Applying pauli-X gate." << std::endl;

        qubit.manipulate(
                [](std::complex<double>& alpha, std::complex<double>& beta) {

                    std::vector<std::complex<double>> newAmplitudes;

                    newAmplitudes.push_back(beta);
                    newAmplitudes.push_back(alpha);

                    return newAmplitudes;
                }
        );

    }

    /**
     * Accepts a qubit object reference and performs a pauli-Y transform
     *
     * @param qubit the qubit to be transformed
     */
    void pauliY(Qubit& qubit) {

        std::cout << "Applying pauli-Y gate." << std::endl;

        qubit.manipulate(
                [](std::complex<double>& alpha, std::complex<double>& beta) {

                    std::vector<std::complex<double>> newAmplitudes;

                    newAmplitudes.push_back(std::complex<double>(0, -1)*beta);
                    newAmplitudes.push_back(std::complex<double>(0, 1)*alpha);

                    return newAmplitudes;
                }
        );

    }

    /**
     * Accepts a qubit object reference and performs a pauli-Z transform
     *
     * @param qubit the qubit to be transformed
     */
    void pauliZ(Qubit& qubit) {

        std::cout << "Applying pauli-Z gate." << std::endl;

        qubit.manipulate(
                [](std::complex<double>& alpha, std::complex<double>& beta) {

                    std::vector<std::complex<double>> newAmplitudes;

                    newAmplitudes.push_back(alpha);
                    newAmplitudes.push_back(-beta);

                    return newAmplitudes;
                }
        );

    }

    void cNot(Qubit& control, Qubit& target) {

    }
}