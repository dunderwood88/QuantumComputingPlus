cmake_minimum_required(VERSION 3.7)
project(QuantumComputing__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp QubitRegister.cpp QubitRegister.h)
add_executable(QuantumComputing__ ${SOURCE_FILES})