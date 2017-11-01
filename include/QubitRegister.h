//
// Created by Dan Underwood on 06/06/2017.
//

#ifndef QUANTUMCOMPUTING_QUBITREGISTER_H
#define QUANTUMCOMPUTING_QUBITREGISTER_H

#include <vector>
#include <complex.h>

class QubitRegister {

private:
    unsigned int _numQubits;
    std::vector<std::complex<double>> _qubitAmplitudes;

    // wavefunction collapse
    unsigned int randomState();
    void collapse(unsigned int state);
    void collapse(unsigned int state, unsigned int measuredQubit);


public:
    QubitRegister();
    QubitRegister(unsigned int numQubits);
    unsigned int size();

    // manipulation
    void manipulate(std::function<std::vector<std::complex<double>> (std::vector<std::complex<double>>&)> manipulation);

    // measurement
    unsigned int qubitMeasure(unsigned int qubitPosition);
    unsigned int intRegisterMeasure();
    std::string strRegisterMeasure();

};


#endif //QUANTUMCOMPUTING_QUBITREGISTER_H
