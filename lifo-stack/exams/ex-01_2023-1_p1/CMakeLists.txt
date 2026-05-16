cmake_minimum_required(VERSION 4.2)
project(ex_01_2023_1_p1)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex_01_2023_1_p1 main.cpp
        Funciones.cpp
        Funciones.h
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/Pila.h)
