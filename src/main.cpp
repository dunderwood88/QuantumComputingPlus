#include <iostream>
#include "../include/QubitRegister.h"
#include "../include/QubitManipulators.h"
#include "../include/util.h"
#include "../include/QuantumAlgorithms.h"

int main() {

    // GROVER'S ALGORITHM TEST (2 qubit case)

    // initialise setup
    unsigned int numQubits = 2;
    QubitRegister qReg(numQubits);

    int searchSpace = (int) pow(2, numQubits);
    int oracleAnswer = 0;

    QuantumAlgorithms::GroverSearch(
            qReg,
            [&searchSpace, &oracleAnswer](std::vector<std::complex<double>> &amplitudes) {

                amplitudes[oracleAnswer] = - amplitudes[oracleAnswer];

                return amplitudes;
            }
    );


    return 0;

}