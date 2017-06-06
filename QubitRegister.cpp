//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include <cmath>
#include "QubitRegister.h"

QuantumRegister::QuantumRegister(int numQubits) {

    _numStates = pow(2, numQubits);

    /*for(int i = 0; i < pow(2, numQubits); i++){

        _qubits.push_back(0.0);
    }*/

}

void QuantumRegister::PrintStates() {

    for(int i = 0; i < _numStates; i++){
        std::cout << "|" << std::bitset<8>(i) << ">" << std::endl;
    }

}

