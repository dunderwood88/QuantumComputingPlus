//
// Created by Dan Underwood on 06/06/2017.
//

#include <iostream>
#include <vector>
#include "../include/Qubit.h"
#include "../include/util.h"


/**
 * Constructor
 */
Qubit::Qubit() {

    // By default initialise in the 0 state
    initialise(1.0, 0.0);
    std::cout << "Qubit initialised in computational |0> state." << std::endl;
}


/**
 * Initialises the qubit state, accepting two complex numbers
 *
 * @param alpha probability density of |0> state
 * @param beta probability density of |1> state
 */
void Qubit::initialise(std::complex<double> alpha, std::complex<double> beta) {

    _alpha = alpha;
    _beta = beta;
}

/**
 * Accepts a lambda function which performs a manipulation on the qubit state
 *
 * @param manipulation the lambda function, which accepts two complex number
 * references and returns a vector of 2 new complex numbers

 */
void Qubit::manipulate(std::function<std::vector<std::complex<double>> (std::complex<double>&, std::complex<double>&)> manipulation) {

    std::vector<std::complex<double>> newAmplitudes = manipulation(_alpha, _beta);

    // check that |a|^2 + |b|^2 = 1
    if (1 - (pow(abs(newAmplitudes[0]),2) + pow(abs(newAmplitudes[1]),2)) < 1E-3) {
        _alpha = newAmplitudes[0];
        _beta = newAmplitudes[1];
    }
}

/**
 * Performs a measurement on the qubit in the computational basis
 *
 * @return either a collapsed 0 or 1 state
 */
int Qubit::measure() {

    double alphaProb = pow(abs(_alpha),2);

    if (util::random() < alphaProb) {
        _alpha = 1;
        _beta = 0;
        std::cout << "Qubit system collapsed to |0>" << std::endl;
        return 0;
    }
    else {
        _alpha = 0;
        _beta = 1;
        std::cout << "Qubit system collapsed to |1>" << std::endl;
        return 1;
    }
}
