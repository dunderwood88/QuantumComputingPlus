#include <iostream>
#import "QubitRegister.h"
#import "QubitManipulators.h"

int main() {

    std::cout << "Initialise qubit register" << std::endl;

    QuantumRegister qRegister(3);
    qubitManipulators::hadamardGate(qRegister);

    return 0;
}