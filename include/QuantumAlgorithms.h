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

};


#endif //QUANTUMCOMPUTING_QUANTUMALGORITHMS_H
