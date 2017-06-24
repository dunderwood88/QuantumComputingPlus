#include <iostream>
#include "../include/QubitRegister.h"
#include "../include/QubitManipulators.h"
#include "../include/Qubit.h"

int main() {

    QubitRegister qReg(3);
    //Qubit qubit;

    qubitManipulators::hadamardGate(qReg, 3);

    return 0;

}