//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include <vector>
#include "../include/Qubit.h"

Qubit::Qubit() {

    // By default initialise in the 0 state
    initialise(1.0, 0.0);
    std::cout << "Qubit initialised in computational |0> state." << std::endl;
}

void Qubit::initialise(std::complex<double> alpha, std::complex<double> beta) {

    _alpha = alpha;
    _beta = beta;
}


void Qubit::manipulate(std::function<std::vector<std::complex<double>> (std::complex<double>&, std::complex<double>&)> manipulation) {

    std::vector<std::complex<double>> newAmplitudes = manipulation(_alpha, _beta);

    // check that |a|^2 + |b|^2 = 1
    if (1 - (pow(abs(newAmplitudes[0]),2) + pow(abs(newAmplitudes[1]),2)) < 1E-3) {
        _alpha = newAmplitudes[0];
        _beta = newAmplitudes[1];
    }
}