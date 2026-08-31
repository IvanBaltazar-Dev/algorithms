cmake_minimum_required(VERSION 4.2)
project(lab_04_2025_2_p1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_04_2025_2_p1 main.cpp
        EstructurasAuxiliares/Resultado.h
        FuncionesAuxiliares/Funciones.cpp
        FuncionesAuxiliares/Funciones.h
        EstructurasAuxiliares/Conteo.h)
