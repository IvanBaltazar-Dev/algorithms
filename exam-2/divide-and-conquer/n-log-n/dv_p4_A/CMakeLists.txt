cmake_minimum_required(VERSION 4.2)
project(dv_p4_A)

set(CMAKE_CXX_STANDARD 20)

add_executable(dv_p4_A main.cpp
        EstructurasAuxiliares/Resultado.h
        FuncionesAuxiliares/Funciones.cpp
        FuncionesAuxiliares/Funciones.h)
