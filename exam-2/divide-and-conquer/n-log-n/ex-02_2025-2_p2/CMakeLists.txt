cmake_minimum_required(VERSION 4.2)
project(ex_02_2025_2_p2)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex_02_2025_2_p2 main.cpp
        EstructurasAdicionales/Resultado.h
        FuncionesAuxiliares/Funciones.cpp
        FuncionesAuxiliares/Funciones.h
        EstructurasAdicionales/Acumulacion.h)
