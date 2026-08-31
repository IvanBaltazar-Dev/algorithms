cmake_minimum_required(VERSION 4.2)
project(ex_02_2025_1_p5)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex_02_2025_1_p5 main.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/Pila.h
        Funciones.cpp
        Funciones.h)
