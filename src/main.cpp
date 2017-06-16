#include <iostream>
#import "../include/QubitRegister.h"
#import "../include/QubitManipulators.h"

int main() {

    std::cout << "Initialise qubit register" << std::endl;

    QubitRegister qRegister(3);

    qubitManipulators::hadamardGate(qRegister);

    qRegister.measure();

    /*for(Qubit& q: qRegister.list()){
        q.measure();
    }*/


    /*std::complex<double> a(1,2);
    std::complex<double> b(2,1);
    std::complex<double> c(3,3);

    std::cout << pow(abs(a*b*c),2) << std::endl;
    std::cout << pow(abs(a),2) * pow(abs(b),2) * pow(abs(c),2) << std::endl;

    return 0;*/
}