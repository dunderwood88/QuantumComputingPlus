cmake_minimum_required(VERSION 3.7)
project(QuantumComputing__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/QubitRegister.cpp include/QubitRegister.h src/QubitManipulators.cpp include/QubitManipulators.h src/Qubit.cpp include/Qubit.h)
add_executable(QuantumComputing__ ${SOURCE_FILES})