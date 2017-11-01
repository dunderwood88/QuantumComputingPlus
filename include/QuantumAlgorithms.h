//
// Created by Dan Underwood on 11/08/2017.
//

#ifndef QUANTUMCOMPUTING_QUANTUMALGORITHMS_H
#define QUANTUMCOMPUTING_QUANTUMALGORITHMS_H


#include "QubitRegister.h"

namespace QuantumAlgorithms {

    /**
     * Grover search algorithm for querying a quantum oracle which promises a single
     * solution.
     * This algorithm finds a solution using O(sqrt(N)) queries to the oracle, whereas
     * classically it would take O(N) queries.
     *
     * @param qReg the qubit register which undergoes manipulation
     * @param oracleFunction the oracle function which recognises the solution. Has a
     * search space of N = 2^n, where n = number of qubits
     */
    void GroverSearch(QubitRegister &qReg,
                      std::function<std::vector<std::complex<double>>(std::vector<std::complex<double>> &)> oracleFunction);



    /**
     * Deutsch-Jozsa algorithm for determining whether a function is constant or balanced.
     * It accepts input |x>|y>, where |x> can be either be a single qubit or a tensor product
     * of qubits. If the function is constant, then |x> will be measured as all zeroes with a
     * probabilty of unity. If it is balanced, then the opposite is true.
     *
     * @param qReg the qubit register, consisting of n-1 input qubits, and 1 ancillary qubit
     * @param function a function that promises to be either constant or balanced, where it takes the
     * qubit register |x>|y> and outputs |x>| (y + f(x))%2 >
     */
    void DeutschJozsa(QubitRegister &qReg,
                      std::function<std::vector<std::complex<double>>(std::vector<std::complex<double>> &)> function);


};


#endif //QUANTUMCOMPUTING_QUANTUMALGORITHMS_H
