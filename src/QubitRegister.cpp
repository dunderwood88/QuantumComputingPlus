//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include "../include/QubitRegister.h"

/**
 * Constructor
 *
 * @param numQubits the size of the register/the number of qubits
 * to initialise
 */
QubitRegister::QubitRegister(int numQubits) {

    for (int i = 0; i < numQubits; i++) {
        _qubits.push_back(Qubit());
    }

}


/**
 * Performs a measurement on the qubit in the computational basis
 *
 * @return a string of binary digits representing a collapsed classical
 * state
 */
std::string QubitRegister::measure() {

    std::string registerValue;

    for (Qubit& q: _qubits) {
        registerValue = registerValue + std::to_string(q.measure());
    }

    return registerValue;

}

/**
 * Getter method for the qubit vector
 *
 * @return a reference to the qubit vector
 */
std::vector<Qubit>& QubitRegister::list() {
    return _qubits;
}
