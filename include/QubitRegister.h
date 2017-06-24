//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUBITREGISTER_H
#define QUANTUMCOMPUTING_QUBITREGISTER_H

#include <vector>
#include <complex.h>

class QubitRegister {

private:
    int _numQubits;
    std::vector<std::complex<double>> _qubitAmplitudes;


public:
    QubitRegister();
    QubitRegister(int numQubits);

    int size();

    void manipulate(std::function<std::vector<std::complex<double>> (std::vector<std::complex<double>>&)> manipulation);
    void manipulate(int registerPosition);


    std::string measure();

};


#endif //QUANTUMCOMPUTING_QUBITREGISTER_H
