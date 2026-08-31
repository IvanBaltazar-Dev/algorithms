cmake_minimum_required(VERSION 4.2)
project(dv_p4)

set(CMAKE_CXX_STANDARD 20)

add_executable(dv_p4 main.cpp
        Funciones/Funciones.cpp
        Funciones/Funciones.h
        EstructurasAdicionales/Resultado.h)
