//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include <vector>
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

void Qubit::collapse() {

}

void Qubit::manipulate(std::function<std::vector<std::complex<double>> (std::complex<double>&, std::complex<double>&)> manipulation) {

    std::vector<std::complex<double>> newAmplitudes = manipulation(_alpha, _beta);


    // check that |a|^2 + |b|^2 = 1
    if (pow(newAmplitudes[0],2) + pow(newAmplitudes[0],2) == 1.0) {
        _alpha = newAmplitudes[0];
        _alpha = newAmplitudes[1];
    }


}
