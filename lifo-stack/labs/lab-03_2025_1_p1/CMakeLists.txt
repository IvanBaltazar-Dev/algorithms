cmake_minimum_required(VERSION 4.2)
project(lab_03_2025_1_p1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_03_2025_1_p1 main.cpp
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/Pila.h
        Funciones.cpp
        Funciones.h)
