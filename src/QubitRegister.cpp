//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include "../include/QubitRegister.h"

QuantumRegister::QuantumRegister(int numQubits) {

    for (int i = 0; i < numQubits; i++) {
        this->push_back(Qubit());
    }

}