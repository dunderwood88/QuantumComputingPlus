#include <iostream>
#import "../include/QubitRegister.h"
#import "../include/QubitManipulators.h"

int main() {

    std::cout << "Initialise qubit register" << std::endl;

    QuantumRegister qRegister(3);
    qubitManipulators::hadamardGate(qRegister);

    for(Qubit& q: qRegister){
        qubitManipulators::measure(q);
    }

    return 0;
}