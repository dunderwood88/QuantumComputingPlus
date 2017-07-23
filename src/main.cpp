#include <iostream>
#include "../include/QubitRegister.h"
#include "../include/QubitManipulators.h"

int main() {


    // GROVER'S ALGORITHM TEST (2 qubit case)

    // initialise setup
    unsigned int numQubits = 2;
    QubitRegister qReg(numQubits);

    int searchSpace = (int) pow(2, numQubits);
    int oracleAnswer = 3;

    // step 1) Hadamard transform on all qubits
    qubitManipulators::hadamardGate(qReg);


    // step 2) Grover unknown function
    qReg.manipulate(
            [&searchSpace, &oracleAnswer](std::vector<std::complex<double>> &amplitudes) {

                amplitudes[oracleAnswer] = - amplitudes[oracleAnswer];

                return amplitudes;
            }
    );

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
    qReg.measure();

    return 0;

}