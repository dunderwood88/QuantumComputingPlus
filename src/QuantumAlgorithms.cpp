//
// Created by Dan Underwood on 11/08/2017.
//

#include <iostream>
#include <complex>
#include <vector>
#include "../include/QuantumAlgorithms.h"
#include "../include/QubitManipulators.h"


// GROVER SEARCH ALGORITHM
void ::QuantumAlgorithms::GroverSearch(
        QubitRegister &qReg,
        std::function<std::vector<std::complex<double>>(std::vector<std::complex<double>> &)> oracleFunction
) {

    // step 1) Hadamard transform on all qubits
    qubitManipulators::hadamardGate(qReg);


    // step 2) Apply the oracle function
    qReg.manipulate(oracleFunction);


    // step 3) Diffusion operator
    qReg.manipulate(
            [](std::vector<std::complex<double>> &amplitudes) {

                std::vector<std::complex<double>> newAmplitudes;

                for (unsigned int i = 0; i < amplitudes.size(); i++) {

                    std::complex<double> amp;

                    amp = amplitudes.at(i) *(-1 + 0.5);

                    for (unsigned int j = 0; j < amplitudes.size(); j++) {

                        if (j != i)
                            amp += amplitudes.at(j) * 0.5;
                    }

                    newAmplitudes.push_back(amp);
                }

                return newAmplitudes;
            }
    );


    // step 4) Hadamard transform on all qubits
    //qubitManipulators::hadamardGate(qReg);

    // step 5) Measure
    std::cout << qReg.strRegisterMeasure() << std::endl;

}


// DEUTSCH-JOZSA ALGORITHM
void ::QuantumAlgorithms::DeutschJozsa(QubitRegister &qReg, std::function<std::vector<std::complex<double>>(
        std::vector<std::complex<double>> &)> function) {


    // step 1) Flip bottom qubit
    qubitManipulators::pauliX(qReg, 1);

    // step 2) Hadamard all qubits
    for (unsigned int i = 1; i <= qReg.size(); i++) {

        qubitManipulators::hadamardGate(qReg, i);

    }

    // step 3) Apply function
    qReg.manipulate(function);

    // step 4) Hadamard top qubits
    for (unsigned int i = qReg.size(); i > 1; i--) {
        qubitManipulators::hadamardGate(qReg, i);
    }

    // step 5) Measure qubits
    std::string measuredRegister = qReg.strRegisterMeasure();
    std::string result = "";

    for (unsigned int i = 0; i < measuredRegister.size() - 1; i++) {

        if (measuredRegister.at(i) == '1') {
            result = "balanced";
            break;
        }

        result = "constant";
    }

    std::cout << "Function is " << result
              << ". Measured:|" + measuredRegister << ">" << std::endl;

}
