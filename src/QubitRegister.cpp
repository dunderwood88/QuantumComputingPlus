//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include <complex.h>
#include "../include/util.h"
#include "../include/QubitRegister.h"

/**
 * Default constructor: initialises a single qubit in the |0> state
 */
QubitRegister::QubitRegister() {

    QubitRegister(1);

}

/**
 * Constructor
 *
 * @param numQubits the size of the register/the number of qubits
 * to initialise
 */
QubitRegister::QubitRegister(unsigned int numQubits) {

    _numQubits = numQubits;
    std::string state = "|";

    for (int i = 0; i < (int)pow(2, _numQubits); i++) {

        // initialise in the |0^n> state
        if (i == 0) {
            _qubitAmplitudes.push_back(std::complex<double>(1.0, 0.0));

        } else {
            _qubitAmplitudes.push_back(std::complex<double>(0.0, 0.0));
        }

        if (i < _numQubits)
            state = state + "0";

    }


    std::cout << "Initialised qubit register in " << state << "> state" << std::endl;

}


/**
 * Returns size of the qubit register (number of qubits)
 *
 * @return length of qubit register
 */
unsigned int QubitRegister::size() {

    return _numQubits;
}


/**
 * Accepts a lambda function which performs a manipulation on the qubit register state.
 * Manipulations accept a qubit system (single or register) object and pass into it a lambda
 * function which performs an internal manipulation, which avoids exposing the internal
 * information of the qubit
 *
 * @param manipulation the lambda function, which accepts a complex number vector
 * reference and returns a new one with manipulated amplitudes

 */
void QubitRegister::manipulate(
        std::function<std::vector<std::complex<double>>(std::vector<std::complex<double>> &)> manipulation) {

    std::vector<std::complex<double>> newAmplitudes = manipulation(_qubitAmplitudes);

    // check for unitarity, i.e. |a|^2 + |b|^2 + ... = 1
    double sum = 0.0;
    for (std::complex<double> amplitude: newAmplitudes) {

        sum += pow(abs(amplitude),2);
    }

    if (1 - sum < 1E-3) {
        _qubitAmplitudes = newAmplitudes;
    }

}

/**
 * Performs a measurement on a qubit in the computational basis
 *
 * @param qubitPosition the position of the qubit in the register
 * that is to be measured
 *
 * @return an integer representing the value recorded in the
 * specified register position
 */
unsigned int QubitRegister::qubitMeasure(unsigned int qubitPosition) {

    int state = randomState();


    return 0;
}


/**
 * Performs a measurement on the qubit register in the computational basis
 *
 * @return an integer representing the base10 value of the collapsed
 * classical state
 */
unsigned int QubitRegister::intRegisterMeasure() {

    unsigned int state = randomState();
    unsigned int i = 0;

    // collapse to random state
    while (i < _numQubits) {

        if (i == state) {
            _qubitAmplitudes[i] = 1.0;
        } else {
            _qubitAmplitudes[i] = 0.0;
        }

        i++;
    }

    return state;

}


/**
 * Performs a measurement on the qubit register in the computational basis
 *
 * @return a string of binary digits representing a collapsed classical
 * state
 */
std::string QubitRegister::strRegisterMeasure() {

    unsigned int state = intRegisterMeasure();

    std::string output = "";
    unsigned int i = 0;

    while (i < _numQubits) {

        output = std::to_string((state >> i) & 1) + output;
        i++;

    }

    return output;
}



/**
 * Gets a single random state from the superposition based
 * on the individual state probability amplitudes
 *
 * @return the position of the random state in the summation
 */
unsigned int QubitRegister::randomState() {

    unsigned int statePos = 0;

    double rand = util::random();
    double totalProb = pow(abs(_qubitAmplitudes[0]), 2);

    while (totalProb < rand && statePos < pow(2, _numQubits)) {
        statePos++;
        totalProb += pow(abs(_qubitAmplitudes[statePos]), 2);
    }

    return statePos;
}

