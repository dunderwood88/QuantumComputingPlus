#include <iostream>
#include "../include/QubitRegister.h"
#include "../include/QubitManipulators.h"
#include "../include/util.h"
#include "../include/QuantumAlgorithms.h"

int main() {

    // GROVER'S ALGORITHM TEST (2 qubit case)

    // initialise setup
    /*unsigned int numQubits = 2;
    QubitRegister qReg(numQubits);

    int searchSpace = (int) pow(2, numQubits);
    int oracleAnswer = 2;

    QuantumAlgorithms::GroverSearch(
            qReg,
            [&searchSpace, &oracleAnswer](std::vector<std::complex<double>> &amplitudes) {

                amplitudes[oracleAnswer] = - amplitudes[oracleAnswer];

                return amplitudes;
            }
    );*/

    QubitRegister qReg(3);

    QuantumAlgorithms::DeutschJozsa(qReg,
                                    [](std::vector<std::complex<double>> &amplitudes) {

                                        std::vector<std::complex<double>> newAmplitudes;

                                        for (unsigned int i = 0; i < amplitudes.size(); i++) {

                                            std::complex<double> amp;

                                            if ( i == 4) {
                                                amp = amplitudes.at(5);
                                            } else if (i == 5) {
                                                amp = amplitudes.at(4);
                                            } else if ( i == 6) {
                                                amp = amplitudes.at(7);
                                            } else if (i == 7) {
                                                amp = amplitudes.at(6);
                                            } else {
                                                amp = amplitudes.at(i);
                                            }

                                            //amp = amplitudes.at(i);


                                            newAmplitudes.push_back(amp);
                                        }

                                        return newAmplitudes;
                                    });

    return 0;

}