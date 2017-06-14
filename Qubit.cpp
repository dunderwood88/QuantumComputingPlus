//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include "Qubit.h"

Qubit::Qubit() {

    // By default initialise in the 0 state
    initialise(1.0, 0.0);
    std::cout << "Qubit initialised in |0> state." << std::endl;
}

void Qubit::initialise(std::complex<double> alpha, std::complex<double> beta) {

    _alpha = alpha;
    _beta = beta;
}

void::collapse() {

}