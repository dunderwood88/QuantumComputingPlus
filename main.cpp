#include <iostream>
#import "QubitRegister.h"

int main() {

    std::cout << "Initialize qubit register" << std::endl;

    QuantumRegister qRegister(3);

    qRegister.PrintStates();

    return 0;
}